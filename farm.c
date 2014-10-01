#include <stdlib.h>
#include <stdio.h>
#include <farm.h>
#include <tank.h>
#include <list.h>
#include <shrimp.h>
#include <gene.h>

farm* init_farm(){
	
	farm *f = (farm*)malloc(sizeof(farm));

	f->twb_tank = init_tank();
	f->f1_tank = init_tank();
	f->trash_tank = init_tank();
	
	return f;
}

void delete_farm(farm *_f){
	delete_tank(_f->twb_tank);
	delete_tank(_f->f1_tank);
	delete_tank(_f->trash_tank);
	free(_f);
}

void process_repro(farm *_f){
	process_list(_f->twb_tank->lshrimps, repro);
	process_list(_f->f1_tank->lshrimps, repro);
	process_list(_f->trash_tank->lshrimps, repro);
}

void process_reap(farm *_f){
	process_list(_f->twb_tank->lshrimps, reap);
	process_list(_f->f1_tank->lshrimps, reap);
	process_list(_f->trash_tank->lshrimps, reap);
}

void process_selection(farm *_f){
	selection(_f, _f->twb_tank);
	selection(_f, _f->f1_tank);
	selection(_f, _f->trash_tank);
}

void process_stats(farm *_f){
	printf("twb tank [");
	stats(_f->twb_tank);
	printf("]\nf1 tank [");
	stats(_f->f1_tank);
	printf("]\ntrash tank [");
	stats(_f->trash_tank);
	printf("]\n");
}

void selection(farm* _f, tank* _t){  

        node *n, *tmp;
        shrimp *shrp;
        gene *g;
        allele expr_gene;
        list *ll;

        ll = _t->lshrimps;

        for(n = ll->head; n; n = tmp){

                shrp = (shrimp*)n->data;
                g = get_gene(shrp->lgenes, YBEE);
                expr_gene = get_expr_gene(g);
                tmp = n->next;

                // Crystal detected in TWB tank
                if(expr_gene == BEE && ll == _f->twb_tank->lshrimps && shrp->age > 30){

                        unlink_node(ll, n);

                        // If first generation not expressing TWB gene, put it in f1 tank, otherwise trash
                        if(g->generation == 1)
                                add_list(_f->f1_tank->lshrimps, shrp, delete_shrimp, print_shrimp);
                        else   
                                add_list(_f->trash_tank->lshrimps, shrp, delete_shrimp, print_shrimp);

                        if(n) free(n);
                }

                // F2+ Crystal detected in f1
                if(expr_gene == BEE && ll == _f->f1_tank->lshrimps && shrp->age > 30 && g->generation > 1){
                        unlink_node(ll, n);
                        add_list(_f->trash_tank->lshrimps, shrp, delete_shrimp, print_shrimp);
                        if(n) free(n);
                }

                // TWB detected outside TWB tank
                if(expr_gene == TWB && ll != _f->twb_tank->lshrimps && shrp->age > 30){
                        unlink_node(ll, n);
                        add_list(_f->twb_tank->lshrimps, shrp, delete_shrimp, print_shrimp);
                        if(n) free(n);
                }
        }
}


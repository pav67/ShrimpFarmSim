#include <stdlib.h>
#include <stdio.h>
#include <aqua.h>
#include <list.h>
#include <crecre.h>
#include <gene.h>

aqua* init_aqua(){
	
	aqua *aq = (aqua*)malloc(sizeof(aqua));

	aq->twb_tank = init_list();
	aq->f1_tank = init_list();
	aq->trash_tank = init_list();
	
	return aq;
}

void delete_aqua(aqua *_aqua){
	delete_list(_aqua->twb_tank);
	delete_list(_aqua->f1_tank);
	delete_list(_aqua->trash_tank);
	if(_aqua) free(_aqua);
}

void process_repro(aqua *_aqua){
	process_list(_aqua->twb_tank, repro);
	process_list(_aqua->f1_tank, repro);
	process_list(_aqua->trash_tank, repro);
}

void process_reap(aqua *_aqua){
	process_list(_aqua->twb_tank, reap);
	process_list(_aqua->f1_tank, reap);
	process_list(_aqua->trash_tank, reap);
}

void process_selection(aqua *_aqua){
	selection(_aqua, _aqua->twb_tank);
	selection(_aqua, _aqua->f1_tank);
	selection(_aqua, _aqua->trash_tank);
}

void selection(aqua *_aqua, list *_ll){

	node *n, *tmp;
	crecre *cre;
	gene *g;
	allele expr_gene;

	for(n = _ll->head; n; n = tmp){

		cre = (crecre*)n->data;
		g = get_gene(cre->lgenes, YBEE);
		expr_gene = get_expr_gene(g);
		tmp = n->next;

		// Crystal detected in TWB tank
		if(expr_gene == BEE && _ll == _aqua->twb_tank && cre->age > 30){
			
			unlink_node(_ll, n);

			// If first generation not expressing TWB gene, put it in f1 tank, otherwise trash
			if(g->generation == 1)
				add_list(_aqua->f1_tank, cre, delete_crecre, print_crecre);
			else
				add_list(_aqua->trash_tank, cre, delete_crecre, print_crecre);
				
			if(n) free(n);
		}

		// F2+ Crystal detected in f1
		if(expr_gene == BEE && _ll == _aqua->f1_tank && cre->age > 30 && g->generation > 1){
			unlink_node(_ll, n);
			add_list(_aqua->f1_tank, cre, delete_crecre, print_crecre);
			if(n) free(n);
		}

		// TWB detected outside TWB tank
		if(expr_gene == TWB && _ll != _aqua->twb_tank && cre->age > 30){
			unlink_node(_ll, n);
			add_list(_aqua->twb_tank, cre, delete_crecre, print_crecre);
			if(n) free(n);
		}
	}
}

void process_stats(aqua *_aq){
	printf("twb tank [");
	stats(_aq->twb_tank);
	printf("]\nf1 tank [");
	stats(_aq->f1_tank);
	printf("]\ntrash tank [");
	stats(_aq->trash_tank);
	printf("]\n");
}

void stats(list *_ll){

	node *n;
	crecre *cre;
	gene *gtwb, *gcol;
	int ntwb;
	int nred;
	int ntot;

	ntwb = nred = ntot = 0;

	for(n = _ll->head; n; n = n->next){
		
		cre = (crecre*)n->data;

		gtwb = get_gene(cre->lgenes, YBEE);
		gcol = get_gene(cre->lgenes, COLOR);

		// number of TWB shrimps
		if(get_expr_gene(gtwb) == TWB) ntwb++;
		// number of red shrimps
		if(get_expr_gene(gcol) == BEE) nred++;
		// total number of shrimps
		ntot++;
	}

	printf("%d shrimps : %d twb - %d crystal - %d red - %d black", ntot, ntwb, ntot-ntwb, nred, ntot-nred);
}

#include <stdio.h>
#include <stdlib.h>
#include <tank.h>
#include <crecre.h>
#include <list.h>
#include <farm.h>
#include <gene.h>

tank* init_tank(){

	tank* t = (tank*)malloc(sizeof(tank));
	t->lshrimps = init_list();

	return t;
}

void delete_tank(tank* _t){

	delete_list(_t->lshrimps);
	free(_t);
}

void stats(tank* _t){
	
	node *n;
        crecre *cre;
        gene *gtwb, *gcol;
        int ntwb;
        int nred;
        int ntot;

        ntwb = nred = ntot = 0;

        for(n = _t->lshrimps->head; n; n = n->next){

                cre = (crecre*)n->data;

                gtwb = get_gene(cre->lgenes, YBEE);
                gcol = get_gene(cre->lgenes, COLOR);

                // number of TWB shrimps
                if(get_expr_gene(gtwb) == TWB) ntwb++;
                // number of red shrimps
                if(get_expr_gene(gcol) == RED) nred++;
                // total number of shrimps
                ntot++;
        }

        printf("%d shrimps : %d twb - %d crystal - %d red - %d black", ntot, ntwb, ntot-ntwb, nred, ntot-nred);
}

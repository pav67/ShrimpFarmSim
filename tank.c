#include <stdio.h>
#include <stdlib.h>
#include <tank.h>
#include <shrimp.h>
#include <list.h>
#include <farm.h>
#include <gene.h>
#include <randomize.h>

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
        shrimp *shrp;
        gene *gtwb, *gcol;
        int ntwb;
        int nred;
        int ntot;

        ntwb = nred = ntot = 0;

        for(n = _t->lshrimps->head; n; n = n->next){

                shrp = (shrimp*)n->data;

                gtwb = get_gene(shrp->lgenes, YBEE);
                gcol = get_gene(shrp->lgenes, COLOR);

                // number of TWB shrimps
                if(get_expr_gene(gtwb) == TWB) ntwb++;
                // number of red shrimps
                if(get_expr_gene(gcol) == RED) nred++;
                // total number of shrimps
                ntot++;
        }

        printf("%d shrimps : %d twb - %d crystal - %d red - %d black", ntot, ntwb, ntot-ntwb, nred, ntot-nred);
}

void reap(list *_ll, node *_n){

        if(!_n) return;
        if(!_n->data) return;

        shrimp* shrp = (shrimp*)_n->data;
        shrp->age++;

        if(shrp->age > shrp->lifeexp){
                delete_node(_ll, _n);
        }
}

void repro(list *_ll, node *_n){

        shrimp *shrp = (shrimp*)_n->data;
        shrimp *bae;
        int i, eggs;

        // If it's a male, skip
        if(shrp->sex == MALE) return;
        // If it's not an adult, skip
        if(shrp->age < shrp->adultage) return;
        // If in pause process, skip
        if(shrp->pause > 0) { shrp->pause--; return; }
        // If no breeding in progress, start one, and skip
        if(shrp->breeding == 0) { shrp->breeding = generate_gestation_time(); return; }

        shrp->breeding--;

        // If breeding in progress, not near to an end, skip
        if(shrp->breeding > 1) return;

        shrp->breeding = 0;

        // Getting shrimp a boyfriend
        if(bae = get_male(_ll)){
                // Getting number of eggs carried
                eggs = generate_egg_number();
                // Creating a new shrimp for each of those eggs
                for(i = 0; i < eggs; i++)
                        add_list(_ll, breed(bae, shrp), delete_shrimp, print_shrimp);

                // Letting our friend rest
                shrp->pause = generate_pause();
        }
}

shrimp* get_male(list *_ll){

        node *n;
        shrimp *shrp, *res;
        shrimp **tshrp = NULL;
        int i = 0;

        res = NULL;

        for(n = _ll->head; n; n = n->next){

                shrp = (shrimp*)n->data;
                if(shrp->sex == MALE && shrp->age >= shrp->adultage){
                        i++;
                        tshrp = (shrimp**)realloc(tshrp, i * sizeof(shrimp*));
                        tshrp[i-1] = shrp;
                }
        }

        if(tshrp){
                res = tshrp[rand()%i];
                free(tshrp);
        }

        return res;
}


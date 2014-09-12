#include <stdio.h>
#include <stdlib.h>
#include <genome.h>

genome* create_genome(char _g1, char _g2, char _recessive, int _generation){

	genome* gen = malloc(sizeof(genome));

	gen->g1 = _g1;
	gen->g2 = _g2;
	gen->recessive = _recessive;
	gen->generation = _generation;

	return gen;
}

void delete_genome(void *_gen){
	free(_gen);
}

void print_genome(void *_gen){
	genome *gen = (genome*)_gen;  
	if(gen->g1 == gen->g2) printf("[%c]", gen->g1);
	if(gen->g1 != gen->g2 && gen->g1 == gen->recessive) printf("[%c]", gen->g2);
	if(gen->g1 != gen->g2 && gen->g1 != gen->recessive) printf("[%c]", gen->g1);
}

void print_genome_full(void *_gen){
	genome *gen = (genome*)_gen;
	printf("[ g1 : %c - g2 : %c - recesive : %c - generation : %d ]", gen->g1, gen->g2, gen->recessive, gen->generation);
}

char get_genome(list *_ll, char _g){

	node *n;
	genome *g;
	char c;

	for(n = _ll->head; n; n = n->next){

		g = (genome*)n->data;

		if(g->recessive == _g){

			if(g->g1 == g->g2){
				c = g->g1;
				break;
			}

			if(g->g1 == g->recessive){
				c = g->g2;
				break;
			}

			c = g->g1;
			break;
		}
	}

	return c;
}

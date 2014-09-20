#include <stdio.h>
#include <stdlib.h>
#include <genome.h>

genome* create_genome(char _g1, char _g2, char _recessive, int _generation){

	genome* gene = malloc(sizeof(genome));

	gene->g1 = _g1;
	gene->g2 = _g2;
	gene->recessive = _recessive;
	gene->generation = _generation;

	return gene;
}

void delete_genome(void *_gene){
	if(_gene) free(_gene);
	_gene = NULL;
}

void print_genome(void *_gene){
	genome *gene = (genome*)_gene;  
	if(gene->g1 == gene->g2) printf("[%c]", gene->g1);
	if(gene->g1 != gene->g2 && gene->g1 == gene->recessive) printf("[%c]", gene->g2);
	if(gene->g1 != gene->g2 && gene->g1 != gene->recessive) printf("[%c]", gene->g1);
}

void print_genome_full(void *_gene){
	genome *gene = (genome*)_gene;
	printf("[ g1 : %c - g2 : %c - recesive : %c - generation : %d ]", gene->g1, gene->g2, gene->recessive, gene->generation);
}

genome* get_genome(list *_ll, char _g){

	node *n;
	genome *g, *res;

	for(n = _ll->head; n; n = n->next){

		g = (genome*)n->data;

		if(g->recessive == _g){

			res = g;
			break;
		}
	}

	return res;
}

char get_expr_gene(genome *_gene){
	
	char c;
			
	c = _gene->g1;

	if(_gene->g1 != _gene->g2 && _gene->g1 == _gene->recessive)
		c = _gene->g2;
	
	return c;
}

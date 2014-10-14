#include <stdio.h>
#include <stdlib.h>
#include <gene.h>

gene* create_gene(allele _g1, allele _g2, allele _recessive, allele _ygene, int _generation){

	gene* g = malloc(sizeof(gene));

	g->g1 = _g1;
	g->g2 = _g2;
	g->recessive = _recessive;
	g->ygene = _ygene;
	g->generation = _generation;

	return g;
}

void delete_gene(void *_gene){
	if(_gene) free(_gene);
}

void print_gene(void *_gene){
	gene *g = (gene*)_gene;  
	if(g->g1 == g->g2) printf("[%c]", g->g1);
	if(g->g1 != g->g2 && g->g1 == g->recessive) printf("[%c]", g->g2);
	if(g->g1 != g->g2 && g->g1 != g->recessive) printf("[%c]", g->g1);
}

void print_gene_full(void *_gene){
	gene *g = (gene*)_gene;
	printf("[ g1 : %c - g2 : %c - recesive : %c - generation : %d ]", g->g1, g->g2, g->recessive, g->generation);
}

gene* get_gene(list *_ll, allele _a){

	node *n;
	gene *g, *res = NULL;

	for(n = _ll->head; n; n = n->next){

		g = (gene*)n->data;

		if(g->ygene == _a){

			res = g;
			break;
		}
	}

	return res;
}

allele get_expr_gene(gene *_gene){
	
	allele a;
			
	a = _gene->g1;

	if(_gene->g1 != _gene->g2 && _gene->g1 == _gene->recessive)
		a = _gene->g2;
	
	return a;
}

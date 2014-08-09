#include <stdio.h>
#include <stdlib.h>
#include <genome.h>

genome* create_genome(char _g1, char _g2, char _recessive){

	genome* gens = malloc(sizeof(genome));

	gens->g1 = _g1;
	gens->g2 = _g2;
	gens->recessive = _recessive;

	return gens;
}

void delete_genome(void* _gens){
	free(_gens);
}

void print_genome(void* _gens){
	genome *gens = (genome*)_gens;  
	if(gens->g1 == gens->g2) printf("[%c]", gens->g1);
	if(gens->g1 != gens->g2 && gens->g1 == gens->recessive) printf("[%c]", gens->g2);
	if(gens->g1 != gens->g2 && gens->g1 != gens->recessive) printf("[%c]", gens->g1);
}

void print_genome_full(void* _gens){
	genome *gens = (genome*)_gens;
	printf("[ g1 : %c - g2 : %c ]", gens->g1, gens->g2);
}

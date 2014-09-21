#ifndef __gene_h
#define __gene_h

#include <list.h>

typedef enum _allele {
	// Type of gene
	YBEE, COLOR, ALBINO,
	// TWB or Crystal bee
	TWB, BEE,
	// Color
	RED, BLACK,
	// Albino 
	ALB, PIGM
} allele;

typedef struct _genome {

	allele g1;
	allele g2;
	allele ygene;
	allele recessive;
	int generation;
} gene;

gene* create_gene(allele,allele,allele,allele,int);
void delete_gene(void*);
void print_gene(void*);
void print_gene_full(void*);
gene* get_gene(list*, allele);
allele get_expr_gene(gene*);

#endif

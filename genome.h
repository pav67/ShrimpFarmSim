#ifndef __genome_h
#define __genome_h

#include <list.h>

typedef struct _genome {

	char g1;
	char g2;
	char recessive;
	int generation;
} genome;

genome* create_genome(char,char,char,int);
void delete_genome(void*);
void print_genome(void*);
void print_genome_full(void*);
char get_genome(list*, char);

#endif

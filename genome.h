#ifndef __genome_h
#define __genome_h

typedef struct _genome {

	char g1;
	char g2;
	char recessive;
} genome;

genome* create_genome(char,char,char);
void delete_genome(void*);
void print_genome(void*);
void print_genome_full(void*);

#endif

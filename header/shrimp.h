#ifndef __shrimp_h
#define __shrimp_h

#include <list.h>
#include <gene.h>

typedef struct _shrimp {
	int age;
	int lifeexp;
	int adultage;
	allele sex;
	int breeding;
	int pause;
	int eggs;
	list *lgenes;
} shrimp;

shrimp* create_shrimp(int, int, allele);
void delete_shrimp(void*);
void print_shrimp(void*);

shrimp* breed(shrimp*, shrimp*);

#endif

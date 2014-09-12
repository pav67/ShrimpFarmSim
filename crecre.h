#ifndef __crecre_h
#define __crecre_h

#include <list.h>

typedef struct _crecre {
	int age;
	int lifeexp;
	int adultage;
	char sex;
	int breeding;
	int pause;
	int eggs;
	list *lgenes;
} crecre;

crecre* create_crecre(int, int, char);
void delete_crecre(void*);
void print_crecre(void*);
crecre* breed(const crecre*, const crecre*);

void reap(list*, node*);
void repro(list*, node*);
crecre* get_male(list*);

#endif

#ifndef __crecre_h
#define __crecre_h

#include <list.h>

typedef struct _crecre {
	int age;
	int lifeexp;
	char sex;
	list *lgens;
} crecre;

crecre* create_crecre(int, char);
void delete_crecre(crecre*);
void print_crecre(const crecre*);
crecre* breed(const crecre*, const crecre*);

#endif

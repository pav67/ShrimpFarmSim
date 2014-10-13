#ifndef __tank_h
#define __tank_h

#include <list.h>
#include <shrimp.h>

typedef struct _tank{
	list *lshrimps;
}tank;

tank* init_tank();
void delete_tank(tank*);

void stats(tank*);
void reap(list*, node*);
void repro(list*, node*);
shrimp* get_male(list*);

#endif

#ifndef __farm_h
#define __farm_h

#include <list.h>
#include <crecre.h>
#include <tank.h>

typedef struct _farm{
	tank *twb_tank;
	tank *f1_tank;
	tank *trash_tank;
}farm;

farm* init_farm();
void delete_farm(farm*);
void process_selection(farm*);
void process_repro(farm*);
void process_reap(farm*);
void process_stats(farm*);

void selection(farm*, tank*);

#endif

#ifndef __aqua_h
#define __aqua_h

#include <list.h>
#include <crecre.h>

typedef struct _aqua{
	list *twb_tank;
	list *f1_tank;
	list *trash_tank;
}aqua;

aqua* init_aqua();
void delete_aqua(aqua*);
void process_selection(aqua*);
void selection(aqua*, list*);
void process_repro(aqua*);
void process_reap(aqua*);
void process_stats(aqua*);
void stats(list*);

#endif

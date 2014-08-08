#ifndef __randomize_h
#define __randomize_h

#include <genome.h>

const genome* generate_genome(const genome*,const genome*);
char generate_sex();
int generate_lifeexp();
int generate_egg_number();
int generate_gestation_time();
int generate_adult_age();
int generate_pause();

#endif

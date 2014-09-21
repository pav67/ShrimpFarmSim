#ifndef __randomize_h
#define __randomize_h

#include <gene.h>

const gene* generate_gene(const gene*,const gene*);
char generate_sex();
int generate_lifeexp();
int generate_egg_number();
int generate_gestation_time();
int generate_adult_age();
int generate_pause();

#endif

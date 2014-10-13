#ifndef __randomize_h
#define __randomize_h

#include <gene.h>

gene* generate_gene(gene*,gene*);
allele generate_sex();
int generate_lifeexp();
int generate_egg_number();
int generate_gestation_time();
int generate_adult_age();
int generate_pause();

#endif

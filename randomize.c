#include <stdlib.h>
#include <time.h>
#include <randomize.h>
#include <gene.h>

const gene* generate_gene(const gene* _father, const gene* _mother){
	
	allele dad, mom;
	gene* g = malloc(sizeof(gene));
	int r = rand()%4;
	
	dad = get_expr_gene(_father);
	mom = get_expr_gene(_mother);

	allele mix[4][2] = {{_father->g1, _mother->g1}, {_father->g1, _mother->g2}, {_father->g2, _mother->g1}, {_father->g2, _mother->g2}};

	g->g1 = mix[r][0];
	g->g2 = mix[r][1];
	g->recessive = _father->recessive;
	g->ygene = _father->ygene;

	
	g->generation = 0;

	if((dad == g->recessive && mom != g->recessive) || (mom == g->recessive && dad != g->recessive))
		g->generation = 1;
	else
		g->generation = _father->generation + 1;

	return g;
}

char generate_sex(){

	const char* sex = "FM";
	return sex[rand()%2]; 
}

int generate_lifeexp(){
	
	int proba[] = { 
		#include "proba.txt" 
	};
	return proba[rand()%(sizeof(proba) / sizeof(int))];
}

int generate_egg_number(){
	
	int proba[] = { 
		#include "eggs.txt" 
	};
	return proba[rand()%(sizeof(proba) / sizeof(int))];
}

int generate_gestation_time(){
	
	int proba[] = { 
		#include "gestation.txt" 
	};
	return proba[rand()%(sizeof(proba) / sizeof(int))];
}

int generate_adult_age(){
	
	int proba[] = { 
		#include "adult.txt" 
	};
	return proba[rand()%(sizeof(proba) / sizeof(int))];
}

int generate_pause(){

	int proba[] = { 
		#include "pause.txt" 
	};
	return proba[rand()%(sizeof(proba) / sizeof(int))];
}

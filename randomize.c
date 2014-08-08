#include <stdlib.h>
#include <time.h>
#include <randomize.h>

const genome* generate_genome(const genome* _father, const genome* _mother){
	
	genome* gens = malloc(sizeof(genome));
	int r = rand()%4;
	
	char mix[4][2] = {{_father->g1, _mother->g1}, {_father->g1, _mother->g2}, {_father->g2, _mother->g1}, {_father->g2, _mother->g2}};

	gens->g1 = mix[r][0];
	gens->g2 = mix[r][1];
	gens->recessive = _father->recessive;

	return gens;
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

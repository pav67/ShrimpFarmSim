#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <crecre.h>
#include <list.h>
#include <randomize.h>
#include <genome.h>

crecre* create_crecre(int _adultage, int _lifeexp, char _sex){

	crecre *ncre = malloc(sizeof(crecre));
	ncre->age = 0;
	ncre->breeding = 0;
	ncre->pause = 0;
	ncre->eggs = 0;
	ncre->adultage = _adultage;
	ncre->lifeexp = _lifeexp;
	ncre->sex = _sex;
	ncre->lgenes = init_list();

	return ncre;
}

crecre* breed(const crecre *_father, const crecre *_mother){

	crecre *ncre = create_crecre(generate_adult_age(), generate_lifeexp(), generate_sex());
	node *n1 = _father->lgenes->head, *n2 = _mother->lgenes->head;
	genome *ngen;
	
	while(n1 && n2){	
		ngen = generate_genome((const genome*)n1->data, (const genome*)n2->data);
		add_list(ncre->lgenes, ngen, delete_genome, print_genome);

		n1 = n1->next;
		n2 = n2->next;
	}

	return ncre;
}

void delete_crecre(void *_cre){

	crecre *cre = (crecre*)_cre;
	delete_list(cre->lgenes);
	if(cre) free(cre);
	cre = NULL;
}

void print_crecre(void *_cre){
	
	crecre *cre = (crecre*)_cre;
	printf("[ genome : ");
	print_list(cre->lgenes);
	printf(" - sex : %c -  age : %d - lifeexp : %d ]\n", cre->sex, cre->age, cre->lifeexp);
}

void reap(list *_ll, node *_n){
	
	if(!_n) return;
	if(!_n->data) return;

	crecre* cre = (crecre*)_n->data;
	cre->age++;

	if(cre->age > cre->lifeexp){
		delete_node(_ll, _n);
	}
}

void repro(list *_ll, node *_n){

	crecre *cre = (crecre*)_n->data;
	crecre *bae;
	int i, eggs;
	
	// If it's a male, skip
	if(cre->sex == 'M') return;
	// If it's not an adult, skip
	if(cre->age < cre->adultage) return;
	// If in pause process, skip
	if(cre->pause > 0) { cre->pause--; return; }
	// If no breeding in progress, start one, and skip
	if(cre->breeding == 0) { cre->breeding = generate_gestation_time(); return; }

	cre->breeding--;

	// If breeding in progress, not near to an end, skip
	if(cre->breeding > 1) return;
	
	cre->breeding = 0;

	// Getting shrimp a boyfriend
	if(bae = get_male(_ll)){
		// Getting number of eggs carried
		eggs = generate_egg_number();
		// Creating a new shrimp for each of those eggs
		for(i = 0; i < eggs; i++)
			add_list(_ll, breed(bae, cre), delete_crecre, print_crecre);

		// Letting our friend rest
		cre->pause = generate_pause();
	}
}

crecre* get_male(list *_ll){
	node *n;
	crecre *cre, *res;
	crecre **tcre = NULL;
	int i = 0;
	
	res = NULL;

	for(n = _ll->head; n; n = n->next){
	
		cre = (crecre*)n->data;
		if(cre->sex == 'M' && cre->age >= cre->adultage){
			i++;
			tcre = (crecre**)realloc(tcre, i * sizeof(crecre*));
			tcre[i-1] = cre;
			res = cre;
		}
	}

	if(tcre){
		res = tcre[rand()%(i+1)];
		free(tcre);
	}

	return res;	
}

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
	ncre->lgens = init_list();

	return ncre;
}

crecre* breed(const crecre *_father, const crecre *_mother){

	crecre *ncre = create_crecre(generate_adult_age(), generate_lifeexp(), generate_sex());
	node *n1 = _father->lgens->head, *n2 = _mother->lgens->head;
	genome* ngen;
	
	while(n1 && n2){	
		ngen = generate_genome((const genome*)n1->data, (const genome*)n2->data);
		add_list(ncre->lgens, ngen, delete_genome, print_genome);

		n1 = n1->next;
		n2 = n2->next;
	}

	return ncre;
}

void delete_crecre(crecre *_cre){

	delete_list(_cre->lgens);
	free(_cre);
}

void print_crecre(const crecre *_cre){
	printf("[ genome : ");
	print_list(_cre->lgens);
	printf(" - sex : %c -  age : %d - lifeexp : %d ]\n", _cre->sex, _cre->age, _cre->lifeexp);
}

void reap(list *_ll, node *_n){

	crecre* cre = (crecre*)_n->data;
	cre->age++;
	if(cre->age > cre->lifeexp)
		delete_node(_ll, _n);
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
	// If no breeding in progress, skip
	if(cre->breeding == 0) return;

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
	
	res = NULL;

	for(n = _ll->head; n; n->next){
	
		cre = (crecre*)n->data;
		if(cre->sex == 'M' && cre->age >= cre->adultage){
			res = cre;
			break;
		}
	}
	return res;
}

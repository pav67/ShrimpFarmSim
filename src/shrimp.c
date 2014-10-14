#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <shrimp.h>
#include <list.h>
#include <randomize.h>
#include <gene.h>

shrimp* create_shrimp(int _adultage, int _lifeexp, allele _sex){

	shrimp *shrp = malloc(sizeof(shrimp));
	shrp->age = 0;
	shrp->breeding = 0;
	shrp->pause = 0;
	shrp->eggs = 0;
	shrp->adultage = _adultage;
	shrp->lifeexp = _lifeexp;
	shrp->sex = _sex;
	shrp->lgenes = init_list();

	return shrp;
}

shrimp* breed(shrimp *_father, shrimp *_mother){

	shrimp *shrp = create_shrimp(generate_adult_age(), generate_lifeexp(), generate_sex());
	node *n = _father->lgenes->head;
	gene *ngen, *ma;
	
	while(n){
		
		ma = get_gene(_mother->lgenes, ((gene*)n->data)->ygene);
		if(!ma) continue;

		ngen = generate_gene((gene*)n->data, ma);
		add_list(shrp->lgenes, ngen, delete_gene, print_gene);

		n = n->next;
	}

	return shrp;
}

void delete_shrimp(void *_shrp){

	shrimp *shrp = (shrimp*)_shrp;
	delete_list(shrp->lgenes);
	free(shrp);
}

void print_shrimp(void *_shrp){
	
	shrimp *shrp = (shrimp*)_shrp;
	printf("[ genome : ");
	print_list(shrp->lgenes);
	printf(" - sex : %d -  age : %d - lifeexp : %d ]\n", shrp->sex, shrp->age, shrp->lifeexp);
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <crecre.h>
#include <list.h>
#include <randomize.h>
#include <genome.h>

crecre* create_crecre(int _lifeexp, char _sex){

	crecre *ncre = malloc(sizeof(crecre));
	ncre->age = 0;
	ncre->lifeexp = _lifeexp;
	ncre->sex = _sex;
	ncre->lgens = init_list();

	return ncre;
}

crecre* breed(const crecre *_father, const crecre *_mother){

	crecre *ncre = create_crecre(generate_lifeexp(), generate_sex());
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
	browse_list(_cre->lgens, print_genome);
	printf(" - sex : %c -  age : %d - lifeexp : %d ]\n", _cre->sex, _cre->age, _cre->lifeexp);
}

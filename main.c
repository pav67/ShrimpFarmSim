#include <stdio.h>
#include <stdlib.h>
#include <list.h>
#include <crecre.h>
#include <randomize.h>

int main(int argc, char** argv){

	srand(time(NULL));

	genome* fg1 = create_genome('T', 'T', 'T');
	genome* fg2 = create_genome('B', 'R', 'R');
	genome* mg1 = create_genome('T', 'B', 'T');
	genome* mg2 = create_genome('R', 'R', 'R');
	crecre* fc = create_crecre(600, 'F');
	crecre* mc = create_crecre(650, 'M');

	int i;
	
	add_list(fc->lgens, fg1, delete_genome, print_genome);
	add_list(fc->lgens, fg2, delete_genome, print_genome);
	add_list(mc->lgens, mg1, delete_genome, print_genome);
	add_list(mc->lgens, mg2, delete_genome, print_genome);

	printf("---- male ----\n");
	print_crecre(fc);
	printf("---- female ----\n");
	print_crecre(mc);

	for(i = 0; i < 10; i++){
		crecre *ncre = breed(fc, mc);
		printf("---- baby shrimp ----\n");
		print_crecre(ncre);
		delete_crecre(ncre);
	}

	delete_crecre(fc);
	delete_crecre(mc);

	return EXIT_SUCCESS;
}

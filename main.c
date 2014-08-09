#include <stdio.h>
#include <stdlib.h>
#include <list.h>
#include <crecre.h>
#include <randomize.h>

int main(int argc, char** argv){

	srand(time(NULL));

	list *aqua = init_list();

	genome* fg1 = create_genome('T', 'T', 'T');
	genome* fg2 = create_genome('B', 'R', 'R');
	genome* mg1 = create_genome('T', 'B', 'T');
	genome* mg2 = create_genome('R', 'R', 'R');
	crecre* fc = create_crecre(180, 600, 'F');
	crecre* mc = create_crecre(200, 650, 'M');

	int i;

	mc->age = 510;
	fc->age = 280;
	
	add_list(fc->lgens, fg1, delete_genome, print_genome);
	add_list(fc->lgens, fg2, delete_genome, print_genome);
	add_list(mc->lgens, mg1, delete_genome, print_genome);
	add_list(mc->lgens, mg2, delete_genome, print_genome);

	add_list(aqua, fc, delete_crecre, print_crecre);
	add_list(aqua, mc, delete_crecre, print_crecre);

	printf("avant");
	print_list(aqua);

	for(i = 0; i<100; i++){
	
		process_list(aqua, reap);
		process_list(aqua, repro);
	}

	printf("apres");
	print_list(aqua);

	delete_list(aqua);

	return EXIT_SUCCESS;
}

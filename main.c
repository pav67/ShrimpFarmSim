#include <stdio.h>
#include <stdlib.h>
#include <list.h>
#include <crecre.h>
#include <randomize.h>
#include <aqua.h>

int main(int argc, char** argv){

	srand(time(NULL));

	aqua* aq = init_aqua();
	
	genome* fg1 = create_genome('T', 'T', 'T', 0);
	genome* fg2 = create_genome('B', 'R', 'R', 1);
	genome* mg1 = create_genome('T', 'B', 'T', 1);
	genome* mg2 = create_genome('R', 'R', 'R', 0);
	crecre* fc = create_crecre(180, 600, 'F');
	crecre* mc = create_crecre(200, 600, 'M');

	int i;

	mc->age = 200;
	fc->age = 210;
	
	add_list(fc->lgens, fg1, delete_genome, print_genome);
	add_list(fc->lgens, fg2, delete_genome, print_genome);
	add_list(mc->lgens, mg1, delete_genome, print_genome);
	add_list(mc->lgens, mg2, delete_genome, print_genome);

	add_list(aq->twb_tank, fc, delete_crecre, print_crecre);
	add_list(aq->twb_tank, mc, delete_crecre, print_crecre);
	
	print_list(aq->twb_tank);

	for(i = 0; i < 100; i++){
		process_reap(aq);
		process_repro(aq);
	}

	for(i = 0; i < 100; i++){

		process_reap(aq);
		process_repro(aq);
		process_selection(aq);
	}

	printf("twb\n");
	print_list(aq->twb_tank);
	printf("f1\n");
	print_list(aq->f1_tank);
	printf("trash\n");
	print_list(aq->trash_tank);
	
	delete_aqua(aq);
	
	return EXIT_SUCCESS;
}

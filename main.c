#include <stdio.h>
#include <stdlib.h>
#include <list.h>
#include <crecre.h>
#include <randomize.h>
#include <farm.h>
#include <gene.h>

int main(int argc, char** argv){

	srand(time(NULL));

	farm* f = init_farm();
	
	gene* fg1 = create_gene(TWB, TWB, TWB, YBEE, 0);
	gene* fg2 = create_gene(BLACK, RED, RED ,COLOR, 1);
	gene* mg1 = create_gene(TWB, BEE, TWB, YBEE, 1);
	gene* mg2 = create_gene(RED, RED, RED, COLOR, 0);
	crecre* fc = create_crecre(180, 600, 'F');
	crecre* mc = create_crecre(200, 600, 'M');

	int i;

	mc->age = 200;
	fc->age = 210;
	
	add_list(fc->lgenes, fg1, delete_gene, print_gene);
	add_list(fc->lgenes, fg2, delete_gene, print_gene);
	add_list(mc->lgenes, mg1, delete_gene, print_gene);
	add_list(mc->lgenes, mg2, delete_gene, print_gene);

	add_list(f->twb_tank->lshrimps, fc, delete_crecre, print_crecre);
	add_list(f->twb_tank->lshrimps, mc, delete_crecre, print_crecre);

	for(i = 0; i < 90; i++){
		process_reap(f);
		process_repro(f);
	}

	for(i = 0; i < 270; i++){

		process_reap(f);
		process_repro(f);
		process_selection(f);
	}

	process_stats(f);

	delete_farm(f);
	
	return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include <list.h>
#include <shrimp.h>
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
	shrimp* fs = create_shrimp(180, 600, FEMALE);
	shrimp* ms = create_shrimp(200, 600, MALE);

	int i;

	ms->age = 200;
	fs->age = 210;
	
	add_list(fs->lgenes, fg1, delete_gene, print_gene);
	add_list(fs->lgenes, fg2, delete_gene, print_gene);
	add_list(ms->lgenes, mg1, delete_gene, print_gene);
	add_list(ms->lgenes, mg2, delete_gene, print_gene);

	add_list(f->twb_tank->lshrimps, fs, delete_shrimp, print_shrimp);
	add_list(f->twb_tank->lshrimps, ms, delete_shrimp, print_shrimp);

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

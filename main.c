#include <stdio.h>
#include <stdlib.h>
#include <list.h>
#include <crecre.h>
#include <randomize.h>

int main(int argc, char** argv){

	/*list *ll = init_list();
	node *n1 = add_list(ll, (void*) "hello1");
	node *n2 = add_list(ll, (void*) "hello2");
	node *n3 = add_list(ll, (void*) "hello3");
	node *n4 = add_list(ll, (void*) "hello4");
	browse_list(ll, (*print_node));
	delete_node(ll, n4);
	browse_list(ll, (*print_node));
	delete_list(ll);
	browse_list(ll, (*print_node));*/

	/*node* n;

	crecre *cre1 = create_crecre("FTTRR");
	crecre *cre2 = create_crecre("MTTBB");
	crecre *cre3 = create_crecre("FTTBR");
	crecre *cre4 = create_crecre("MTTRB");
	crecre *cre5 = create_crecre("MTTRR");

	list *ll = init_list();
	add_list(ll, cre1, delete_crecre, print_crecre);
	add_list(ll, cre2, delete_crecre, print_crecre);
	add_list(ll, cre3, delete_crecre, print_crecre);
	add_list(ll, cre4, delete_crecre, print_crecre);
	add_list(ll, cre5, delete_crecre, print_crecre);

	//browse_list(ll, print_crecre);
	for(n=ll->head;n;n=n->next)
		n->print_callback(n->data);
	
	delete_list(ll);*/
	
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

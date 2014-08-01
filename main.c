#include <stdio.h>
#include <stdlib.h>
#include <list.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	char** t1 = "t1";
	char** t2 = "t2";
	char** t3 = "t3";
	char** t4 = "t4";
	int i = 0;
	
	list l = initList();
	node* tmp = l;
	
	add(l,t1);
	add(l,t2);
	add(l,t3);
	add(l,t4);
	
	while(tmp != NULL){
		printf("liste(%i) : %s\n", i, (char**)tmp->pData);
		tmp = tmp->pNext;
		i++;
	}
	
	freeList(l);
	
	return 0;
}

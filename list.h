#ifndef __list_h_
#define __list_h_

typedef struct node node;
struct node{
	node* pNext;
	void* pData;
};

typedef node* list;

list initList();
void add(list l, void* data);
void freeList(list l);

#endif

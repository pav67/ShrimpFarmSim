#include <list.h>
#include <stddef.h>

list initList(){
	
	node* pFirstNode = malloc(sizeof(node));
	pFirstNode->pNext = NULL;
	pFirstNode->pData = NULL;
	
	return pFirstNode;
}


void add(list _l, void* _data){
	
	node* pNewNode = malloc(sizeof(node));
	node* pTmp = _l;
		
	pNewNode->pNext = NULL;
	pNewNode->pData = _data;
	
	while(pTmp->pNext != NULL) pTmp = pTmp->pNext;

	pTmp->pNext = pNewNode;
}


void freeList(list _l){
	
	node* pTmp1 = _l;
	node* pTmp2 = _l;
	
	while(pTmp1 != NULL){
		pTmp2 = pTmp1;
		pTmp1 = pTmp1->pNext;
		free(pTmp2);
	}
}

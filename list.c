#include <stdlib.h>
#include <stdio.h>
#include <list.h>
#include <crecre.h>

list* init_list(){
	
	list *ll = malloc(sizeof(list));
	ll->head = NULL;

	return ll;
}

node* add_list(list *_ll, void *_data, void (*_delete_callback)(void*), void (*_print_callback)(void*)){
	
	node *n   = malloc(sizeof(node));
	n->next   = _ll->head;

	if(_ll->head) _ll->head->prev = n;

	n->prev   = NULL;
	n->data   = _data;
	n->delete_callback = _delete_callback;
	n->print_callback = _print_callback;
	_ll->head = n;

	return n;
}

void delete_list(list *_ll){
	
	node *n1 = _ll->head;
	node *n2;

	while(n1){

		n2 = n1->next;
		n1->delete_callback(n1->data);
		free(n1);	
		n1 = n2;
	}

	free(_ll);
}

void delete_node(list *_ll, node *_n){

	if(!_n) return;

	if(_n->next){
		if(_n->prev) {
			_n->prev->next = _n->next;
			_n->next->prev = _n->prev;
		}
		else{
			_ll->head = _n->next;
			_n->next->prev = NULL;
		}
	}else{
		if(_n->prev) _n->prev->next = NULL;
		else _ll->head = NULL;
	}

	_n->delete_callback(_n->data);
	free(_n);
}

void print_list(const list *_ll){
	
	node *n;
	for(n = _ll->head; n; n = n->next)
		n->print_callback(n->data);
}

void browse_list(list* _ll, void (*_callback)(void*)){
	node *n;
	for(n = _ll->head; n; n = n->next)
		(*_callback)(n->data);
}

void process_list(list* _ll, void(*_callback)(list*, node*)){

	node *n;
	for(n = _ll->head; n; n = n->next)
		(*_callback)(_ll, n);
}

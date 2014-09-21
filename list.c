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

void unlink_node(list *_ll, node *_n){
	if(_n->prev)
                _n->prev->next = _n->next;
        else
                _ll->head = _n->next;

        if(_n->next)
                _n->next->prev = _n->prev;
	else
		if(_n->prev)
			_n->prev->next = NULL;
	
}


void delete_list(list *_ll){
	
	node *n1 = _ll->head;
	node *n2;

	while(n1){

		n2 = n1->next;
		n1->delete_callback(n1->data);
		if(n1) free(n1);	
		n1 = n2;
	}

	if(_ll) free(_ll);
	_ll = NULL;
}

void delete_node(list *_ll, node *_n){
	
	unlink_node(_ll, _n);

	_n->delete_callback(_n->data);
        if(_n) free(_n);
	_n = NULL;
}

void print_list(const list *_ll){
	
	node *n;
	if(_ll)
	for(n = _ll->head; n; n = n->next)
		n->print_callback(n->data);
}

void browse_list(list *_ll, void (*_callback)(void*)){
	node *n;
	for(n = _ll->head; n; n = n->next)
		(*_callback)(n->data);
}

void process_list(list *_ll, void(*_callback)(list*, node*)){

	node *n, *tmp;
	n = _ll->head;
	while(n){
		tmp = n->next;
		(*_callback)(_ll, n);
		n = tmp;
	}
}

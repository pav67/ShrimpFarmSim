#ifndef __list_h
#define __list_h

typedef struct _list {
	struct _node *head;
} list;

typedef struct _node {
	struct _node *next;
	struct _node *prev;
	void *data;
	void (*delete_callback)(void*);
	void (*print_callback)(void*);
} node;

list* init_list();
node* add_list(list*, void*, void(*delete_callback)(void*), void(*print_callback)(void*));
void unlink_node(list*,node*);
void delete_list(list*);
void delete_node(list*, node*);
void browse_list(list*, void (*callback)(void*));
void process_list(list*, void (*callback)(list*, node*));

#endif

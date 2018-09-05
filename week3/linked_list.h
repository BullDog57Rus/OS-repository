#ifndef FOROS_LIST_H
#define FOROS_LIST_H

struct LinkedList *newList();

void insert_node(struct LinkedList *list, int value);

void delete_node(struct LinkedList *list, int value);

void print_list(struct LinkedList *list);

#endif //FOROS_LIST_H

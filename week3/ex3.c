#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


int main(void) {
    struct LinkedList *list = newList();
    printf("Inserting value 1\n");
    insert_node(list, 1);
    printf("The list: ");
    print_list(list);
    printf("Inserting value 3\n");
    insert_node(list, 3);
    printf("The list: ");
    print_list(list);
    printf("Inserting value 2\n");
    insert_node(list, 2);
    printf("The list: ");
    print_list(list);
    printf("Inserting value 5\n");
    insert_node(list, 5);
    printf("The list: ");
    print_list(list);
    printf("Inserting value 9\n");
    insert_node(list, 9);
    printf("The list: ");
    print_list(list);
    printf("Deleting value 0\n");
    delete_node(list, 0);
    printf("The list: ");
    print_list(list);
    printf("Deleting value 1\n");
    delete_node(list, 1);
    printf("The list: ");
    print_list(list);
    printf("Deleting value 9\n");
    delete_node(list, 9);
    printf("The list: ");
    print_list(list);
    printf("Deleting value 2\n");
    delete_node(list, 2);
    printf("The list: ");
    print_list(list);
    printf("Deleting value 3\n");
    delete_node(list, 3);
    printf("The list: ");
    print_list(list);
    printf("Deleting value 5\n");
    delete_node(list, 5);
    printf("The list: ");
    print_list(list);
    return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
};

struct LinkedList {
    struct Node *head;
    struct Node *tail;
    int size;
};

struct Node *newNode() {
    struct Node *node = malloc(sizeof(struct Node));
    node->next = NULL;
    node->prev = NULL;
    return node;
}

struct LinkedList *newList() {
    struct LinkedList *list = malloc(sizeof(struct LinkedList));
    list->tail = NULL;
    list->head = NULL;
    list->size = 0;
    return list;
};

void insert_node(struct LinkedList *list, int value) {
    struct Node *new = newNode();
    if (list->size == 0) {
        list->head = new;
        new->value = value;
        list->tail = new;
    } else {
        list->tail->next = new;
        new->prev = list->tail;
        list->tail = new;
        new->value = value;
    }
    list->size++;
};

void delete_node(struct LinkedList *list, int value) {
    struct Node *ptr = list->head;
    while (ptr != NULL && ptr->value != value) {
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        return;
    }
    if (ptr == list->head && ptr == list->tail) {
        list->head = NULL;
        list->tail = NULL;
    } else if (ptr == list->head) {
        list->head = ptr->next;
        ptr->next->prev = NULL;
    } else if (ptr == list->tail) {
        list->tail = ptr->prev;
        ptr->prev->next = NULL;
    } else {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
    }
    free(ptr);
    list->size--;
}

void print_list(struct LinkedList *list) {
    struct Node *ptr = list->head;
    if (ptr == NULL) {
        printf("Empty");
    }
    while (ptr != NULL) {
        printf("%d ", ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}
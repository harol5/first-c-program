#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string.h>

struct Node
{
     void *data;
     struct Node *next;     
};

struct LinkedList 
{
     size_t data_size;
     struct Node *head;
     int length;
};

struct LinkedList *createLinkedList(size_t data_size)
{
     struct LinkedList *p_linkedList = malloc(sizeof(struct LinkedList));          
     p_linkedList->data_size = data_size;
     p_linkedList->head = NULL;
     p_linkedList->length = 0;
     return p_linkedList;
};

void addAtLast(struct LinkedList *linkedList, void *data)
{     
     // allocates space on the heap and initialize members.
     struct Node *newNode = malloc(sizeof(struct Node));
     newNode->data = malloc(linkedList->data_size);
     newNode->next = NULL;

     // Copy contents of data to newly allocated memory for node data.
     memcpy(newNode->data, data, linkedList->data_size);

     if(!linkedList->head) {          
          linkedList->head = newNode;
          linkedList->length++;
          return;
     }
     
     struct Node *crrNode = linkedList->head;
     while (crrNode->next) {
          crrNode = crrNode->next;
     }

     crrNode->next = newNode;
     linkedList->length++;
};

void addAtHead(struct LinkedList *linkedList, void *data)
{
     // allocates space on the heap and initialize members.
     struct Node *newNode = malloc(sizeof(struct Node));
     newNode->data = malloc(linkedList->data_size);

     // Copy contents of data to newly allocated memory for node data.
     memcpy(newNode->data, data, linkedList->data_size);

     struct Node *crrHead = linkedList->head;
     newNode->next = crrHead;
     linkedList->head = newNode;
     linkedList->length++;
}


// this function allows to pass a func pointer to print the desire data type properly.
void printLinkedList(struct LinkedList *linkedList, void(*printer)(void *))
{     
     if (linkedList->length == 0) {
          printf("your linkedlist is empty\n");
          return;
     }

     struct Node *node = linkedList->head;

     while (node) {                    
          (*printer)(node->data);
          node = node->next;          
     }     
}

// default int linked list printer.
void printIntLinkedList(void *data)
{
     printf("=== Node ===\n");
     printf("data: %d\n", *((int*)data));
}
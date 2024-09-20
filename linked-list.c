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



int addAtLast(struct LinkedList *linkedList, void *data)
{     
     if(!linkedList) return 0;

     // allocates space on the heap and initialize members.
     struct Node *newNode = malloc(sizeof(struct Node));     
     newNode->data = malloc(linkedList->data_size);
     newNode->next = NULL;     

     // Copy contents of data to newly allocated memory for node data.
     memcpy(newNode->data, data, linkedList->data_size);

     if(!linkedList->head) 
     {          
          linkedList->head = newNode;
          linkedList->length++;          
          return 0;
     }
     
     struct Node *crrNode = linkedList->head;
     while (crrNode->next) 
     {
          crrNode = crrNode->next;
     }

     crrNode->next = newNode;
     linkedList->length++;    
     return 1; 
};

int addAtHead(struct LinkedList *linkedList, void *data)
{
     if(!linkedList) return 0;

     // allocates space on the heap and initialize members.
     struct Node *newNode = malloc(sizeof(struct Node));
     newNode->data = malloc(linkedList->data_size);

     // Copy contents of data to newly allocated memory for node data.
     memcpy(newNode->data, data, linkedList->data_size);

     struct Node *crrHead = linkedList->head;
     newNode->next = crrHead;
     linkedList->head = newNode;
     linkedList->length++;

     return 1;
}


/**
 * Adds node at a giving position. if position is greater than
 * the length of the linked list or position <= 0, the node will be attached
 * to the end of the linked list.
 */
int addAt(int position, void *data, struct LinkedList *linkedList)
{
     if(!linkedList) return 0;

     if (position > linkedList->length || position <= 0) 
     {          
          return addAtLast(linkedList,data);
     }

     if(position == 1)
     {          
          return addAtHead(linkedList, data);
     }

     struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
     newNode->data = malloc(linkedList->data_size);
     memcpy(newNode->data, data, linkedList->data_size);     

     int crrPosition = 1;
     struct Node *crrNode = linkedList->head;
     while(position - 1 != crrPosition)
     {
          crrPosition++;
          crrNode = crrNode->next;
     }

     newNode->next = crrNode->next;
     crrNode->next = newNode;
     linkedList->length++;     

     return 1;
}

int removeAt(int position ,struct LinkedList *linkedList)
{
     if(!linkedList) return 0;

     //I must validate the position value.
     // position cannot be 0 or less. (position < 1).
     // position cannot be greater than the length of the linked List. (position > linkedList->length)
     // returns if any of the conditions above are true.
     if( position < 1 || position > linkedList->length|| linkedList->length == 0) return 0;      

     // head node.
     if( position == 1 )
     {
          struct Node *crrHead = linkedList->head;
          linkedList->head = crrHead->next;
          linkedList->length--;     
          free(crrHead->data);
          free(crrHead);
          return 1;
     }    

     int crrPosition = 1;
     struct Node *crrNode = linkedList->head;
     struct Node *prevNode;
     while(crrPosition != position)
     {          
          if(crrPosition == position - 1) prevNode = crrNode;          
          crrPosition++;
          crrNode = crrNode->next;          
     }

     prevNode->next = crrNode->next;
     linkedList->length--;     
     free(crrNode->data);
     free(crrNode);
     return 1;
}

void freeNode(struct Node *node)
{
     if(node->next) freeNode(node->next);
     free(node->data);
     free(node);
}

int emptyLinkedList(struct LinkedList *linkedList)
{
     if(!linkedList) return 0;     
     if (!linkedList->head) return 0;
     freeNode(linkedList->head);    
     linkedList->length = 0; 
     linkedList->head = NULL;
     return 1;
}

/**
 * takes a pointer to a struct LinkedList pointer (struct LinkedList **linkedList)
 * and free memory used by the linked list struct(pointer to struct) and sets the
 * pointer variable used to store the linked list address(pointer to struct -
 * LinkedList pointer) to NULL which helps to avoid Dangling Pointers.
 */
int deleteLinkedList(struct LinkedList **linkedList)
{
     if (!*linkedList) return 0;
     printf("this !*linkedList returns: false\n");
     if ((*linkedList)->head) {
          printf("this (*linkedList)->head returns: true\n");
          freeNode((*linkedList)->head);
     }     
     free(*linkedList);
     *linkedList = NULL;
     return 1;
}




// this function allows to pass a func pointer to print the desire data type properly.
int printLinkedList(struct LinkedList *linkedList, void(*printer)(void *))
{               
     if(!linkedList) return 0;

     if ((linkedList)->length == 0) {
          printf("your linkedlist is empty\n");
          return 0;
     }

     struct Node *node = (linkedList)->head;

     while (node) {                    
          (*printer)(node->data);
          node = node->next;          
     }     

     return 1;
}

// default int linked list printer.
void printIntLinkedList(void *data)
{     
     printf("=== Node ===\n");
     printf("data: %d\n", *((int*)data));
}

// default int linked list printer.
void printCharLinkedList(void *data)
{     
     printf("=== Node ===\n");
     printf("data: %c\n", *((char*)data));
}
#include<stdlib.h>
#include<stdio.h>
#include"linkedlist.h"

/*
 * Creates a LinkedListNode by malloc'ing the space.
 * INPUT: the data of node as an integer
 * Returns a pointer to the new node.
 */
Node* CreateNode(int x) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = x;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

/*
 * Creates a DoublyLinkedList.
 * Customer is responsible for calling DestroyLinkedList() to destroy the LinkedList when done.
 * Returns an empty LinkedList.
 */
LinkedListPtr CreateDoublyLinkedList(){
  LinkedListPtr list = (LinkedListPtr)malloc(sizeof(struct DoublyLinkedList));
  list->head = NULL;
  list->tail = NULL;
  list->num_elements = 0;
  return list;
}


/*
 * Destroys and free's a provided node.
 * INPUT: A pointer to the node to destroy.
 */
void DestroyNode(Node* node){
  free(node);
}


/*
 * Destroys a LinkedList.
 * All structs associated with a DoublyLinkedList will be released and freed.
 * INPUT: A DoublyLinkedList pointer.
 */
void DestroyLinkedList(LinkedListPtr list){
  Node* temp = list->head;
  while (temp != NULL){
    RemoveNode(list, temp);
    temp = temp->next;   // traverse linked list and free every node
  }
  free(list);            // free linked list
}


/*
 * Gets the number of elements in the doubly linked list.
 * INPUT: A DoublyLinkedList pointer.
 * Returns the number of elements in the list.
 */
int NumElementsInLinkedList(LinkedListPtr list){
  return list->num_elements;
}


/*
 * Adds an element to the head of a LinkedList with the given value x.
 * INPUT: A pointer to the DoublyLinkedList.
 * INPUT: The value of new node as an integer.
 */
void InsertLinkedList(LinkedListPtr list, int x){
  if (list == NULL){
    return;
  }
  Node* newNode = CreateNode(x);
  if (list->head == NULL){      // if list is empty
      list->head = newNode;     // update head
      list->tail = newNode;     // update tail
      list->num_elements += 1;  // update num of elements
      return;
  }
  list->head->prev = newNode;
  newNode->next = list->head;
  newNode->prev = NULL;
  list->head = newNode;       // update head
  list->num_elements += 1;    // update num of elements
  return;
}


/*
 * Adds an element to the tail of a LinkedList with the given value x.
 * INPUT: A pointer to the DoublyLinkedList.
 * INPUT: The value of new node as an integer.
 */
void AppendLinkedList(LinkedListPtr list, int x){
  if (list == NULL){
    return;
  }
  Node* newNode = CreateNode(x);
  Node* temp = list->head;
  if (list->head == NULL){      // if list is empty
      list->head = newNode;     // update head
      list->tail = newNode;     // update tail
      list->num_elements += 1;  // update num of elements
      return;
  }
  while (temp->next != NULL){
    temp = temp->next;       // go to last node
  }
  temp->next = newNode;
  newNode->prev = temp;
  newNode->next = NULL;
  list->tail = newNode;      // update tail
  list->num_elements += 1;   // update num of elements
  return;
}


/*
 * Removes an element from a given DoublyLinkedList.
 * INPUT: A pointer to the DoublyLinkedList.
 * INPUT: A pointer to the Node that will be removed from the list.
 */
void RemoveNode(LinkedListPtr list, Node* node){
  if(list->head == NULL || node == NULL){
    return;
  }
  if(list->head == node){       // if node to be deleted is the head node
    list->head = node->next;    // update head
  }
  if(node->next != NULL){       // Change next if node to be deleted is not tail
    node->next->prev = node->prev;
  }
  if(list->tail == node){       // if node to be deleted is the tail node
    list->tail = node->prev;    // update tail
  }
  if(node->prev != NULL){       // Change prev if node to be deleted is not head
    node->prev->next = node->next;
  }
  list->num_elements -= 1;
  free(node);                   // free removed node
  return;
}


/*
 * Prints out a DoublyLinkedList.
 * INPUT: A pointer to the DoublyLinkedList.
 */
void PrintLinkedList(LinkedListPtr list){
  Node* temp = list->head;
  while(temp != NULL){
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

/*
 * Converts an array to a DoublyLinkedList.
 * INPUT: An integer array.
 * INPUT: An integer n that specifies the length of array.
 * Returns a DoublyLinkedList pointer.
 */
LinkedListPtr arrayToLinkedList(int arr[], int n){
  LinkedListPtr list = CreateDoublyLinkedList();
  int i;
  for (i = 0; i < n; i++){
    AppendLinkedList(list, arr[i]);
  }
  return list;
}

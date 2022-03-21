#include<stdlib.h>
#include<stdio.h>
#include"linkedlist.h"

LinkedListPtr CreateDoublyLinkedList();
void AppendLinkedList(LinkedListPtr, int);
void InsertLinkedList(LinkedListPtr, int);
void PrintLinkedList(LinkedListPtr);
void RemoveNode(LinkedListPtr, Node*);
int NumElementsInLinkedList(LinkedListPtr);
void DestroyLinkedList(LinkedListPtr);


int main(){
  LinkedListPtr list = CreateDoublyLinkedList();
  printf("Function tests: \n");
  AppendLinkedList(list, 2);      // 2
  printf("Append 2 to linked list: \n");
  PrintLinkedList(list);

  AppendLinkedList(list, 4);      // 2->4
  printf("Append 4 to linked list: \n");
  PrintLinkedList(list);

  InsertLinkedList(list, 6);      // 6->2->4
  printf("Insert 6 to linked list: \n");
  PrintLinkedList(list);

  InsertLinkedList(list, 8);      // 8->6->2->4
  printf("Insert 8 to linked list: \n");
  PrintLinkedList(list);

  Node* rmv = list->tail->prev;  // remove the second last node
  RemoveNode(list, rmv);
  int num = NumElementsInLinkedList(list);
  printf("Remove second last node: \n");
  PrintLinkedList(list);         // 8->6->4
  printf("The number of elements in linked list is: \n");
  printf("%d\n", num);

  DestroyLinkedList(list);       // destroy doubly linked list
  printf("Tests end.\n");
}

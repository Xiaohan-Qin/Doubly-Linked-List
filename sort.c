#include <stdio.h>
#include<stdlib.h>
#include"linkedlist.h"
#include"sort.h"

/*
 * Swaps the data between two LLNode without changing their relevant positions.
 * INPUT: A pointer to the first node.
 * INPUT: A pointer to the second node.
 * */
void SwapData (Node* first, Node* second){
  int value = first->data;
  first->data = second->data;
  second->data = value;
}

/*
 * Sorts a LinkedList using insertion sort.
 * INPUT: A pointer to a DoublyLinkedList.
 * */
void InsertionSort(LinkedListPtr list){
    Node* front = list->head;      // used to iterate the liked list
    Node* back = NULL;             // used to place each node at the correct position, swap if necessary
    while(front!=NULL){
      back = front->next;
      while (back!=NULL && back->prev != NULL && back->data < back->prev->data){
        SwapData(back, back->prev);
        back = back->prev;
      }
      front = front->next;
    }
}

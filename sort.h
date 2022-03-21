#include "linkedlist.h"
#ifndef SORT_H
#define SORT_H

/*
 * Swaps the data between two LLNode without changing their relevant positions.
 * INPUT: A pointer to the first node.
 * INPUT: A pointer to the second node.
 * */
void SwapData (Node* first, Node* second);

/*
 * Sorts a LinkedList using insertion sort.
 * INPUT: A pointer to a DoublyLinkedList.
 * */
void InsertionSort(LinkedListPtr list);

#endif

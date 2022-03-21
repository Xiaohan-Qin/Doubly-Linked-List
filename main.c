#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"
#include"sort.h"

LinkedListPtr arrayToLinkedList(int arr[], int n);
void PrintLinkedList(LinkedListPtr);
void InsertionSort(LinkedListPtr);
void DestroyLinkedList(LinkedListPtr);


int main(){
  // create an array with 50 random numbers (range 1 - 100)
  int my_arr[50];
  int lower = 1, upper = 100;
  srand(0);
  int i;
  for(i = 0; i < 50; i++){
    my_arr[i] = (rand() % (upper - lower + 1)) + lower;
  }
  int n = sizeof(my_arr)/sizeof(my_arr[0]);
  // convert array to liked list
  LinkedListPtr list = arrayToLinkedList(my_arr, n);
  printf("Linked list before sorting: \n");
  PrintLinkedList(list);
  printf("Linked list after sorting: \n");
  InsertionSort(list);
  PrintLinkedList(list);
  DestroyLinkedList(list);
  return 0;
}

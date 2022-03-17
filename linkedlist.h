#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/*
 * ======================================================
 * A Doubly-Linked List
 * ======================================================
 *
 *
 * STRUCT DEFINITIONS
 *
 *
 * We have 2 structs: One is Node, and one is DoublyLinkedList,
 * which we create an alias for the pointer.
 */

/*
 * This struct represents an individual node in the doubly linked list.
 * A node has data and a next and prev pointers.
 */
typedef struct Node {
  int data;              // Data this node holds
  struct Node* next;     // next node in list, or NULL
  struct Node* prev;     // prev node in list, or NULL
} Node;

/*
 * This struct represents the entire doubly linked list. It contains metadata about the list.
 * A doubly linked list has number of elements and a head and tial pointers.
 */
typedef struct DoublyLinkedList {
  int num_elements;       //  # elements in the list
  Node* head;             // head of linked list, or NULL if empty
  Node* tail;             // tail of linked list, or NULL if empty
} *LinkedListPtr;


/*
 * Creates a LinkedListNode by malloc'ing the space.
 * INPUT: the data of node as an integer
 * Returns a pointer to the new node.
 */
Node* CreateNode(int data);


/*
 * Destroys and free's a provided node.
 * INPUT: A pointer to the node to destroy.
 */
void DestroyNode(Node* node);


/*
 * Creates a DoublyLinkedList.
 * Customer is responsible for calling DestroyLinkedList() to destroy the LinkedList when done.
 * Returns an empty LinkedList.
 */
LinkedListPtr CreateDoublyLinkedList();


/*
 * Destroys a LinkedList.
 * All structs associated with a DoublyLinkedList will be released and freed.
 * INPUT: A DoublyLinkedList pointer.
 */
void DestroyLinkedList(LinkedListPtr list);


/*
 * Gets the number of elements in the doubly linked list.
 * INPUT: A DoublyLinkedList pointer.
 * Returns the number of elements in the list.
 */
int NumElementsInLinkedList(LinkedListPtr list);


/*
 * Adds an element to the head of a LinkedList with the given value x.
 * INPUT: A pointer to the DoublyLinkedList.
 * INPUT: The value of new node as an integer.
 */
void InsertLinkedList(LinkedListPtr list, int x);


/*
 * Adds an element to the tail of a LinkedList with the given value x.
 * INPUT: A pointer to the DoublyLinkedList.
 * INPUT: The value of new node as an integer.
 */
void AppendLinkedList(LinkedListPtr list, int x);


/*
 * Removes an element from a given DoublyLinkedList.
 * INPUT: A pointer to the DoublyLinkedList.
 * INPUT: A pointer to the Node that will be removed from the list.
 */
void RemoveNode(LinkedListPtr list, Node* node);


/*
 * Prints out a DoublyLinkedList.
 * INPUT: A pointer to the DoublyLinkedList.
 */
void PrintLinkedList(LinkedListPtr);


/*
 * Converts an array to a DoublyLinkedList.
 * INPUT: An integer array.
 * INPUT: An integer n that specifies the length of array.
 * Returns a DoublyLinkedList pointer.
 */
LinkedListPtr arrayToLinkedList(int arr[], int n);

#endif

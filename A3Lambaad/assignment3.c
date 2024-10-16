#include <stdio.h>
#include <stdlib.h>

/*struct to define what a node is, consists of value and pointer*/
typedef struct node {
        int num;
        struct node *next;
    }Node, *NodePtr;

/*Code to create a node of the typdef struct with the int value passed in*/
    NodePtr makeNode(int n){
        NodePtr np = (NodePtr)malloc(sizeof(Node));
        np -> num = n;
        np -> next = NULL;
        return np;
    }

/* create a new node with int value by using the makeNode() method
and make it's next pointer point to head*/
    NodePtr insertNodeAtHead(NodePtr head, int n) {
        NodePtr np = makeNode(n);
        np -> next = head;
        return np;
    }

    /*calculates the length of the list by starting at the head and
    iterating thourgh it and incrementing a counter (in this case length)*/
    int listLength(NodePtr head) {
        int length = 0;
        NodePtr current = head;
        while (current != NULL) {
            length++;
            current = current -> next;
        }
        return length;
    }

/*calculates the length of the list starting at the head and going through the
list recursively by going to where the head next pointer is pointing and repeating*/
int listLength_recursive(NodePtr head){
    if (head == NULL) {
        return 0;
    }
    return 1 + listLength_recursive(head -> next);
}

/*calculates the sum of all of the node's values by iterating through the list*/
int listSum(NodePtr head){
    int sum = 0;
    NodePtr current = head;
    while (current != NULL) {
        sum += current -> num;
        current = current -> next;
    }
    return sum;
}

/*calculates the sum of the node's values by recursion until head is NULL*/
int listSum_recursive(NodePtr head) {
    if (head == NULL) {
        return 0;
    }
    return head -> num + listSum_recursive(head -> next);
}

/*print the list of node vaules using iteration, moving the current pointer
to the current pointer's next value, printing and repeating*/
    void printList(NodePtr head) {
        NodePtr current = head;
        while (current != NULL) {
            printf("%d\n", current -> num);
            current = current -> next;
        }
    }

/*print the list of node values using recursion, print the curent value, move the
head's current value to the it's next value and repeating until null is encoutered*/
void printList_recursive(NodePtr head){
    if (head == NULL) {
        return;
    }
    printf("%d\n", head -> num);
    printList_recursive(head -> next);
}

/*print the node values in reverse order using iteration.
First, calculate the length using the listLength() method.
Then create a temporary space to hold integers, so allocate int sized values.
Assign the value of the current pointer to the value of the head pointer.
In the first loop i = 0 and will keep incrementing until the value of length is reached.
in the second loop i = length -1, and will decrementing until i is not >= 0.
First loop starts at the head and stores value in temp list, incrementing to the next value
by setting the current pointer to the next, effectively reversing the order of values.
Second loop prints the value at the current node temp[i], before it increments to the next value.
*/
void printListReverse(NodePtr head) {
    int length = listLength(head);
    int *temp = (int *)malloc(length * sizeof(int));
    NodePtr current = head;
    int i = 0;
    for (i = 0; i < length; i++){
        temp[i] = current -> num;
        current = current -> next;
    }
    for (i = length - 1; i >= 0; i--) {
        printf("%d\n", temp[i]);
    }
    free(temp);
}

/*print the node values in reverse order using recursion
Once head is equal to null, the function is complete.
print the current value and change the current head pointer to that of the current
head's next and repeat.*/
void printListReverse_recursive(NodePtr head){
    if (head == NULL){
        return;
    }
    printListReverse_recursive(head -> next);
    printf("%d\n", head -> num);
}

void freeList(NodePtr head){
    NodePtr temp;
    while (head != NULL){
    temp = head;
    head = head -> next;
    free(temp);
    }
}


int main () {

    NodePtr head = NULL;

    head = insertNodeAtHead (head, 10);
    head = insertNodeAtHead (head, 20);
    head = insertNodeAtHead (head, 30);
    head = insertNodeAtHead (head, 40);
    head = insertNodeAtHead (head, 50);

/*print the list using both methods*/
    printf("Print using iteration: \n");
    printList(head);

    printf("Print using recursion: \n");
    printList_recursive(head);

/*calculate the length of the list using both methods*/
printf("List length using iteration: %d\n", listLength(head));
printf("List length using recursion: %d\n", listLength_recursive(head));

/*calculate the sum of the node values using both methods*/
printf("list sum using iteration: %d\n", listSum(head));
printf("list sum using recursion: %d\n", listSum_recursive(head));

/*print the list in reverse order using both methods*/
printf("list in reverse order using iteration: \n");
printListReverse(head);
printf("list in reverse using recursion: \n");
printListReverse_recursive(head);

/*Free the list that was created*/
freeList(head);

    return 0;
}
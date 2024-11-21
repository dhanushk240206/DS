#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void sortList(struct Node* head) {
    if (head == NULL) return; 
    struct Node *i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
               
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}


void reverseList(struct Node** head) {
    struct Node *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL) {
        next = current->next;  
        current->next = prev;  
        prev = current;        
        current = next;
    }
    *head = prev;  
}


void concatenateLists(struct Node** head1, struct Node* head2) {
    if (*head1 == NULL) {
        *head1 = head2; 
        return;
    }
    struct Node* temp = *head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2; 

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    
    append(&list1, 3);
    append(&list1, 1);
    append(&list1, 2);

    
    append(&list2, 7);
    append(&list2, 6);
    append(&list2, 8);

    printf("List 1:\n");
    printList(list1);

    printf("List 2:\n");
    printList(list2);

   
    sortList(list1);
    printf("\nSorted List 1:\n");
    printList(list1);

    
    reverseList(&list1);
    printf("\nReversed List 1:\n");
    printList(list1);

    
    concatenateLists(&list1, list2);
    printf("\nConcatenated List 1 and List 2:\n");
    printList(list1);

    return 0;
}

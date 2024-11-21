
#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode-> data = data;
    newNode->next = NULL;
    return newNode;
}


struct Node* insert(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    }
    else{
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    }
    printf("Node %d inserted \n", data);
    
    return head;
    
}

struct Node* deletion(struct Node * head){
    struct Node* ptr;
    if (head==NULL){
        printf("Empty");
    }
    else{
        ptr=head;
        head=head->next;
        free(ptr);
    }
    printf("Node deleted.\n", head->data);
    return head;
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
    }
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
  
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\nQueue:\n");
        printf("\nMenu:\n");
        
        printf("1. insertion to queue\n");
        printf("2. Deletion to queue\n");
        printf("3. Display \n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
             printf("Enter the data to insert : ");
                scanf("%d", &data);
                head=insert(head, data);
                break;
            case 2:
               head=deletion(head);
                break;
        
            case 3:
                displayList(head);
                break;
            case 6:
              
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}




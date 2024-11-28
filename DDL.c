#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

struct node* insert_at_position(struct node* head, int data, int pos) {
    struct node* new_node = create_node(data);
    if (head == NULL || pos == 0) {
        new_node->next = head;
        if (head != NULL) {
            head->prev = new_node;
        }
        head = new_node;
    } else {
        struct node* temp = head;
        int i;
        for (i = 0; temp != NULL && i < pos - 1; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            free(new_node);
            printf("Position exceeds the length of the list.\n");
            return head;
        } else {
            new_node->next = temp->next;
            if (temp->next != NULL) {
                temp->next->prev = new_node;
            }
            temp->next = new_node;
            new_node->prev = temp;
        }
    }
    return head;
}

struct node* delete(struct node* head, int value) {
    struct node* temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }

    if (head->data == value) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return head;
    }

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found in the list.\n");
        return head;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
    return head;
}

void display(struct node* head) {
    struct node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;
    int value, pos, choice;

    while (1) {
        printf("\n*** Menu ***\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                head = insert_at_position(head, value, pos);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                head = delete(head, value);
                break;

            case 3:
                display(head);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}












// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * next;
    struct node * prev;
};

struct node * create_node (int data){
    struct node * new_node;
    new_node = (struct node *) malloc(sizeof (struct node));
    new_node -> data = data;
    new_node -> prev = NULL;
    new_node -> next = NULL;
}

struct node * insertatLeft(struct node * head, int data,int pos){
    struct node * new_node = create_node (data);
    struct node * temp = head;
    if(head == NULL){
        head = new_node;
    }
    else{
        for (int i=0; i>pos; i++){
            temp = temp->next;
        }
        new_node-> next = temp ->next;
        temp -> next = new_node;
        new_node -> prev = temp;
        new_node -> next -> prev = new_node;
    }
    return head;    
}

struct node * Delete (struct node * head, int value){
        struct node * temp = head;
        if(head == NULL){
            printf ("Empty..");
        }
        else if (head -> data == value){
            head = head->next;
            free(temp);
        }
         else if (head -> next == NULL){
             free(temp);
            head = NULL;
        }
        else{
            for (int i=0; temp->data = value; i++){
                temp=temp->next;
            }
            temp -> prev -> next = temp->next;
            temp -> next -> prev = temp->prev;
            free(temp);
        }
        return head;
}

struct node * Display (struct node * head){
    struct node * temp = head;
    while (temp != NULL){
        printf("%d->",temp -> data);
        temp = temp->next;
    }

}



int main() {
    struct node * head = NULL;
    int value, pos,choice;
    while(1){
        printf("\n***Menu***\n");
        printf("1.insert\n2.Delete\n3.Display\n4.Exist\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch (choice){
            case 1:
             printf("Enter your value:");
             scanf("%d",&value);
              printf("Enter the postion:");
             scanf("%d",&pos);
             head = insertatLeft(head,value,pos);
             break;
             
             case 2:
              printf("Enter your value to delete:");
             scanf("%d",&value);
              head = Delete(head,value);
              break;
              
              case 3:
              head = Display(head);
              break;
              
              case 4:
              exit(0);
              break;
              
              default :
              printf("Worng");
            
            
        }
    }
    
    
}











#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};


void display(struct Node *head){
    struct Node *ptr = head;
    printf("\nThe circular linked list is: ");
    do{
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }while(ptr!=head);
    printf("\n");
}


struct Node *createNode(struct Node *head){
    int data;
    printf("Enter element: ");
    scanf("%d", &data);
    struct Node * p = (struct Node *) malloc(sizeof(struct Node));
    p->data = data;
    p->next = 0;
    struct Node * ptr;

    if(head == 0){
        head = p;
        ptr = head;
        return head;
    }
    else{
        ptr -> next = p;
        ptr = p;
        return head;
    }
    p->next = head;
}

//Deleting an element
struct Node * deleteAtIndex(struct Node *head, int index){
    struct Node * p = head;
    struct Node *q = head->next;
    if(index==0){
        struct Node *ptr = head;
        head = head->next;
        free(ptr);
        return head;
    }
    else{
        for(int i = 0; i<index-1; i++){
            p = p->next;
            q = q->next;
        }
        p->next = q->next;
        free(q);
        return head;
    }
}

struct Node * insertAtIndex(struct Node *head, int data, int index){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    if(index == 0){
        struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
        ptr -> data = data;
        ptr -> next = head;
        return ptr;
    }
    else{
        while(i!=index-1){
            p = p->next;
            i++;
        }
        ptr -> data = data;
        ptr -> next = p->next;
        p->next = ptr;
        return head;
    }
}

int main(){
    int i,n,choice;
    struct Node * head = 0;
    printf("Enter the no. of elements you want in CLL: ");
    scanf("%d", &n);
    for(i = 0; i<n; i++){
        head = createNode(head);
    }

    do{
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("\nEnter the operation no. you want to perform: ");
        scanf("%d", &choice);
        int data, index;
        switch(choice){
            case 1:
                printf("\nEnter the data and the index no. at which you want to insert the element: ");
                scanf("%d %d", &data, &index);
                head = insertAtIndex(head, data, index);
                display(head);
                break;
            case 2:
                printf("\nEnter the index no of element you want to delete: ");
                scanf("%d", &index);
                head = deleteAtIndex(head, index);
                display(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("\nExited\n");
                break;
            default:
                printf("Please enter the valid choice code.");
                break;
        }
    }while(choice!=4);

    return 0;
}
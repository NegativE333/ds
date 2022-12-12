#include <stdlib.h>
#include <stdio.h>

struct Node{
    int data;
    struct Node *next;
};

void display(struct Node * head){
    struct Node *p = head;
    printf("Linked list is: ");
    while(p!=NULL){
        printf("%d  ", p->data);
        p = p->next;
    }
    printf("\n");
}

struct Node * createNode(struct Node * head){
    int data;
    printf("Enter element: ");
    scanf("%d", &data);
    struct Node *p = (struct Node *) malloc(sizeof(struct Node));
    p->data = data;
    p->next = NULL;
    struct Node * ptr;

    if(head == NULL){
        head = p;
        ptr = head;
        return head;
    }
    else{
        ptr -> next = p;
        ptr = p;
        return head;
    }
}

struct Node * deleteNode(struct Node * head, int index){
    struct Node *p = head;
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

struct Node *insertAtIndex(struct Node *head, int data, int index){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;

    if(index == 0){
        struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
        ptr -> data = data;
        ptr -> next = head;
        return ptr;
    }
    else{
        while(i != index-1){
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
    int n,i,choice;
    printf("Enter the no. of nodes you want in a linked list: ");
    scanf("%d", &n);
    struct Node * head = NULL;
    for(int i = 0; i<n; i++){
        head = createNode(head);
    }
    display(head);

    do{
        
        printf("\n1.Insert Element.\n2.Delete Element.\n3.Display the linked list.\n4.Exit\n");
        printf("\n\nEnter the opration no. you want to perform: ");
        scanf("%d", &choice);
        int index, data;
        switch(choice){
            case 1:
                printf("\nEnter data and index no. at which you want to insert the element: ");
                scanf("%d %d", &data, &index);
                head = insertAtIndex(head,data,index);
                printf("\n");
                display(head);
                break;
            case 2:
                printf("\nEnter the index of element you want to  delete: ");
                scanf("%d", &index);
                head = deleteNode(head, index);
                printf("\n");
                display(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("\nExited\n");
                break;
            default:
                printf("\nEnter valid choice code.\n");
                break;
        }
    }while(choice!=4);

    return 0;
}
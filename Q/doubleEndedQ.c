#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct Q{
    int data[MAX];
    int R,F;
}Q;

void init(Q*P){
    P->R = -1;
    P->F = -1;
}

int isEmpty(Q*P){
    if(P->R == -1)
    return 1;
    return 0;
}

int isFull(Q*P){
    if(P->R == MAX - 1)
    return 1;
    return 0;
}

void insertfront(Q*P){
    int x;
    printf("\n Enter number to be inserted: ");
    scanf("%d",&x);
    // int x = 3;
    if(P->F == -1){
        P->F = P->R = 0;
        P->data[P->F] = x;
    }
    else{
        P->F = P->F-1;
        P->data[P->F] = x;
    }
}

int deleterear(Q*P){
    int x;
    if(P->R == P->F){
        x = P->data[P->R];
        P->R = P->F = -1;
        return(x);
    }
    else{
        x=P->data[P->R];
        P->R = P->R-1;
        return(x);
    }
}

void insertrear(Q*P){
    int x;
    printf(" Enter number to be inserted: ");
    scanf("%d",&x);
    if(P->R == -1){
        P->R = P->F = 0;
        P->data[P->R] = x;
    }
    else{
        P->R = P->R + 1;
        P->data[P->R] = x;
    }
}

int deletefront(Q*P){
    int x;
    x = P->data[P->F];
    if(P->F == P->R){
        P->F = -1;
        P->R = -1;
    }
    else
    P->F = P->F + 1;
    return(x);
}

void print(Q*P){
    int i;
    if(!isEmpty(P)){
        for(i=P->F; i<=P->R; i++){
            printf(" %d", P->data[i]);
        }
        printf("\n");
    }
}

int main(){
    Q q;
    int x,i,choice;
    init(&q);
    printf("Enter 3 elements \n");
    for(i=0;i<3;i++){
        if(!isFull(&q)){
            insertrear(&q);
        }
        else{
            printf("quene is full");
            exit(0);
        }
    }

while(choice!=6){
    printf("\n 1.Insertfront \t 2.Insert rear\t 3.Delete front\t 4.Delete rear\t 5.Display \t 6.Exit");
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                insertfront(&q);
                break;
            }
            case 2:
            {
                insertrear(&q);
                break;
            }
            case 3:
            {
                deletefront(&q);
                break;
            }
            case 4:
            {
                deleterear(&q);
                break;
            }
            case 5:
            {
                print(&q);
                break;
            }
            case 6:
            {
                printf("\n exit");
                break;
            }
            default:
            {
                printf ("\n Please Enter a Valid Choice");
            }
                
        }
    }
}


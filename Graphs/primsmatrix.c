#include<stdio.h>
#define v 5

// void prims(int [][]);
// int minkey(int [],int []);
// void displayMST(int[],int[][]);

int minkey(int key[],int set[]){
    int min=999,index;

    for(int i=0;i<v;i++){
        if(set[i]==0 && key[i]<min){
            min=key[i];
            index=i;
        } 
    }

    return index;
}

void displayMST(int parent[],int a[v][v]){
    printf("Edge \t Weight\n");
    for(int i=1;i<v;i++){
        printf(" %d - %d \t %d \n",parent[i],i,a[i][parent[i]]);
    }
}

void prims(int a[v][v]){
    int parent[10],key[10],set[10],u;

    for(int i=0;i<v;i++){
        key[i]=999;
        set[i]=0;
    }
    key[0]=0;
    parent[0]=-1;

    for(int i=0;i<v-1;i++){
        u=minkey(key,set);
        set[u]=1;

        for(int j=0;j<v;j++){
            if(a[u][j]!=998 && set[j]==0 && a[u][j]<key[j]){
                parent[j]=u;
                key[j]=a[u][j];
            }
        }

    }
    displayMST(parent,a);
}

int main(){
    int i,j,a[v][v];
    printf("\nEnter Adjacency matrix : ");
    printf("\n Enter 998 if not connected.");
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            printf("\n a[%d][%d] = ",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    prims(a);
}

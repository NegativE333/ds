#include<stdio.h>
#include<stdlib.h>
struct Node  {
struct Node *previous;
int item;
struct Node *next;
};

struct Node *head;

struct Node *GetNewNode(int ele) {
struct Node *ptr
= (struct Node*)malloc(sizeof(struct Node));
ptr->item = ele;
ptr->previous = NULL;
ptr->next = NULL;
return ptr;
}

void InsertBeginning(int ele) {
struct Node *ptr = GetNewNode(ele);

if(head == NULL) {
head = ptr;
return;
}
// if there is some item in the list pointed by head
head->previous = ptr;
ptr->next = head;
head = ptr;
}
//delete a Node from the starting of the list
void DeleteBeginning()
{
struct Node *ptr;
//checking if the list is empty or not
if(head == NULL)
{
printf("\n Sorry there are no items in the list");
}
//if there is only one item present in the list
else if(head->next == NULL)
{
head = NULL;
free(head);
printf("\nCongratulations!! Node has been successfully deleted \n");
}
//if there are more than one item present in the list
else
{
ptr = head;
head = head -> next;
head -> previous = NULL;
free(ptr);
printf("\n Congratulations!! Node has been successfully deleted \n");
}
}

void DisplayForward() {
struct Node *ptr1 = head;
if(ptr1 == NULL)
{
printf("\n Sorry there are no items in the list");
}
else
{
printf("Elements in the forward Direction ");
while(ptr1 != NULL) {
printf("%d  ",ptr1->item);
ptr1 = ptr1->next;
}
printf("\n");
}
}

void DisplayReverse() {
struct Node *ptr1 = head;
if(ptr1 == NULL)
{
printf("\n Sorry there are no items in the list");
}
else
{
// traversing till the last node
while(ptr1->next != NULL) {
ptr1 = ptr1->next;
}
// Traversing backward with the help of previous pointer
printf("Elements in the Reverse Direction ");
while(ptr1 != NULL) {
printf("%d ",ptr1->item);
ptr1 = ptr1->previous;
}
printf("\n");
}
}

int main() {

head = NULL;
InsertBeginning(12);
InsertBeginning(23);
InsertBeginning(33);
InsertBeginning(56);
DisplayForward();
DisplayReverse();
DeleteBeginning();
DisplayForward();
DisplayReverse();
}
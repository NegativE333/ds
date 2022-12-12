#include <stdio.h>

#include <stdlib.h>

  

/* Each treeNode holds some value, a pointer to left child (leftChild)

   and a pointer to right child (rightChild) */

struct treeNode 

{

    int value;

    struct treeNode* leftChild;

    struct treeNode* rightChild;

};



/* A method to traverse a tree using Morris traversal, hence without using recursion or stack */

void MorrisTraversal(struct treeNode* root)

{

    struct treeNode *current, *predecessorofCurrent;

    if (root == NULL)

        return;

    current = root;

    //The while loop continues till our current root is not NULL

    while (current != NULL) 

    {

        if (current->leftChild == NULL) 

        {

            printf("%d ", current->value);

            current = current->rightChild;

        }

        else 

        {

            //Getting the inorder predecessor of the current node

            predecessorofCurrent = current->leftChild;

            while (predecessorofCurrent->rightChild != NULL

                   && predecessorofCurrent->rightChild != current)

                predecessorofCurrent = predecessorofCurrent->rightChild;

  

            /* Setting the right child of predecessorofCurrent as current, and update current to the value of the leftChild of the current */

            if (predecessorofCurrent->rightChild == NULL) 

            {

                predecessorofCurrent->rightChild = current;

                current = current->leftChild;

            }

            /* Reverting the changes made due to the if block to

               restore the tree to its original state by fixing the right

               child of the predecessor. Printing the result of traversal */

            else 

            {

                predecessorofCurrent->rightChild = NULL;

                printf("%d ", current->value);

                current = current->rightChild;

            } 

        } 

    } 

}

  

/* A utility/helper function to allocate a new treeNode with the

   given value, along with NULL leftChild and NULL rightChild pointers. */

struct treeNode* newtreeNode(int value)

{

    struct treeNode* node = malloc (sizeof(struct treeNode));

    node->value = value;

    node->leftChild = NULL;

    node->rightChild = NULL;

    return (node);

}

  

int main()

{

  

    /* The tree created:

            4

          /   \

         2     5

       /   \

      1     3

  */

    struct treeNode* root = newtreeNode(4);

    root->leftChild = newtreeNode(2);

    root->rightChild = newtreeNode(5);

    root->leftChild->leftChild = newtreeNode(1);

    root->leftChild->rightChild = newtreeNode(3);

  

  /* Morris Traversal for the created tree */

    MorrisTraversal(root);

  

    return 0;

}
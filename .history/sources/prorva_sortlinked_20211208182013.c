/*
** EPITECH PROJECT, 2021
** do_op.c
** File description:
** do flags with diff vaues
*/

#include "./../includes/libraries.h"
#include "./../includes/structs.h"

node *firstNode;

void createLinkedList(int numberOfNodes)
{
    node *newNode;
    node *currentNodes;
    int nodeData;
    int nodeCtr;

    firstNode = (node *) malloc(sizeof(node));
    if (firstNode == NULL) {
        printf("memory cant be allocated");
    } else {
        printf("input num:  ");
        scanf("%d", &nodeData);

        firstNode->filesize = nodeData;
        firstNode->next = NULL;
        currentNodes = firstNode;
        
        for (nodeCtr = 2; nodeCtr <= numberOfNodes; nodeCtr++) {
            newNode = (node *)malloc(sizeof(node));
            if (newNode == NULL) {
                printf("Memory can not be allocated");
                exit (84);
            } else {
                scanf("%d", &nodeData);
                newNode->filesize = nodeData;
                newNode->next = NULL;
                currentNodes->next = newNode;
                currentNodes = currentNodes->next;
            } 
        }
    }
}

void sortLinkedList(int numberOfNodes)
{
    int nodeCtr;
    int ctr;
    int nodeDataCopy;
    node *currentNode;
    node *nextNode;
    
    for (nodeCtr = numberOfNodes - 2; nodeCtr >= 0; nodeCtr--) {
        currentNode = firstNode;
        nextNode = currentNode->next;
        for (ctr = 0; ctr <= nodeCtr; ctr++) {
            if (currentNode->filesize > nextNode->filesize) {
                nodeDataCopy = currentNode->filesize;
                currentNode->filesize = nextNode->filesize;
                nextNode->filesize = nodeDataCopy;
            }
            currentNode = nextNode;
            nextNode = nextNode->next;
        }
    }
}

void displayLinkedList()
{
    node *currentNode;
    currentNode = firstNode;
    while (currentNode != NULL)
    {
        printf("%d\t", currentNode->filesize);
        currentNode = currentNode->next;
    }
}

int main()
{
    int numberOfNodes;
    firstNode = NULL;
    printf("Input the numbner of elemnts in the linked list:");
    scanf("%d", &numberOfNodes);
    createLinkedList(numberOfNodes);
    sortLinkedList(numberOfNodes);
    printf("Sorted order is: \n");
    displayLinkedList();
    return (0);

}
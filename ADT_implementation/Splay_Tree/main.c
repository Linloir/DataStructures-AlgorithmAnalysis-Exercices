#include "splaytree.h"
#include <stdio.h>

int main(){
    SplayTree sampleTree = NULL;
    int command = -1;
    int value = 0;
    while(command != 0){
        printf("===================\n");
        printf("Test Splay Tree:\n");
        printf("[0]Exit\n");
        printf("[1]Insert value\n");
        printf("[2]Delete value\n");
        printf("[3]Visit value\n");
        printf("[4]Print tree\n");
        printf("===================\n");
        scanf("%d", &command);
        if(command > 0 && command < 4)
            scanf("%d", &value);
        switch (command)
        {
        case 1:
            sampleTree = Insert(sampleTree, value);
            break;
        case 2:
            sampleTree = Delete(sampleTree, value);
            break;
        case 3:
            sampleTree = Find(sampleTree, value);
            break;
        case 4:
            printf("Tree:\n===========================\n");
            Display(sampleTree, 0);
            printf("===========================\n");
            break;        
        default:
            command = 0;
            break;
        }
    }
}
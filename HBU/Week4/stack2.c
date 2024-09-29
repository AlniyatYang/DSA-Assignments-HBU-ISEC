#include <stdio.h>
#include <stdlib.h>


typedef struct Snode{
    int data;
    struct Snode* next;
}Snode;

int isEmpty(Snode* top){
    return (top == NULL);
}

Snode* push(Snode* top, int x){
    Snode* p = (Snode*)malloc(sizeof(Snode));
    p->data = x;
    p->next = top;
    top = p;
    return top;
}

Snode* pop(Snode* top , int* x){
    if (top == NULL){
        printf("Stack underflow!");
        return NULL;
    }
    *x = top->data;
    Snode* temp = top;
    top = top->next;
    free(temp);
    return top;
}

void printStack(Snode* top){
    if(isEmpty(top)) printf("Stack is empty!");
    else{
        Snode* current = top;
        while(current != NULL){
            printf("%d",current->data);
            if(current->next != NULL) printf("->");
            current = current->next;
        }
        printf("\n");
    }


}

int main(){
    Snode* stack = NULL;
    stack = push(stack,10);
    stack = push(stack,20);
    stack = push(stack,30);
    printf("Stack after pushing:\n");
    printStack(stack);
    
    printf((isEmpty(stack)?"Stack is empty.\n":"Stack isn't empty.\n"));

    int val;
    stack = pop(stack,&val);
    printf("pop:%d\n",val);

    printf("Stack after poping:\n");
    printStack(stack);

    return 0;
}
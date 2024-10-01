#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createStack(){
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    return head;
}

int isEmpty(Node* head){
    return (head->next == NULL);
}


Node* push(Node* head , int x){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = head->next;
    head->next = temp; 
    return head;
}

int pop(Node* head){
    if (isEmpty(head)){
        printf("[ERROR] The stack is empty\n");
        return -1;
    }  
    Node *temp = head->next;
    head->next = temp->next;
    int popped_data = temp->data;
    free(temp);
    return popped_data;
}

void printStack(Node* head){
    Node* current = head->next;
    while(current != NULL){
        printf("%d",current->data);
        if (current->next != NULL)  printf("->");
        current = current->next;
    }
    printf("\n");
}

int main(){
    Node* top = createStack();
    for (int i = 1 ; i <= 20 ; i++) top = push(top,i);
    printStack(top);
    for (int i = 1; i<= 20 ; i++) printf("poped: %d\n",pop(top));
    pop(top);
    return 0;
}
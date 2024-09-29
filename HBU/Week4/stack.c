#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1024

typedef struct SeqStack{
    int data[MAX_SIZE];
    int top;
}SeqStack;

//初始化栈空间
SeqStack* initStack(){
    SeqStack* s;
    s = (SeqStack*)malloc(sizeof(SeqStack));
    s->top = -1;
    return s;
}

//判断栈是否为空
int isEmpty(SeqStack* s){
    return (s->top == 1)? 1 : 0;
}

//压入新栈元素
int push(SeqStack* s,int x){
    if (s->top == MAX_SIZE-1) return 0;
    else{
        s->top++;
        s->data[s->top]=x;
        return 1;
    }
}

//删除栈顶元素
int pop(SeqStack *s ,int *x){  //x用来接收弹出的值 可先定义一个变量val,再传入&val
    if(isEmpty(s)) return 0;
    else{
        *x = s->data[s->top];
        s->top--;
        return 1;
    }
}

//获取栈顶元素
int peek(SeqStack *s , int *x){
    if (isEmpty(s)) return 0;
    else{
        *x = s->data[s->top];
        return 1;
    }

}

//打印所有栈元素
int printSeqStack(SeqStack *s){
    int size = s->top;
    while (size != -1){
        printf("%d\n",s->data[size]);
        if(size-1 != -1) printf("---\n");
        size--;
    }
}

int main(){
    SeqStack* s = initStack();
    printf((isEmpty)?"is empty\n":"is not empty\n");
    for (int i = 1 ; i <= 10 ; i++) push(s,i);
    int val;
    pop(s,&val),printf("pop:%d\n",val);
    peek(s,&val),printf("top:%d\n",val);    
    printSeqStack(s);
    return 0;
}
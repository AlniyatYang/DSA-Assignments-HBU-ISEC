#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
/* 
输入规范：
第一行: 顺序表长度
第二行：空格间隔的整型
e.g：
5
1 2 2 3 4
 */

typedef struct SeqList{
    int data[MAXSIZE];
    int length;
}SeqList;

void inputList(SeqList* L){
    scanf("%d",&L->length);
    for(int i = 0 ; i < L->length ; i++){
        scanf("%d",&L->data[i]);
    }
}

void deleteList(SeqList* L){
    for (int i = 0 ; i < L->length-1 ; i++){
        for (int j = i+1 ; j < L->length ; j++){
            if (L->data[i] == L->data[j]){
                for (int k = j ; k < L->length-1 ; k++){
                    L->data[k] = L->data[k+1];
                }
                L->length--;//减少顺序表长度
                j--;  //回退一个位置，重新检查该位置的新元素
            }
        }


    }
}

void printList(SeqList* L){
    for (int i = 0 ; i < L->length ; i++){
        printf("%d ",L->data[i]);
    }
    printf("\n");
}


int main(){
    SeqList* L = (SeqList*)malloc(sizeof(SeqList)); 
    inputList(L);
    deleteList(L);
    printList(L);
    return 0;
}

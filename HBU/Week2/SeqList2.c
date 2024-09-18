#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
typedef struct{
    int data[MAXSIZE];
    int last;
}SeqList;

/*
线性表的关键在于： 
    1.顺序i - 1 = 索引值
    2.插入的元素位置：不能超过索引值+1 （末尾值的下一个位置可以放置，不能超过）
    3.删除元素的位置：不能超过索引值
*/ 

SeqList* initSeqList(){
    SeqList* L;
    L = (SeqList*)malloc(sizeof(SeqList));
    L->last = -1;
    printf("======Initializing Sucessfully======\n");
    return L;
}

int insertSeqList(SeqList* L , int i , int x){
    //防止越界
    if (L->last == MAXSIZE-1){
        printf("The list is full\n");
        return -1;
    }

    if (i < 1 || i-1 > L->last + 1){
        printf("Wrong position\n");
        return 0;
    }

    for (int j = L->last ; j >= i-1 ; j--)
        L->data[j+1] = L->data[j];
    L->data[i-1] = x;
    L->last++;
    return 1;
}

int deleteSeqList(SeqList* L , int i){
    if (i < 1 || i-1 > L->last){
        printf("Wrong position\n");
        return 0;
    }

    for (int j = i-1 ; j < L->last ; j++)
        L->data[j] = L->data[j+1];
    L->last--;
    return 1;
}

int searchSeqList(SeqList* L , int x){
    for (int j = 0 ; j <= L->last ; j++){
        if (L->data[j] == x ){
            printf("The element->%d is  i = %d\n",x,j+1);
            return 1;
        }
    }
    printf("The element->%d is not in the SeqList\n",x);
    return 0;
}

void printSeqList(SeqList* L){
    int index = 0;
    
    if (L->last < 0){
        printf("The list is empty\n");
        return;
    }
        
    
    for (index = 0 ; index <= L->last ; index++){
        printf("%d",L->data[index]);
        if (index != L->last)
            printf("->");
    }

    printf("\n");
}



int main(){
    SeqList* L = initSeqList();
    printSeqList(L);
    insertSeqList(L,1,10);
    insertSeqList(L,2,20);
    insertSeqList(L,3,30);
    insertSeqList(L,4,40);
    insertSeqList(L,5,50);
    printSeqList(L);
    deleteSeqList(L,1);
    searchSeqList(L,10);
    searchSeqList(L,30);
    printSeqList(L);
    return 0;
}
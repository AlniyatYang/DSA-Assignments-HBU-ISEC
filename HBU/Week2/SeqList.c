#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 30
typedef struct{
    int data[MAXSIZE];
    int last;
}SeqList;

//??????????
SeqList* Init_SeqList(){
    SeqList* L;
    L = (SeqList*)malloc(sizeof(SeqList));
    L->last=-1;
    printf("==========????????????==========\n");
    return L;
}

//?????????
int Insert_SeqList(SeqList* L ,int i ,int x){
    if(L->last == MAXSIZE-1){
        printf("Full");
        return -1;
    }
    if (i < 1 || i > L->last + 2){
        printf("Wrong Position");
        return 0;
    }
    for(int j = L->last ; j >= i-1 ; j--){
        L->data[j+1] = L->data[j];
    }
    L->data[i-1]=x;
    L->last++;
    
    return 1;
}

//?????????
int Delete_SeqList(SeqList* L , int i){
    if (i < 1 || i > L->last + 1){
        printf("Doesn't exit the no.%d element",i);
        return 0;
    }

    for (int j = i-1 ; j <= L->last ; j++){
        L->data[j] = L->data[j+1];
    }  

    L->last--;
    return 1;
}

//?????????
int Location_SeqList(SeqList* L , int x){
    //int index = 0;
    // while(index <= L->last && L->data[index] != x )
    //     index++;
    // if (index > L->last) return -1;
    // else return index;
    for (int i = 0 ; i <= L->last ; i++){
        if (L->data[i] == x)
            return i;
    }
    return -1;
}

//????????
void Print_SeqList(SeqList* L){
    printf("??????????\n");
    for (int i = 0 ; i <= L->last ; i++){
        
        printf("%d",L->data[i]);
        if (i != L->last)
            printf("->");        
    }
    printf("\n");
}



int main(){
    SeqList* L = Init_SeqList();
    printf("??????????...\n");
    Insert_SeqList(L,1,10);
    Insert_SeqList(L,2,20);
    Insert_SeqList(L,3,40);
    Insert_SeqList(L,3,30);
    Insert_SeqList(L,5,50);
    Print_SeqList(L);
    printf("??????????...\n");
    Delete_SeqList(L,2);
    Print_SeqList(L);
    while(1){
        int num ;
        printf("\n==============================\n");
        printf("????????????????????\n");
        scanf("%d",&num);
        if (num == 666){
            printf("?????????");
            return 0;
        }
        printf(Location_SeqList(L,num) != -1 ? "?????????????%d ?????%d?????\n" : "¦Ä????????%d\n" , num ,Location_SeqList(L,num)+1,num );
    }
    
}
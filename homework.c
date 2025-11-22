#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
}Node;
struct Node* head;
void headinsert(int x){
    Node* temp = (Node*)malloc(sizeof(Node));
    (*temp).data = x;
    (*temp).next = head;
    head = temp;
}
void insert(int data,int n){
    Node* temp1 = (Node*)malloc(sizeof(Node));
    (*temp1).data = data;
    (*temp1).next = NULL;
    if(n == 1){
        temp1 ->next = head;
        head = temp1;
        return;
    }
    Node* temp2 = head;
    for(int i=0;i<n-2;i++){
        temp2 = (*temp2).next;
    }
    (*temp1).next = (*temp2).next;
    (*temp2).next = temp1;
}
void Print(){
    Node* temp = head;
    while(temp!=NULL){
        printf("%d",(*temp).data);
        temp = (*temp).next;
        if(temp!=NULL) printf(" ");
    }
    printf("\n");
}
int main(){
    head = NULL;
    while(1){
        int tmp;scanf("%d",&tmp);
        if(tmp == 0) break;
        insert(tmp); 
    }
    Print();
}
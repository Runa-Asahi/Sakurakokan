#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
}Node;
struct Node* head;

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
void delete(int n){
    Node* temp1 = head;
    if(n == 1){
        head = (*temp1).next;
        free(temp1);
        return;
    }
    for(int i=0;i<n-2;i++){
        temp1 = (*temp1).next;
    }
    Node* temp2 = (*temp1).next;
    (*temp1).next = (*temp2).next;
    free(temp2);
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
    head = NULL;int index = 1;
    while(1){
        int tmp;scanf("%d",&tmp);
        if(tmp == 0) break;
        insert(tmp,index); 
        index++;
    }
    Print();
}
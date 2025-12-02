#include <stdio.h>
#include <malloc.h>
struct link{
    int n;
    struct link* next = NULL;
};
struct link* build(){
    struct link* head=NULL,*tail=NULL;
    while(1){
        int t;scanf("%d",&t);
        if(t==0) break;
        struct link* Node = (struct link*)malloc(sizeof(struct link));
        Node->n = t;
        if(head==NULL){
            head = Node;tail = Node;
        }
        else {
            tail->next  = Node;
            tail = tail->next;
            tail->next = NULL;
        }        
    }
    return head;
}
void print(struct link* head){
    struct link* tmp=head;
    while(tmp!=NULL){
        printf("%d",tmp->n);
        tmp = tmp->next;
        if (tmp != NULL) printf(" ");
    }
}
void release(struct link* head){
    struct link* tmp;
    while(head!=NULL){
        tmp = head;
        head = head->next;
        free(tmp);
    }
}
int main(){
    struct link* head;
    head = build();
    if(head!=NULL)
    print(head);
    else
    printf("NULL");
    release(head);
    return 0;
}

#include <malloc.h>
#include <stdio.h>
struct cell {//单链表结点结构体定义
 int x;
 struct cell* next;
};
struct cell* build(void) {//新建单链表，并将建好的单链表首结点地址返回
 struct cell* head, * tmp, * p;
 head = tmp = p = NULL;
 int n;int cnt=0;
 while(scanf("%d",&n)==1){
    tmp = (struct cell*)malloc(sizeof(struct cell));
    tmp->x = n;
    tmp->next = NULL;
    if(head == NULL){
        head = tmp;
        p = tmp;
    }else {
        (*p).next = tmp;
        p = (*p).next;
    }
 }
 return head;//返回单链表头
}
struct cell* mid(struct cell* head) {//寻找链表中间位置结点地址并返回，head是单链表首结点指针
    struct cell* travel = head;int cnt=0;
    while(travel!=NULL){
        cnt++;
        travel = (*travel).next;
    }
    travel = head;
    if(cnt%2==0){
        for(int i=1;i<cnt/2;i++){
            travel = (*travel).next;
        }
        return travel;
    }
    else if(cnt%2!=0){
        for(int i=1;i<=cnt/2;i++){
            travel = (*travel).next;
        }
        return travel;
    }
    return NULL;
}
void print(struct cell* head) {//打印整个单链表,head是单链表首结点指针
    struct cell* tmp=head;
    while(tmp!=NULL){
        printf("%d",(*tmp).x);
        tmp = (*tmp).next;
    }
    return;
}
void release(struct cell* head) {//释放单链表空间,head是单链表首结点指针
    struct cell* tmp=head;
    while(tmp!=NULL){
        struct cell* next = tmp->next;
        free(tmp);
        tmp = next;
    }
    return;
}
int main(void) {
 struct cell* head,*half;
 head = build();
 half = mid(head);
 if(half!=NULL)
        print(half);
    else
        printf("NULL");
 release(head);
}
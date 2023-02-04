#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct _listnode {
    int num;
    struct _listnode *next;
} ListNode;
typedef struct _linkedlist { 
    ListNode *head;
    int size;
} LinkedList;
typedef struct _stack {
    LinkedList ll;
} Stack;
void printList(ListNode *head) {
	ListNode *cur=head;
	if (head==NULL){
		printf("Danh sach lien ket khong co phan tu nao");
		return;
	}
	while (cur!=NULL){
		printf("%d ",cur->num);
		cur=cur->next;
	}
	printf("\n");
}
ListNode *findNode(ListNode *head, int i) {
	ListNode *cur = head;
   	if ((head == NULL) || (i < 0)) {
    printf("Danh sach lien ket rong hoac phan tu tim kiem khong ton tai");
	return NULL;
   	}
	while (i > 0) {
        cur = cur->next ;
        i=i-1;
		if (cur == NULL) {
		printf("Phan tu tim kiem khong ton tai");
		return NULL;
		}
	}
   return cur;
}
void insertNode(ListNode **pHead, int index, int value){
  ListNode *cur, *newNode;
  if (*pHead == NULL || index == 0 ){
	newNode = malloc(sizeof(ListNode));
	newNode->num = value;
	newNode->next = *pHead ;
	*pHead = newNode ;
  	}
  else if ((cur = findNode( *pHead, index-1)) != NULL){
	newNode = malloc(sizeof(ListNode));
	newNode->num = value;
	newNode->next = cur->next;
	cur->next =newNode ;
	} else printf("can not insert the new item at index %d!\n", index);
}
void removeNode(ListNode **ptrHead, int index){
    ListNode *cur, *pre;
    if (index == 0) {
        cur = *ptrHead;
        *ptrHead = cur->next;
        free(cur);
    } else {
        pre = findNode(*ptrHead, index-1);
        cur = pre->next;
        pre->next = cur->next ;
        free(cur);
    }
}
void push(Stack *s, int item ) {
    insertNode(&(s->ll.head), 0, item);
    s->ll.size = (s->ll.size)+1;
}
int isEmptyStack(Stack *s) {
    if ( s->ll.size==0 ) return 1;
    return 0;
}
int pop(Stack *s) {
    int item;
    if (!isEmptyStack(s)) {
        item = ((s->ll).head)->num;
        removeNode(&(s->ll.head),0);
        (s->ll).size--;
        return item ;
    }
    else { 
	printf("Ngan xep rong");
	return NULL;
	}
}
int peek(Stack *s) {
    if ((s->ll).size!=NULL)
        return ((s->ll).head)->num;
    else { 
printf("Ngan xep rong");
return NULL;
}
}
int main() {
	Stack *s = malloc(sizeof(Stack));
    s->ll.size = 0;
    s->ll.head= NULL;
    printList(s->ll.head);
    printf("\n");
    push(s,3);
    push(s,4);
    push(s,5);
    push(s,6);
    printList(s->ll.head);
    printf("\n%d\n", pop(s)); printf("\n%d\n", pop(s));
    printList(s->ll.head);
    peek(s);
}

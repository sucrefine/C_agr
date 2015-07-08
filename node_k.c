/*找到链表中倒数第k节点*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}Node,*ListNode;
ListNode CreateList(int a[],int n){
	int i=0;
	ListNode p=(ListNode)malloc(sizeof(Node));
	ListNode head=p;
	for(i;i<n;i++){
		ListNode node=(ListNode)malloc(sizeof(node));
		node->data=a[i];
		p->next=node;
		p=node;
	}
	return head;
}
int Find_Kth(ListNode head,int k){
	ListNode p=head;
	int count=1;
	while(head->next!=NULL){
		if(count<k){
			head=head->next;
			count++;
		}
		else{
			head=head->next;
			p=p->next;
		}
	}
	return p->data;	
}
int main(){
	int a[]={1,2,3,4,5};
	ListNode p=CreateList(a,5);
	ListNode q=p;
	while(q->next!=NULL){
		printf("%d\n",q->next->data);
		q=q->next;
	}
	int result=Find_Kth(p,1);
	printf("last k is %d\n",result);
}

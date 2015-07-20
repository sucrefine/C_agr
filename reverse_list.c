/*链表就地逆转*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}Node,*NodeList;
NodeList create(int a[],int n){
	int i=0;
	NodeList p=(NodeList)malloc(sizeof(Node));
	NodeList head=p;
	for(i;i<n;i++){
		NodeList node=(NodeList)malloc(sizeof(node));
		node->data=a[i];
		p->next=node;
		p=node;
	}   
	return head;
}
NodeList reverse(NodeList head){
	NodeList p=head->next;
	NodeList r=head;
	head->next=NULL;
	while(p->next!=NULL){
		NodeList q=p->next;
		r->next=head->next;
	
		p=q;
	}
	return r;
}
int main(){
	int a[5]={1,2,3,4,5};
	NodeList head,p;
	head=create(a,5);
	p=head;
	while(p->next!=NULL){
		p=p->next;
		printf("%d\n",p->data);
	}
	NodeList reversed;
	reversed=reverse(head);
	while(reversed->next!=NULL){
		reversed=reversed->next;
		printf("%d\n",reversed->data);
	}
}

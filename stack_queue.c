/*每次从s1进栈，从s2出栈*/
#include<stdio.h>
#include<stdlib.h>
typedef struct stack{
	int top;
	int arr[100];
}stack,*pstack;
stack s1;
stack s2;
int init_stack(pstack s){
	s->top=0;
	return 0;
}
int push_stack(int i,pstack s){
	s->top+=1;
	s->arr[s->top]=i;
	return 0;
}
int pop_stack(pstack s){
	int get=s->arr[s->top];
	s->top-=1;
	return get;
}
int push_queue(int i,pstack s1,pstack s2){//进队列从s1栈进
	while(s2->top!=0){
		int s2_top=pop_stack(s2);
		push_stack(s2_top,s1);
	}
	s1->top+=1;
	s1->arr[s1->top]=i;
	return 0;
}
int pop_queue(pstack s1,pstack s2){
	while(s1->top!=0){//如果需要出队列，先把栈s1的元素全部压入栈s2
		int s1_top=pop_stack(s1);//s1出栈
		push_stack(s1_top,s2);//压入s2
	}
	int get =pop_stack(s2);
	return get;
}
int main(){
	pstack s1;
	pstack s2;
	s1=(pstack)malloc(sizeof(stack));
	s2=(pstack)malloc(sizeof(stack));
	init_stack(s1);
	init_stack(s2);
	push_queue(1,s1,s2);
	push_queue(2,s1,s2);
	push_queue(3,s1,s2);
	int show1=pop_queue(s1,s2);
	printf("%d\n",s2->top);
	//printf("%d\n",pop_stack(s2));
	push_queue(4,s1,s2);
	int show2=pop_queue(s1,s2);
	int show3=pop_queue(s1,s2);
	int show4=pop_queue(s1,s2);
	printf("first is %d\n",show1);
	printf("second is %d\n",show2);
	printf("third is %d\n",show3);
	printf("fourth is %d\n",show4);
}

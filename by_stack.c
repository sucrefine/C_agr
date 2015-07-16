/*输入两个整数序列，第一个序列是压入顺序，请判断第二个是否是弹出序列，例如：序列12345,为某栈的压栈顺序，判断45321和43512是否为压栈序列的弹出序列*/
#include<stdio.h>
#include<stdlib.h>
int if_in(int num ,int a[],int n){
	int i=0,flag=0;
	for(i;i<n;i++){
		if(a[i]==num){
			flag=1;
		}
	}
	return flag;
}//判断num是否在a中
int judge(int push[],int pop[],int n){
	int i=0,j=0,k=-1,foot=0,result=1;
	int stack[n];
	for(i;i<n;i++){
		int top = pop[i];
		printf("top is %d\n",top);
		int flag=0;
		flag=if_in(top,stack,n);
		if(flag==0){
			for(j;j<n;j++){
				if(j<foot)
					continue;//从第foot个数开始把push元素添加到stack中，直到遇到top
				stack[++k]=push[j];
				if (push[j]==top){
					printf("%dand%dand%d\n",j,top,k);
					foot=j+1;
					stack[k]=0;//同时把top出栈
					k--;
					break;
				}
			}
			printf("k=%d\n",k);
		}
		else{
			if(k<0)
				break;
			printf("top:%d;stack[k]:%d;k:%d\n",top,stack[k],k);
			if(top!=stack[k]){//如果stack的出栈元素跟pop不一样返回0
				result=0;
				break;
			}
			else{
				stack[k]=0;
				k--;
			}
		}
			
	}
	return result;
}
int main(){
	int push[]={1,2,3,4,5};
	int pop[]={4,3,5,1,2};
	int result;
	result=judge(push,pop,5);
	printf("%d\n",result);
}

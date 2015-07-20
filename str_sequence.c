/*输入一个字符串，打印出该字符串中字符的所有排列*/
#include<stdio.h>
void swap(char *a,char *b){
	char temp=*a;
	*a=*b;
	*b=temp;
}
void sequence(char *str,int start,int end){
	//printf("%d~%d\n",start,end);
	if(start==end-1){
		printf("%s\n",str);
	}
	else{
		int i;
		for(i=start;i<end;i++){
			swap(str+start,str+i);
			sequence(str,start+1,end);
			swap(str+start,str+i);//为什么需要这一步，不理解
		}
	}
}
int main(){
	char str[]={'a','b','c'};
	sequence(str,0,3);
	return 0;
}

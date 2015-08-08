/*翻转句子，比如 i am a students.,翻转结果为students. a am i。思想，先把整个句子翻转，然后堆句子中单词翻转*/
#include<stdio.h>
void reverse(char a[],int start,int end){
	int i=start;
	int j=end;
	while(i<=j){
		char temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		i++;
		j--;
	}
}//翻转操作
int main(){
	char a[]="i am a student.";
	reverse(a,0,14);//翻转整个句子
	int p=0,q=0;
	while(q<=14){
		q++;
		if(a[q]==32){//以空格（ANSI码为32）为将句子分割成单词，然后对每个单词翻转
			reverse(a,p,q-1);
			p=q+1;
		}
	}
	int i;
	for(i=0;i<=14;i++){
		printf("%c",a[i]);
	}
	printf("\n");
}

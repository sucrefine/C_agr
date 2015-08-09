/*循环左移字符串，比如abcdef循环左移2位得到cdefab。思想：将字符串分成两部分X和Y，把X和Y分别翻转组合到一起后在将所有一起翻转就得到。结论：（X^T Y^T）^T=YX*/
#include<stdio.h>
void reverse(char a[],int start,int end){
	int i=start;
	int j=end;
	while(i<=j){
		char temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		j--;
		i++;
	}
}//翻转操作
void revolve(char a[],int len,int digit){
	reverse(a,0,digit-1);//先将X翻转
	reverse(a,digit,len-1);//Y翻转
	reverse(a,0,len-1);//整个字符串翻转
}
int main(){
	char a[]="abcdef";
	revolve(a,6,2);
	int i;
	for(i=0;i<6;i++){
		printf("%c",a[i]);
	}
	printf("\n");
	return 1;
}

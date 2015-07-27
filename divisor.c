/*输入整数数组，求数组的最大公约数。思想：先求出第一个与第二的最大公约数，然后求这个最大公约与第三个元素的最大公约数，循环下去*/
#include<stdio.h>
int divisor(int a,int b){
	int div=1;
	if(a>b){
		int temp=a;
		a=b;
		b=temp;
	}
	while(div){
		div=b%a;
		b=a;
		a=div;
	}
	return b;
}//求a和b的最大公约数
int main(){
	int a[]={568,14,24,976,18,22};
	int i;
	int div=divisor(a[0],a[1]);
	for(i=2;i<6;i++){
		div = divisor(div,a[i+1]);
	}
	printf("%d\n",div);
}

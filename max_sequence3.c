/*这个算法还没完全弄明白，时间复杂度为O(n)*/
#include<stdio.h>
int main(){
	int a[10]={5,-5,3,-7,9,4,-3,7,-3,5};
	int sum=0;
	int b=0,i;
	int index1=0,index2=0;
	for (i=0;i<10;i++){
		if(b<0){
			b=a[i];
			index1=i;
		}
		else
			b+=a[i];
		if(sum<b){
			sum=b;
			index2=i;
		}
	}
	printf("sum=%d,index1=%d,index2=%d\n",sum,index1,index2);
	return 0;
}

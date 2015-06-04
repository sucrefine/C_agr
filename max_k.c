/*寻找最大的k个数，思想：以一个数temp为基础将数据划分为两部分，一部分全部大于
temp，另外一部分全部小于temp，如果第一部分的个数大于k那么最大的k个数全部在第一部分，如果第一部分的个数小于k，那么在第二部分还有k减去第一部分个数那么多个数，那么在第二部分可以运用递归的思想继续第一个步骤*/
#include<stdio.h>
void max_k(int a[],int front ,int rear,int k){
	int temp=a[front];
	int i=front;
	int j=rear;
	while(i<j){
		while(i<j&&a[j]<=temp){
			j--;
		}
		a[i]=a[j];
		while(i<j&&a[i]>=temp){
			i++;
		}
		a[j]=a[i];

	}
	a[i]=temp;
	if((i-front)==k){
		int p;
		for(p=0;p<k;p++){
			printf("%d\n",a[p]);
		}
	}
	if((i-front)>k){
		max_k(a,front,i,k);
	}
	if((i-front)<k){
		max_k(a,i,rear,k-i);	
	}
}
int main(){
	int a[10]={4,6,2,1,44,52,2,14,5,32};
	max_k(a,0,9,4);
	int q;
	int p;
	for (p=0;p<4;p++){
		printf("%d\n",a[p]);
	}
	printf("###############\n");
	for(q=0;q<10;q++){
		printf("%d\n",a[q]);
	}
}

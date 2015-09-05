/*冒泡排序算法，算法思想：相邻的两个元素比较，把较大的交换到后面，一轮循环下来最末尾的就是最大，然后除最末尾的数外，重复比较相邻的数继续交换*/
#include<stdio.h>
void sort(int a[],int n){
	int i,j;
	for(i=n-1;i>=0;i--){
		for(j=0;j<=i;j++){
			if(a[j]>a[j+1]){
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
int main(){
	int a[]={1,5,6,2,4,3,9,8,7};
	sort(a,9);
	int i;
	for(i=0;i<9;i++){
		printf("%d\n",a[i]);
	}
}

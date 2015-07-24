/*此算法实在max1算法基础上优化而来，因为，在计算[i..j]的和的k循环可以直接运用[i..j-1]+j即可，算法时间复杂度是O(N^2)*/
#include<stdio.h>
int MaxSequence(int a[],int n){
	int i,j;
	int max=0,max1,max2;
	for (i=0;i<n;i++){
		int sum=0;
		for (j=i;j<n;j++){
			sum+=a[j];
			if(sum>max){
				max=sum;
				max1=i;
				max2=j;
			}
		}
	}
	printf("最大数组子序列是从第%d到%d，总和为%d\n",max1,max2,max);
	return max;
}
int main(){
	int a[10]={5,-5,3,-7,9,4,-3,7,-3,5};
	int max=MaxSequence(a,10);
	return 0;
}

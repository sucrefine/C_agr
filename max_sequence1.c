/*穷举法，算出每个i~j之和，取最大值,i,j的for循环用来遍历序列a[i..j]，k的for 循环用来计算子序列[i..j]的和*/
#include<stdio.h>
int main(){
	int a[10]={5,-5,3,-7,9,4,-3,7,-3,5};
	int i,j,k;
	int max=0;
	int max1,max2;
	for (i=0;i<10;i++){
		for (j=0;j<10;j++){
			int sum=0;
			for (k=i;k<=j;k++){
				sum+=a[k];
			}
			if(sum>max){
				max=sum;
				max1=i;
				max2=j;
			} 
		}
	}
	printf("最大连续子数组是从%d到%d，他们的和是%d\n",max1,max2,max);
	return max;
}

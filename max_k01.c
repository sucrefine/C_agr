/*求最大k个数，思想：只要找到最大的k个数中最小的那个数，那么数组中大于这个数的就是最大k个数，因为那个数一定是在数组的最大值和最小值之间，于是就可以利用二分查找的思想，对于给定的数mid，轻松统计出大于mid的个数，如果正好等于k那么这最大k个数就是数组中大于mid的数*/
#include<stdio.h>
void max_k(int a[],int k,int n){
	int i;
	int max=a[0];
	int min=a[0];
	for(i=0;i<n;i++){
		if(a[i]>max)
			max=a[i];
		if(a[i]<min)
			min=a[i];
	}//找出数组中最大最小的数
	int low=min,high=max;
	int mid=(high+low)/2;
	while(mid>low&&mid<high){
		int count=0;
		for (i=0;i<n;i++){
			if(a[i]>=mid){
				count++;
			}
		}
		if(count==k)
			break;
		else 
			if(count>k){
				low=mid;
				mid=(high+low)/2;
			}
			else{
				high=mid;
				mid=(low+high)/2;
			}
	printf("count is %d",count);
	printf("and mid is %d\n",mid);
	}
	for(i=0;i<n;i++){
		if(a[i]>=mid)
			printf("output is %d\n",a[i]);
	}	
}
int main(){
	int a[10]={4,6,2,1,44,52,2,14,5,32};
	max_k(a,4,10);	
}

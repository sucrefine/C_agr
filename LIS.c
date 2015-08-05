/*求一个数组的最大非降子序列，及其长度。由于当前一个元素的最长子序列
是由前面的元素决定了，所以可以用动态规划思想，比如a[]={2,5,7,1,2,3,4,7}，如果用d[i]
表示包含a[i]的最优解，则d[i]应该是从0~i-1中d[j]最大，且a[j]<=a[i]。算出所有的d[i]求最大就是最优解了*/
#include<stdio.h>
int lis(int a[],int n){
	int len=0;
	int i,j,top=0;
	int d[n];//用于保存包含a[i]时的当前最优解
	int pre[n];//用于保存如果最优解包含a[i]，它之前的一个元素下标
	d[0]=1;
	for(i=0;i<n;i++){
		int max=0;//临时指示器，用于寻找局部最大值
		pre[i]=-1;//初始化为-1
		for(j=i-1;j>=0;j--){
			if(a[j]<=a[i]&&d[j]>max){//递推条件，i-1之前最大值，并且该元素要小于a[i]
				max=d[j];
				pre[i]=j;
			}
		}
		d[i]=max+1;//满足条件，在基础上加一（包含了a[i]）
		if(d[i]>len){
			len=d[i];
			top=i;//记录全局最优的末尾元素，方便回溯查找之前的元素
		}//寻找全局最优
	}
	printf("%d\n",a[top]);//输出末尾元素
	while(pre[top]!=-1){
		printf("%d\n",a[pre[top]]);
		top=pre[top];
	}//回溯查找之前序列
	return len;
}
int main(){
	int a[]={2,5,7,1,2,4,3,7};
	int len=lis(a,8);
	printf("len is %d\n",len);
}

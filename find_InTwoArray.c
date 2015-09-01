#include<stdio.h>
int find(int a[],int m,int b[],int n,int k){
	int i=m-1;
	int j=n-1;
	int result;
	for(k;k>0;k--){
		if(a[i]>b[j]){
			result=a[i];
			i--;
		}
		else{
			result=b[j];
			j--;
		}
	}
	return result;
}
int main(){
	int a[]={2,4,6,8,9,12};
	int b[]={5,7,15};
	int show=find(a,6,b,3,3);
	printf("%d\n",show);
}

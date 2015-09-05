/*直接插入排序*/
#include<stdio.h>
void sort(int a[],int n){
	int i,j;
	for(i=1;i<n;i++){
		if(a[i]<a[i-1]){
			int temp=a[i];//注意要用个临时变量保存a[i]
			for(j=i-1;j>=0;j--){
				if(temp<a[j]){
					a[j+1]=a[j];//因为此处覆盖掉了a[i]的值
				}
				else
					break;
			}
			a[j+1]=temp;
		}
	}
}
int main(){
	int a[]={1,9,8,7,2,3,6,5,4};
	sort(a,9);
	int i;
	for(i=0;i<9;i++){
		printf("%d\n",a[i]);
	}
}

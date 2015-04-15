#include<stdio.h>
int min(int a,int b,int c){
	if(a<=b){
		if(c<=a)
			return c;
		else
			return a;
	}
	else{
		if(b<=c)
			return b;
		else
			return c;
	}
}
int findugly(int n){
	int save[n];
	int index2=0,index3=0,index5=0;
	save[0]=1;
	int count=1;
	while(count<n){
		int aim=min(save[index2]*2,save[index3]*3,save[index5]*5);
		save[count]=aim;
		while(save[index2]*2<=aim){
			index2++;
		}
		while(save[index3]*3<=aim){
			index3++;
		}
		while(save[index5]*5<=aim){
			index5++;
		}
		count++;
	}
	return save[n-1];
}
int main(){
	printf("please input a number!\n");
	int n;
	scanf("%d",&n);
	int i;
	for(i=1;i<n;i++){
		int target=findugly(i);
		printf("%d\n",target);
	}
	return 0;
}

/*输入n，打印出从1到最大的n位整数*/
#include<stdio.h>
int main(){
	int n;
	printf("please input a number!\n");
	scanf("%d",&n);
	printf("the number you input is %d\n",n);
	char number[n+1];
	int i;
	for (i=0;i<n;i++){
		number[i]='0';
	}
	int flag=1;
	while(flag){
		number[n-1]+=1;
		for (i=n-1;i>=0;i--){
			if((number[i]-58)==0){
				number[i-1]=number[i-1]+1;
				number[i]='0';
			}
		}
		flag=0;
		for(i=0;i<n;i++){
			if(number[i]!=57){
				flag=1;
				break;	
			}
		}
		int k;
		for(i=0;i<n;i++){
			if(number[i]!='0'){
				k=i;
				break;
			}
		}
		for(k;k<n;k++){
			printf("%c",number[k]);
		}
		printf("  ");
	}
	printf("\n");
	return 0;
}

/*两个字符串的编辑距离。动态规划算法，递推公式：取一下三个数的最小值，（1）如果比较的
两个字符相同，则为左上方数组，否则左上方加一，（2）上方数组加一，（3）左方数字加一*/
#include<stdio.h>
int min(int a,int b,int c){
	if(a<b){
		if(a<c)
			return a;
		else
			return c;
	}
	else{
		if(b<c)
			return b;
		else
			return c;
	}
}
int distance(char a[],int m,char b[],int n){
	int d[m][n];
	int i,j;
	for(i=0;i<m;i++){
		d[i][0]=i;
	}
	for(j=0;j<n;j++){
		d[0][j]=j;
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(a[i]==b[j]){
				d[i][j]=min(d[i-1][j]+1,d[i][j-1]+1,d[i-1][j-1]);
			}
			else
				d[i][j]=min(d[i-1][j]+1,d[i][j-1]+1,d[i-1][j-1]+1);	
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d",d[i][j]);
			printf("	");
		}
		printf("\n");
	}
	return d[m-1][n-1];
}
int main(){
	char a[]={'a','b','c','d'};
	char b[]={'a','b','c'};
	int d=distance(a,4,b,3);
	printf("%d\n",d);
}

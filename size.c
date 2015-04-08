#include<stdio.h>
int main(){
	unsigned a=0;
	unsigned b=a-1;
	printf("%u\n",b);
	int count=1;
	while(b!=1){
		b=b/2;
		count++;
	}
	printf("%d\n",count);
	return 0;
}

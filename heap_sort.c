/*堆排序算法，用大根对的思想，将数组看成一颗完全二叉树。第一步：将二叉树调整成大根堆。
第二步：将无序区的第一个元素跟最后一个元素交换，将交换后的最后一个元素交换到有序区。
第三步：调整无序区为大根堆，循环二三步骤*/
#include<stdio.h>
//给定一个无序序列，将其调整成大根堆
void heap_adjust(int a[],int i,int n){
	int child;
	int temp;
	for(i;i*2+1<n;i=child){
		child=2*i+1;
		if(child<n-1&&a[child+1]>a[child])
			++child;
		if(a[i]<a[child]){
			temp=a[i];
			a[i]=a[child];
			a[child]=temp;
		}
		else
			break;
	}
}/*此函数只是针对某一个子树调整，该子树的根节点是i，如果想在整个二叉树上调整成大根堆，
就必须自底向上的调整各个子树，也就是说，先从n/2处调整（如下25到27行），
因为n/2处的孩子节点就是整个二叉树最末尾的叶子节点*/
void heap_sort(int a[],int n){
	int i;
	for(i=n/2-1;i>=0;--i){
		heap_adjust(a,i,n);
	}//先调整成大根堆
	int temp;
	for(i=n-1;i>0;--i){
		temp=a[0];
		a[0]=a[i];
		a[i]=temp;//交换首位元素
		heap_adjust(a,0,i);//缩小调整的范围，每次调整0～i处为大根堆，i循环一次就减一
	}
}
int main(){
	int a[]={3,2,1,5,7,6,4,8,9,10};
	heap_sort(a,10);
	int i;
	for(i=0;i<10;i++){
		printf("%d\n",a[i]);
	}
}

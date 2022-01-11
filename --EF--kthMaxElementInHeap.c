#include<stdio.h>
#include<stdlib.h>
#include"heap.h"
int main(){
	int k = 7, count;
	heap h1,h2;
	createHeap(&h1,9);
	createHeap(&h2,9);
	for(int i=1; i<=9; i++)
		insertInHeap(&h1,i);
	insertInHeap(&h2,h1.arr[0]);
	count = 0;
	while(1){
		int heapElement = deleteFromHeap(&h2);
		if(++count == k){
			printf("%d\n",heapElement);
			break;
		}
		else{
			if(h1.count > 2*(count-1)+1)
				insertInHeap(&h2,h1.arr[2*(count-1)+1]);
			if(h1.count > 2*(count-1)+2)
				insertInHeap(&h2,h1.arr[2*(count-1)+2]);
		}
	}
	return 0;
}

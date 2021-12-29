#include <stdio.h>
#include <stdlib.h>
void swap(int arr[], int a, int b){
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
void heapify(int arr[], int n){
	int i = (n/2)-1, j, temp;
	for(i; i>=0; i--){
		j = i;
		temp = arr[j];
		while(j <= (n/2)-1){
			if(2*j+2 < n){
				if(arr[2*j+1]>arr[2*j+2]){
					if(temp<arr[2*j+1]){
						swap(arr,j,2*j+1);
						j = 2*j+1;
					}
				}
				else if(temp<arr[2*j+2]){
					swap(arr,j,2*j+2);
					j = 2*j+2;
				}
				else break;
			}
			else if(temp < arr[2*i+1]){
				swap(arr,j,2*j+1);
				j = 2*j+1;
			}
			else break;
		}
	}
}
int main(){
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int n = sizeof(arr) / sizeof(int);
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	heapify(arr, n);
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}
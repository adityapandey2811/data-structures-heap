#include<stdio.h>
#include<stdlib.h>
typedef struct h{
    int *arr, count, capacity, type;
}heap;
void createHeap(heap *max_heap, int size){
    max_heap->capacity = size;
    max_heap->arr = (int*)malloc(sizeof(int)*size);
    max_heap->count = 0;
}
void insertInHeap(heap *max_heap, int element){
    int i;
    if(max_heap->count == 0){
        max_heap->arr[max_heap->count] = element;
    }
    else{
        i = max_heap->count;
        while(i>0 && element > max_heap->arr[(i-1)/2]){
            max_heap->arr[i] = max_heap->arr[(i-1)/2];
            i = (i-1)/2;
        }
        max_heap->arr[i] = element;
    }
    max_heap->count++;
}
int deleteFromHeap(heap *max_heap){
    int x,i=0,temp;
    if(max_heap->count == 0)
        return -1;
    x = max_heap->arr[0];
    max_heap->count--;
    temp = max_heap->arr[max_heap->count];
    max_heap->arr[max_heap->count] = x;
    while(i<max_heap->count){
        if((2*i+2<max_heap->count)){
            if(max_heap->arr[2*i+1]>max_heap->arr[2*i+2]){
                max_heap->arr[i] = max_heap->arr[2*i+1];
                i = 2*i+1;
            }
            else{
                max_heap->arr[i] = max_heap->arr[2*i+2];
                i = 2*i+2;
            }
        }
        else if((2*i+1<max_heap->count) && temp<max_heap->arr[2*i+1]){
            max_heap->arr[i] = max_heap->arr[2*i+1];
            i = 2*i+1;
        }
        else
            break;
    }
    max_heap->arr[i] = temp;
    return x;
}
int main(){
    heap max_heap;
    createHeap(&max_heap,20);
    for(int i = 0; i < 7; i++)
        insertInHeap(&max_heap,i+1);
    for(int i = 0; i < max_heap.count; i++)
        printf("%d ",max_heap.arr[i]);
    // printf("\n%d\n",deleteFromHeap(&max_heap));
    printf("\n");
    for(int i = 0; i < 7; i++)
        deleteFromHeap(&max_heap);
    for(int i = 0; i < 7; i++)
        printf("%d ",max_heap.arr[i]);
    return 0;
}

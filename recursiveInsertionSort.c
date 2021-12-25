#include <stdio.h>
void recursiveInsertionSort(int arr[], int i,int n){
    if(i==n) return ;
    int  key = arr[i];
    int j=i-1;
    printf("\n%d %d\n",i,j);
    printf("%d %d\n",key,arr[j]);
    while(j>=0 && key<arr[j]){
        arr[j+1]=arr[j];
        j--;
        printf("swap %d and %d",j+1,j+2);
    }
    arr[j+1]=key;
    recursiveInsertionSort(arr,i+1,n);


//    if (n <= 1)
//       return;
//    recursiveInsertionSort( arr, n-1 );
//    int nth = arr[n-1];
//    int j = n-2;
//    while (j >= 0 && arr[j] > nth){
//       arr[j+1] = arr[j];
//       j--;
//    }
//    arr[j+1] = nth;
}
int main(){
   int array[] = {34, 7, 12, 90, 51};
   int n = sizeof(array)/sizeof(array[0]);
   printf("Unsorted Array:\t");
      for (int i=0; i < n; i++)
   printf("%d ",array[i]);
      recursiveInsertionSort(array, 0,n);
   printf("\nSorted Array:\t");
   for (int i=0; i < n; i++)
      printf("%d ",array[i]);
   return 0;
}
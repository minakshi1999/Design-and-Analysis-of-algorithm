//Q2
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef long  int li;

void countSort(long int arr[],long int n,long int d){

   long int count[10];
     for(int i=0;i<10;i++){
         count[i]=0;
     }

     for(int i=0;i<10;i++){
         count[(arr[i]/d)%10]++;
     }
    long int stable_arr[n];
    for(int i=1;i<10;i++){
        count[i] += count[i-1];
    }

    for(li i=n-1;i>=0;i--){
        stable_arr[count[(arr[i]/d)%10]-1]=arr[i];
        count[(arr[i]/d)%10]--;
    }
    
   for(li i=0;i<n;i++){
       arr[i]=stable_arr[i];
    }
}

void radixSort(long int arr[],long int n){
 /*    long int max_val=0;
     for(li i=0;i<n;i++){
         if(max_val<arr[i])
         max_val=arr[i];
     }
     long int exp=1;
     while(exp<=max_val){
         countSort(arr,n,exp);
         exp *= 10;
     }
     */
}

int main(){
    long int n=50;
    int it=0;
    
    double best_t[6],worst_t[6],avg_t[6];

    printf("input_size\tbest_case\tWorst_case\tAverage_case\n");

    while(it<10){
        clock_t start,end;
        //for best case
        long int a[n];
        long int j=100;
        for(li i=0;i<n;i++){
          a[i]=j;
          j++;
        }

        start=clock();
        radixSort(a,n);
        end=clock();

        best_t[it]=((double)(end-start));

        //for worst case
        long int b[n];
        long int k=100;
        for(li i=n-1;i>=0;i--){
            b[i]=k;
            k++;
        }

         start=clock();
        radixSort(b,n);
        end=clock();

        worst_t[it]=((double)(end-start));

        //for average case
        long int c[n];
        srand(time(0));
        for(li i=0;i<n;i++){
            c[i]=rand()%900+100;
        }

        start=clock();
        radixSort(c,n);
        end=clock();

        avg_t[it]=(double)((end-start));

        printf("%ld\t\t %ld\t\t %ld\t\t %ld\t\t\n",n,(long int)best_t[it],(long int)worst_t[it],(long int)avg_t[it]);

        n = n*2;
        it=it+1;

    }
    return 0;
}
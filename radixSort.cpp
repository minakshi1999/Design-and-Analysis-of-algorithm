#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

void Display(vector<int>& arr){
    for(int ele : arr){
        cout<< ele << " ";
    }
}

void countsort(vector<int> &arr, int d){
    // write your code here
    vector<int>cnt(10,0);
    for(int i=0;i<arr.size();i++){
        cnt[(arr[i]/d)%10]++;
    }

    cnt[0]=cnt[0]-1;
    for(int i=1;i<cnt.size();i++){
        cnt[i] += cnt[i-1];
    }
  
    vector<int>ans(arr.size(),0);
    for(int i=arr.size()-1;i>=0;i--){
        ans[cnt[(arr[i]/d)%10]]=arr[i];
        cnt[(arr[i]/d)%10]--;
    }
    arr=ans;
    
    cout<< "After sorting on " << d << " place -> ";
    Display(arr);
    cout << endl;
}

void radixSort(vector<int> &arr){
    // write your code here
    int max_val=INT_MIN;
    for(int i=0;i<arr.size();i++){
        max_val=max(max_val,arr[i]);
    }
    int exp=1;
    while(exp<=max_val){
        countsort(arr,exp);
        exp *= 10;
    }

}


int main(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    
    for(int i = 0; i < n; i++){    
        cin >> arr[i];
    }
    
    radixSort(arr);
    Display(arr);
    return 0;
}
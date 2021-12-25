#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

void countsort(vector<int> &arr, int max, int min){
    // write your code here
    vector<int>cnt(max-min+1,0);
    for(int i=0;i<arr.size();i++){
       cnt[arr[i]-min]++;
    }
   cnt[0]=cnt[0]-1;
    for(int i=1;i<cnt.size();i++){
        cnt[i] += cnt[i-1];
    }
    vector<int>ans(arr.size(),0);
    for(int i=arr.size()-1;i>=0;i--){
       ans[cnt[arr[i]-min]]=arr[i];
       cnt[arr[i]-min]--;
    }
    for(int i=0;i<ans.size();i++){
       arr[i]=ans[i];
    }
}

void Display(vector<int>& arr){
    for(int ele : arr){
        cout<< ele << endl;
    }
}


int main(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    
    for(int i = 0; i < n; i++){    
        cin >> arr[i];
    }
    
    int maxi = (int)-1e9;
    int mini = (int)1e9;
    
    for(int i = 0; i < n; i++){
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }
    
    countsort(arr, maxi, mini);
    Display(arr);
    
}
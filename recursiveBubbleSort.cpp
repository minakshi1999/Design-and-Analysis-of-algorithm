#include<iostream>
#include<vector>

using namespace std;


void swap(vector<int>& arr, int i, int j) {
  cout << "Swapping " << arr[j] << " and " << arr[i] << endl;
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}


void Bubblesort(vector<int>& arr,int i,int n) {
  // write your code here
 if(i==n) return;
    for(int j=0;j+1<n-i;j++){
        cout<<"Comparing "<<arr[j+1]<<" and "<<arr[j]<<"\n";
       if(arr[j]>arr[j+1]) swap(arr,j,j+1);
    }
Bubblesort(arr,i+1,n);
}


void Display(vector<int>& arr) {
  for (int ele : arr) {
    cout << ele << endl;
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  Bubblesort(arr,0,n);
  Display(arr);
  return 0;
}
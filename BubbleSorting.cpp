#include<iostream>
using namespace std;

int bubbleSort(vector<int> &arr){
  int n = arr.size();

  for(int i= 0;i<n;i++){
    for(int j = 0;j<n-i-1;j++){
      if(arr[i] > arr[j]){
        swap(arr[i], arr[j]);
      }
    }
  }
  return arr;
}

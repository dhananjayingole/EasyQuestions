#include<iostream>
using namespace std;

int FindMaxMin(vector<int>& arr){
int max = arr[0];
int min = arr[0];
for(int i = 0;i<arr.size();i++){
if(arr[i] > max){
max = arr[i];
}
  if(arr[i] < min){
    min = arr[i]    
  }

  return max, min;
}
int main(){
vector<int> array = {4,5,6,8,9,7};
  int ans = FindMaxMin(array);
  return ans;

  return 0;
}

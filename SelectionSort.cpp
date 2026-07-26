#include <bits/stdc++.h>
using namespace std;

void selectionsort(vector<int>arr){
    int n = arr.size();
    
    for(int i=0;i<n-1;i++){
        int min_idx = i;
        
        for(int j = i+1;j<n;j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        
        // swap the found min ele with the first ele of unosrted array.
        
        swap(arr[i], arr[min_idx]);
        
    }
    // return arr
    
    for(int num: arr){
        cout << num <<" ";
    }
}

int main() {
	// your code goes here
	int size;
	cout<< "Size pf arr: ";
	cin>>size;
	
	vector<int>arr(size);
	
	cout<<"Enter Ele:";
	
	for(int i=0;i<size;i++){
	    cin>>arr[i];
	}
	
	selectionsort(arr);
	
	return 0;
}

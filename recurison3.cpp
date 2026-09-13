#include<bits/stdc++.h>
using namespace std;

void findSubsequences(int curr, vector<int>&arr, vector<int>&subarr, vector<vector<int>>&result){

    if(curr == arr.size()){
        result.push_back(subarr);
        return;
    }

    // Picking up of the Elements.
    subarr.push_back(arr[curr]);

    findSubsequences(curr + 1, arr, subarr, result);

    // not to take the Elements.
    subarr.pop_back();

    findSubsequences(curr+1, arr, subarr, result);
}

void findSubsequeceswithsumGiven(int curr, int sum, vector<int>&arr, vector<int>&ans, vector<vector<int>>&result, int target){

    if(curr == arr.size()){
        if(sum == target){
            result.push_back({ans});
        }
        return;
    }

    ans.push_back(arr[curr]);
    sum += arr[curr];
    findSubsequeceswithsumGiven(curr+1, sum, arr, ans, result, target);

    ans.pop_back();
    sum -= arr[curr];
    findSubsequeceswithsumGiven(curr+1, sum , arr, ans, result, target);    
}


int main(){
    vector<int>arr = {3,2,1};
    int target = 3;
    int n = arr.size();

    int summu =0;
    vector<int>subarr;
    vector<vector<int>>result;

    findSubsequences(0, arr, subarr, result);

    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }


    cout<<"Print the subsequences which are Giving the target Sum."<<endl;
    vector<int>ans;
    vector<vector<int>>result2;

    findSubsequeceswithsumGiven(0, summu, arr, ans, result2, target);
    for(int i=0;i<result2.size();i++){
        for(int j=0;j<result2[i].size();j++){
            cout<<result2[i][j]<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}

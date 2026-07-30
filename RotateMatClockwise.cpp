#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>RotateMatClockwise(vector<vector<int>>&nums){
    int n = nums.size();
    int m = nums[0].size();
    
    vector<vector<int>>result(n, vector<int>(m));
    
    // First Transpose the Matrix.
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            result[j][i] = nums[i][j];
        }
    }
    
    // reverse the rows.
    for(int i=0;i<result.size();i++){
        reverse(result[i].begin(), result[i].end());
    }
    return result;
}

int main(){
    int r, c;
    cout<<"Enter No of Rows:";
    cin>>r;
    cout<<"Enter No of Cols:";
    cin>>c;
    
    vector<vector<int>>nums(r, vector<int>(c));
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>nums[i][j];
        }
    }
    
    // print nums matrix
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums[0].size();j++){
            cout<<nums[i][j];
        }
        cout<<endl;
    }
    
    vector<vector<int>>ans = RotateMatClockwise(nums);
    
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    
    return 0;
}

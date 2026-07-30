#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>RotateMatrixAnti(vector<vector<int>>& matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<vector<int>>ans(n, vector<int>(m));
    // Reverse Each Row First.
    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
    
    // transpose
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans[j][i] = matrix[i][j];
        }
    }
    return ans;
}

int main(){
    int r, c;
    cout<<"Enter Rows:";
    cin>>r;
    cout<<"Enter Cols:";
    cin>>c;
    
    vector<vector<int>>matrix(r, vector<int>(c));
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>matrix[i][j];
        }
    }
    
    vector<vector<int>>result = RotateMatrixAnti(matrix);
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<result[i][j];
        }
        cout<<endl;
    }
    
    return 0;
}

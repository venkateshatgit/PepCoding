#include <bits/stdc++.h>
using namespace std;

bool targetSumSubset(int n, int index, vector<int> arr, int sum, int tar, int** dp) {

    if(sum == tar)
        return 1;

    if(n==0 || sum>tar)
        return 0;

    if(dp[n][sum]>-1)
        return dp[n][sum];
    
    int left = targetSumSubset(n-1, index+1, arr, sum, tar, dp); 
    int right = targetSumSubset(n-1, index+1, arr, sum+arr[index], tar, dp);

    dp[n][sum] = left || right;

    return dp[n][sum];
}


int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++) {
    cin >> arr[i];
    }
    int tar;
    cin >> tar;


    int **dp;
    dp = new int* [n+1];
    for(int i=0; i<=n; ++i)
        dp[i] = new int[tar+1];


    for(int i=0; i<=n; ++i){
        for(int j=0; j<=tar; ++j){
            dp[i][j]=-1;
        }  
    }

    cout<<targetSumSubset(n, 0, arr, 0, tar, dp)<<endl;

    for(int i=0; i<n; ++i)
        delete [] dp[i];
    delete [] dp;

    return 0;
}
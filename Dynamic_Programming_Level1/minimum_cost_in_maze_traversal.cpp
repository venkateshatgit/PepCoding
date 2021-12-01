#include <bits/stdc++.h>
using namespace std;

/* 
Just fill the dp for all down and right edge values,
and make decision for minimum of (down,right) + arr[i][j]
*/

//recursion solution
int minCost(int n, int m, int r, int c, vector<vector<int>>& arr, vector<vector<int>>& dp ) {

    if(r>=n || c>=m)
        return INT_MAX;
    
    if(r==n-1 && c==m-1)
        return arr[r][c];
    
    if(dp[r][c]!=-1)
        return dp[r][c];

    int down = minCost(n, m, r+1, c, arr, dp);
    int right = minCost(n, m, r, c+1, arr, dp);
    
    dp[r][c] = arr[r][c] + min(down, right);

    return dp[r][c];
}

int main(){

  int n;
  int m;

  cin >> n >> m;

  vector<vector<int>> arr(n, vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  vector<vector<int>> dp(n, vector<int>(m, -1));

  cout << minCost(n, m, 0, 0, arr, dp)<<endl;

  return 0; 
}
#include <bits/stdc++.h>

using namespace std;

//use loop

int collectGold(int n, int m, vector<vector<int>>& arr, vector<vector<int>>& dp) {

    //write your code here

    for(int i=0; i<n; ++i){
        dp[i][m-1]=arr[i][m-1];
    }        

    for(int j=m-2; j>=0; j--){
        for(int i=0; i<n; ++i){

            if(i==0){
                dp[i][j]=arr[i][j] + max(dp[i][j+1], dp[i+1][j+1]);
            }

            else if(i==n-1){
                dp[i][j]=arr[i][j] + max(dp[i-1][j+1], dp[i][j+1]);
            }

            else{
                dp[i][j]=arr[i][j] + max(dp[i][j+1], max(dp[i+1][j+1], dp[i-1][j+1]));
            }
        }
    }

    int ans=0;
    for(int i=0; i<n; ++i){
        ans = max(ans, dp[i][0]);
    }

    return ans;
}



int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> arr(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  vector<vector<int>> dp(n, vector<int>(m, 0));

  cout << collectGold(n, m, arr, dp)<<endl;

  return 0;

}
#include <bits/stdc++.h>
using namespace std;
void display(vector<int>a) {
  for (int i = 0; i < a.size(); i++)
  {
    cout << a[i] << endl;
  }
}

vector<int> solve(vector<int>arr)
{
    vector <int> output(arr.size(), 0);
    stack <int> s;
    for(int i=arr.size()-1; i>=0; --i){
        
        while(!s.empty() && arr[i] >= s.top()){
            s.pop();
        }

        if(s.empty())
            output[i]=-1;
        else
            output[i]=s.top();
        
        s.push(arr[i]);
    }

    return output;
}

int main(int argc, char** argv)
{
  int n;
  cin >> n;
  vector<int>arr(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  vector<int>nge(n, 0);
  nge = solve(arr);
  display(nge);
  return 0;
}
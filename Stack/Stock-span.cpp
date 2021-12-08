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
    vector <int> output(arr.size(), 1);
    stack <int> s;
    
    for(int i=0; i<arr.size(); ++i){

        while(!s.empty() && arr[i]>arr[s.top()])
            s.pop();
        
        if(s.empty()){
            output[i]+=i;
        }
        else{
            output[i] = i-s.top();
        }

        s.push(i);
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
  vector<int>span(n, 0);
  span = solve(arr);
  display(span);
  return 0;
}
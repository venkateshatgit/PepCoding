#include <bits/stdc++.h>
using namespace std;

int fib(int n, int* arr){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    
    if(arr[n]>-1)
        return arr[n];
    
    int sum = fib(n-1, arr) + fib(n-2, arr);

    arr[n] = sum;

    return sum; 
}

int main(){
    
    int n;
    cin>>n;
    int *arr = new int[n+1];
    for(int i=0; i<=n; ++i)
        arr[i]=-1;
    
    //Using Recusion
    cout<<fib(n, arr)<<endl;

    delete [] arr;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

/*
You are given a number n, representing the number of stairs in a staircase.
You are on the 0th step and are required to climb to the top.
In one move, you are allowed to climb 1, 2, or 3 stairs.
You are required to print the number of different paths via which you can climb to the top.
*/


int climb(int stairs, int* store){

    if(stairs < 0)
        return 0;
    
    if(stairs == 0)
        return 1;

    if(store[stairs]>-1)
        return store[stairs];

    //steps are 1, 2, 3

    int ans = climb(stairs-1, store) + climb(stairs-2, store) + climb(stairs-3, store); 
    store[stairs] = ans;

    return ans; 
}

int main(){

    int stairs;
    cin>>stairs;

    int *store = new int[stairs+1];
    for(int i=0; i<=stairs; ++i)
        store[i]=-1;

    cout<<climb(stairs, store)<<endl;

    delete [] store;
    return 0;
}
/*Description
Given a fibonacci sequence a[0], a[1], a[2], ... in which:  a[0] = 0, a[1] = 1, a[n] = a[n-1] + a[n-2], for all n >= 2
Given  positive integer n, compute a[n-1].
Input
Line 1: contains a positive integer n (2 <= n <= 21)
Output
Write a[n-1]
Example
Input
9
Output
21*/
#include <bits/stdc++.h> 
using namespace std;
//C++ 
int Fb(int n){
    if(n<=1){
        return n;
    }
    vector<int> fib(n+1);//we use dp technique by using an array to store the value
    fib[0]=0;
    fib[1]=1;
    for(int i=2; i<=n; i++){
    fib[i]=fib[i-1]+fib[i-2];
    }
        return fib[n-1];
    /*anyway there are better idea to solve this which is store two variables prev and curr with initial
    state is 0 and 1*/
}
int main() 
{ 
    int test;
    cin>>test;
    cout<<Fb(test);
}

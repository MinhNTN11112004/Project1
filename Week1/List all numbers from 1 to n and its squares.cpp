/*Description
Given an integer n, print numbers from 1 to n and its squares.
Input
Line 1: contains a positive integer n (1 <= n <= 100)
Output
Each line i (i = 1,...,n): contains i and i^2 (elements are separated by one SPACE character)
Example
Input
3
Output
1 1
2 4
3 9*/
//C++ 
#include <bits/stdc++.h> 
using namespace std;
int main() 
{  
   int n;
   cin>>n;
   int i=1;
   while(n){
       cout<<i<<" "<<i*i<<endl;
       i++;
       n--;
   }
    
}

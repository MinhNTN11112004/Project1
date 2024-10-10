/*Description
Given a sequence of integer a1, a2, ..., an. Count the number of odd elements and even elements of the sequence.
Input
Line 1: contains a positive integer n (1 <= n <= 100000)
Line 2: contains a1, a2, ..., an. (1 <= ai <= 1000000)
Output
Write the number of odd elements and the number of even elements (separated by a SPACE character)
Example 
Input 
6
2 3 4 3 7 1
Output 
4 2*/
//C++ 
#include <bits/stdc++.h> 
using namespace std;
int main() 
{
    int n, odd=0, even=0;
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    for(int i=0; i<n; i++){
       if(A[i]%2) odd++;
       else even++;
    }
    cout<<odd<<" "<<even;
}

/*Description
Given an integer n, write a program that generates all binary sequences without consecutive 11 in a lexicographic order.
Input
Line 1: contains an integer n (1 <= n <= 20)
Output
Write binary sequences in a lexicographic order, each sequence in a line
Example
Input
3
Output
000
001
010
100
101*/
//C++ 
#include <bits/stdc++.h> 
using namespace std;
void generate_sequence(int &k, const string &sequence){
    if(sequence.length()==k){
        cout<<sequence<<endl;
        return ;
    }
    generate_sequence(k, sequence+'0');
    if(sequence.empty()||sequence.back()!='1'){
        generate_sequence(k, sequence+'1');
    }
}
int main() 
{ 
    int n;
    cin>>n;
    generate_sequence(n, "");
}

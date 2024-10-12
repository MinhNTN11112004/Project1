/*Description
Given an integer n, write a program to generate all permutations of 1, 2, ..., n in a lexicalgraphic order (elements of a permutation are separated by a SPACE character).
Example
Input 
3
Output
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 1 2 
3 2 1*/
//C++ 
#include <bits/stdc++.h> 
using namespace std;
void permutation(vector<int> &num, vector<bool> &check, vector<int> &current){
    if(current.size()==num.size()){
        for(int num:current){
            cout<<num<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=0; i<num.size(); i++){
        if(!check[i]){
            current.push_back(num[i]);
            check[i]=true;
            permutation(num,check,current);
            check[i]=false;
            current.pop_back();
        }
    }
}
int main() 
{ 
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=1; i<=n; i++){
        v[i-1]=i;
    }
    std::vector<bool> check(n, false); 
    std::vector<int> current;
    permutation(v, check, current); 
}

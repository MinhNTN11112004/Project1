/*Description
Given an integer n, write a program that generates all the binary sequences of length n in a lexicographic order.
Input
Line 1: contains an integer n (1 <= n <= 20)
Output
Write binary sequences in a lexicographic ordder, eac sequence in a line
Example
Input
3
Output
000
001
010
011
100
101
110
111*/
#include<bits/stdc++.h> 
using namespace std;
void f(int n) {
    int total = 1 << n; 
    for (int i = 0; i < total; ++i) {
        cout << setw(n) << setfill('0') << bitset<32>(i).to_string().substr(32 - n) << endl;
    }
}
int main() {
    int n;
    cin >> n;
    f(n);
    return 0;
}

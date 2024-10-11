/*Description
Given two positive integers k and n. Compute C(k,n) which is the number of ways to select k objects from a given set of n objects.
Input
Line 1: two positive integers k and n (1 <= k,n <= 999)
Output
Write te value C(k,n) modulo 109+7.
Example
Input
3  5
Output
10*/
//C++ 
#include <iostream> 
#include <vector>
using namespace std;
const int modulo=1e9+7;
//su dung dinh ly fermat little theorem
long long nghichdao(long long a, long long p){
    long long res=1;
    long long mu=p-2;
    while(mu){
        if(mu%2==1){
            res=res*a%p;
        }
        a=(a*a)%p;
        mu=mu/2;
    }
    return res;
}
//tinh ham so
long long C(int k, int n) {
    if (k > n) return 0;
    vector<long long> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = (fact[i - 1] * i) % modulo;
    }
    long long x = fact[n];
    long long y = (fact[k] * fact[n - k]) % modulo;
    return (x * nghichdao(y,modulo)) % modulo;
}
int main() 
{ 
   int n,k;
   cin>>k>>n;
   cout<<C(k,n);
}

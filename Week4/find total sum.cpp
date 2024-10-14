//C++ 
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main() 
{ 
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    unordered_map<int, int> seen;
    int count=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        int sub=m-a[i];
        if(seen.find(sub)!=seen.end()){
            count+=seen[sub];
        }
        seen[a[i]]++;
    }
    cout<<count<<endl;
    return 0;
}

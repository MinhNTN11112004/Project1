/* Description
Given a sequence of integers a1, a2, ..., an. Perform a sequence of queries over this sequence including:
find-max: return the maximum element of the given sequence
find-min: return the minimum element of the given sequence 
sum: return the sum of the elements of the given sequence 
find-max-segment i j: return the maximum element of the subsequence from index i to index j (i <= j)
Input
The first block contains the information about the given sequence with the following format:
Line 1: contains a positive integer n (1 <= n <= 10000)
Line 2: contains n integers a1, a2, ..., an (-1000 <= ai <= 1000)
The first block is terminated by a character *
The second block contains a sequence of queries defined above, each query is in a line. The second block is terminated a 3 characters ***
Output
Write the result of each query in a corresponding line
Example
Input
5
1 4 3 2 5
*
find-max
find-min
find-max-segment 1 3
find-max-segment 2 5
sum
***
Output
5
1
4
5
15*/
//C++ 
#include <bits/stdc++.h> 
using namespace std;
int main() 
{ 
   int n;
   char kitu;
   cin>>n;
   vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
   cin>>kitu;
   string command, quit;
    cin.ignore(); 
   while(getline(cin,command)&&quit!="***"){
       if(command=="find-max"){
           int max=A[0];
           for(int num:A){
               if(max<num){
                max=num;
               }
           }
           cout<<max<<endl;
       }else if(command=="find-min"){
           int min=A[0];
           for(int num:A){
               if(min>num){
                min=num;
               }
           }
           cout<<min<<endl;
       }else if(command=="sum"){
           int sum=0;
           for(int num:A){
               sum=sum+num;
           }

           cout<<sum<<endl;
       }else if (command.substr(0, 16) == "find-max-segment"){
           int k,j;
           stringstream ss(command);
           string temp;
           ss>>temp>>k>>j;
           int max1=A[k-1];
           for(int i=k-1; i<j;i++){
            if(max1<A[i]){
                max1=A[i];
            }
           }
           cout<<max1<<endl;
       }
   }
}

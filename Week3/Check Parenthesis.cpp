/*Description
Given a string containing only characters (, ), [, ] {, }. Write a program that checks whether the string is correct in expression.
Example
 ([]{()}()[]): correct
 ([]{()]()[]): incorrect
Input
One line contains the string (the length of the string is less than or equal to $10^6$)One line contains the string (the length of the string is less than or equal to 10
6
)
Output
Write 1 if the sequence is correct, and write 0, otherwise
Example
Input
(()[][]{}){}{}[][]({[]()})
Output
1*/
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;
int main()
{
    string s;
    cin>>s;
    stack<char> s1;
    unordered_map<char,char> parenthesis{
        {')','('},
        {'}','{'},
        {']','['}
    };
    for(char c:s){
        if(c=='('||c=='{'||c=='['){
            s1.push(c);
        }else if(c==')'||c=='}'||c==']'){
            if(s1.empty()||s1.top()!=parenthesis[c]){
                cout<<0<<endl;
                return 0;
            }
            s1.pop();
        }
    }
    if(s1.empty()){
        cout<<1<<endl;
    }else{
        cout<<0<<endl;
    }

    return 0;
}

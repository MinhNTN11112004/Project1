/*Description
Perform a sequence of operations over a stack, each element is an integer:
PUSH v: push a value v into the stack
POP: remove an element out of the stack and print this element to stdout (print NULL if the stack is empty)
Input
Each line contains a command (operration) of type 
PUSH  v
POP
Output
Write the results of POP operations (each result is written in a line)*/
#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    stack<int> s;
    string s1;
    while(1==1){
        getline(cin, s1);
        if(s1=="#"){
            break;
        }
        if(s1.substr(0,5)=="PUSH "){
            int value= stoi(s1.substr(5));
            s.push(value);
        }else if(s1=="POP"){
            if(!s.empty()){
                cout<<s.top()<<endl;
                s.pop();
            }else{
                cout<<"NULL"<<endl;
            }
        }
    } 
    return 0;
}
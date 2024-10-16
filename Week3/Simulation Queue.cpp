/*Description
Perform a sequence of operations over a queue, each element is an integer:
PUSH v: push a value v into the queue
POP: remove an element out of the queue and print this element to stdout (print NULL if the queue is empty)
Input
Each line contains a command (operration) of type
PUSH  v
POP
Output
Write the results of POP operations (each result is written in a line)
Example
Input
PUSH 1
PUSH 2
PUSH 3
POP
POP
PUSH 4
PUSH 5
POP
#
Output
1
2
3
Input
PUSH 1
POP
POP
PUSH 4
POP
#
Output
1
NULL
4*/
#include<iostream>
#include<queue>
#include<string>
using namespace std;
int main(){
    queue<int> s;
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
                cout<<s.front()<<endl;
                s.pop();
            }else{
                cout<<"NULL"<<endl;
            }
        }
    } 
    return 0;
}

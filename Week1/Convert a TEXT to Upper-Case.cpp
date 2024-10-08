/*Description
Given a TEXT, write a program that converts the TEXT to upper-case. 
Input
The TEXT
Output
The TEXT in which characters are converted into upper-case
Example 
Input 
Hello John,
How are you?
Bye,
Output 
HELLO JOHN,
HOW ARE YOU?
BYE,*/
//C++ 
#include <bits/stdc++.h> 
using namespace std;
int main() 
{ 
	string line;
    while (getline(cin, line)) {
        for(int i=0; i<line.size(); i++){
		if(line[i]>='a'&&line[i]<='z'){
			line[i]-=32;
		}
	}
    cout<<line<<endl;
    }
}

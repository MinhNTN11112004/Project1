/*Description
Given a time moment which is a string under the format hh:mm:ss (in which hh (0 <= hh <= 23) is the hour, mm (0 <= mm <= 59) is the minute, and ss (0 <= ss <= 59) is the second). Convert this time moment in seconds (result = hh*3600 + mm*60 + ss).
Input
Line 1: contains a string s representing the time moment.  
Output
if s is not under the format hh:mm:ss, then write INCORRECT. Otherwise, write value converted.
Example
Input
13:05:26
Output
47126
Input
13:05:6
Output
INCORRECT 
Input
13:05 26
Output
INCORRECT*/
#include<bits/stdc++.h>
using namespace std;
string f(const string& s) {
    if (s.length() != 8) {
        return "INCORRECT";
    }
    if (s[2] != ':' || s[5] != ':' || 
        !isdigit(s[0]) || !isdigit(s[1]) || 
        !isdigit(s[3]) || !isdigit(s[4]) || 
        !isdigit(s[6]) || !isdigit(s[7])) {
        return "INCORRECT";
    }
    int hh = stoi(s.substr(0, 2));
    int mm = stoi(s.substr(3, 2));
    int ss = stoi(s.substr(6, 2));
    if (hh < 0 || hh > 23 || mm < 0 || mm > 59 || ss < 0 || ss > 59) {
        return "INCORRECT";
    }
    int seconds = hh * 3600 + mm * 60 + ss;
    return to_string(seconds);
}
int main() {
    string text;
    getline(cin, text);
    cout << f(text) << endl;
    return 0;
}



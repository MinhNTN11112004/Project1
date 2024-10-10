/*Description
Given a date which is a string under the format YYYY-MM-DD (in which YYYY is the year, MM is the month (the month í from 1 to 12), and DD is the date (the date is from 1 to 31)). Extract the year, month and date.
Input
Line 1: contains a string s  
Output
if s is not under the format YYYY-MM-DD, then write INCORRECT. Otherwise, write year, month, and date separated by a SPACE character
Example
Input
2023-10-04
Output
2023 10 4
Input
2023-10-4
Output
INCORRECT 
Input
2023-10 04
Output
INCORRECT*/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
string extractDate(const string& s) {
    if (s.length() != 10) {
        return "INCORRECT";
    }
    if (s[4] != '-' || s[7] != '-' || 
        !isdigit(s[0]) || !isdigit(s[1]) || !isdigit(s[2]) || !isdigit(s[3]) ||
        !isdigit(s[5]) || !isdigit(s[6]) ||
        !isdigit(s[8]) || !isdigit(s[9])) {
        return "INCORRECT";
    }
    string year = s.substr(0, 4);
    string month = s.substr(5, 2);
    string day = s.substr(8, 2);
    int monthInt = stoi(month);
    int dayInt = stoi(day);
    if (monthInt < 1 || monthInt > 12 || dayInt < 1 || dayInt > 31) {
        return "INCORRECT";
    }
    return year + " " + to_string(monthInt) + " " + to_string(dayInt);
}

int main() {
    string input;
    getline(cin, input);
    cout << extractDate(input) << endl;
    
    return 0;
}

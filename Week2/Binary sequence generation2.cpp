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
//C++ 
#include <iostream>
#include <string>
void generate_sequences(int n, const std::string& current_sequence) {
    if (current_sequence.length() == n) {
        std::cout << current_sequence << std::endl;
        return;
    }
    generate_sequences(n, current_sequence + "0");
    generate_sequences(n, current_sequence + "1");
}
int main() {
    int n;
    std::cin >> n;
    generate_sequences(n, "");
    return 0;
}

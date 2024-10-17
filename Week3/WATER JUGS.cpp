/*Description
There are two jugs, a-litres jug and b-litres jug (a, b are positive integers). There is a pump with unlimited water. Given a positive integer c, how to get exactly c litres.
Input
   Line 1: contains positive integers a,   b,  c  (1 <= a, b, c <= 900)
Output
  write the number of steps or write -1 (if no solution found)
Example

Input
6  8  4
Output
4*/
#include <iostream>
#include <queue>
#include <set>
#include <tuple>
using namespace std;
int gcd(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}
int canMeasure(int a, int b, int c) {
    if (c > max(a, b)) {
        return -1;
    }
    if (c % gcd(a, b) != 0) {
        return -1;
    }
    queue<tuple<int, int, int>> q; 
    set<pair<int, int>> visited;    
    q.push(make_tuple(0, 0, 0));     
    visited.insert(make_pair(0, 0));
    while (!q.empty()) {
        auto [x, y, steps] = q.front();
        q.pop();
        if (x == c || y == c) {
            return steps;
        }
        vector<tuple<int, int>> nextStates = {
            {a, y},                       
            {x, b},                       
            {0, y},                       
            {x, 0},                       
            {max(0, x - (b - y)), min(b, y + x)}, 
            {min(a, x + y), max(0, y - (a - x))}  
        };
        for (const auto& state : nextStates) {
            int newA = get<0>(state);
            int newB = get<1>(state);
            if (visited.find(make_pair(newA, newB)) == visited.end()) {
                visited.insert(make_pair(newA, newB));
                q.push(make_tuple(newA, newB, steps + 1));
            }
        }
    }
    return -1; 
}
int main() {
    int a, b, c;
    cin >> a >> b >> c; 
    cout << canMeasure(a, b, c) << endl; 
    return 0;
}

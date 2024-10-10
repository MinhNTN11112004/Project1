/*Description
Given an equation ax^2 + bx + c = 0. Find solution to the given equation.
Input
Line 1 contains 3 integers a, b, c 
Output
Write NO SOLUTION if the given equation has no solution 
Write x0 (2 digits after the decimal point) if the given equation has one solution x0 
Write x1 and x2 with x1 < x2 (2 digits after the decimal point) if the given equation has two distinct solutions x1, x2 
Example
Input 
1 1 8
Output 
NO SOLUTION*/
#include<bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    double D = b * b - 4 * a * c;
    if (D < 0) {
        cout << "NO SOLUTION" << endl; 
    } else if (D == 0) {
        double x0 = -b / (2.0 * a);
        cout << fixed << setprecision(2) << x0 << endl;
    } else {
        double sqrtD = sqrt(D);
        double x1 = (-b - sqrtD) / (2.0 * a);
        double x2 = (-b + sqrtD) / (2.0 * a);
        if (x1 > x2) {
            swap(x1, x2);
        }
        cout << fixed << setprecision(2) << x1 << " " << x2 << endl;
    }
    return 0;
}

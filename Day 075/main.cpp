/*
    Title: Power Function using Exponentiation by Squaring method

    Problem Statement:
        - Implement a function to calculate b^e (b raised to power e), where:
            - b is a floating point number (base)
            - e is an integer (exponent)
        - Handle negative exponents correctly.

    Approach:
        - Use recursion with exponentiation by squaring:
            - If e is 0, return 1.
            - If e is negative, return 1 / power(b, -e).
            - Recur with power(b, e/2), then square the result.
            - Multiply by b if e is odd.

    Time Complexity:
        - O(log e)

    Space Complexity:
        - O(log e) due to recursion stack

    Author: Vishal Singhaniya
*/

#include <iostream>
using namespace std;

// Efficient power function (handles negative exponents)
float power(float b, int e) {
    if (e == 0) return 1;
    if (e < 0) return 1 / power(b, -e);

    float temp = power(b, e / 2);

    if (e % 2 == 0)
        return temp * temp;
    else
        return temp * temp * b;
}

int main() {
    float b = 0.2;
    int e = 5;

    cout << b << "^" << e << " = " << power(b, e) << endl;
    return 0;
}

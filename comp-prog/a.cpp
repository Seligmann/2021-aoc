#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int c;
    cin >> c;
    while (c--) {
        int octal, binaryNum, decimal = 0, product = 0;
        long long binary = 0;
        cin >> octal;

        while(octal != 0) {
            decimal += (octal%10) * pow(8,product);
            ++product;
            octal /= 10;
        }

        product = 1;
        while (decimal != 0) {
            binary += (decimal % 2) * product;
            decimal /= 2;
            product *= 10;
        }
        cout << binary;

    }
}



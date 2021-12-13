#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
    // p1
    int sarr[2000];
    int count = 0;
    ifstream file("yo.txt");
    if (file.is_open()) {
        for (int i = 0; i < 2000; i++) {
            file >> sarr[i];
        }
    }
    for (int i = 1; i < 2000; i++) {
        if (sarr[i] > sarr[i-1])
            count++;
    }
    
    cout << count << '\n';

    // p2
    count = 0;
    for (int i = 0; i < 2000-3; i++) {
        if ((sarr[i] + sarr[i+1] + sarr[i+2]) < (sarr[i+1] + sarr[i+2] + sarr[i+3]))
            count++;
    }
    cout << count << '\n';
}

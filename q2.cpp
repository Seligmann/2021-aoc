#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main () {
    // p1
    int x = 0, y = 0;
    string line;
    string arr[2000];

    ifstream myfile("myFile.txt");
    if (myfile.is_open()) {
        for (int i = 0; i < 2000; i++) {
            myfile >> arr[i];
        }
    }
    myfile.close();

    for (int i = 0; i < 2000-1; i+=2) {
        stringstream iInt(arr[i+1]);
        int iLength;
        iInt >> iLength;
        if (arr[i].compare("forward")==0)
            x += iLength;
        else if (arr[i].compare("up")==0)
            y -= iLength;
        else if (arr[i].compare("down")==0)
            y += iLength;

    }
    cout << "p1: " << x*y << '\n';

    // p2
    x = 0;
    y = 0;
    int aim = 0;

    for (int i = 0; i < 2000-1; i+=2) {
        stringstream tmpInt(arr[i+1]);
        int X;
        tmpInt >> X;
        if (arr[i].compare("down") == 0)
            aim += X;
        else if (arr[i].compare("up") == 0)
            aim -= X;
        else if (arr[i].compare("forward") == 0) {
            x += X;
            y += aim * X;
        }
    }
    cout << "p2: " << x*y << '\n';

    
}

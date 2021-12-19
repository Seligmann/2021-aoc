#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <typeinfo>
#include <iterator>
#include <algorithm>
#include <bitset>
#include <array>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <forward_list>
#include <vector>
#include <cmath>
#include <stdexcept>

typedef long unsigned int lu;
typedef long long int ll;
typedef long long unsigned int llu;

using namespace std;

int partOne();
int partTwo();

int main () {
    cout << partOne() << '\n';
    cout << partTwo() << '\n';
}

int partOne() {
    map<int, int> m;
    ifstream fin("input.txt");
    string line;
    int max = -1147483647;
    int min = 2147483647;
    while (getline(fin, line, ',')) {
        stringstream ss(line);
        int tmp;
        ss >> tmp;
        min = (tmp < min) ? tmp : min;
        max = (tmp > max) ? tmp : max;
        m[tmp]++;
    }

    int minCount = 2147483647;
    for (int i = min; i <= max; i++) {
        int tmpCount = 0;
        for (auto &it: m) {
            tmpCount += (it.second * abs(it.first - i));
        }
        if (tmpCount <= minCount)
            minCount = tmpCount;
    }
    return minCount;
    
}


int partTwo() {
    map<int, int> m;
    ifstream fin("input.txt");
    string line;
    int max = -1147483647;
    int min = 2147483647;
    while (getline(fin, line, ',')) {
        stringstream ss(line);
        int tmp;
        ss >> tmp;
        min = (tmp < min) ? tmp : min;
        max = (tmp > max) ? tmp : max;
        m[tmp]++;
    }

    int minCount = 2147483647;
    for (int i = min; i <= max; i++) {
        int tmpCount = 0;
        for (auto &it: m) {
            int tmp = 0;
            for (int j = 1; j <= abs(it.first - i); j++) {
                tmp += 1 * j;
            }
            tmpCount += it.second * tmp;
        }
        if (tmpCount <= minCount)
            minCount = tmpCount;
    }
    return minCount;

}


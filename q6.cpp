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
llu partTwo();

int main () {
    cout << partOne() << '\n';
    cout << partTwo() << '\n';
}

int partOne() {
    int t = 80;
    ifstream fin("input.txt");
    string line;
    vector<int> nums;
    while (getline(fin, line)) {
        string tmp = line;
        for (int i = 0; i < tmp.length(); i+=2)
            nums.push_back(line[i] - '0');
    }

    int count = nums.size();
    for (int i = 0; i < t; i++) {
        int sizeBeforePush = nums.size();
        for (int j = 0; j < sizeBeforePush; j++) {
            if (nums[j] == 0) { 
                nums[j] = 6;
                nums.push_back(8);
                count++;
            } 
            else
                nums[j]--;
        }
    }
    return count;
    
}




llu partTwo() {
    map<int, llu> m;
    ifstream fin("input.txt");
    string line;
    while (getline(fin, line)) {
        string tmp = line;
        for (int i = 0; i < tmp.length(); i+=2) {
            m[tmp[i] - '0']++;
        }
    }

    for (int i = 0; i < 256; i++) {
        map<int, llu> M;
        for (map<int, llu>::iterator it = m.begin(); it != m.end(); it++) {
            if (it->first == 0) {
                M[8] += it->second;
                M[6] += it->second;
            }
            else {
                M[(it->first)-1] += it->second;
            }
        }
        m = M;
    }

    llu count = 0;
    for (map<int, llu>::iterator it = m.begin(); it != m.end(); it++) {
        count += it->second;
    }
    return count;
}


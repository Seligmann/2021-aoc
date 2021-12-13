#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <typeinfo>
#include <iterator>
#include <algorithm>
#include <bitset>
#include <array>
#include <vector>
typedef long unsigned int lu;
typedef long long int ll;
typedef long long unsigned int llu;
using namespace std;

void partOne();
void partTwo();

int main () {
    partOne();
    partTwo();
}

void partOne() {
    string str[1000];
    string oxy[1000];
    string carbon[1000];
    int arr[12];
    char g[] = "000000000000";
    char e[] = "000000000000";

    ifstream myfile("myFile.txt");
    if (myfile.is_open()) {
        for (int i = 0; i < 1000; i++) {
            myfile >> str[i];
        }
    }
    myfile.close();

    for (int i = 0; i < sizeof(str)/sizeof(str[0]); i++) {
        for (int j = 0; j < sizeof(arr)/sizeof(arr[0]); j++) {
            if (str[i][j] > '0') { 
                arr[j]++;
            }
        }
    }

    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) { 
        if (arr[i] > 500) {
            g[i] = '1';
        }
        else {
            e[i] = '1';
        }
    }
    cout << "Part one: " << strtoull(g, NULL, 2) * strtoull(e, NULL, 2) << '\n';

}

void partTwo() {
lu checkOxy, checkCo;
    const int b = 12;
    vector<bitset<b>> diags;
    lu oxyCounts[b];
    lu coCounts[b];

    ifstream fin("myFile.txt");
    string line;
    while (fin >> line) {
        diags.push_back(bitset<b>(line));
    }

    vector<bitset<b>> oxy(diags);
    vector<bitset<b>> co(diags);

    // initial 1's count
    int counting = 0;
    for (lu i = 0; i < b; i++) {
        for (lu j = 0; j < diags.size(); j++) {
            if (diags[j][b-i-1]) {
                counting++;
            }
        }
        oxyCounts[i] = counting;
        coCounts[i] = counting;
        counting = 0;
    }

    // o2
    for (lu i = b-1; i >= 0 && oxy.size() > 1; i--) {
        if (oxy.size() % 2 == 0) {
            if (oxyCounts[b-i-1] >= oxy.size() / 2)
                checkOxy = 1;
            else
                checkOxy = 0;
        } else {
            if (oxyCounts[b-i-1] >= 1 + oxy.size() / 2)
                checkOxy = 1;
            else
                checkOxy = 0;
        }
        for (lu j = 0; j < oxy.size(); j++) {
            bitset<b> tmp = oxy[j];
            if (checkOxy != tmp[i]) {
                for (int k = b-1; k >= 0; k--) { // undo count amount
                        oxyCounts[b-k-1] -= oxy[j][k];
                }
                oxy.erase(oxy.begin()+j);
                j--;
            }

        }
    }

    // co2
    for (lu i = b-1; i >= 0 && co.size() > 1; i--) {
        if (co.size() % 2 == 0) {
            if (coCounts[b-i-1] >= co.size() / 2)
                checkCo = 0;
            else
                checkCo = 1;
        } else {
            if (coCounts[b-i-1] > co.size() / 2)
                checkCo = 0;
            else
                checkCo = 1;
        }
        for (lu j = 0; j < co.size(); j++) {
            bitset<b> tmp = co[j];
            if (checkCo != tmp[i]) {
                for (int k = b-1; k >= 0; k--) {
                        coCounts[b-k-1] -= co[j][k];
                }
                co.erase(co.begin()+j);
                j--;
            }
        }
    }

    cout << "Part two: " << oxy[0].to_ulong() * co[0].to_ulong() << '\n';
}

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
    int si;
    vector<string> boards;
    int nums[] = {90,4,2,96,46,1,62,97,3,52,7,35,50,28,31,37,74,26,59,53,82,47,83,80,19,40,68,95,34,55,54,73,12,78,30,63,57,93,72,77,56,91,23,67,64,79,85,84,76,10,58,0,29,13,94,20,32,25,11,38,89,21,98,92,42,27,14,99,24,75,86,51,22,48,9,33,49,18,70,8,87,61,39,16,66,71,5,69,15,43,88,45,6,81,60,36,44,17,41,65};

    ifstream fin("input.txt");
    string line;
    int a = 0;
    while (fin >> line) {
        if (a == 0) ;
        else
            boards.push_back(line);
        a++;
    }
    
    for (int i = 0; i < sizeof(nums)/sizeof(nums[0]); i++) {
        for (int j = 0; j < boards.size(); j++) {
            stringstream ss(boards[j]);
            ss >> si;
            if (si == nums[i]) { // find matches and mask
                boards[j] = "x";
                
                // check bingo

                for (int k = 0; k < boards.size()-4 ; k+=5) { // check rows
                    if (boards[k].compare("x")==0 && boards[k+1].compare("x")==0 && boards[k+2].compare("x")==0 && boards[k+3].compare("x")==0 && boards[k+4].compare("x")==0) {
                        int sum = 0;
                        if (k % 25 == 0 || k == 0) {
                            for (int l = k; l < k+25; l++) {
                                stringstream ss(boards[l]);
                                ss >> si;
                                sum += si;
                            }
                        } else {
                            int start = (k / 25) * 25;
                            for (int l = start; l < start+25; l++) {
                                cout << "start: " << start << '\n';
                                if (boards[l].compare("x")==0)
                                        continue;
                                stringstream ss(boards[l]);
                                ss >> si;
                                sum += si;
                            }
                        }
                        cout << "ans: " << sum * nums[i] << '\n';
                        return;

                    }
                }

                int tmpEnd = 4;
                int tmpStart = 0;
                for (int k = tmpStart; k <= tmpEnd && k < boards.size()-20; k++) { // check columns
                    if (boards[k].compare("x")==0 && boards[k+5].compare("x")==0 && boards[k+10].compare("x")==0 && boards[k+15].compare("x")==0 && boards[k+20].compare("x")==0) {
                        int sum=0;
                        for (int s = tmpStart; s < tmpStart+25; s++) {
                            if (boards[s].compare("x")==0)
                                    continue;
                            stringstream ss(boards[s]);
                            ss >> si;
                            sum += si;
                        }
                        cout <<"ans: " << sum * nums[i] << '\n';
                        return;
                    } 
                    else if (k == tmpEnd) {
                        tmpStart += 25;
                        k += -4+24;
                        tmpEnd += 25;
                    }
                }
            }
        }
    }
}


void partTwo() {
    int si;
    vector<string> boards;
    int nums[] = {90,4,2,96,46,1,62,97,3,52,7,35,50,28,31,37,74,26,59,53,82,47,83,80,19,40,68,95,34,55,54,73,12,78,30,63,57,93,72,77,56,91,23,67,64,79,85,84,76,10,58,0,29,13,94,20,32,25,11,38,89,21,98,92,42,27,14,99,24,75,86,51,22,48,9,33,49,18,70,8,87,61,39,16,66,71,5,69,15,43,88,45,6,81,60,36,44,17,41,65};

    ifstream fin("input.txt");
    string line;
    int a = 0;
    while (fin >> line) {
        if (a == 0) ;
        else
            boards.push_back(line);
        a++;
    }
    bool doneFlags[boards.size()/25];
    for (int i = 0; i < boards.size()/25; i++) doneFlags[i] = false;
    
    for (int i = 0; i < sizeof(nums)/sizeof(nums[0]); i++) {
        for (int j = 0; j < boards.size(); j++) {
            stringstream ss(boards[j]);
            ss >> si;
            if (si == nums[i]) { // find matches and mask
                boards[j] = "x";
                
                // check bingo

                for (int k = 0; k < boards.size()-4 ; k+=5) { // check rows
                    if (boards[k].compare("x")==0 && boards[k+1].compare("x")==0 && boards[k+2].compare("x")==0 && boards[k+3].compare("x")==0 && boards[k+4].compare("x")==0) {
                        int pos;
                        int sum = 0;
                        if (k % 25 == 0 || k == 0) {
                            for (int l = k; l < k+25; l++) {
                                stringstream ss(boards[l]);
                                ss >> si;
                                sum += si;
                            }
                        } else {
                            int start = (k / 25) * 25;
                            for (int l = start; l < start+25; l++) {
                                if (boards[l].compare("x")==0)
                                        continue;
                                stringstream ss(boards[l]);
                                ss >> si;
                                sum += si;
                            }
                        }
                        pos = k / 25;
                        doneFlags[pos] = true;
                        int flagSum = 0;
                        for (auto a: doneFlags) {
                            flagSum += a;
                        }
                        if (flagSum == sizeof(doneFlags)/sizeof(doneFlags[0])) {
                            cout << sum * nums[i] << '\n';
                            return;
                        }
                    }
                }

                int tmpEnd = 4;
                int tmpStart = 0;
                for (int k = tmpStart; k <= tmpEnd && k <= boards.size()-15; k++) { // check columns
                    if (boards[k].compare("x")==0 && boards[k+5].compare("x")==0 && boards[k+10].compare("x")==0 && boards[k+15].compare("x")==0 && boards[k+20].compare("x")==0) {
                        int pos = k / 25;
                        int sum=0;
                        for (int s = tmpStart; s < tmpStart+25; s++) {
                            if (boards[s].compare("x")==0)
                                    continue;
                            stringstream ss(boards[s]);
                            ss >> si;
                            sum += si;
                        }
                        doneFlags[pos] = true;
                        int flagSum = 0;
                        for (auto a: doneFlags) {
                            flagSum += a;
                        }
                        if (flagSum == sizeof(doneFlags)/sizeof(doneFlags[0])) {
                            cout << sum * nums[i] << '\n';
                            return;
                        }
                    } 

                    if (k == tmpEnd) {
                        tmpStart += 25;
                        k += -4+24;
                        tmpEnd += 25;
                    }
                }
            }
        }
    }


}

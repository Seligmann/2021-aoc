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
    ifstream fin("input.txt");
    string line;
    const int rows = 1000;
    int board[rows][rows];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            board[i][j] = 0;
        }
    }
    int dangers;
    int x1, y1, x2, y2;
    int counts[rows * rows];
    while (getline(fin, line)) {
            sscanf(line.c_str(), "%d,%d -> %d,%d", &x1, &y1, &x2, &y2);
            int tmp[4] = {x1, y1, x2, y2};
            if (x1 == x2 || y1 == y2) {
                int start, end, tmpConst;
                if (x1 == x2) { 
                    tmpConst = x1;
                    start = (y1 < y2) ? y1 : y2;
                    end = (start == y1) ? y2 : y1;
                    for (int i = start; i <= end; i++) { 
                        if (board[i][tmpConst] == -999) continue;
                        board[i][tmpConst]++;
                        if (board[i][tmpConst] >= 2) { 
                            dangers++;
                            board[i][tmpConst] = -999;
                        }
                    }
                }
                else {
                    tmpConst = y1;
                    start = (x1 < x2) ? x1 : x2;
                    end = (start == x1) ? x2 : x1;
                    for (int i = start; i <= end; i++) { // mark positions
                        if (board[tmpConst][i] == -999) continue;
                        board[tmpConst][i]++;
                        if (board[tmpConst][i] >= 2) { // positions marked at/above 2 marks are accounted for and flagged
                            dangers++;
                            board[tmpConst][i] = -999;
                        }
                    }
                }
            }
    }
    return dangers;

    
}

int partTwo() {
    ifstream fin("input.txt");
    string line;
    const int rows = 1000;
    int board[rows][rows];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            board[i][j] = 0;
        }
    }
    int dangers;
    int x1, y1, x2, y2;
    while (getline(fin, line)) {
            sscanf(line.c_str(), "%d,%d -> %d,%d", &x1, &y1, &x2, &y2);
            int tmp[4] = {x1, y1, x2, y2};
            int start, end, startx, starty;
            if (x1 == x2 || y1 == y2) {
                int tmpConst;
                if (x1 == x2) { 
                    tmpConst = x1;
                    start = (y1 < y2) ? y1 : y2;
                    end = (start == y1) ? y2 : y1;
                    for (int i = start; i <= end; i++) {
                        board[i][tmpConst]++;
                    }
                }
                else if (y1 == y2) { 
                    tmpConst = y1;
                    start = (x1 < x2) ? x1 : x2;
                    end = (start == x1) ? x2 : x1;
                    for (int i = start; i <= end; i++) {
                        board[tmpConst][i]++;
                    }
                }
            }
            else if (abs(x2 - x1) == abs(y2 - y1)) {
                if (x1 < x2 && y1 < y2) {
                    for (int i = 0; i <= x2 - x1; i++) {
                        board[y1 + i][x1 + i]++;
                    }
                } else if (x1 < x2 && y1 > y2) {
                    for (int i = 0; i <= x2 - x1; i++) {
                        board[y1 - i][x1 + i]++;
                    }
                } else if (x1 > x2 && y1 < y2) {
                    for (int i = 0; i <= x1 - x2; i++) {
                        board[y1 + i][x1 - i]++;
                    }
                } else if (x1 > x2 && y1 > y2) {
                    for (int i = 0; i <= x1 - x2; i++) {
                        board[y1 - i][x1 - i]++;
                    }
                }
            }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            if (board[i][j] >= 2) dangers++;
        }
    }
    return dangers;
}

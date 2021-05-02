#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(vector <vector <int>> v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int pos(string s) {
    vector <string> let = {"a", "b", "c", "d", "e", "f", "g", "h"};
    for (int i = 0; i < let.size(); i++) {
        if (s == let[i]) {
            return i;
        }
    }
    return -1;
}

int main() 
{
    int N, x, y;
    cin >> N;
    string inp;
    vector <vector <int>> ch(8, vector<int> (8, 0));
    for (int i = 0; i < N; i++) {
        cin >> inp;
        // cout << inp;
        x = pos(inp.substr(0, 1));
        y = stoi(inp.substr(1, 2))-1;
        ch[y][x] = 1;
    }
    print(ch);
    cin >> inp;
    x = pos(inp.substr(0, 1));
    y = stoi(inp.substr(1, 2))-1;
    vector <vector <int>> res(8, vector<int> (8, 0));
// int sum;
    res[y][x] = 1;
    for (int i = 1; i < 8; i++) {
        // cout << "--";
        for (int j = 0; j < 7; j++) {
            if (res[i-1][j] != 0 && ch[i][j] != 1) {
                res[i][j] += res[i-1][j];
            }
            if (ch[i][j] == 1) {
                if (j-1 >= 0) {
                    if (res[i-1][j-1] != 0) {
                        res[i][j] += res[i-1][j-1];
                    }
                }
                if (j+1 < 8) {
                    if (res[i-1][j+1] != 0) {
                        res[i][j] += res[i-1][j+1];
                    }
                }
            }
        }
        print(res);
    }
    int sum = 0;
    for (int j = 0; j < 8; j++) {
        sum += res[7][j];
    }
    cout << sum << endl;
    
    return 0;
}
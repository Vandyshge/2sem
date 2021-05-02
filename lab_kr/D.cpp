#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
    int res = 0;
    int n = -1;
    int flag = 0;
    int num;
    string inp;
    getline(cin, inp);
    for (auto i = 0; i < inp.size(); i++) {
        if (inp[i] == '1' || inp[i] == '2' || inp[i] == '3' || inp[i] == '4' || inp[i] == '5' || inp[i] == '6' || inp[i] == '7' || inp[i] == '8' || inp[i] == '9' || inp[i] == '0') {
            if (flag == 0) {
                flag = 1;
                n = i;
                // cout << "---" << endl;
            }
        } else if (flag == 1) {
            // cout << stoi(inp.substr(n)) << endl;
            num = stoi(inp.substr(n, i));
            if (num > res) res = num;
            n = -1;
            flag = 0;
        }
    }
    // cout << "flag " << flag << endl;
    if (flag == 1) {
        num = stoi(inp.substr(n));
        // cout << stoi(inp.substr(n)) << endl;
        if (num > res) res = num;
        n = -1;
        flag = 0;
    }
    cout << res;

    return 0;
}
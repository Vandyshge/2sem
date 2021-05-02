#include <iostream>
#include <string>

using namespace std;

int main()
{
    int res = 0;
    bool chet = true;
    string inp;
    getline(cin, inp);
    for (auto i = 0; i < inp.size(); i++) {
        if (inp[i] != ' ') {
            if (chet) {
                inp[i] = toupper(inp[i]);
                chet = false;
            } else {
                inp[i] = tolower(inp[i]);
                chet = true;
            }
        }
    }

    cout << inp;

    return 0;
}
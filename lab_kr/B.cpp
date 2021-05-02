#include <iostream>
#include <string>

using namespace std;

int main()
{
    int res = 0;
    int flag = 0;
    string inp;
    getline(cin, inp);
    for (auto i = 0; i < inp.size(); i++) {
        if (inp[i] == ' ' && flag == 1) {
            res++;
            flag = 0;
        } else if (inp[i] != ' ' && flag == 0) {
            flag = 1;
        }
    }
    if (flag == 1) res++;
    cout << res;

    return 0;
}
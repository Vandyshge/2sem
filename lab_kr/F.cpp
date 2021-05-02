#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
    int t0 = 0;
    int t1 = 0;
    int t2 = 1;
    int tn;
    int n = 2;
    int inp;
    int res;
    cin >> inp;
    if (inp < 0) {
        res = 0;
    } else if (inp == 0) {
        res = 2;
    } else {
        while (true) {
            tn = t0 + t1 + t2;
            n++;
            if (tn > inp) {
                res = n;
                break;
            }
            t0 = t1;
            t1 = t2;
            t2 = tn;
        }
    }
    cout << res;

    return 0;
}
#include <iostream>

using namespace std;

int main()
{
    int inp, res;
    cin >> inp;
    res = inp % 10 + inp / 100 + inp / 10 % 10;
    cout << res;
    return 0;
}
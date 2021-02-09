#include <iostream>

using namespace std;

int main()
{
    int a, b;
    int c;
    cin >> a >> b;
    if (b <= a) {
        c = a;
        a = b;
        b = c;
    };

    while (a > 0) {
        c = a;
        a = b % a;
        b = c;
    };
    cout << b;
    return 0;
} 
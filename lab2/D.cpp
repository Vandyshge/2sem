#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n > 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            cout << "NO";
            break;
        };
    };
    if (n == 1) {
        cout << "YES";
    };
    return 0;
}
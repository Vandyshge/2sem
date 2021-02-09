#include <iostream>

using namespace std;

int main()
{
    int n, s;
    s = 0;
    cin >> n;
    while (n != 0) {
        if (n % 2 == 0) {
            s++;
        };
        cin >> n;
    }
    cout << s;
    return 0;
} 
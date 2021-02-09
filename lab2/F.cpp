#include <iostream>

using namespace std;

int main()
{
    int n, n_max, s;
    s = 0;
    n_max = 0;
    cin >> n;
    while (n != 0) {
        if (n_max < n) {
            n_max = n;
            s = 1;
        } else if (n == n_max) {
            s++;
        };
        cin >> n;
    }
    cout << s;
    return 0;
} 
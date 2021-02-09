#include <iostream>

using namespace std;

int main()
{
    int n, n_max;
    n_max = 0;
    cin >> n;
    while (n != 0) {
        if (n_max < n && n % 2 == 0) {
            n_max = n;
        };
        cin >> n;
    }
    cout << n_max;
    return 0;
} 
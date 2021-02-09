#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    int flag = 1;
    cin >> n;
    for (auto i = 2; i < (int) (sqrt(n) + 1); i++) {
        if (n % i == 0) {
            cout << 0;
            flag = 0;
            break;
        };
    }
    if (flag == 1) {
        cout << 1;
    };
    return 0;
}
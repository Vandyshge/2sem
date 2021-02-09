#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N, n;
    int flag = 1;
    cin >> n;
    N = n;
    for (auto i = 2; i < (int) (sqrt(N) + 1); i++) {
        if (n == 1) {
            break;
        } else {
            while (n % i == 0) {
                n = n / i;
                cout << i << endl;
                if (flag == 1) {
                    flag = 0;
                };
            };
        };
    };
    if (flag == 1) {
        cout << N << endl;
    } else if (n != 1) {
        cout << n << endl;
    }
    return 0;
}
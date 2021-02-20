#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool prime (int a) {
    int flag = 1;
    for (auto i = 2; i < (int) (sqrt(a) + 1); i++) {
        if (a % i == 0) {
            return false;
            flag = 0;
            break;
        };
    };
    if (flag == 1) {
        return true;
    };
    return false;
}

int main()
{
    int n;
    cin >> n;
    int i = 2;
    int N = 1;
    if (n == 1) {
        cout << 2;
    } else {
        while (i <= n) {
            N += 2;
            if (prime (N)) {
                i++;
            };
        }
        cout << N;
    };
    return 0;
}
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int a[2];
    int res[4] = {0, 0, 0, 0};
    for (auto i = 0; i < N; i++) {
        cin >> a[0] >> a[1];
        if (a[0] > 0) {
            if (a[1] > 0) {
                res[0]++;
            } else if (a[1] < 0) {
                res[3]++;
            };
        } else if (a[0] < 0) {
            if (a[1] > 0) {
                res[1]++;
            } else if (a[1] < 0) {
                res[2]++;
            };
        };
    };
    int max = 0;
    int n_max = 1;
    for (auto i = 0; i < 4; i++) {
        if (max < res[i]) {
            max = res[i];
            n_max = i + 1;
        };
    };
    cout << n_max << " " << max;
    return 0;
}
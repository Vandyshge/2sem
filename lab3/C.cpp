#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int a, b;
    int a_1_min, a_2_min, a_1_max, a_2_max; 
    cin >> a;
    a_1_min = a;
    a_2_max = a;
    // cout << a_1_min << " " << a_2_min << " " << a_1_max << " " << a_2_max << endl;
    cin >> a;
    if (a > a_2_max) {
        b = a_2_max;
        a_2_max = a;
        a_1_max = b;
    } else {
        a_1_max = a;
    };
    // cout << a_1_min << " " << a_2_min << " " << a_1_max << " " << a_2_max << endl;

    if (a < a_1_min) {
        b = a_1_min;
        a_1_min = a;
        a_2_min = b;
    } else {
        a_2_min = a;
    };
    // cout << a_1_min << " " << a_2_min << " " << a_1_max << " " << a_2_max << endl;
    for (auto i = 2; i < N; i++) {
        cin >> a;
        if (a > a_2_max) {
            b = a_2_max;
            a_2_max = a;
            a_1_max = b;
        } else if (a > a_1_max) {
            a_1_max = a;
        };

        if (a < a_1_min) {
            b = a_1_min;
            a_1_min = a;
            a_2_min = b;
        } else if (a < a_2_min) {
            a_2_min = a;
        };
        // cout << a_1_min << " " << a_2_min << " " << a_1_max << " " << a_2_max << endl;
    };
    // cout << a_1_min << " " << a_2_min << " " << a_1_max << " " << a_2_max << endl;
    cout << a_1_min + a_2_min << " " << a_1_max + a_2_max;
    return 0;
}
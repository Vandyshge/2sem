#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int n_v = (int) (N + 1) / 2;
    int n_h = 0;
    for (auto i = 0; i < n_v; i++) {
        for (auto j = 0; j < N; j++) {
            if (j < n_h || j >= (N - n_h)) {
                cout << " ";
            } else {
                cout << "*";
            };
        };
        cout << endl;
        n_h += 1;
    };
    return 0;
} 
#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int n = 1;
    for (auto i = 0; i < N; i++) {
        for (auto j = 0; j < n; j++) {
            cout << "*";
        };
        cout << endl;
        n++;
    };
    return 0;
} 
#include <iostream>
#include <string>

using namespace std;

int main() {
	int n, i, d, N, h1, h;
    cin >> N >> h;
    int *z = new int[N];
    
    for (auto i = 0; i < N; i++) {
        cin >> z[i];
    }

    d = (z[N - 1] - z[0]) / (h - 1) + 1;

    h1 = 1;
    while (h1 < h) {
        d--;
        h1 = 1;
        n = 0;
        i = 0;
        while (n < N - 1) {
            while (z[i] - z[n] < d) {
                i++;
            }
            n = i;
            h1++;
        }
        if (d < 1) {
            break;
        }
    }
    cout << d << endl;
    return 0;
}

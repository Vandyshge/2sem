#include <iostream>
#include <vector>

using namespace std;

void print (vector <bool> v, int N) {
    for (auto i = 0; i < N-1; i++) {
        if (v[i]) cout << i+2 << " ";
    }
    cout << endl;
}

int main()
{
    int N;
    cin >> N;
    vector <bool> v(N-1);
    for (auto i = 0; i < N-1; i++) {
        v[i] = true;
    }
    // int p;
    for (auto i = 2; i*i < N; i++) {
        if (v[i-2]) {
            // cout << " 123 " << endl;
            for (auto j = i*i; j <= N; j += i) {
                if (v[j-2]) v[j-2] = false;
                // cout << j-2 << " ";
            } 
            // cout << endl;
        }
        // print(v, N);
    }
    print(v, N);

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

void print (vector <int> v, int N) {
    for (auto i = 0; i < N; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    int N;
    cin >> N;
    vector <int> v(N);
    for (auto i = 0; i < N; i++) {
        cin >> v[i];
    }

    // print(v, N);
    // cout << " f ";

    for(int i = 1; i < N; ++i) {
        for(int j = 0; j < N-i; j++) {
            if(v[j] > v[j+1]) {
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
            print(v, N);
        }
    }

    print(v, N);

    return 0;
}
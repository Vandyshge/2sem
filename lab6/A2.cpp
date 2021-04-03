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
    int N, n;
    cin >> N >> n;
    vector <int> v(N);
    for (auto i = 0; i < N; i++) {
        cin >> v[i];
    }
    // print(v, N);
    // cout << "roeib" << endl;
    
    int temp;
    for (auto i = 0; i < n; i++) {
        // cout << "oeib" << endl;
        for (auto j = 0; j < N-1; j++) {
            // cout << "eib" << endl;
            temp = v[j];
            v[j] = v[j+1];
            v[j+1] = temp;
        }
        // print(v, N);
    }
    
    print(v, N);
    return 0;
}
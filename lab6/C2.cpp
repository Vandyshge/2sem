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
    // cout << "roeib" << endl;
    
    int v0, temp1, temp2;
    v0 = v[0];
    temp1 = v[0];
    v[0] = (v[N-1] + v[0] + v[1]) / 3;
    for (auto i = 1; i < N-1; i++) {
        temp2 = v[i];
        v[i] = (temp1 + v[i] + v[i+1]) / 3;
        temp1 = temp2;
        // print(v, N);
    }
    v[N-1] = (v0 + temp1 + v[N-1]) / 3;
    
    print(v, N);
    return 0;
}
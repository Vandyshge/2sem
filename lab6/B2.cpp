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
    
    int temp;
    for (auto i = 0; i < (N)/2; i++) {
        // cout << "oeib" << endl;
        temp = v[i];
        v[i] = v[N-i-1];
        v[N-i-1] = temp;
        // print(v, N);
    }
    
    print(v, N);
    return 0;
}
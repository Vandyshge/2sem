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

    int v_max, v_min;
    v_max = v[0];
    v_min = v[0];
    for (auto i = 1; i < N; i++) {
        if (v_max < v[i]) v_max = v[i];
        if (v_min > v[i]) v_min = v[i];
    }
    // print(v, N);

    cout << v_max - v_min + 1 - N;

    return 0;
}
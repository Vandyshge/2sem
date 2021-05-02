#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int N;
    cin >> N;
    vector <int> v(N);
    int a;
    for (auto i = 0; i < N; i++) {
        cin >> v[i];
    }

    for (auto i = 0; i < v.size()/2; i++) {
        a = v[i];
        v[i] = v[N - i - 1];
        v[N - i - 1] = a;
    }

    for (auto a:v) {
        cout << a << " ";
    }

    return 0;
}
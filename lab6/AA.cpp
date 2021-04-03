#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector <int> v(N);
    int s = 0;
    for (auto i = 0; i < N; i++) {
        cin >> v[i]; 
        s += v[i]; 
    }
    float a = s / N;
    int res = 0;
    for (auto i = 0; i < N; i++) if (v[i] > a) res += v[i];
    cout << res;
    return 0;
}
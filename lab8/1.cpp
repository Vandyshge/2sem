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
    int a = s / N;
    int res = 0;
    for (auto i = 0; i < N; i++) if (v[i] > a) res++;
    cout << res << endl;
    for (auto i = 0; i < N; i++) if (v[i] > a) cout << i << " ";
    return 0;
}
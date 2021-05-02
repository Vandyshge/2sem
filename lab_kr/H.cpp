#include <iostream>
#include <vector>

using namespace std;



int main()
{
    int N, a;
    cin >> N;
    cin >> a;
    int t1 = 0;
    int t2 = N-1;
    int res = -1;
    vector <int> v(N);
    for (auto i = 0; i < N; i++) {
        cin >> v[i];
    }
    while (t2 - t1 > 1) {
        // cout << "---" << endl;
        if (v[(t2 + t1)/2] == a) {
            res = (t2 + t1)/2;
            // cout << v[(t2 + t1)/2];
            break;
        } else if (v[(t2 + t1)/2] > a) {
            t2 = (t2 + t1)/2;
            // cout << v[(t2 + t1)/2];
        } else {
            t1 = (t2 + t1)/2;
            // cout << v[(t2 + t1)/2];
        }
    }
    if (v[t2] == a) res = t2;
    if (v[t1] == a) res = t1;
    if (res != -1) res++;
    cout << res;



    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void print (int N, int K, vector <vector <int>> v) {
    for (auto i:v) {
        for (auto j:i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector <vector <int>> v(N, vector <int> (K, 0));
    int n;
    cin >> n;
    vector <vector <int>> a(n, vector <int> (2));
    for (auto i = 0; i < n; i++) {
        cin >> a[i][0];
        cin >> a[i][1];
        a[i][0] -= 1;
        a[i][1] -= 1;
    }
    // print(N, K, v);
    int x, y;
    for (auto i = 0; i < n; i++) {
        x = a[i][0];
        y = a[i][1];
        if (x - 1 >= 0 && y - 1 >= 0) v[x-1][y-1]++;
        if (x - 1 >= 0) v[x-1][y]++;
        if (x - 1 >= 0 && y + 1 < K) v[x-1][y+1]++;
        if (x + 1 < N && y - 1 >=0) v[x+1][y-1]++;
        if (x + 1 < N) v[x+1][y]++;
        if (x + 1 < N && y + 1 < K) v[x+1][y+1]++;
        if (y - 1 >= 0) v[x][y-1]++;
        if (y + 1 < K) v[x][y+1]++;
    }
    for (auto i = 0; i < n; i++) {
        x = a[i][0];
        y = a[i][1];
        v[x][y] = -1;
    }
    print(N, K, v);
    return 0;
}
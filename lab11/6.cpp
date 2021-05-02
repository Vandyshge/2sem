#include <iostream>
#include <vector>

using namespace std;

void print(vector <vector <int>> v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


int main() 
{
    int N, M;
    cin >> N >> M;
    vector <vector <int>> P(N, vector<int> (M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> P[i][j];
        }
    }
    int sum;
    cin >> sum;
    // print(P);
    vector <vector <int>> res(N, vector<int> (M, 0));
    // print(res);
    // res[0][0] = P[0][0];
    bool flag;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            flag = false;
            if (i-1 >= 0) {
                res[i][j] = res[i-1][j];
                flag = true;
            }
            if (j-1 >= 0) {
                if (res[i][j] > res[i][j-1] || !flag) {
                    res[i][j] = res[i][j-1];
                }
            }
            res[i][j] += P[i][j];
            // print(res);
        }
    }

    if (sum - res[N-1][M-1] >= 0) {
        cout << sum - res[N-1][M-1] << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}
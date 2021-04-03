#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print (vector <vector <int>> v) {
    for (auto i = 0; i < v.size(); i++) {
        for (auto j = 0; j < v[0].size(); j++) cout <<  v[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

struct out
{
    vector <int> v;
    int n_max;
};

int main()
{
    int N;
    cin >> N;
    vector <vector <int>> mat(N, vector <int> (N));
    vector <vector <int>> mat_roat(N, vector <int> (N));
    // int n = 1;
    for (auto i = 0; i < N; i++) {
        for (auto j = 0; j < N; j++) {
            cin >> mat[i][j];
            // mat[i][j] = n;
            // n++;
        }
    }
    
    // print(mat);

    for (auto x = 0; x < N/2; x++) {
        for (auto i = x; i < N - x; i++) {
            // cout << mat[x][i] << endl;
            mat_roat[i][N-x-1] = mat[x][i];
            // print(mat_roat);
            mat_roat[N-i-1][x] = mat[N-x-1][N-i-1];
            // print(mat_roat);
            mat_roat[N-x-1][N-i-1] = mat[i][N-x-1];
            // print(mat_roat);
            mat_roat[x][i] = mat[N-i-1][x];
            // print(mat_roat);
            // cout << endl;
        }
    }
    if (N % 2 != 0) {
        mat_roat[N/2][N/2] = mat[N/2][N/2];
    }
    print(mat_roat);
    return 0;
}
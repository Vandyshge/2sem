#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

void print_two(vector <vector <int>> v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void print_one(vector<int>& v) {
    for (auto a:v) {
        cout << a << " ";
    }
    cout << endl;
}

void lenth_ij(vector <int> v1, vector <int> v2, int i, int j, vector <vector <int>>& res, vector <vector <int>>& col) {
    // print_two(res);
    if (i > 0 && j > 0) {
        if (v1[i] == v2[j]) {
            // cout << "1 " << i << " " << j << " :" << v1[i] << endl;
            res[i][j] = 3;
            lenth_ij(v1, v2, i-1, j-1, res, col);
            col[i][j] = 1 + col[i-1][j-1];
        } else {
            // cout << "2 " << i << " :" << v1[i] << " " << j << " :" << v2[j] << endl;
            if (col[i-1][j] == -1) lenth_ij(v1, v2, i-1, j, res, col);
            if (col[i][j-1] == -1) lenth_ij(v1, v2, i, j-1, res, col);
            if (col[i-1][j] > col[i][j-1]) {
                res[i][j] = 1;
                col[i][j] = col[i-1][j];
            } else {
                res[i][j] = 2;
                col[i][j] = col[i][j-1];
            }
        }
    } else if (i == 0 || j == 0) {
        // cout << "3 " << i << " :" << v1[i] << " " << j << " :" << v2[j] << endl;
        if (v1[i] == v2[j]) {
            res[i][j] = 3;
            col[i][j] = 1;
        } else {
            if (i == 0 && j != 0) {
                if (col[i][j-1] == -1) lenth_ij(v1, v2, i, j-1, res, col);
                res[i][j] = 2;
                col[i][j] = col[i][j-1];
            } else if (i != 0 && j == 0) {
                if (col[i-1][j] == -1) lenth_ij(v1, v2, i-1, j, res, col);
                res[i][j] = 1;
                col[i][j] = col[i-1][j];
            } else {
                res[i][j] = 1;
                col[i][j] = 0;
            }
        }
    }
}




vector <int> LCS(vector <int> v1, vector <int> v2) {
    vector <vector <int>> res(v1.size(), vector <int> (v2.size(), 0));
    vector <vector <int>> col(v1.size(), vector <int> (v2.size(), -1));
    int i = v1.size()-1;
    int j = v2.size()-1;
    lenth_ij(v1, v2, i, j, res, col);
    // cout << "lenth: " << lenth << endl;
    // print_two(res);
    vector <int> res_1;
    i = v1.size()-1;
    j = v2.size()-1;
    while (i >= 0 && j >= 0) {
        if (res[i][j] == 3) {
            res_1.push_back(v1[i]);
            i--;
            j--;
            // cout << "3 " << i << " " << j << endl;
        } else if (res[i][j] == 2) {
            j--;
            // cout << "2 " << i << " " << j << endl;
        } else if (res[i][j] == 1) {
            i--;
            // cout << "1 " << i << " " << j << endl;
        }
    }
    
    reverse(res_1.begin(), res_1.end());
    return res_1;

}

int main() 
{
//     vector <int> v1{1, 5, 7, 8, 9, 2, 4, 6};
//     vector <int> v2{3, 6, 7, 5, 7, 6, 1, 2};
    // vector <int> v1{1, 2, 3, 10, 5, 6};
    // vector <int> v2{1, 2, 3, 4, 5, 6};
    int N1, N2;
    cin >> N1;
    cin >> N2;
    vector <int> v1(N1);
    for (int i = 0; i < N1; i++) cin >> v1[i];
    vector <int> v2(N2);
    for (int i = 0; i < N2; i++) cin >> v2[i];
    // print(v1);
    // print(v2);
    // int x;
    // vector <int> v1;
    // vector <int> v2;
    // while (cin >> x) {
    //     v1.push_back(x);
    // }
    // while (cin >> x) {
    //     v2.push_back(x);
    // }
    // cout << " hello" << endl;
    vector <int> res = LCS(v1, v2);
    print_one(res);

    return 0;
}
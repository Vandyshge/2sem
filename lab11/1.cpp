#include <iostream>
#include <vector>

using namespace std;

// int find(vector<int> v, int i) {
//     int l = 1;
//     int prev = i;
//     // cout << "dji" << endl;
//     for (int j = i+1; j < v.size(); j++) {
//         if (v[j] > v[prev]) {
//             l++;
//             prev = j;
//         }
//     }
//     return l;
// }

int maxvec(vector <int> v) {
    int max = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (max < v[i]) {
            max = v[i];
        }
    }
    return max;
}

void print(vector<int>& v) {
    for (auto a:v) {
        cout << a << " ";
    }
    cout << endl;
}

void lenth_i(vector <int> v, int i, vector <int>& res) {
    if (i == 0) {
        res[i] = 1;
    } else if (res[i] == -1) {
        vector <int> res_i;
        int col = 0;
        for (int j = i-1; j >= 0; j--) {
            if (v[i] > v[j]) {
                col++;
                if (res[j] == -1) {
                    lenth_i(v, j, res);
                }
                res_i.push_back(res[j]);
            }
        }
        if (col == 0) {
            res[i] = 1;
        } else {
            res[i] = maxvec(res_i)+1;
        }
        // print(res);
    }
}

int LIS(vector <int> v) {
    vector <int> res(v.size(), -1);
    for (int i = v.size()-1; i >= 0; i--) lenth_i(v, i, res);
    return maxvec(res);
}

int main() 
{
    // vector <int, int> v;
    int N;
    cin >> N;
    vector <int> inp(N);
    for (int i = 0; i < N; i++) {
        cin >> inp[i];
    }

    cout << LIS(inp) << endl;
    
    return 0;
}
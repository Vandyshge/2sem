#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(vector<int>& v) {
    for (auto a:v) {
        cout << a << " ";
    }
    cout << endl;
}

int abs_i(int a) {
    if (a > 0) {
        return a;
    } else {
        return -a;
    }
}

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

void en_i(vector <int> v, int i, vector <int>& en) {
    if (en[i-2] == -1) en_i(v, i-2, en);
    if (en[i-1] == -1) en_i(v, i-1, en);
    int e1 = 3*abs_i(v[i-2]-v[i]) + en[i-2];
    int e2 = abs_i(v[i-1]-v[i]) + en[i-1];
    if (e1 > e2) {
        en[i] = e2;
    } else {
        en[i] = e1;
    }
}

int energy(vector<int> v) {
    if (v.size() == 1) return 0;
    if (v.size() == 2) return abs_i(v[1] - v[0]);
    vector <int> en(v.size(), -1);
    en[0] = 0;
    en[1] = abs_i(v[1] - v[0]);
    en_i(v, v.size()-1, en);
    return en[v.size()-1];
}

int main() 
{
    int N;
    cin >> N;
    vector <int> inp(N);
    for (int i = 0; i < N; i++) {
        cin >> inp[i];
    } 

    cout << energy(inp) << endl;

    return 0;
}
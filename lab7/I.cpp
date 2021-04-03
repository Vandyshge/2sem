#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print (vector <int> v, int N, int flag) {
    if (flag == 0) {
        for (auto i = 0; i < N; i++) {
            if (v[i] % 2 == 0) cout << v[i] << " ";
        }

        for (auto i = 0; i < N; i++) {
            if (v[i] % 2 != 0) cout << v[i] << " ";
        }
    } else {
        for (auto i = 0; i < N; i++) {
            cout << v[i] << " ";
        }
    }
    cout << endl;
}

vector <int> split(string s) {
    vector <int> v;
    string s_i = s;
    int n;
    while (s_i.size() != 0) {
        n = 0;
        while (s_i[n+1] != ' ' && s_i.size() > n+1) {
            n++;
            // cout << n << endl;
        }
        // cout << s_i.substr(0, n+1) << endl;
        v.push_back(stoi(s_i.substr(0, n+1)));
        // cout << stoi(s_i.substr(0, n+1)) << endl;
        if (s_i.size() >= n+2) { 
            s_i = s_i.substr(n+2);
        } else if (s_i.size() >= n+1) {
            s_i = s_i.substr(n+1);
        }
        // cout << s_i << endl;
    }
    // v.push_back(10);
    return v;
}

int main()
{
    string inp;
    getline(cin, inp);
    vector <int> v;
    v = split(inp);
    // print(v, v.size(), 1);
    

    for(int i = 1; i < v.size(); ++i) {
        for(int j = 0; j < v.size()-i; j++) {
            if(v[j] > v[j+1]) {
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
    print(v, v.size(), 0);

    return 0;
}
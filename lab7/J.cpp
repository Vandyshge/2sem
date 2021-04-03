#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print (vector <int> v, int N) {
    for (auto i = 0; i < N; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

struct out
{
    vector <int> v;
    int n_max;
};

struct out split(string s) {
    out out_func;
    string s_i = s;
    int n;
    out_func.n_max = 0;
    while (s_i.size() != 0) {
        n = 0;
        while (s_i[n+1] != ' ' && s_i.size() > n+1) {
            n++;
            // cout << n << endl;
        }
        if (n+1 > out_func.n_max) out_func.n_max = n+1;
        // cout << s_i.substr(0, n+1) << endl;
        out_func.v.push_back(stoi(s_i.substr(0, n+1)));
        // cout << stoi(s_i.substr(0, n+1)) << endl;
        if (s_i.size() >= n+2) { 
            s_i = s_i.substr(n+2);
        } else if (s_i.size() >= n+1) {
            s_i = s_i.substr(n+1);
        }
        // cout << s_i << endl;
    }
    // v.push_back(10);
    return out_func;
}

int main()
{
    string inp;
    getline(cin, inp);
    out out_split;
    out_split = split(inp);
    // print(v, v.size(), 1);

    // cout << out_split.n_max;
    int n = 1;
    for (auto i = 0; i < out_split.n_max; i++) {
        for(int i = 1; i < out_split.v.size(); ++i) {
            for(int j = 0; j < out_split.v.size()-i; j++) {
                if (out_split.v[j]%(10*n)/n > out_split.v[j+1]%(10*n)/n ) {
                    int temp = out_split.v[j];
                    out_split.v[j] = out_split.v[j+1];
                    out_split.v[j+1] = temp;
                }
            }
        }
        n *= 10;
        print(out_split.v, out_split.v.size());
    }

    // cout << 12%(10*10)/10;

    return 0;
}
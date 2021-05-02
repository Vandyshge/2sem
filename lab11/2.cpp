#include <iostream>
#include <string>
#include <vector>

using namespace std;

void bubble_sort(vector<int>& v) {
    int temp;
    for (int i = 1; i < v.size(); i++) {
        for (int j = 0; j < v.size()-i; j++) {
            if (v[j] > v[j+1]) {
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
}

void print(vector<int>& v) {
    for (auto a:v) {
        cout << a << " ";
    }
    cout << endl;
}


int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int main() 
{
    int N;
    cin >> N;
    vector <int> inp(N);
    vector <int> link(N);
    for (int i = 0; i < N; i++) {
        cin >> inp[i];
        link[i] = 0;
    }

    bubble_sort(inp);
    // print(inp);

    int len = 0;
    int r, l;
    if (inp.size() == 2) {
        len += inp[1] - inp[0];
    } else {
        len += inp[1] - inp[0] + inp[inp.size()-1] - inp[inp.size()-2];
        link[0] = 1;
        link[1] = 1;
        link[inp.size()-1] = 1;
        link[inp.size()-2] = 1;
        for (int i = 1; i < N-1; i++) {
            if (i+1 < inp.size() && link[i] == 0) {
                r = inp[i+1] - inp[i];
            } else {
                r = -1;
            }

            if (i-1 >= 0 && link[i] == 0) {
                l = inp[i] - inp[i-1];
            } else {
                l = -1;
            }

            if (r == -1 && l != -1) {
                len += l;
                link[i] = 1;
                link[i-1] = 1;
            } else if (l == -1 && r != -1) {
                len += r;
                link[i] = 1;
                link[i+1] = 1;
            } else if (l != -1 && r != -1) {
                if (r > l) {
                    len += l;
                    link[i] = 1;
                    link[i-1] = 1;
                } else if (r <= l) {
                    len += r;
                    link[i] = 1;
                    link[i+1] = 1;
                }
            }
            // cout << i << " " << len << " " << r << " " << l << endl; 
        }
    }

    cout << len << endl;

    return 0;
}
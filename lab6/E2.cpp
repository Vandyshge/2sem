#include <iostream>
#include <vector>

using namespace std;

void print (vector <int> v, int N) {
    for (auto i = 0; i < N; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    int N;
    cin >> N;
    vector <int> v(N);
    // vector <int> v(N);
    for (auto i = 0; i < N; i++) {
        cin >> v[i];
    }

    // print(v, N);
    // cout << " f ";

    vector <int> temp_pos(2);
    vector <int> temp_neg(2);
    int temp;
    for(int i = 1; i < N; ++i) {
        temp_pos = {0, -1};
        temp_neg = {0, -1};
        for(int j = 0; j < N-i+1; j++) {
            if (v[j] >= 0) {
                // cout << temp_pos[0] << " ejofi " << temp_pos[1] << endl;
                if (temp_pos[1] != -1) {
                    if (temp_pos[0] > v[j]) {
                        temp = v[j];
                        v[temp_pos[1]] = v[j];
                        v[j] = temp_pos[0];
                        temp_pos[1] = j;
                        print(v, N);
                    } else {
                        temp_pos = {v[j], j};
                    }
                } else {
                    temp_pos = {v[j], j};
                }
            } else {
                // cout << temp_neg[0] << " ejofi " << temp_neg[1] << endl;
                if (temp_neg[1] != -1) {
                    if (temp_neg[0] < v[j]) {
                        temp = v[j];
                        v[temp_neg[1]] = v[j];
                        v[j] = temp_neg[0];
                        temp_neg[1] = j;
                        print(v, N);
                    } else {
                        temp_neg = {v[j], j};
                    }
                } else {
                    temp_neg = {v[j], j};
                }
            }
            // print(v, N);
            // cout << endl;
        }
        // cout << endl;
    }
    // print(v, N);
    // print(v, N);

    return 0;
}
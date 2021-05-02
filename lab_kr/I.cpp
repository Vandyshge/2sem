#include <iostream>
#include <vector>

using namespace std;

void print (vector <int> v) {
    for (auto i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    int N;
    cin >> N;
    vector <int> v1(N);
    vector <int> v2(N);
    for (auto i = 0; i < N; i++) {
        cin >> v1[i];
    }
    for (auto i = 0; i < N; i++) {
        cin >> v2[i];
    }

    int temp;
    for(int i = 1; i < N; ++i) {
        for(int j = 0; j < N-i; j++) {
            if(v1[j] > v1[j+1]) {
                temp = v1[j];
                v1[j] = v1[j+1];
                v1[j+1] = temp;
                temp = v2[j];
                v2[j] = v2[j+1];
                v2[j+1] = temp;
            } else if (v1[j] == v1[j+1]) {
                if (v2[j] > v2[j+1]) {
                    temp = v2[j];
                    v2[j] = v2[j+1];
                    v2[j+1] = temp;
                    temp = v1[j];
                    v1[j] = v1[j+1];
                    v1[j+1] = temp;
                }
            }
        }
    }

    print(v1);
    print(v2);

    return 0;
}
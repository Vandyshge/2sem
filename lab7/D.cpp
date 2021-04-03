#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int N, news, M;
    cin >> N >> news;
    int quan = N;
    vector <string> v_name(N);
    vector <int> v_char(N);
    for (auto i = 0; i < N; i++) {
        cin >> v_name[i] >> v_char[i];
    }
    cin >> M;

    int num = 0;
    for (auto i = 0; i < M; i++) {
        if (quan == 1) {
            break;
        }

        if (v_name[num] == "dead") {
            while (v_name[num] == "dead") {
                if (num == N-1) {
                    num = 0;
                } else {
                    num++;
                }
            }
        }

        if (v_char[num] == 0) {
            if (news == 0) {
                news = 1;
                v_char[num] = 1;
            } else {
                news = 0;
            }
        } else if (v_char[num] == 1 && news == 0) {
            v_name[num] = "dead";
            quan--;
        }

        if (num == N-1) {
            num = 0;
        } else {
            num++;
        }
    }

    for (auto j = 0; j < N; j++) {
        if (v_name[j] != "dead") {
            cout << v_name[j] << " " << v_char[j] << endl;
        }
    }

    return 0;
}
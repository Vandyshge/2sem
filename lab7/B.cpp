#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int N, num;
    int flag = 0;
    cin >> N;
    for (auto i = 0; i < N; i++) {
        cin >> num;
        if (num % 4 == 0 && num / 1000 != 4 && num / 1000 != 5) {
            cout << num << endl;
            flag++;
        } else if (num % 7 == 0 && num / 1000 != 7 && num / 1000 != 1) {
            cout << num << endl;
            flag++;
        } else if (num % 9 == 0 && num / 1000 != 9 && num / 1000 != 8) {
            cout << num << endl;
            flag++;
        }
    }
    if (flag == 0) cout << 0 << endl;
    
    return 0;
}
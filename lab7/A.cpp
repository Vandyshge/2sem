#include <iostream>
#include <vector>

using namespace std;



int main()
{
    int a, b, ans;
    float c, d;
    cin >> a >> b >> c >> d >> ans;
    int ans_1 = b - a;
    float ans_2 = d / c;
    if (ans == ans_1 && (float) ans == ans_2) {
        cout << 5 << endl;
    } else if (ans == 1024 && ans != ans_1 && (float) ans != ans_2) {
        cout << 3 << endl;
    } else if (ans == ans_1 || (float) ans == ans_2) {
        cout << 4 << endl;
    } else {
        cout << 2 << endl;
    }
    
    return 0;
}
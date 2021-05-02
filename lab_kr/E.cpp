#include <iostream>

using namespace std;


int main()
{
    double M = 0.0;
    double F = 0.0;
    int N;
    cin >> N;
    for (auto i = 0; i < N; i++) {
        M = 0.3*(100.0 + 2.0*F) + 10.0;
        F = 0.7*(100.0 + 2.0*F);
    }
    int64_t M_i64 = static_cast<int64_t>(M);
    cout << M_i64;

    return 0;
}
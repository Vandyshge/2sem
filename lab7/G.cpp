#include <iostream>

using namespace std;

int sign(float x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

int my_abs(float k, float n) {
    if (k > n) {
        return k - n;
    } else {
        return n - k;
    }
}
 
float find_root(float (*f)(float), float a, float b, float tol) {
    float x_n = a;
    float x_k = b;
    float x_i;
    float eps = 0.000001;
    if (f(a) == 0) return a;
    if (f(b) == 0) return b;
    while (x_k - x_n > eps && my_abs(f(x_k), f(x_n)) > tol) {
        x_i = x_n + (x_k - x_n) / 2;
        if (f(x_i) == 0) return x_i;
        if (sign(f(x_n)) != sign(f(x_i))) {
            x_k = x_i;
        } else {
            x_n = x_i;
        }
        // cout << x_i << endl;
    }
    return x_i;
}

int main()
{
    float a, b, tol;
    cin >> a >> b >> tol;
    cout << find_root(&f, a, b, tol);
    return 0;
};
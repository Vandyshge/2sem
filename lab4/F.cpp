#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int* my_slightly_dumb_reallocation(int* source, unsigned int n_old, unsigned int n_new);

void print (int* a, int n) {
    for (auto i = 0; i < n; i++) {
        cout << *(a + i) << " ";
    }
    cout << endl << endl;
}

int main() {
    unsigned int n, i;
    cin >> n;
    int *a = my_slightly_dumb_reallocation(NULL, 0, n / 2);
    // print(a, n/2);
    for (i = 0; i < n / 2; i++)
        cin >> a[i];
    // print(a, n/2);
    a = my_slightly_dumb_reallocation(a, n / 2, n);
    // print(a, n);
    for (; i < n; i++)
        cin >> a[i];
    int sum = 0;
    for (i = 0; i < n; i++)
        sum += a[i];
    cout << sum << endl;
    a = my_slightly_dumb_reallocation(a, n, n / 2);
    a = my_slightly_dumb_reallocation(a, n / 2, 0);
    a = my_slightly_dumb_reallocation(a, 0, 0);
    return 0;
}

// int* my_slightly_dumb_reallocation (int* source, unsigned int n_old, unsigned int n_new) {
//     int *ps = new int [n_new];
//     if (source != NULL) {
//         if (n_new == 0) return NULL;
//         int a;
//         a = n_old;
//         if (a > n_new) a = n_new;
//         for (auto j = 0; j < a; j++) {
//             // cout << j << endl;
//             // print(ps, n_new);
//             *(ps + j) = *(source + j);
//             // print(ps, n_new);
//         }
//         delete[] source;
//     }
//     return ps;
// }


int* my_slightly_dumb_reallocation(int* source, unsigned int n_old, unsigned int n_new) {
    int* ps;
    if (source == NULL && n_new != 0) {
        ps = new int[n_new];
        delete[] source;
    } else if (n_new == 0) {
        ps = NULL;
        delete[] source;
    } else {
        ps = new int[n_new];
        if (n_new > n_old) {
            for (int i = 0; i < n_old; i++) ps[i] = source[i];
        } else {
            for (int i = 0; i < n_new; i++) ps[i] = source[i];
        }
        delete[] source;
        }
    return ps;
}
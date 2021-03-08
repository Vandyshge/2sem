#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int do_some_awesome_work(int* a, int* b);

int main() {
    int a, b, c;
    cin >> a >> b;
    int *pa = &a;
    int *pb = &b;
    c = do_some_awesome_work(pa, pb);
    cout << c;
    return 0;
}

int do_some_awesome_work (int* a, int* b) {
    return *a + *b;
}
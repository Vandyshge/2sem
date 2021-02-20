#include <iostream>
#include <string>

using namespace std;

int main()
{
    string h1, h2;
    int t1, t2, t3;
    cin >>  h1 >> h2;
    t1 = 3600 * (10 * ((int) h1[0] - 48) + ((int) h1[1] - 48)) + 60 * (10 * ((int) h1[3] - 48) + ((int) h1[4] - 48)) + (0 * ((int) h1[6] - 48) + ((int) h1[7] - 48));
    t2 = 3600 * (10 * ((int) h2[0] - 48) + ((int) h2[1] - 48)) + 60 * (10 * ((int) h2[3] - 48) + ((int) h2[4] - 48)) + (0 * ((int) h2[6] - 48) + ((int) h2[7] - 48));
    if (t1 <= t2) {
        t3 = t2 - t1;
    } else {
        t3 = t2 + 86400 - t1;
    }
    cout << t3;
    return 0;
}
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    int number;
    string s_number("");
    cin >> number;
    int n = 1;
    int number_i;
    int number_ii;
    int n_i;
    int n_ii;
    while (number > 0) {
        number_i = number % (int) pow(60, n);
        number -= number_i;
        number_ii = number_i / (int) pow(60, n - 1);
        if (n > 1) {
            s_number = "." + s_number;
        }
        n_i = 0;
        while (number_ii > 0) {
                n_ii = number_ii % 10;
                number_ii = (number_ii - n_ii) / 10;
                if (n_i == 0) {
                    for (auto j = 0; j < n_ii; j++) {
                        s_number = "v" + s_number;
                    }
                } else {
                    for (auto j = 0; j < n_ii; j++) {
                        s_number = "<" + s_number;
                    }
                };
                n_i++;
        }
        n++;
    }
    cout << s_number;
    return 0;
}
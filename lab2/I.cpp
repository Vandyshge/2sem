#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    string last_car("A999AA");
    int sum = 0;
    int vel;
    string number;
    cin >> vel >> number;
    while (number != last_car) {
        if (vel > 60) {
            if (number[1] == number[2] && number[2] == number[3]) {
                sum += 1000;
            } else if (number[1] == number[2] || number[1] == number[3] || number[2] == number[3]) {
                sum += 500;
            } else {
                sum += 100;
            };
        };
        cin >> vel >> number;
    }
    cout << sum << endl;
    return 0;
}
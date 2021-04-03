#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float sum = 0;
    float sum_sq = 0;
    float n = 0;
    float num;

    cin >> num;
    while (num != 0) {
        // cout << 1 << endl;
        sum += num;
        sum_sq += num*num;
        n++;
        cin >> num;
    }
    float mean = roundf(1000*(sum / n))/ 1000;
    float sq = roundf(1000*(sum_sq/n - sum*sum/(n*n)))/1000;
    if ((int) mean*1000 % 1000 == 0) {
        cout << mean << ".0" << " ";
    } else {
        cout << mean << " ";
    }
    if ((int) sq*1000 % 1000 == 0) {
        cout << sq << ".0" << " ";
    } else {
        cout << sq << " ";
    }

    // cout << typeid(round(10 * 100.3) / 10).name();
    // cout << round(10*100)/10;
    
    return 0;
}
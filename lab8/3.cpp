#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print (vector <vector <string>>* pv) {
    int i = 1;
    for (auto a: *pv) {
        cout << i;
        for (auto b: a) cout << b << " ";
        cout << endl;
        i++;
    }
    cout << endl;
}

int day_in_month(int month)
{
    if (month == 1) {
        return 28;
    } else if (month % 2 != 1) {
        return 31;
    } else {
        return 30;
    }
}

void add(vector <vector <string>>* pv, int i, string s)
{
    (*pv)[i-1].push_back(s);
}

void dump(vector <vector <string>>* pv, int i)
{
    int col = 0;
    for (auto a: (*pv)[i-1]) col++;
    cout << col << " ";
    for (auto a: (*pv)[i-1]) cout << a << " ";
    cout << endl;
}

void next1(vector <vector <string>>* pv, int *month, int *day)
{
    if (*month == 11) {
        *month = 0;
    } else {
        *month += 1;
    }
    int new_day = day_in_month(*month);
    if (new_day < *day) {
        for (auto i = 0; i < *day - new_day; i++) {
            for (auto a: (*pv)[*day - i - 1]) (*pv)[new_day - 1].push_back(a);
            (*pv)[*day - i - 1].clear();
        }
    }
    (*pv).resize(new_day);
}

int main()
{
    int N, month, day, k;
    cin >> N;
    month = 0;
    day = day_in_month(month);
    vector <vector <string>> v(31);
    vector <vector <string>> *pv = &v;
    string inp;
    int* pm = &month;
    int* pd = &day;

    for (int j = 0; j < N; j++) {
        cin >> inp;
        if (inp == "ADD") {
            cin >> k >> inp;
            add(pv, k, inp);
        } else if (inp == "DUMP") {
            cin >> k;
            dump(pv, k);
            // cout << 13 << endl;
        } else if (inp == "NEXT") {
            next1(pv, pm, pd);
            // cout << 12 << endl;
        }
        // cout << "-------------" << endl;
        // print(pv);
    }

    return 0;
}
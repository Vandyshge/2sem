#include <iostream>
#include <string>

using namespace std;
 
struct stek
{
    int value;
    struct stek *next;
};

void pop (stek* &NEXT, int* plev)
{
    int temp = NEXT->value;
    stek *MyStack = NEXT;
    NEXT = NEXT->next;
    delete MyStack;
    *plev -= 1;
}
 
void push (stek* &NEXT, const int VALUE, int* plev)
{
    stek *MyStack = new stek;
    MyStack->value = VALUE;
    MyStack->next = NEXT;
    NEXT = MyStack;
    *plev += 1;
}

void worry(int i, stek* &NEXT, int* plev)
{
    stek *MidleStek = NEXT;
    for (auto j = 0; j < i - 1; j++) {
        MidleStek = MidleStek->next;
        // cout << MidleStek->value;
    }
    MidleStek->value = 1;
}

void quiet(int i, stek* &NEXT, int* plev)
{
    stek *MidleStek = NEXT;
    for (auto j = 0; j < i - 1; j++) {
        MidleStek = MidleStek->next;
        // cout << MidleStek->value;
    }
    MidleStek->value = 0;
}

void come(stek* &NEXT, int k, int* plev)
{
    if (k >= 0) {
        // cout << "elpkf";
        for (auto i = 0; i < k; i++) push(NEXT, 0, plev);
    } else {
        for (auto i = 0; i < -k; i++) pop(NEXT, plev);
    }
}

int worry_cout(stek* &NEXT, int* plev)
{
    int cout = 0;
    stek *MidleStek = NEXT;
    for (auto j = 0; j < *plev - 1; j++) {
        if (MidleStek->value == 1) cout++;
        // cout << MidleStek->value;
        MidleStek = MidleStek->next;
    }
    if (MidleStek->value == 1) cout++;
    return cout;
}

void print(stek* &NEXT, int* plev) 
{
    stek *MidleStek = NEXT;
    for (auto j = 0; j < *plev-1; j++) {
        cout << MidleStek->value << " ";
        MidleStek = MidleStek->next;
    }
    if (*plev != 0) cout << MidleStek->value << endl;
}



int main()
{
    stek *p = 0;
    int lev = 0;
    int *plev = &lev;
    string inp;
    int N;
    cin >> N;
    int k;
    
    for (int j = 0; j < N; j++) {
        cin >> inp;
        if (inp == "COME") {
            cin >> k;
            come(p, k, plev);
            // cout << 11 << endl;
        } else if (inp == "WORRY_COUNT") {
            cout << worry_cout(p, plev) << endl;
            // cout << 13 << endl;
        } else if (inp == "WORRY") {
            cin >> k;
            worry(k, p, plev);
            // cout << 12 << endl;
        } else if (inp == "QUIET") {
            cin >> k;
            quiet(k, p, plev);
            // cout << 14 << endl;
        }
        // cout << "-------------" << endl;
        // print(p, plev);
    }

    
    
    return 0;
};
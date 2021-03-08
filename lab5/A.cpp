#include <iostream>

using namespace std;
 
struct stek
{
    int value;
    struct stek *next;
};

int pop (stek* &NEXT)
{
    int temp = NEXT->value;
    stek *MyStack = NEXT;
    NEXT = NEXT->next;
    delete MyStack;
    // cout << temp;
    return temp;
}
 
void push (stek* &NEXT, const int VALUE, int* plev)
{
    if (VALUE > 0) {
        stek *MyStack = new stek;
        MyStack->value = VALUE;
        MyStack->next = NEXT;
        NEXT = MyStack;
        *plev += 1;
    } else if (VALUE < 0) {
        if (*plev > 0) {
            if (-VALUE >= NEXT->value) {
                // cout << "efojrihduj";
                pop(NEXT);
                *plev -= 1;
            } else {
                NEXT->value += VALUE; 
            }
        }
    }
}

int main()
{
    stek *p = 0;
    int lev = 0;
    int *plev = &lev;
    
    int n;
    cin >> n;
    while (n != 0) {
        push(p, n, plev);
        // cout << lev << endl;
        cin >> n;
    }           
    // cout << "ojefvbjk" << endl;

    if (lev == 0) {
        cout << lev << " " << -1 << endl;
    } else {
        cout << lev << " " << pop(p) << endl;
    }
    return 0;
}
#include <iostream>
#include <string>

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
    stek *MyStack = new stek;
    MyStack->value = VALUE;
    MyStack->next = NEXT;
    NEXT = MyStack;
    *plev += 1;
}

int main()
{
    stek *p = 0;
    int lev = 0;
    int *plev = &lev;

    char inp;
    int res;
    int a, b;
    bool sign = false;
    int num = 0;
    cin >> noskipws;
    // cin >> inp;
    // // cout << inp;
    while (cin >> inp) {
        // cout << (int) inp << endl;
        if (num != 0 && inp == ' ') {
            push(p, num, plev);
            num = 0;
            sign = false;
        } else if (sign && (inp == ' ' || inp == '\n') && lev >= 2) {
            a = pop(p);
            b = pop(p);
            push(p, b - a, plev);
            sign = false;
            a = 0;
            b = 0;
        } else if (sign && num == 0 && inp != ' ') {
            num -= ((int) inp - 48);
        } else if (sign && num != 0 && inp != ' ') {
            num = num*10 - (int) inp + 48; 
        } else if (inp == '-' && num == 0) {
            sign = true;
        } else if (num == 0 && inp <= '9' && inp >= '0') {
            num += (int) inp - 48;
        } else if (num != 0 && inp <= '9' && inp >= '0') {
            num = num*10 + (int) inp - 48;
        } else if (inp == '+' && lev >= 2) {
            push(p, pop(p) + pop(p), plev);
        } else if (inp == '*' && lev >= 2) {
            push(p, pop(p) * pop(p), plev);
        // } else if (inp == '-' && lev >= 2) {
        //     a = pop(p);
        //     b = pop(p);
        //     push(p, b - a, plev);
        } else if (inp == '/' && lev >= 2) {
            a = pop(p);
            b = pop(p);
            push(p, b / a, plev);
            a = 0;
            b = 0;
        }
        if (inp == '\n') break;
        
        // cin >> inp;
        // push(p, n, plev);
        // cout << p->value << endl;
    }           
    // cout << "finish" << endl;
    cout << pop(p) << endl;
    
    return 0;
};
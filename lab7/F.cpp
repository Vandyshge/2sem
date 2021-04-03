#include <iostream>
#include <string>

using namespace std;
 
struct stek
{
    int value;
    struct stek *next;
};

struct queue
{
    struct stek *rerp;
    struct stek *frnt;  
};

int pop (queue* &NEXT, int* plev)
{
    int temp = NEXT->frnt->value;
    stek *MyStack = NEXT->frnt;
    NEXT->frnt = NEXT->frnt->next;
    delete MyStack;
    // cout << temp;
    *plev -= 1;
    return temp;
}
 
void push (queue* &NEXT, const int VALUE, int* plev)
{
    stek *MyStack = new stek;
    MyStack->value = VALUE;
    MyStack->next = NULL;
    if (*plev > 1) {
        stek *LastStek = NEXT->frnt;
        for (auto i = 0; i < (*plev-1); i++) LastStek = LastStek->next;
        LastStek->next = MyStack;
    } else if (*plev == 0) {
        NEXT->frnt = MyStack;
    } else if (*plev == 1) {
        // cout << "ertg " << NEXT->frnt->value << " " << NEXT->rerp->value << endl;
        NEXT->frnt->next = MyStack;
    }
    NEXT->rerp = MyStack;
    *plev += 1;
}

void midle (queue* &Queue, const int VALUE, int* plev)
{
    stek *MyStack = new stek;
    MyStack->value = VALUE;
    int n = (*plev + 1) / 2 - 1;
    stek *MidleStek = Queue->frnt;
    for (auto i = 0; i < n; i++) MidleStek = MidleStek->next;
    // cout << MidleStek->value << endl;
    stek *NextMidleStek = MidleStek->next;
    MidleStek->next = MyStack;
    MyStack->next = NextMidleStek;
    *plev += 1;
}

void print (queue* &NEXT, int* plev)
{
    stek *LastStek = NEXT->frnt;
    for (auto i = 0; i < *plev; i++) {
        cout << LastStek->value << " ";
        LastStek = LastStek->next;
    }
    cout << endl;
}

int main()
{
    queue *p = new queue;
    int lev = 0;
    int *plev = &lev;

    int N;
    string inp;
    getline(cin, inp);
    N = stoi(inp);
    int num;
    for (auto i = 0; i < N; i++) {
        getline(cin, inp);
        // cout << inp << endl;
        if (inp[0] == '-') {
            cout << pop(p, plev) << endl;
        } else if (inp[0] == '+') {
            inp = inp.substr(2);
            num = stoi(inp);
            push(p, num, plev);
        } else if (inp[0] == '*') {
            inp = inp.substr(2);
            num = stoi(inp);
            if (*plev == 0) {
                push(p, num, plev);
            } else {
                midle(p, num, plev);
            }
        }
        // print(p, plev);
    }
    return 0;
};
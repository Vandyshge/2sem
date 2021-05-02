#include <iostream>
#include <string>
#include <vector>

using namespace std;




int main()
{
    vector <int> v;
    vector <int>* pv;
    cout << pv << endl;
    pv = &v;
    cout << pv; 
    return 0;
};
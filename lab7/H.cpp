#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print (vector <int> v, int N) 
{
    for (auto i = 0; i < N; i++) 
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    int N;
    cin >> N;
    vector <int> v(N);
    vector <int> elems;
    int elem;
    for (auto i = 0; i < N; i++) 
    {
        cin >> elem;
        if (elem < 0) elems.push_back(i);
        v[i] = elem;
    }
    // print(elems, elems.size());

    int lenth = N+1;
    int n;
    for (auto i = 0; i < elems.size(); i++) 
    {
        n = elems[i];
        // cout << elems[i];
        for (auto j = n+1; j < N; j++) 
        {
            // cout << v[j] << " " << v[n] << endl;
            if (v[j] == v[n]) break;
            if (v[j] == - v[n]) 
            {
                if (lenth > j - n) 
                {
                    lenth = j - n;
                    // cout << "new lenth " << lenth << endl;
                    break;
                }
            }
        }
    }

    // print(v, v.size());
    if (lenth == N+1) 
    {
        cout << 0 << endl;
    } else 
    {
        cout << lenth << endl;
    }
    

    return 0;
}
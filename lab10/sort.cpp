#include <iostream>
#include <string>
#include <vector>


using namespace std;


void print(vector<int>& v) {
    for (auto a:v) {
        cout << a << " ";
    }
    cout << endl;
}

void print1(vector<int>& v, int l, int r) {
    for (auto i = l; i <= r; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void bubble_sort(vector<int>& v) {
    int temp;
    for (int i = 1; i < v.size(); i++) {
        for (int j = 0; j < v.size()-i; j++) {
            if (v[j] > v[j+1]) {
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
}


void comb_sort(vector<int>& v) {
    const double factor = 1.247;
    double size = v.size() - 1;
    int temp;

    while (size > 1) {
        for (auto i = 0; i + size < v.size(); i++) {
            if (v[i] > v[i+size]) {
                temp = v[i];
                v[i] = v[i+size];
                v[i+size] = temp;
            }
        }
        size /= factor;
    }


    // for(int i = 1; i < v.size(); i++) {
    //     for(int j = 0; j < v.size()-i; j++) {
    //         if(v[j] > v[j+1]) {
    //             temp = v[j];
    //             v[j] = v[j+1];
    //             v[j+1] = temp;
    //         }
    //     }
    // }
}


void selection_sort(vector<int>& v) {
    int temp;
    int min;

    for (int i = 0; i < v.size(); i++) {
        min = i;
        for (int j = i + 1; j < v.size(); j++) {
            if (v[min] > v[j]) {
                min = j;
            }
        }
        temp = v[min];
        v[min] = v[i];
        v[i] = temp;
    }
}

void q_sort_r(vector<int>& v, int r, int l) {
    int p;
    int wall = r;
    int temp;
    
    while (v[l] > v[wall]) wall++;
    p = wall;
    
    while (p < l) {
        if (v[p] < v[l]) {
            temp = v[wall];
            v[wall] = v[p];
            v[p] = temp;
            wall++;
        }
        p++;
    }
    
    if (wall != l) {
        temp = v[wall];
        v[wall] = v[l];
        v[l] = temp;
    }

    if ((wall-r) > 1) q_sort_r(v, r, wall-1);
    if ((l-wall) > 1) q_sort_r(v, wall+1, l);
}

void q_sort(vector<int>& v) {
    q_sort_r(v, 0, v.size()-1);
}

void merge_sort_r(vector<int>& v, int l, int r) {
    if ((r-l) >= 1) {
        int p = (l + r) / 2;
        // print1(v, l, r);
        merge_sort_r(v, l, p);
        merge_sort_r(v, p+1, r);
        
        // print1(v, l, r);

        // int temp;
        // int elem;
        int i = l;
        int j = p+1;

        vector <int> v1;
        while ((i <= p) && (j <= r)) {
            if (v[i] < v[j]) {
                v1.push_back(v[i]);
                i++;
            } else {
                v1.push_back(v[j]);
                j++;
            }
        }

        while (i <= p) {
            v1.push_back(v[i]);
            i++;
        }

        while (j <= r) {
            v1.push_back(v[j]);
            j++;
        }

        for (auto x = 0; x < v1.size(); x++) {
            v[l + x] = v1[x];
        }
    }
}

void merge_sort(vector<int>& v) {
    // cout << "----" << endl;
    merge_sort_r(v, 0, v.size()-1);
}


void form(vector<int>& v, int i, int n) {
    // cout << "haha" << endl;
    int root = i;
    int l = 2*root+1;
    int r = 2*root+2;
    int ch;

    
    if (l < n && v[root] < v[l]) {
        root = l;
        ch = l;
    }
    
    if (r < n && v[root] < v[r]) {
        root = r;
        ch = r;
    }

    if (root != i) {
        int temp = v[i];
        v[i] = v[root];
        v[root] = temp;
        form(v, ch, n);
    }
    
}


void heap_sort(vector<int>& v) {
    for (int i = v.size()/2 - 1; i >= 0; i--) {
        form(v, i, v.size());
    }
    
    // cout << " alo " << endl;
    for (int i = v.size()-1; i > -1; i--) {
        // cout << i << endl;
        int temp = v[0];
        v[0] = v[i];
        v[i] = temp;
        form(v, 0, i);
    }
}


// int main()
// {
//     vector <int> v = {9, 8, 7, 6, 5, 4, 3, 2, 1};
// //     // int inp;
// //     // cin >> inp;
// //     // while (inp != 0) {
// //     //     v.push_back(inp);
// //     //     cin >> inp;
// //     // }
//     print(v);
//     q_sort(v);
//     print(v);

//     return 0;
// };
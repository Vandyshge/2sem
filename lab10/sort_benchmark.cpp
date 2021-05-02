#include<vector>
#include<chrono>
#include<random>
#include<iostream>
#include<algorithm>
#include<cassert>
#include <fstream>
#include "sort.cpp"
#include <string>
// #include <boost>

using namespace std;
using namespace std::chrono;

constexpr int max_value = 100000;

vector<int> generate_random_vector(uint64_t n) {

    vector<int> ret(n);

    //это математически строгий и надежный способ генерировать случайные числа
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, max_value);

    for (int i = 0; i < n; ++i) {
        ret[i] = dist(gen);
    }

    return ret;
}

vector<int> generate_good_vector(uint64_t n) {

    vector<int> ret(n);

    for (int i = 0; i < n; ++i) {
        ret[i] = i;
    }

    return ret;
}

vector<int> generate_bad_vector(uint64_t n) {

    vector<int> ret(n);

    for (int i = n-1; i > -1; --i) {
        ret[n-i-1] = i;
    }

    return ret;
}


//это магическая строчка
//благодаря этому функция может принимать аргумент произвольного типа
//название для конкретно этого типа вы придумываете сами (я назвал его SortFunction)
template<typename SortFunction, typename Generate_vector>
double benchmark(SortFunction f, Generate_vector g, uint64_t n) {

    auto v = g(n);
    // print(v);

    auto start = steady_clock::now();
    //время засекается внутри этого блока
    f(v);
    auto finish = steady_clock::now();

    //это проверка на то, верно ли проведена сортировка
    //в случае ошибки программа падает с сообщением "assertion failed"
    assert(is_sorted(begin(v), end(v)));
    // if (is_sorted(begin(v), end(v))) {
    //     cout << "1" << endl;
    //     print(v);
    // } else {
    //     cout << "2" << endl;
    //     print(v);
    // }

    //возвращаем время работы в мс
    return duration_cast<milliseconds>(finish - start).count();
}

template<typename SortFunction>
void time_sort(string s, SortFunction f) {
    ofstream out;
    out.open(s + ".txt");
    double t;
    double N = 1000;
    double N1 = 100;
    vector <int> quan;
    vector <double> time;

    // out << "generate_random_vector\n"; 
    // cout << "generate_random_vector" << endl; 
    // for (auto n = 550; n < 1000; n += 50) {
    //     t = 0;
    //     quan.push_back(n);
    //     cout << n << endl;
    //     for (auto i = 0; i < N; i++) {
    //         t += benchmark(f, generate_random_vector, n);
    //     }
    //     time.push_back(t/N);
    //     // cout << t/N;
        
    //     // out << "\n";
    // }
    // // print(quan);
    // // print(time);
    // for (auto i = 0; i < quan.size(); i++) {
    //     out << quan[i] << " ";
    // }
    // out << "\n";
    // for (auto i = 0; i < time.size(); i++) {
    //     out << time[i] << " ";
    // }
    // out << "\n";
    // quan.clear();
    // time.clear();
    

    // out << "generate_good_vector\n"; 
    // cout << "generate_good_vector" << endl; 
    // for (auto n = 550; n < 1000; n += 50) {
    //     t = 0;
    //     quan.push_back(n);
    //     cout << n << endl;
    //     for (auto i = 0; i < N; i++) {
    //         t += benchmark(f, generate_good_vector, n);
    //     }
    //     time.push_back(t/N);
    // }
    // // print(quan);
    // // print(time);
    // for (auto i = 0; i < quan.size(); i++) {
    //     out << quan[i] << " ";
    // }
    // out << "\n";
    // for (auto i = 0; i < time.size(); i++) {
    //     out << time[i] << " ";
    // }
    // out << "\n";
    // quan.clear();
    // time.clear();

    // out << "generate_bad_vector\n"; 
    // cout << "generate_bad_vector" << endl;
    // for (auto n = 550; n < 1000; n += 50) {
    //     t = 0;
    //     quan.push_back(n);
    //     cout << n << endl;
    //     for (auto i = 0; i < N; i++) {
    //         t += benchmark(f, generate_bad_vector, n);
    //     }
    //     time.push_back(t/N);
    // }
    // // print(quan);
    // // print(time);
    // for (auto i = 0; i < quan.size(); i++) {
    //     out << quan[i] << " ";
    // }
    // out << "\n";
    // for (auto i = 0; i < time.size(); i++) {
    //     out << time[i] << " ";
    // }
    // out << "\n";
    // quan.clear();
    // time.clear();

    // (auto n = 33000; n < 43000; n += 1000)
    // (auto n = 50000; n < 100000; n += 5000)
    out << "generate_random_vector\n"; 
    cout << "generate_random_vector" << endl; 
    for (auto n = 50000; n < 100000; n += 5000) {
        t = 0;
        quan.push_back(n);
        cout << n << endl;
        for (auto i = 0; i < N1; i++) {
            t += benchmark(f, generate_random_vector, n);
        }
        time.push_back(t/N1);
    }
    // print(quan);
    // print(time);
    for (auto i = 0; i < quan.size(); i++) {
        out << quan[i] << " ";
    }
    out << "\n";
    for (auto i = 0; i < time.size(); i++) {
        out << time[i] << " ";
    }
    out << "\n";
    quan.clear();
    time.clear();

    // out << "generate_good_vector\n"; 
    // cout << "generate_good_vector" << endl; 
    // for (auto n = 33000; n < 43000; n += 1000) {
    //     t = 0;
    //     quan.push_back(n);
    //     cout << n << endl;
    //     for (auto i = 0; i < N1; i++) {
    //         t += benchmark(f, generate_good_vector, n);
    //     }
    //     time.push_back(t/N1);
    // }
    // // print(quan);
    // // print(time);
    // for (auto i = 0; i < quan.size(); i++) {
    //     out << quan[i] << " ";
    // }
    // out << "\n";
    // for (auto i = 0; i < time.size(); i++) {
    //     out << time[i] << " ";
    // }
    // out << "\n";
    // quan.clear();
    // time.clear();

    // out << "generate_bad_vector\n"; 
    // cout << "generate_bad_vector" << endl;
    // for (auto n = 33000; n < 43000; n += 1000) {
    //     t = 0;
    //     quan.push_back(n);
    //     cout << n << endl;
    //     for (auto i = 0; i < N1; i++) {
    //         t += benchmark(f, generate_bad_vector, n);
    //     }
    //     time.push_back(t/N1);
    // }
    // // print(quan);
    // // print(time);
    // for (auto i = 0; i < quan.size(); i++) {
    //     out << quan[i] << " ";
    // }
    // out << "\n";
    // for (auto i = 0; i < time.size(); i++) {
    //     out << time[i] << " ";
    // }
    // out << "\n";
    out << "N(small) = " << N << "; N(huge) = " << N1 << "\n";
}

int main() {
    // for (auto n = 50000; n < 100000; n += 10000) {
    //     out << n << "\n";
    // }
    // cout << benchmark(q_sort, generate_random_vector, 10);
    // vector <int> v = generate_random_vector(100);
    // print(v);

    time_sort("comb_sort", comb_sort);

    // cout << boost::format("%d.txt", "bubble_sort");


    


    return 0;
}
#include <sstream>
#include <iostream>
#include "set.cpp"
#include <vector>
#include <set>


using namespace std;
using namespace avl;

template <typename Type>
void PrintSet(const Set<Type>& s, ostream& os)
{
  os << "\"";
  bool is_first = true;
  for (auto it = s.front(); it != s.back(); it = s.next(it))
  {
    if (!is_first)
      os << " ";
    is_first = false;
    os << it->value;
  }
  if (s.back() != nullptr)
  {
    if (!is_first)
      os << " ";
    os << s.back()->value;
  }
  os << "\"";
}

template <typename Type>
void PrintSet(const set<Type>& s, ostream& os)
{
  os << "\"";
  bool is_first = true;
  for (const auto& elem : s)
  {
    if (!is_first)
      os << " ";
    is_first = false;
    os << elem;
  }
  os << "\"";
}


int main()
{
  {
    Set<int> s;
    cout << "CheckEmpty size check " << (s.size() == 0 ? " succeeded, size = 0" : " failed, size != 0") << endl;
    cout << "CheckEmpty find check " << (s.find(1) ? " failed, element is found inside an empty set" : " succeeded, element is not found inside an empty set") << endl;
  }
  {
    Set<int> s;
    s.insert(1);
    if (s.front()->value != 1 || s.back()->value != 1)
      cout << "Problem with insertion or iterators, inserted 1" << endl;
    s.insert(2);
    if (s.front()->value != 1 || s.back()->value != 2)
      cout << "Problem with insertion or iterators, inserted 1 and 2" << endl;
    if (s.next(s.front()) != s.back())
      cout << "Problem with next() method" << endl;
    if (s.previo(s.back()) != s.front())
      cout << "Problem with previo() method" << endl;
  }
  {
    Set<int> s;
    set<int> check_set;
    vector<int> numbers = {4, 2, 7, 3, 6, 8, 5, 3, 6, 9};
    vector<int> different_numbers = {10, 11, 50, 0, 1};
    {
      bool success = true;
      for (auto n : numbers)
      {
        s.insert(n);
        check_set.insert(n);
        stringstream ss;
        stringstream ss_check;
        PrintSet(s, ss);
        PrintSet(check_set, ss_check);
        if (ss.str() != ss_check.str())
        {
          cout << "Check failed, after insertion of " << n << " set is " << ss.str() << " instead of " << ss_check.str() << endl;
          success = false;
        }
      }
      if (success)
        cout << "Insertion check ok" << endl;
      else
        cout << "Insertion check failed" << endl;
    }
    {
      bool success = true;
      for (auto n :numbers)
      {
        if (!s.find(n))
        {
          cout << "Check failed, unable to find " << n << " in your set" << endl;
          success = false;
        }
      }
      if (success)
        cout << "Find existing check ok" << endl;
      else
        cout << "Find existing check failed" << endl;
    }
    {
      bool success = true;
      for (auto n : different_numbers)
      {
        if (s.find(n))
        {
          cout << "Check failed, " << n << " found in your set but should not have been" << endl;
          success = false;
        }
      }
      if (success)
        cout << "Not find not existing check ok" << endl;
      else
        cout << "Not find not existing check failed" << endl;
    }
    {
      s.PrintSet1();
      bool success = true;
      for (auto n : numbers)
      {
        auto result = s.erase(n);
        // cout << "-----" << endl;
        auto check_result = check_set.erase(n);
        if (result != check_result)
        {
          cout << "Check failed, " << (result ? " true was returned and an element must not have been deleted" : " false was returned and the element should have been deleted") << endl;
        }
        stringstream ss;
        stringstream ss_check;
        cout << "-----" << endl;
        s.PrintSet1();
        // PrintSet(s, ss);
        // // cout << "-----" << endl;
        // PrintSet(check_set, ss_check);
        // // cout << "----- ------" << endl;
        // if (ss.str() != ss_check.str())
        // {
        //   cout << "Check failed, after deletion of " << n << " set is " << ss.str() << " instead of " << ss_check.str() << endl;
        //   success = false;
        // }
      }
      if (success)
        cout << "Erasing check ok" << endl;
      else
        cout << "Erasing check failed" << endl;
    }
  }
  return 0;
}

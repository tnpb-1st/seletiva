#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
// g++ -std=c++14 main.cpp -o main && time ./main

template<class T>
void printAll(T &cont)
{
    for(auto it = cont.begin(); it != cont.end(); it++)
    {
        cout << *it;
        it++;cout<< " \n"[it == cont.end()];it--;
    }
}

int main()
{
    string anagram = "1234";
    printAll(anagram);
    while(next_permutation(anagram.begin(), anagram.end()))
    {
        printAll(anagram);
    }
}

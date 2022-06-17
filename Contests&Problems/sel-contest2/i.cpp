#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define pq priority_queue
using namespace std;
typedef long long ll;
// typedef __int128_t bgl;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
// range of int values -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)
// g++ -std=c++14 -O2 -Wall test.cpp -o main

void solve()
{
	string w1 ,w2;
    map<string,string> dic;
    while(getline(cin,w1) && w1 != "" && w1.find(' ') != w1.npos)
    {
        w2 = w1.substr(w1.find(' ') + 1);
        w1 = w1.substr(0, w1.find(' '));
        dic[w2] = w1;
        // cout<<w2<<' '<<w1<<endl;
    }
    while(getline(cin,w1))
    {
        if(dic.find(w1)!=dic.end())
        {
            cout<<dic[w1]<<endl;
        }
        else
        {
            cout<<"eh"<<endl;
        }
    }
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	solve();
	return 0;
}
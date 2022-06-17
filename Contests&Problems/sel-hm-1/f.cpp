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
    string s;
    while(getline(cin,s) && s!= "0")
    {
        stringstream N(s);
        int n;
        N>>n;
        string st;
        while(getline(cin,s) && s!= "0")
        {
            queue<int> Q;
            stack<int> S;
            int x;
            stringstream SS(s);
            while(SS >> x)
            {
                Q.push(x);
            }

            bool possible = true;
            int ele = 1;
            while(!Q.empty())
            {
                if(Q.front() == ele)
                {
                    Q.pop();
                    ele++;
                }
                else if(!S.empty() && S.top() == Q.front())
                {
                    S.pop();
                    Q.pop();
                }
                else if(Q.front() != ele && ele <= n)
                {
                    S.push(ele);
                    ele++;
                }
                else
                {
                    possible = false;
                    break;
                }
            }
            if(possible)
                cout << "Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
        if(s=="0")cout<<endl;
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
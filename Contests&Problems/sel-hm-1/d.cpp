#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
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
	int t, n;
    while(cin >> t && t>0)
    {
        cin.ignore();
        stack<int> S;
        queue<int> Q;
        int next = 1;
        int x; n = t;
        bool ans = true;
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            Q.push(x);
        }
        while(next < n)
        {
            if(!S.empty() && S.top() == next)
            {
                S.pop();
                next++;
                continue;
            }
            else if(Q.front() == next)
            {
                Q.pop();
                next++;
            }
            else if(!Q.empty()){
                S.push(Q.front());
                Q.pop();
            }
            else 
            {
                ans = false;
                break;
            }
        }
        if(ans)
            cout << "yes"<<endl;
        else
            cout<<"no"<<endl;
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
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
	int t;
    cin >> t;
    while(t--)
    {
        deque<int> dq;
        int n, x;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            if(!dq.size())
                dq.pb(x);
            else
            {
                if (dq.front() > x)
                    dq.push_front(x);
                else
                {
                    dq.pb(x);
                }
            }
        }
        while(!dq.empty())
        {
            cout<<dq.front()<<' ';
            dq.pop_front();
        }
        cout<<endl;
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
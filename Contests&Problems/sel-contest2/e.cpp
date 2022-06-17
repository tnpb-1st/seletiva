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
        int n, x;
        pq<pii> ppl;
        stack<string> ans;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            if(x > 0)
            {
                pii ele = {x, i+1};
                ppl.push(ele);
            }
        }
        while(ppl.size() > 1)
        {
            pii a, b;
            a = ppl.top();
            ppl.pop();
            b = ppl.top();
            ppl.pop();
            a.first -= 1;
            b.first -= 1;
            if(a.first > 0)
                ppl.push(a);
            if(b.first > 0)
                ppl.push(b);
            string s = to_string(b.second) + ' ' + to_string(a.second) + '\n';
            ans.push(s);
        }
        cout<<ans.size()<<endl;
        while(!ans.empty())
        {
            cout<<ans.top();
            ans.pop();
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

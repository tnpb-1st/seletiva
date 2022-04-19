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
	int n;
    cin >> n;
    map<ll, set<ll>> mp;
    set<string> my_set;
    vector<pair<ll,ll>> V;
    ll x, y;
    int ans = 0;
    while(n--)
    {
        cin >> x >> y;
        mp[x].emplace(y);
        mp[y].emplace(x);
        V.push_back({x,y});
    }
    for(int i = 0; i < V.size(); i++)
    {
        for(int j = i+1; j < V.size(); j++)
        {
            ll x1, x2, y1, y2, xc, yc;
            // bool c1, c2, c3;
            // c1 = c2 = c3 = false;
            pair<ll,ll> p1, p2;
            p1 = V[i];
            p2 = V[j];
            x1 = p1.first, y1 = p1.second;
            x2 = p2.first, y2 = p2.second;
            string ele = "";
            ele+= to_string(min(x1,x2)) + to_string(max(x2,x1));
            if(x1 == x2 || y1 == y2 && (my_set.find(ele) == my_set.end()))
            {
                xc = (x1+x2)/2;yc = (y1+y2/2);
                if (mp[xc].find(yc)!= mp[xc].end())
                {
                    int local_ans = 0;
                    if(yc == y1)
                    {
                        local_ans += mp[yc].size() - 1; 
                    }
                    else
                    {
                        local_ans += mp[xc].size() - 1;
                    }
                    ans+= local_ans;
                    my_set.emplace(ele);
                }
            }
        }
    }
    cout<<ans<<endl;
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
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

class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const pii &p1, const pii &p2) const
  {
    if (reverse) return (p1.first>p2.first);
    else return (p1.first<p2.first);
  }
};

void solve()
{
	int n, k, x;
    cin >> n >> k;
    int A[n];
    set<int> indexes;
    pq<pii, vector<pii>,mycomparison> pairs; 
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        pii pr = make_pair(x,i);
        pairs.emplace(pr);
        indexes.emplace(i);
    }
    bool t1 = true;
    while(!pairs.empty())
    {
        pii my_pr = pairs.top();
        pairs.pop();
        int pos = my_pr.second;
        if(!indexes.count(pos))continue;
        vi Players;
        Players.pb(pos);
           
        int l,r;
        auto it = indexes.find(pos);
        for(int i = 0; i<=k;i++)
        {
            l = *it;
            Players.pb(l);
            if(it==indexes.begin())break;
            --it;
        }
        it = next(indexes.find(pos));
        for(int i = 0; i<k;i++)
        {
            r = *it;
            if(it==indexes.end())break;
            Players.pb(r);
            ++it;
        }
        for(auto &i:Players)
        {
            if(t1)
                A[i] = 1;
            else
                A[i] = 2;
            indexes.erase(i);
        }
        t1 = !t1;
    }
    for(auto &x:A)cout<<x;
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
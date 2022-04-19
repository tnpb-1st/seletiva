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
bool my_greater(int i, int j) {return i > j;}
bool standard(int i, int j) {return i < j;}

void solve()
{
	int n;
    cin >> n;
    int A[n], B[n], C[n], D[n];
    for(int i = 0; i < n; i++)
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    vector<ll> AB, CD;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
           AB.pb(A[i] + B[j]);
           CD.pb(C[i] + D[j]);
        }
    }

    int ans = 0;
    sort(all(CD));
    for(int i = 0; i < AB.size(); i++)
    {
        auto p = equal_range(CD.begin(), CD.end(), -1 * AB[i], standard);
        ans += (p.second-p.first);
    }
    cout<<ans;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	solve();
	return 0;
}

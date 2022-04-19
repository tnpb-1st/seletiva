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
	int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    pii A[n+1] = {};
    A[0] = {0,0};
    int acont, bcont;
    acont = bcont = 0;

    for(int i = 1; i <= n; i++)
    {
        if(s[i-1] == 'a') acont++;
        else bcont++;
        A[i] = {acont , bcont};
    }
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        int l = i, r = n-1, mid, x;
        while(l < r)
        {
            mid = l + (r - l + 1)/2;
            x = min(A[mid+1].first - A[i].first, A[mid+1].second - A[i].second);
            if(x <= k)
                l = mid;
            else
                r = mid - 1;
        }
        res = max(res, r - i + 1);
    }
    cout << res;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);

	solve();
	return 0;
}

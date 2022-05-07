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
int MAX = INT_MAX;

int lowerBound(int x, vector<ll> &vec) {
    int l = 0, r = vec.size(), mid, ans;
    while (l < r) {
        mid = l + (r-l)/2;
        if(x <= vec[mid]) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if(l < (int)vec.size() && vec[l] < x) l++;
    return l;
}

int upperBound(int x, vector<ll> &vec) {
    int l = 0, r = vec.size(), mid, ans;
    while(l < r) {
        mid = l + (r-l)/2;
        if(x >= vec[mid]) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    if(l < vec.size() && vec[l] <= x) l++;
    return l;
}

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
           AB.pb(A[i]+B[j]);
           CD.pb(C[i]+D[j]);
        }
    }

    int ans = 0;
    sort(all(CD));
    for(int i = 0; i < (int) AB.size(); i++)
    {
        auto bounds = equal_range(CD.begin(),CD.end(),-1*AB[i]);
        ans += (bounds.second - bounds.first); 
    }
    cout<<ans;
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

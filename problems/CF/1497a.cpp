#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()
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
        int n;
        cin >> n;
        vi A(n);
        vi B;
        for(int i = 0; i < n; i++)
            cin >> A[i];
        
        sort(all(A));
        for(int i = 0; i < n; i++)
        {
            if(i == 0)
                B.pb(A[i]);
            else
            {
                if(A[i] != A[i-1])
                    B.pb(A[i]);
            }
        }

        for(int i = 1; i < n; i++)
        {
            if(A[i] == A[i-1])
                B.pb(A[i]);
        }

        for(auto &x:B)
            cout << x << " ";
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
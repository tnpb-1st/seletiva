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
        int x; cin >> x;
        bool poss = false;
        int max_low, max_larg;
        max_low = ceil(x/3);
        max_larg = ceil(x/7);
        for(int l = 0; l <= max_low; l++)
        {
            for(int lg = 0; lg <= max_larg; lg++)
            {
                if(lg*7 + l*3 == x)
                {
                    poss = true;
                    break;
                }
            }
        }
        if(poss)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
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
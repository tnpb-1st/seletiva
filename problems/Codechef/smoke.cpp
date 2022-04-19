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
        int n, b, c;
        cin >> n >> b >> c;
        int max_b = ceil((float)n/100), max_c = ceil((float)n/4);
        int min_v = max_b * b;
        for(int i = 0; i <= max_b; i++)
        {
            for(int j = 0; j <= max_c; j++)
            {
                int pb = i * b + j * c;
                if((100*i + 4*j >= n) && (min_v > pb))
                {
                    min_v = pb;
                    break;
                }
            }
        }
        cout << min_v<<endl;
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
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
        ll x,y;
        int cont = 0;
        string s,d;
        cin >> x;

        s = bitset<30>(x).to_string();
        d = "";
        for(auto &c:s)
        {
            if(cont < 1)
            {
                if(c == '1')
                {
                    cont++;
                }
                d+='0';
            }
            else
            {
                d+='1';
            }
        }
        y = bitset<30>(d).to_ulong();
        cout<<y<<endl;
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
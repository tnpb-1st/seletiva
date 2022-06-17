#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
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
    while (cin >> t)
    {
        if(t == 0)break;
        map<string, int> F;
        string s;
        vector<string> S(5);
        int maxF = 0;
        for(int i = 0; i < t; i++)
        {
            string sum = "";
            for (int i = 0; i < 5; i++)
            {
                cin >> S[i];
            }
            sort(all(S));
            for(auto &x:S)
                sum+=x;
            if(F.find(sum)!=F.end())
            {
                F[sum]++;
                maxF = max(maxF, F[sum]);
            }else
            {
                F[sum] = 1;
                maxF = max(maxF,1);
            }
        }

        int res = 0;
        for(auto &pair:F)
        {
            if(pair.second == maxF)
                res += pair.second;
        }
        cout << res << endl;
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
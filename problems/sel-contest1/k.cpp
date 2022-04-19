#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
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
	string s;
    while(getline(cin,s))
    {
        vi F(3001,0);
        vi A;
        stringstream S(s);
        int x, n;
        S >> n;
        while(S >> x)
        {
            A.pb(x);
        }
        int dif;
        for(int i = 1; i <(int) A.size(); i++)
        {
            dif = abs(A[i] - A[i-1]);
            F[dif]++;
        }
        bool ans = true;
        for(int i = 1; i < n; i++)
        {
            if(F[i] == 0)
            {
                ans = false;
                break;
            }
        }

        if(ans)
            cout<<"Jolly"<<endl;
        else
            cout<<"Not jolly"<<endl;
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
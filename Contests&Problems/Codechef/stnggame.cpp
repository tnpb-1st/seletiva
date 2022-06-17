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
        int n;
        cin >> n;
        deque<char> A, B;
        queue<char> ansb;
        stack<char> ansf;
        bool turn = true;
        char c;
        for(int i = 0; i < n; i++)
        {
            cin >> c;
            A.pb(c);
        }
        for(int i = 0; i < n; i++)
        {
            cin >> c;
            B.pb(c);
        }
        int cont = 0;
        sort(all(A));
        sort(B.rbegin(),B.rend());
        while(cont < 2*n)
        {
            if(turn)
            {
                if(A.front() < B.front())
                {
                    ansb.push(A.front());
                    A.pop_front();
                }
                else
                {
                    ansf.push(A.back());
                    A.pop_back();
                }
            }
            else
            {
                if(!A.empty() && B.front() > A.front())
                {
                    ansb.push(B.front());
                    B.pop_front();
                }
                else
                {
                    ansf.push(B.back());
                    B.pop_back();
                }
            }
            turn = !turn;
            cont++;
        }
        while(!ansb.empty())
        {
            cout<<ansb.front();
            ansb.pop();
        }
        while(!ansf.empty())
        {
            cout<<ansf.top();
            ansf.pop();
        }
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
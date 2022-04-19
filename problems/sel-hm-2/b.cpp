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
bool checkM(pii &my_pair, vector<vi> &Matrix)
{
    int l = my_pair.first,c = my_pair.second;
    if(Matrix[l][c] == 1)
        return true;
    return false;
}

void solve()
{
    int A[] = {-2, -1, 1, 2};
	string inp;
    while(getline(cin, inp) && inp!="0")
    {
        vector<vi> Matrix(10), Pos(10);
        stringstream SS(inp);
        int sqrs = 0;
        int n, b, off;
        SS >> n;
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                Matrix[i].pb(-1);
                Pos[i].pb(-1);
            }
        }
        for(int i = 0; i < n; i++)
        {
            SS >> b >> off;
            for(int col = b; col < b + off; col++){
                Matrix[i][col] = 1;
                Pos[i][col] = 0;
                sqrs++;
            }
        }
        auto tranverseBoard = [&](pii &my_pair, queue<pii> &my_q, int &res)
        {
            int l = my_pair.first, c=my_pair.second;
            for(auto f1:A)
            {
                for(auto f2:A)
                {
                    if(abs(f1) + abs(f2) == 3)
                    {
                        if(l + f1 >= 0 && l +f1 < 10)
                        {
                            if(c + f2 >= 0 && c + f2 < 10)
                            {
                                if(Matrix[l + f1][f2 + c] == 1)
                                {
                                    if(Pos[l+f1][f2+c] == 0)
                                    {
                                        my_q.push({l + f1, c + f2});
                                        Pos[l+f1][f2+c] = 1;
                                        res++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        };
        int res = 0;
        queue<pii> Moves;
        Moves.push({0, 0});
        while(!Moves.empty())
        {
            pii my_pair = Moves.front();
            Moves.pop();
            tranverseBoard(my_pair, Moves, res);
        }
        cout << sqrs - res << endl;
    }
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

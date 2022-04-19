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
bool check(int A[], int sum)
{
    if(sum & 1)return false;
    for(int i = 0; i< 6; i++)
    {
        for(int j = i + 1; j< 6; j++)
        {
            for(int k = j + 1; k< 6; k++)
            {
                if(A[i] + A[k] + A[j] == sum/2)
                {
                    return true;
                }
            }
        }    
    }
    return false;
}

void solve()
{
    int A[6], sum = 0;
    for(int i = 0; i < 6; i++)
    {
        cin >> A[i];
        sum += A[i];
    }
    if(check(A, sum))cout<<"YES";
    else cout<<"NO";
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

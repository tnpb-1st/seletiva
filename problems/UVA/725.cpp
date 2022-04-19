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
bool checkNumbs(int n1, int n2)
{
    int A[10] = {};
    int d;
    int c1, c2;
    c1 = c2 = 0;
    while(n1 > 0)
    {
        d = n1 % 10;
        if(A[d] > 0)return false;
        A[d]++;
        n1/=10;
        c1++;
    }
    while(n2 > 0)
    {
        d = n2 % 10;
        if(A[d] > 0)return false;
        A[d]++;
        n2/=10;
        c2++;
    }
    if(c1 < 5)A[0]++;
    if(c2 < 5)A[0]++;
    if(A[0] > 1)return false;
    return true;
}


void solve()
{
	int N, count = 0;
    while(cin >> N && N)
    {
        int n1, n2;
        bool found = false;
        count++;
        if(count > 1)cout<<endl;
        for(n1 = 1234; n1 < 49383; n1++)
        {
            n2 = n1 * N;
            if(n2 < 0 || n2 > 98765) break;
            if(!checkNumbs(n2, n1))continue;
            found = true;
            string s1, s2;
            if(n1 < 10000)s1 = '0' + to_string(n1);
            else s1 = to_string(n1);
            if(n2 < 10000)s2 = '0' + to_string(n2);
            else s2 = to_string(n2);
            cout << s2 << " / " << s1 << " = " << N<<endl;
        }
        if(!found)
            cout << "There are no solutions for "<< N << "."<<endl;
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

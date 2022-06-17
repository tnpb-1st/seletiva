#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
set<int> ppl;

int jos(int n, int k, int killer=0) {
    if(n == 1) return 0;
    return (jos(n-1,k) + k ) % n;
}

void solve() {
    
}

int main()
{
	time_t start, end;
	time(&start);
	cin.tie(0);
	ios::sync_with_stdio(0);
    solve();
    // freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	time(&end);
	cout << endl << fixed << (double) end-start << setprecision(3)<<endl;
	return 0;
}

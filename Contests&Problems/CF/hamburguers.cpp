#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
// range of int values -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)

// bool auxF(int &Cb, int &Nb, int &Pb, int &Cs, int &Ns, int &Ps, int &Cc, int &Nc, int &Pc, ll X, ll &R)
// {
// 	ll resb = Cb * X - Nb;
// 	(X <= Nb || Cb == 0) ? resb = 0 : resb = resb *Pb;
	
// 	ll ress = Cs * X - Ns;
// 	(X <= Ns || Cs == 0) ? ress = 0 : ress = ress *Ps;
	
// 	ll resc = Cc * X - Nc;
// 	(X <= Nc || Cc == 0) ? resc = 0 : resc = resc *Pc;
	
// 	if(  R - (resb + ress+ resc) >= 0) return true;
// 	return false; 
// }

void solve()
{
	string S;
	int cb = 0, cs = 0, cc = 0, pb, ps, pc, nb, ns, nc;
	ll x ,R;
	cin >> S;
	for(char c: S)
	{
		if(c == 'B') cb++;
		else if(c == 'S') cs++;
		else cc++;
	}

	cin >> nb >> ns >> nc;
	cin >> pb >> ps >> pc;
	cin >> R;

	//
	auto auxF = [&] (ll X)
	{
		ll tot = pb * max(0LL, X * cb - nb) + ps * max(0LL, X * cs - ns) + pc * max(0LL, X * cc - nc);
		return (tot <= R);
	};
	// BS
	ll l = 0, mid, last = 0LL, r = 1e13;

	while(l <= r)
	{
		mid = l + (r - l)/2;
		if(auxF(mid))
		{	
			last = mid;
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}

	cout << last << endl;
}

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);

	solve();
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define pq priority_queue
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<bool> vbool;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
const int inf = 1e9;
const ll infl = 1e18;
/*
SOLUTION BY tnpb
*/
const ll MOD = 2 * 10e9;

ll fPow(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		b >>=1;
	}
	return ans;
}

ll gcd(ll a, ll b) {
    while(b) a%=b, swap(a,b);
    return a;
}

vi countDivisors(int &n) {
	vi divisors;
	int num_divisors = 0;
	for(int i = 1; i*i <= n; i++) {
		if(n%i == 0) {
			num_divisors++;
			divisors.pb(i);
			if(n/i != i) {num_divisors++;divisors.pb(n/i);}
		}
	}
	return divisors;
}

vector<pii> get_primes(int n) {
	vector<pii> primes;
	for(int p = 2; p * p <= n; ++p) {
		if(n % p == 0) {
			int exp = 0;
			while(n % p == 0) {n /= p; ++exp;}
			primes.emplace_back(p,exp);
		}
	}
	if(n > 1) primes.emplace_back(n, 1);
	return primes;
}

ll gcd_ext(ll a, ll b, ll &x, ll &y) {
	if(b == 0) {
		x = 1, y = 0;
		return a;
	}
	ll nx, ny;
	ll gc = gcd_ext(b, a%b, nx, ny);
	x = ny;
	y = nx - (a/b) * ny;
	return gc;
}

const int LIM = 10e6+10;
bool is_prime[LIM];
vector<int> sieve() {
	memset(is_prime, 1, sizeof(is_prime));
	is_prime[0] = is_prime[1] = false;
	vector<int> primes;
	for(int i = 2; i < LIM; i++) {
		if(is_prime[i]) {
			primes.push_back(i);
			if(1ll * i * i > LIM)continue;
			for(int j = i*i; j < LIM; j+= i) {
				is_prime[j] = false;
			}
		}
	}
	return primes;
}

ll sum_div[LIM];
void sieveSum() {
	for(int i = 1; i < LIM; i++) {
		for(int j = i; j < LIM; j+=i) {
			sum_div[j] += i;
		}
	}
}

int num_div[LIM];
void sieveNumDiv() {
	for(int i = 1; i < LIM; i++) {
		for(int j = i; j < LIM; j+=i) {
			num_div[j] += 1;
		}
	}
}

int phi(int n) {
	int ans = n;
	for(int i = 2; i*i <= n; i++) {
		if(n%i==0) {
			ans-=ans/i;
			while(n%i==0)n/=i;
		}
	}
	if(n>1) {
		ans-=ans/n;
	}
	return ans;
}

int PHI[LIM];
void phiSieve() {
	for(int i = 1; i<= LIM; i++)PHI[i] = i;
	for(int i = 2; i<=LIM; i++) {
		if(PHI[i] == i) {
			for(int j =i; j<=LIM;j+=i)
			PHI[j] = PHI[j]/i*(i-1); 
		}
	}
}

void solve()
{

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

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
const int arrLim = 1e6;
int dp[100001];
/*
SOLUTION BY tnpb
*/
template<class T>
void printContainer(T &container) {
	for(auto &ele:container) cout << ele << ' ';
	cout<<'\n';
}

struct Node{
	ll v;
	Node(ll _v=0) {v = _v;}
	Node operator+ (const Node &o) {
		//	merge function
		Node result;
		result.v = v + v.o;
		return result;
	}
	ll getValue() {return v;}
};

vector<Node> tree;
ll sz;

SegTree(vector<Node> &vec) {
	sz = vec.size() - 1; //-1 is a correction factor
	tree.resize(4*sz);
	build(vec, 1, 1, sz);
}

void build(vector<Node> &vec, ll n, ll l, ll r) {
	if(l == r) {
		tree[n] = vec[l];
		return;
	}
	ll m = (l+r)>>1;
	build(vec, 2*n, 1, m);
	build(vec, 2*n + 1, m+1, r);
	tree[n] = tree[2*n] + tree[2*n + 1];
}

void update(ll p, ll val) {
	Node node(val);
	update(1, 1, sz, p, node);
}

void update(ll n, ll l, ll r, ll p, Node &node) {
	if(l == r) {
		// update the node
		tree[n] = tree[n] + node;
		return;
	}

	ll m = (l+r) >> 1;
	if(p <= m) update(2*n, l , m, p, node);
	else update(2*n+1, m+1, r, p, node);

	tree[n] = tree[2*n] + tree[2*n+1];
}

Node query(ll r, ll r) {
	return query(1, 1, sz, l , r);
}

Node query(ll n, ll l, ll r, ll a, ll b) {
	if(a <= l && r <= b) return treé[n];
	if(r < a || b < l) {
		// return node that doesn't change the segtree
		return Node();
	}

	ll m = (l+r)>>1;
	Node left = query(2*n, l, m, a, b);
	Node right = query(2*n + 1, m+1,r, a, b);
	return left+right;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	solve();
	return 0;
}

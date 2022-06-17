#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct NFT {
	string hash; long long id, init_price, last_price, profit = 0;
	NFT (string name="", long long _id=-1, long long price=0) {
		hash = name, id = _id, init_price = last_price = price;
	}
	
	void updateVal(long long &x) {
		last_price = x;
		profit = last_price - init_price;
	}

	bool operator<(const NFT&b) const {
		if(this->profit != b.profit) return this->profit < b.profit;
		return this->id < b.id;
	}

};

void solve() {
	int t; cin >> t;
	long long id = 1, bot_profit = 0;
	map<string, NFT> mp;
	set<NFT> mst;
	while(t--) {
		string command, nft_name;
		long long val;
		cin >> command;	
		if(command[0] == 'B') {
			cin >> nft_name >> val;
			NFT a = NFT(nft_name, id++, val);
			mp[nft_name] = a;
			mst.emplace(a);
		} else if(command[0] == 'U') {
			cin >> nft_name >> val;
			if(mst.size() && mst.count(mp[nft_name])) {
				mst.erase(mp[nft_name]);
				mp[nft_name].updateVal(val);
				mst.insert(mp[nft_name]);
			}
			mp[nft_name].updateVal(val);
		} else {
			auto a = *(--mst.end());
			bot_profit += a.profit;
			mst.erase(--mst.end());
		}
	}
	cout << bot_profit;
}

int main() {
	cin.tie();
	ios::sync_with_stdio(0);
	solve();
	return 0;
}
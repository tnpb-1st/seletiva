#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
// range of int values -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)

void solve()
{
	int rep_s, siz, try_s;
	char act;
	string dna;
	rep_s = 1;
	getline(cin, dna);
	siz = dna.size();
	for(int i=0; i < siz; i++)
	{
		act = dna[i];
		if(i+ rep_s < siz && dna[i + rep_s] == act)
		{
			int j = i + 1;
			try_s = 1;
			while(j < siz && dna[j] == act)
			{
				try_s++;
				j++;
			}
			if(try_s > rep_s)
			{
				rep_s = try_s;
				i+= rep_s - 1;
			}
		}
	}
	cout<<rep_s;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	// freeopen("input.txt", "r", stdin);
	// freeopen("output.txt", "w", stdout);

	solve();
	return 0;
}
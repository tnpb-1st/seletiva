#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
string out = "";

void hanoi_tower(int piece, string start_tower, string aux_tower, string end_tower) {
    if(piece == 0) return;
    if(piece == 1) {
        out += "Move Disc 1 from " + start_tower +  " to " + end_tower + '\n';
        return;
    }
    hanoi_tower(piece-1, start_tower, end_tower, aux_tower);
    out += "Move Disc " + to_string(piece) + " from " + start_tower +  " to " + end_tower + '\n';
    hanoi_tower(piece-1, aux_tower, start_tower, end_tower);
}

void solve() {
    hanoi_tower(3, "A", "B", "C");
    cout<<out;
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

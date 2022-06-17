#include <bits/stdc++.h>
using namespace std;

int rope_cutting(int len, int a, int b, int c) {
    int ans = 0;
    if(len < 0) return 0;
    else if(len == 0) return 1;
    int op_a = rope_cutting(len-a, a, b, c);
    int op_b = rope_cutting(len-b, a, b, c);
    int op_c = rope_cutting(len-c, a, b, c);
    ans = op_a + op_b + op_c;
    return ans;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
    cout << rope_cutting(9, 2, 2, 2)<<endl;
    // freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	return 0;
}

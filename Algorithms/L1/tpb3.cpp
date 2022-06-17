/*
Foi dado um array de n inteiros. Depois nos são dados q queries da forma: l,r, x.
Em que em cada querie devemos adicionar o valor x aos elementos que vão de l até r.

ex de querie:
l, r, x
A[l] += x
A[l + 1] += x
A[l + 2] += x
.
.
.
A[r] += x
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n];
	int p[n] = {};
	for(int i=0; i<n; i++)
		cin >> a[i];

	int q;
	cin >> q;
	
	while (q--)
	{
		int l, r, inc;
		cin >> l >> r >> inc;

		
		p[l] += inc;
		if(r + 1 < n)
			p[r + 1] -= inc;
	}

	for (int i = 1; i < n; i++)
		p[i] = p[i - 1] + p[i];

	for(int i = 0; i < n; i++)
		cout << a[i] + p[i] << " ";
	cout<<endl;

	return 0;
}
/*
Foi dado um array de n inteiros. Depois nos são dados q queries da forma: l,r.
Em que devemos imprimir as somas dos elementos das queries de l até r.

P[i] = A[0] + A[1] + A[2] + ... + A[i]
P[i+ 1] = A[0] + A[1] + A[2] + ... + A[i] + A[i + 1]
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, q, l, r;
	cin >> N;
	int A[N];
	int P[N];
	for(int i=0; i < N; i++)
		cin >> A[N];
	
	P[0] = A[0];
	for(int i=1; i < N; i++)
		P[i] = P[i - 1] + A[i];
	
	cin >> q;
	while(q--)
	{
		cin >> l >> r;
		cout << P[r] - P [l - 1] << "\n";
	}
	
	return 0;
}
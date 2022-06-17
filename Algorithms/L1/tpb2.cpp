/*
Foi dado um array de n inteiros. Depois nos são dados q queries da forma: l,r.
Em que devemos imprimir as somas dos elementos das queries de l até r com 
fatores:

Querie:
A[l] + A[l + 1] * 2 + A[l + 2] * 3 + ... + (r - l + 1) * A[r]

Dica: esse problema é resolvido manipulando as propriedades de somátorios juntamente
com as fórmulas do prefix sum array
*/
#include <bits/stdc++.h>
using namespace std;

int return prefix_sum(int l, int r, int* P1, int* P2)
{
	return P2[r] - ((l-1) * P1[r]);
}

int main()
{
	int n, q,  l, r;
	cin >> n >> q;
	int A[n];
	int P1[n];
	int P2[n];
	for(int i=0; i < n; i++)
		cin >> A[i];


	P1[0] = P2[0] = A[0];
	for(int i=1 ; i < n; i++)
		P1[i] = P1[i - 1] + A[i];
		P2[i] = P2[i - 1] + (i+1) * A[i];


	while(q--)
	{
		cin >> l >> r;
		cout << prefix_sum(l, r, P1, P2) << "\n";
	}

	return 0;
}
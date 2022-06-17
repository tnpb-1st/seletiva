#include <bits/stdc++.h>
using namespace std;

int prefixRange(int l, int r, int* P)
{
	if (l-1 >= 0) return P[r] - P[l-1];
	return 0;
}

int main()
{
	int N;
	cin>>N;
	int A[N];
	int P[N];
	
	for(int i=0; i<N;i++)
		cin>>A[i];
	
	P[0] = A[0];

	for(int i=1; i<N; i++)
		P[i] = P[i-1] + A[i];

	return 0;
}
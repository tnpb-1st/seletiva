/*
2D Arrays prefix sum

Foi dado um array de n inteiros. Depois nos são dados q queries da forma: l,r.

[00, 01, 02, 03, 04]          
[10, 11, 12, 13, 14]
[20, 21, 22, 23, 24]
[30, 31, 32, 33, 34]
[40, 41, 42, 43, 44]

[YY, YY, YY, YY, YY]
[YY, YY, YY, YY, YY]
[YY, YY, 22, 23, YY]
[YY, YY, 32,  X, YY]
[YY, YY, YY, YY, YY]

        l2      r2
l1 [YY, XX, XX, XX, YY]
   [YY, XX, XX, XX, YY]
   [YY, XX, XX, XX, YY]
r1 [YY, XX, XX, XX, YY]
   [YY, YY, YY, YY, YY]



*/



#include <bits/stdc++.h>
using namespace std;

int main()
{
	int M, N, Q;
	int A[M][N];
	int P[M][N];
	cin >> M >> Q;
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> A[M][N];
		}
	}

	P[0][0] = A[0][0];

	for(int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int t1, t2, t3;
			(i - 1 >= 0) ? t1 = P[i-1][j] : t1 = 0;
			(j - 1 >= 0) ? t2 = P[i][j-1] : t2 = 0;
			((i - 1 >= 0) && (j - 1 >= 0)) ? t3 = P[i - 1][j - 1];
			P[i][j] = t1 + t2 - t3 + A[i][j];
		}
	}
	cin >> Q;
	int l1, r1, l2, r2, t1, t2, t3;
	while(Q--)
	{
		cin >> l1 >> r1 >> l2 >> r2;
		int resul = P[r1][r2];
		(l2 - 1 >= 0) ? t1 = P[r1][l2-1] : t1 = 0;
		(l1 - 1 >= 0) ? t2 = P[l1 - 1][r2] : t2 = 0;
		((l1 - 1 >= 0) && (l2-1 >= 0)) : t3 = P[l1 - 1][l2 - 1]:t3 = 0;
		resul -= (t1 + t2 +t3);
		cout<<resul<<"\n";
	}


	return 0;
}
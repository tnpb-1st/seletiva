#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, q, l1, l2, r1, r2;
	cin >> n >> m;
	int A[n][m]; // n linhas m colunas
	int P[n][m];

	cin >> A[0][0];
	P[0][0] = A[0][0];

	for(int i=0; i< n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if (i == 0 && j == 0) continue;
			
			cin >> A[i][j];
			int t1, t2, t3;
			(i - 1 >= 0) ? t1 = P[i-1][j] : t1 = 0;
			(j - 1 >= 0) ? t2 = P[i][j-1] : t2 = 0;
			((i -1 >=0) && (j - 1 >= 0)) ? t3 = P[i-1][j-1] : t3 = 0;
			P[i][j] = t1 + t2 - t3 + A[i][j];
		}
	}

	// for(int i = 0; i < n; i++)
	// {
	// 	for(int j = 0; j < m; j++)
	// 	{
	// 		cout << P[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	cin >> q;
	while(q--)
	{
		int res = 0;
		int t1, t2, t3;
		t1 = t2 = t3 = 0;

		cin >> l1 >> r1 >> l2 >> r2;
		
		(l1 - 1 >= 0) ? t1 = P[l1-1][r2] : t1 = 0;
		(l2 - 1 >= 0) ? t2 = P[r1][l2-1] : t2 = 0;
		((l1 -1 >=0) && (l2 - 1 >= 0)) ? t3 = P[l1-1][l2-1] : t3 = 0;
		
		cout << P[r1][r2] - t1 - t2 + t3 << "\n";
	}

	return 0;
}
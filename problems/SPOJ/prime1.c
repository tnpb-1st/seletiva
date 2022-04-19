#include <stdio.h>
#define large_n 1000000001

long long arr[large_n] = {0};
int main()
{
	int i,l,r;
	scanf("%d", &i);
	for(long long j = 0; j <i; j++)
	{
		scanf("%d %d", &l, &r);
		for(long long i=2; i < r; i++) arr[i] = 1;

		for(long long k=2; k * k <= r; k++)
		{
			if(arr[k])
			{
				for(long long a = k * k; a <= r; a+=k)
				{
					arr[a] = 0;
				}
			}
		}
		
		for(int k = l; k<= r; k++)
			if(arr[k]) printf("%d\n", k);
		
		printf("\n");
	}
	
	return 0;
}

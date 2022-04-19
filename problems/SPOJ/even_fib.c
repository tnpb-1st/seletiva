#include <stdio.h>
#include <math.h>
char arr[100000000] = {0};

int main()
{
    int a;
    int limit = 10000;
    int large_n = 100000000;
    arr[0] = arr[1] = 1;
    for(__int32_t i = 2; i*i <= large_n; i++)
    {
        if(!arr[i])
        {
            for(__int32_t k = i*i; k <= large_n; k += i)
            {
                arr[k] = 1;
            }

        }
    }

    for(__int32_t x = 2, j = 100; x < large_n; x++)
    {
        if(!arr[x])
        {
            
            if(j % 100 == 0)printf("%d\n",x);
            j++;
        }

    }

    return 0;
}
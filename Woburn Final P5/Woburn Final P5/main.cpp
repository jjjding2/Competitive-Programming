#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int arr [1 << 20];
int n;
pair <int, int> arr2 [21];
int first, second;
long long int total = 0;
int main ()
{
    scanf ("%d", &n);
    for (int x = 0; x < n; x++)
    {
        scanf ("%d%d", &first, &second);
        arr2 [x] = {first, second};
    }
    for (int x = 0; x < (1 << 20); x++)
    {
        int freq [4];
        for (int y = 0; y <= 20; y++)
        {
            if ((x >> 1)&1)
            {
                freq [arr2[y].first]++;
                freq [arr2[y].second]++;
            }
        }
        if (freq [1] > freq [2] && freq [1] > freq [3])
        {
            total ++;
        }
    }
    printf("%lld\n", total);
    return 0;
}

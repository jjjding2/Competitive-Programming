#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;

string str;
string result = "";
int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> str;
    for (int x = 0; x < str.length(); x++)
    {
        string temp = "";
        if (x < str.length())
        {
            for (int y = x; y < x + 4; y++)
            {
                temp += str [y];
            }
            if (temp == "bull")
            {
                result += "bll";
                x += 3;
            }
            else
            {
                result += str [x];
            }
        }
        else
        {
            result += str [x];
        }
    }
    cout << result << endl;
}

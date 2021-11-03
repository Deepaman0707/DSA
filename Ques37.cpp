#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long int
#define fast ios_base::sync_with_stdio(NULL), cin.tie(0), cout.tie(0)
#define MOD 1e9 + 7
#define cin(a, n)               \
    for (int i = 0; i < n; i++) \
    cin >> a[i]

#define cout(a, n)              \
    for (int i = 0; i < n; i++) \
    cout << a[i]

#define rep(i, n) for (int i = 0; i < n; i++)
#define forr(i, n) for (int i = n; i >= 0; i--)
#define fep(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    int r = 0, c = 0;
    cin >> r >> c;
    int a[r][c];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            a[i][j] = 0;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];

    int startr = 0, startc = 0, endr = r - 1, endc = c - 1;

    while (startr <= endr)
    {
        for (int j = startc; j <= endc; j++)
            cout << a[startr][j] << " ";

        startr++;

        for (int j = startr; j <= endr; j++)
            cout << a[j][endc] << " ";

        endc--;

        for (int j = endc; j >= startc; j--)
            cout << a[endr][j] << " ";

        endr--;

        for (int j = endr; j >= startr; j--)
            cout << a[j][startc] << " ";

        startc++;
    }
}

int main()
{
    fast;
    solve();
    return 0;
}
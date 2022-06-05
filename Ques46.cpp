#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define pb push_back
#define pob pop_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define ff first
#define ss second
#define ll long long int
#define fast ios_base::sync_with_stdio(NULL), cin.tie(0), cout.tie(0)
#define MOD 1000000007
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
    int n, m;
    cin >> n >> m;
    int mat[n][m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    map<int, int> mp;
    for (int i = 0; i < m; i++)
        mp[mat[0][i]] = 1;

    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mp[mat[i][j]] == i)
                mp[mat[i][j]]++;

    for (auto i : mp)
    {
        if (i.second == n)
            cout << i.first << " ";
    }
}

int32_t main()
{
    fast;
    solve();
    return 0;
}
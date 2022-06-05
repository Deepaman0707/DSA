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
    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    int mx = a[n - 1][n - 1];
    dp[n - 1][n - 1] = a[n - 1][n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        if (mx <= a[n - 1][i])
        {
            mx = a[n - 1][i];
        }
        dp[n - 1][i] = mx;
    }

    mx = dp[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (mx <= a[i][n - 1])
        {
            mx = a[i][n - 1];
        }
        dp[i][n - 1] = mx;
    }

    for (int i = n - 2; i >= 0; i--)
        for (int j = n - 2; j >= 0; j--)
        {
            dp[i][j] = max({dp[i + 1][j], dp[i][j + 1], a[i][j]});
        }

    int ans = INT_MIN;

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1; j++)
            ans = max(dp[i + 1][j + 1] - a[i][j], ans);

    cout << ans << endl;
}

int32_t main()
{
    fast;
    solve();
    return 0;
}
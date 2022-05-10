#include <bits/stdc++.h>
using namespace std;

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

int knapsack(int weight[], int profit[], int w, int n, int **dp)
{
    if (n == 0 || w == 0)
        return 0;

    if (dp[n][w] != -1)
        return dp[n][w];

    if (weight[n - 1] <= w)
        return dp[n][w] = max(profit[n - 1] + knapsack(weight, profit, w - weight[n - 1], n - 1, dp), knapsack(weight, profit, w, n - 1, dp));

    else
        return dp[n][w] = knapsack(weight, profit, w, n - 1, dp);
}

void solve()
{
    int n, w;
    cin >> n >> w;
    int weight[n];
    int profit[n];
    cin(weight, n);
    cin(profit, n);
    int **dp;
    dp = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
        dp[i] = new int[w + 1];

    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < w + 1; j++)
            dp[i][j] = -1;

    cout << knapsack(weight, profit, w, n, dp) << endl;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < w + 1; j++)
            cout << dp[i][j] << " ";

        cout << endl;
    }

    // for (int i = 0; i < n + 1; i++)
    //     dp[i][0] = 0;

    // for (int i = 0; i < w + 1; i++)
    //     dp[0][i] = 0;

    // for (int i = 1; i < n + 1; i++)
    // {
    //     for (int j = 1; j < w + 1; j++)
    //     {
    //         if (weight[i - 1] <= j)
    //             dp[i][j] = max(profit[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
    //         else
    //             dp[i][j] = dp[i - 1][j];
    //     }
    // }

    cout << dp[n][w] << endl;
}

int main()
{
    fast;
    solve();
    return 0;
}
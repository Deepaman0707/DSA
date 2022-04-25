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
    cout << a[i] << " "

#define rep(i, n) for (int i = 0; i < n; i++)
#define forr(i, n) for (int i = n; i >= 0; i--)
#define fep(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    int n;
    cin >> n;
    int a[n];
    cin(a, n);
    int first = INT_MAX, second = INT_MAX, buy1 = 0, buy2 = 0;

    int *profit = new int[n];
    for (int i = 0; i < n; i++)
        profit[i] = 0;

    int max_price = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] > max_price)
            max_price = a[i];

        profit[i] = max(profit[i + 1], max_price - a[i]);
        // cout << profit[i] << " ";
    }

    int min_price = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] < min_price)
            min_price = a[i];

        profit[i] = max(profit[i - 1], profit[i] + (a[i] - min_price));
        // cout << profit[i] << " ";
    }
    // cout(profit, n);
    int result = profit[n - 1];
    delete[] profit;
    cout << result;
}

int main()
{
    fast;
    solve();
    return 0;
}

// 0    1    2    3   4    5    6
// 2   30   15   10   8   25   80
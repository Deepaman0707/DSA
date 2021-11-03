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

bool comp(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

void solve()
{
    int n;
    bool flag = false;
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2, 0));
    vector<vector<int>> result;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            cin >> intervals[i][j];

    sort(intervals.begin(), intervals.end(), comp);

    vector<int> ans(2, 0);
    ans[0] = intervals[0][0];
    ans[1] = intervals[0][1];

    for (int i = 0; i < n - 1; i++)
    {
        if (ans[1] >= intervals[i + 1][0])
        {
            ans[1] = max(ans[1], intervals[i + 1][1]);
        }
        else
        {
            result.pb(ans);
            ans[0] = intervals[i + 1][0];
            ans[1] = intervals[i + 1][1];
        }
    }

    result.pb(ans);

    for (int i = 0; i < result.size(); i++)
        for (int j = 0; j < 2; j++)
            cout << result[i][j] << " ";
}

int main()
{
    fast;
    solve();
    return 0;
}
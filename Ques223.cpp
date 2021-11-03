#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
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

//  The time complexicity of this method is n^2. And we can further optimize it using STL sorting function and vector of pairs. After optimizing it, time complexicity reduces to nlogn.

void sortRatio(double ratio[], double weight[], double profit[], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (ratio[i] < ratio[j])
            {
                double temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
}

void solve()
{
    int n = 0, ans = 0, max = 0;
    cin >> n;
    double weight[n] = {0}, profit[n] = {0};
    cin(profit, n);
    cin(weight, n);
    cin >> max;
    double ratio[n] = {0};
    for (int i = 0; i < n; i++)
        ratio[i] = profit[i] / weight[i];

    sortRatio(ratio, weight, profit, n);

    for (int i = 0; i < n; i++)
    {
        if (weight[i] <= max)
        {
            max -= weight[i];
            ans += profit[i];
        }
        else
        {
            ans += ratio[i] * max;
            break;
        }
    }
    cout << ans << endl;
}

// The method having time complexicity of nlogn.

bool comp(pii p1, pii p2)
{
    double res1 = (double)p1.ff / p1.ss;
    double res2 = (double)p2.ff / p2.ss;
    return res1 > res2;
}

void solvenlogn()
{
    int n = 0, ans = 0, max = 0;
    cin >> n;
    vii a(n);
    rep(i, n)
    {
        cin >> a[i].ff >> a[i].ss;
    }
    cin >> max;

    sort(a.begin(), a.end(), comp);

    for (int i = 0; i < n; i++)
    {
        if (a[i].ss <= max)
        {
            max -= a[i].ss;
            ans += a[i].ff;
        }
        else
        {
            ans += ((double)a[i].ff / a[i].ss) * max;
            break;
        }
    }
    cout << ans << endl;
}

int main()
{
    fast;
    // solve();
    solvenlogn();
    return 0;
}
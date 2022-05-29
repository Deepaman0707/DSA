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

void solve()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    cin(a, n);
    deque<int> min;
    deque<int> max;
    int sum = 0;
    int i = 0, j = 0;
    while (j < n)
    {
        while (min.size() > 0 && min.back() > a[j])
        {
            min.pop_back();
        }
        min.push_back(a[j]);

        while (max.size() > 0 && max.back() < a[j])
            max.pop_back();

        max.push_back(a[j]);

        if (j - i + 1 == k)
        {
            sum += min.front() + max.front();
            if (a[i] == min.front())
                min.pop_front();

            if (a[i] == max.front())
                max.pop_front();

            i++;
        }
        j++;
    }
    cout << endl
         << sum << endl;
}

int main()
{
    fast;
    solve();
    return 0;
}

// 0 1 2 3 4 5 6 7 8 9 10 11 12 13
// ( ) ( ( ( ) ) ( ) ( ) ) ) ( )

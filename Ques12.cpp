#include <bits/stdc++.h>
using namespace std;

// Custom templates

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

// Merge two sorted array without any extra space.

void mergeit(int a[], int b[], int n, int m)
{
    rep(i, n)
    {
        if (a[i] > b[0])
        {
            int temp = a[i];
            a[i] = b[0];
            b[0] = temp;
            rep(j, m) if (b[j] > b[j + 1])
            {
                int temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
}

// Gap algorithm

void gapAlgo(int a[], int b[], int n, int m)
{
    bool flag = true;
    int gap = (n + m) / 2;
    while (flag == true)
    {
        if (gap == 1)
            flag = false;

        for (int i = 0, j = gap; j < n + m; i++, j++)
        {
            if (i < n && j < n)
            {
                if (a[i] > a[j])
                {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
            else if (i < n && j >= n)
            {
                if (a[i] > b[j - n])
                {
                    int temp = a[i];
                    a[i] = b[j - n];
                    b[j - n] = temp;
                }
            }
            else
            {
                if (b[i - n] > b[j - n])
                {
                    int temp = b[j - n];
                    b[j - n] = b[i - n];
                    b[i - n] = temp;
                }
            }
        }
        gap /= 2;
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int a[n] = {0}, b[m] = {0};
    cin(a, n);
    cin(b, m);
    // mergeit(a, b, n, m);
    gapAlgo(a, b, n, m);
    cout(a, n);
    cout << endl;
    cout(b, m);
}

int main()
{
    fast;
    solve();
    return 0;
}

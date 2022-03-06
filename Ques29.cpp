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

int rainwater(int a[], int n)
{
    int i = 0, j = n - 1;

    while (a[i] <= a[i + 1])
        i++;
    while (a[j] <= a[j - 1])
        j--;

    int left = i, right = j;
    int maxheight = a[i], pos = i;

    while (i <= j)
    {
        if (maxheight <= a[i])
        {
            maxheight = a[i];
            pos = i;
        }
        i++;
    }
    int leftmax = a[left];
    int volumeleft = 0;
    for (int l = left; l < pos; l++)
    {
        if (leftmax > a[l])
            volumeleft += (leftmax - a[l]);
        else
            leftmax = a[l];
    }

    int rightmax = a[right];
    int volumeright = 0;

    for (int l = right; l > pos; l--)
    {
        if (rightmax > a[l])
            volumeright += (rightmax - a[l]);
        else
            rightmax = a[l];
    }

    return volumeleft + volumeright;

    // cout << left << " " << pos << " " << right << endl;
    // return 0;
}

void solve()
{
    int n;
    cin >> n;
    int a[n];
    cin(a, n);
    cout << rainwater(a, n) << endl;
}

int main()
{
    fast;
    solve();
    return 0;
}
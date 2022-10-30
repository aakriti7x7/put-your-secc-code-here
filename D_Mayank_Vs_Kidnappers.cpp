#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll check(ll x, ll y, ll n)
{
    ll sum = x + y;
    ll num = LLONG_MAX;

    if (sum == n || x == n || y == n)
    {
        // cout<<"WTF";
        num = 1;
    }
    else if (sum > n || (x > n && y > n))
    {
        // cout<<"WTF";
        num = LLONG_MAX;
        /* code */
    }
    else
    {
        num = min(1 + check(x + y, y, n), 1 + check(x, x + y, n));
    }

    return num;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        // -------   check for n==1   -------------

        ll n;
        cin >> n;

        ll ans = 1 + check(1, 1, n);

        if (n == 1)
        {
            ans = 0;
            /* code */
        }

        cout << ans;

        cout << endl;
    }
    return 0;
}
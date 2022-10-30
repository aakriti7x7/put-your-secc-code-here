#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <utility>
#include <algorithm>
#include <vector>
#define INF 10000000000
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        long long int w, h, x1, y1, x2, y2, x, y, a1 = INF, a2 = INF;
        cin >> w >> h >> x1 >> y1 >> x2 >> y2 >> x >> y;
        int ch = 0, wh = 0;
        if (y1 >= y || h - y2 >= y)
        {
            ch = 1;
            a2 = 0;
        }
        else
        {
            if ((y - y1 + y2) <= h)
            {
                ch = 1;
                a2 = min(y - y1, y - h + y2);
            }
        }

        if (x1 >= x || w - x2 >= x)
        {
            wh = 1;
            a1 = 0;
        }
        else
        {
            if ((x - x1 + x2) <= w)
            {
                wh = 1;
                a1 = min(x - x1, x - w + x2);
            }
        }

        //cout << ch << " " << wh << endl;
        //cout<<a1 
        if (wh == 1 || ch == 1)
        {
            long long int ans = min(a1,a2);
            cout<<ans<<endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }

    return 0;
}
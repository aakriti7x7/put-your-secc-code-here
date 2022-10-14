#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, int> info;

    info["Age"] = 18;
    info["Year"] = 2022;
    info["Number of Players"] = 15;

    for (auto x : info)
    cout << x.first << " " << x.second << endl;
}

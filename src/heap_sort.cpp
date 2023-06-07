#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v;
    int num;
    while(cin >> num)
        v.push_back(num);

    make_heap(v.begin(), v.end());
    sort_heap(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}
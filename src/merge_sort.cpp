#include <bits/stdc++.h>

using namespace std;

void merge_sort(vector<int> &v, int l, int r)
{
    if (l >= r)
        return;

    int mid = (l + r) / 2;
    merge_sort(v, l, mid);
    merge_sort(v, mid + 1, r);

    vector<int> tmp;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (v[i] < v[j])
            tmp.push_back(v[i++]);
        else
            tmp.push_back(v[j++]);
    }
    while (i <= mid)
        tmp.push_back(v[i++]);
    while (j <= r)
        tmp.push_back(v[j++]);

    for (int i = l; i <= r; i++)
        v[i] = tmp[i - l];
}

int main()
{
    vector<int> v;
    int num;
    while (cin >> num)
        v.push_back(num);

    merge_sort(v, 0, v.size() - 1);

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}
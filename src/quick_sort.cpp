#include <bits/stdc++.h>

using namespace std;

// qsort function
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main(int argc, char const *argv[])
{
    vector<int> v;
    int num;
    while (cin >> num)
        v.push_back(num);

    qsort(&v[0], v.size(), sizeof(int), compare);

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}
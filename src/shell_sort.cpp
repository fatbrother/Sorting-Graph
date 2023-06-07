#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v;
    int num;
    while (cin >> num)
        v.push_back(num);

    for (int gap = v.size() / 2; gap > 0; gap /= 2)
        for (int i = gap; i < v.size(); i++)
            for (int j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
                swap(v[j], v[j + gap]);

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}
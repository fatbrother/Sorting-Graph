Sorting Comparison
===

## 執行

To run this repo locally, follows the below steps:

1. Clone this repo
2. Run `pip install -r requirements.txt`
3. Run the paint.py
4. Check the running_time.png

## 介紹

### `paint.py`
In the, we compile the cpp file in the `src/`, and generate the test case with every size of data.
```python=
data_sizes = [10000, 50000, 100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000]

def generate_random_data(data_size: int) -> list[int]:
    data = [i for i in range(data_size)]
    random.shuffle(data)
    return data
```
After that, the program call every exe file, give the data, check if the result valid and calc the time it cost.
```python=
def call_exe(sort_name: str, random_data: list[int]) -> float:
    path = './exe/{}.exe'.format(sort_name)

    start_time = time.time()
    out = subprocess.Popen(path, stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    out = out.communicate(input=' '.join([str(i) for i in random_data]).encode('utf-8'))[0]
    end_time = time.time()

    out = out.decode('utf-8').split()
    out = [int(i) for i in out]
    if not check_sorted(out):
        print('Error: {} is not sorted!'.format(sort_name))
        sys.exit(1)

    return end_time - start_time

def check_sorted(data: list) -> bool:
    for i in range(len(data) - 1):
        if data[i] > data[i + 1]:
            return False
    return True
```
When all case is over, call the `paint_data()` to paint the result.

### `heap_sort.cpp`
Use c++ build in func `make_heap` and `sort_heap` to sort the data with heap sort.
```cpp!
make_heap(v.begin(), v.end());
sort_heap(v.begin(), v.end());
```

### `merge_sort.cpp`
Use recursion merge sort to sort the data.
```cpp=
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
```

### `quick_sort.cpp`
Use C build in func `qsort()` to sort the data.
```cpp=
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

qsort(&v[0], v.size(), sizeof(int), compare);
```

### `shell_sort.cpp`
Initially set the gap as half of data size, in every loop, we devide it with 2.
```cpp=
for (int gap = v.size() / 2; gap > 0; gap /= 2)
        for (int i = gap; i < v.size(); i++)
            for (int j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
                swap(v[j], v[j + gap]);
```

## 結果
![](https://hackmd-prod-images.s3-ap-northeast-1.amazonaws.com/uploads/upload_398ad122639d8f6addbe4a4c54ee0c50.png?AWSAccessKeyId=AKIA3XSAAW6AWSKNINWO&Expires=1686131549&Signature=Yb9EHcspmrCvj7wRoiHHmBvSB1I%3D)

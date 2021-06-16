#include <bits/stdc++.h>
using namespace std;

// O(n) O(n)
int distinctCount(int arr[], int n)
{
    set<int> unordered_set;

    for (int i = 0; i < n; i++)
        unordered_set.insert(arr[i]);

    return unordered_set.size();
}

int mostFrequent(int arr[], int n)
{
    sort(arr, arr + n);

    int max_count = 1, res = arr[0], curr_count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
            curr_count++;
        else
        {
            if (curr_count > max_count)
            {
                max_count = curr_count;
                res = arr[i - 1];
            }
            curr_count = 1;
        }
    }

    if (curr_count > max_count)
    {
        max_count = curr_count;
        res = arr[n - 1];
    }

    return res;
}

int main()
{
    int arr[] = {10, -3, 10, 4, 2, 3, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Count of distinct values : "
         << distinctCount(arr, n) << endl;

    cout << "Most frequent element : "
         << mostFrequent(arr, n);

    return 0;
}
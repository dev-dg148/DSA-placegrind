/*Problem Name: Top K Frequent Elements

   Constraints:
   1 <= nums.length <= 10^4
   -1000 <= nums[i] <= 1000
   1 <= k <= number of distinct elements in nums

   Input Format:
   - First line: Integer N (size of the array) and Integer K.
   - Second line: N space-separated integers.

   Output Format:
   - Print K space-separated integers representing the most frequent elements.

   Example 1:
   Input:
   6 2
   1 2 2 3 3 3
   Output:
   2 3

   Example 2:
   Input:
   2 1
   7 7
   Output:
   7
   ========================================== */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
vector<int> topk(vector<int> v, int k)
{
    vector<int> ans;
    unordered_map<int, int> mp;
    for (int i = 0; i < v.size(); i++)
    {
        mp[v[i]]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        min_heap.push({i->second, i->first});
        if (min_heap.size() > k)
        {
            min_heap.pop();
        }
    }
    while (!min_heap.empty())
    {
        ans.push_back(min_heap.top().second);
        min_heap.pop();
    }
    return ans;
}
int main()
{
    int size, k;
    cout << "Enter size and k :-" << endl;
    cin >> size;
    cin >> k;
    vector<int> v(size);
    cout << "Enter element-" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> v[i];
    }
    vector<int> top = topk(v, k);
    for (int i : top)
    {
        cout << i << " ";
    }

    return 0;
}
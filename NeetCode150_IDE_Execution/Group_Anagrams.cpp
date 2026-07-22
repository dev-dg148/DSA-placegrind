/*
Problem Name: Group Anagrams

Constraints:
- 1 <= strs.length <= 10^4
- 0 <= strs[i].length <= 100
- strs[i] consists of lowercase English letters.

Input Format:
- The first line contains an integer N, the number of strings.
- The next N lines contain one string each.

Output Format:
- Print the grouped anagrams. Each group on a new line.

Example 1:
Input:
6
eat
tea
tan
ate
nat
bat
Output:
bat
nat tan
ate tea eat
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> mp;
    for (int i = 0; i < strs.size(); i++)
    {
        string s = strs[i];
        sort(s.begin(), s.end());

        mp[s].push_back(strs[i]);
    }
    vector<vector<string>> ans;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        ans.push_back(it->second);
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter n-";
    cin >> n;
    vector<string> vs(n);
    cout << "Enter strings:- ";
    for (int i = 0; i < n; i++)
    {
        cin >> vs[i];
    }
    vector<vector<string>> result = groupAnagrams(vs);
    
    cout << "Output:" << endl;
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
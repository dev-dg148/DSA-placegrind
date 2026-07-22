/*
Problem Name: Valid Anagram

Constraints:
- 1 <= s.length, t.length <= 5 * 10^4
- s and t consist of lowercase English letters.

Input Format:
- The first line contains the string s.
- The second line contains the string t.

Output Format:
- Print "True" if the two strings are anagrams of each other, otherwise print "False".

Example 1:
Input:
anagram
nagaram
Output:
True

Example 2:
Input:
rat
car
Output:
False
*/
#include <iostream>
using namespace std;
bool isAnagram(string s, string t)
{
    int freq[26] = {0};
    if (s.length() != t.length())
        return false;
    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string s, t;
    cout << "Enter s :" << endl;
    cin >> s;
    cout << "Enter t :" << endl;
    cin >> t;
    bool va = isAnagram(s, t);
    if (va)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}
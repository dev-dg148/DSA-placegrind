/*
   Problem Name: Encode and Decode Strings (NeetCode 150)

   Concept: Arrays & Hashing / String Manipulation
   Time Complexity: O(N)
   Space Complexity: O(N)

   Constraints:
   0 <= strs.length < 100
   0 <= strs[i].length < 200
   strs[i] contains any possible ASCII characters.

   Input Format (ip):
   - First line: Integer N (number of strings).
   - Next N lines: One string per line.

   Output Format (op):
   - Print the Encoded string.
   - Print the Decoded strings back to original format.

   ------------------------------------------
   SAMPLE TESTCASE:
   ------------------------------------------
   Input (ip):
   2
   Hello
   Wo#rld

   Output (op):
   Encoded Output (op): 5#Hello6#Wo#rld
   Decoded Output (op): [Hello] [Wo#rld]
   ========================================== */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string encode(vector<string> &strs)
{
    string en = "";
    for (int i = 0; i < strs.size(); i++)
    {
        string s = strs[i];
        en += to_string(s.length()) + "#" + s;
    }
    return en;
}

vector<string> decode(string s)
{
    vector<string> st;
    int i = 0;
    while (i < s.length())
    {
        int j = i;
        while (s[j] != '#')
        {
            j++;
        }
        int l=stoi(s.substr(i,j-i));
        st.push_back(s.substr(j+1,l));
        i=j+1+l;
        
    }
    return st;
}

int main()
{

    int n;
    cout << "Enter size (n):-";
    cin >> n;
    vector<string> vs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vs[i];
    }
    string encoded_str = encode(vs);
        cout << "Encoded Output (op): " << encoded_str << "\n";
        vector<string> decoded_strs = decode(encoded_str);
        cout << "Decoded Output (op): ";
        for (const string &str : decoded_strs)
        {
            cout << "[" << str << "] ";
        }
        cout << "\n";
    

    return 0;
}
/*
Problem Name: Contains Duplicate

Constraints:
1 <= N <= 10^5
-10^9 <= arr[i] <= 10^9

Input Format:
- The first line contains an integer N, denoting the size of the array.
- The second line contains N space-separated integers representing the array elements.

Output Format:
- Print "true" if any value appears at least twice, otherwise print "false".

Example 1:
Input:
4
1 2 3 3
Output:
true

Example 2:
Input:
4
1 2 3 4
Output:
false
*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int>s;
    for(int i=0;i<nums.size();i++){
        if(s.find(nums[i])!=s.end()){
            return true;
        }
        s.insert(nums[i]);
    }
    return false;
}
int main(){
    int size;
    cout<<"size:- ";
    cin >> size;
    vector<int> v(size);
    cout<<"Enter element"<<endl;
    for(int i = 0; i < size; i++){
        cin >> v[i];
    }
    bool cd=containsDuplicate(v);
    if(cd){cout<<"True"<<endl;}else{cout<<"False"<<endl;}
    return 0;
}
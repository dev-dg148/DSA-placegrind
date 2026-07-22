/*
Problem Name: Two Sum

Constraints:
- 2 <= nums.length <= 10^4
- -10^9 <= nums[i] <= 10^9
- -10^9 <= target <= 10^9
- Only one valid answer exists.

Input Format:
- The first line contains the size of the array N.
- The second line contains N space-separated integers.
- The third line contains the target integer.

Output Format:
- Print the two indices (space-separated) that add up to the target.

Example 1:
Input:
4
3 4 5 6
7
Output:
0 1

Example 2:
Input:
3
4 5 6
10
Output:
0 2

Example 3:
Input:
2
5 5
10
Output:
0 1
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
 vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int t=target-nums[i];
            if(mp.find(t)!=mp.end()){
                return {mp[t],i};
            }
            mp[nums[i]]=i;
        }
        return {-1,-1};
    }
int main(){
int size;
cout<<"size:";
cin>>size;
vector<int>v(size);
cout<<"Enter element:-";
for(int i=0;i<size;i++){
    cin>>v[i];
}
int target;
cout<<"Enter Target:-";
cin>>target;
vector<int>ans=twoSum(v,target);
cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}
/*
   Problem Name: Products of Array Except Self (NeetCode 150)   
   Concept: Arrays & Hashing / Prefix & Postfix Product
   Time Complexity: O(N)
   Space Complexity: O(1) (excluding output array)

   Constraints:
   2 <= nums.length <= 1000
   -20 <= nums[i] <= 20
   Each product is guaranteed to fit in a 32-bit integer.
   Follow-up: Solve it in O(n) time without using division.

   Input Format (ip):
   - First line: Integer N (size of array).
   - Second line: N space-separated integers representing nums.

   Output Format (op):
   - Print the output array enclosed in brackets [].
   
   Example 1:
   Input:
   4
   1 2 4 6
   Output:
   [48,24,12,8]
   ========================================== */

#include <iostream>
#include <vector>

using namespace std;
 vector<int> productExceptSelf(vector<int>& nums) {
    vector<int>presum(nums.size());
    presum[0]=1;
    for(int i=1;i<nums.size();i++){
        presum[i]=presum[i-1]*nums[i-1];
    }
    int sufsum=1;
    for(int i=nums.size()-1;i>=0;i--){
        
        presum[i]*=sufsum;
        sufsum*=nums[i];
    }
    return presum;

    }
int main(){
    int n;
    cout<<"Enter n-";
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){cin>>v[i];}
    v=productExceptSelf(v);
    for(int vi:v){cout<<vi<<" ";}
    return 0;
}


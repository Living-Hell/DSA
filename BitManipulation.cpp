#include<bits/stdc++.h>
using namespace std;

class BitManipulation{
    public:    
    //Given a positive integer N, print count of set bits in it. 
    int setBits(int N) {
        if(N==1) return 1;
        return (N%2) + setBits(N/2);
    }

    //Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in 
    //pairs whereas the other two number occur exactly once and are distinct. Find the other two numbers. 
    //Return in increasing order.
    vector<int> singleNumber(vector<int> nums) {
        int xorall=0;
        for(int num:nums) xorall ^= num;
        xorall = xorall & ~(xorall-1);
        int set1=0, set2=0;
        for(int num:nums){
            if(xorall&num) set1^=num;
            else set2^=num;
        }
        if(set1>set2) swap(set1,set2);
        return {set1,set2};
    }
    //Method-2
    vector<int> singleNumber(vector<int> nums){
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int n = nums.size();
        for(int i=0; i<n-2; i++){
            if((nums[i]^nums[i+1]) != 0 and (nums[i+1]^nums[i+2]) != 0)
                ans.push_back(nums[i+1]);
        }
        if(nums[0] != nums[1]) ans.push_back(nums[0]);
        if(nums[n-1] != nums[n-2]) ans.push_back(nums[n-1]);
        if(ans[0]>ans[1]) swap(ans[0],ans[1]);
        return ans;
    }

    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        int x = a ^ b;
        int ans = 0;
        while(x!=0){
            if(x&1) ans++;
            x = x>>1;
        }
        return ans;
    }

};

int main(){
    BitManipulation bitsm;

    return 0;
}
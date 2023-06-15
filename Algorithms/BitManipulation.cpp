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
    vector<int> SingleNumber(vector<int> nums){
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

    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n){
        if(n==0) return 0;
        int mx2pwr = 0;
        while(1 << mx2pwr <= n) mx2pwr++;
        mx2pwr--;
        int tillMx2Pr = (1 << (mx2pwr-1))*mx2pwr;
        int leftMostSet = n - (1<<mx2pwr) + 1;
        int ans = tillMx2Pr + leftMostSet + countSetBits(n-(1<<mx2pwr));
        return ans;
    }

    //Given a number N having only one ‘1’ and all other ’0’s in its binary representation, find position of the only set bit. 
    //If there are 0 or more than 1 set bit the answer should be -1. 
    int findPosition(int N) {
        int pwrOf2=0;
        while(1<<pwrOf2 <= N) pwrOf2++;
        pwrOf2--;
        if((1<<pwrOf2) == N) return pwrOf2+1;
        else return -1;
    }

    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){ 
        return (n!=0) and (n&(n-1)) == 0;
    }

    //Given two numbers X and Y, and a range [L, R] where 1 <= L <= R <= 31. Find the set bits of Y 
    //in range [L, R] and set these bits in X also. Return this modified X.
    int setSetBit(int x, int y, int l, int r){
        for(int i=r; i>=l; i--){
            if(1<<(i-1) & y)
                x = x | 1<<(i-1);
        }
        return x;
    }

    //Given two integers dividend and divisor. Find the quotient after dividing dividend by divisor 
    //without using multiplication, division and mod operator.
    long long divide(long long dvd, long long dsr){
        int sign = (dvd<0) ^ (dsr<0) ? -1 : 1;
        dvd = abs(dvd);
        dsr = abs(dsr);
        int ans=0;
        while(dvd >= dsr){
            for(int i=0; i<32; i++){
                if(dsr * (1<<i) > dvd){
                    dvd -= dsr * (1<<(i-1));
                    ans += (1<<(i-1));
                    break;
                }
            }
        }
        return sign*ans;
    }

    //Given a string S, Find all the possible subsequences of the String in lexicographically-sorted order.
    vector<string> AllPossibleStrings(string s){
        int n = s.size();
        vector<string> ans;
        long long val = 1<<n;
        for(long long i=1; i<=val; i++){
            string s1;
            for(int j=0; j<n; j++){
                if(i&(1<<j))
                    s1.push_back(s[j]);
            }
            ans.push_back(s1);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }

    //Given an integer n, calculate the square of a number without using *, / and pow()
    int square(int n){
        n = abs(n);
        int ans=0, ind=0, temp = n;
        while(temp>0){
            if(temp&1){
                ans += n<<ind;
            }
            temp = temp>>1;
            ind++;
        }
        return ans;
    }


};

int main(){
    BitManipulation bitsm;
    cout<<bitsm.square(16);
    return 0;
}
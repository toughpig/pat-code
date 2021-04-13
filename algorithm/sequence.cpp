#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:

// 15. 三数之和
// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        int len = nums.size();
        sort(nums.begin(),nums.end());
        int index=0;
        while(index<len-2){
            int val = nums[index];
            if(val>0) break;
            int ll=index+1, rr=len-1;
            int target = 0-val;
            while(ll<rr){
                int lnum=nums[ll], rnum=nums[rr];
                int sum = lnum+rnum;
                if(sum==target){
                    ans.push_back(vector<int>({val,lnum,rnum}));
                    do
                    {
                        ll++;
                    }while(ll<rr&&lnum==nums[ll]);
                    do
                    {
                        rr--;
                    }while(ll<rr&&rnum==nums[rr]);
                }
                else if(sum<target){
                    do{
                        ll++;
                    }while(ll<rr&&nums[ll]==lnum);
                }
                else{
                    do{
                        rr--;
                    }while(rr>ll&&nums[rr]==rnum);
                }
            }
            do{
                index++;
            }while(index<nums.size()-2&&val==nums[index]);
        }
        return ans;
    }

// 18. 四数之和
// 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
    vector<vector<int>> fourSum(vector<int>& nums, int target){
        vector<vector<int> > ans;
        int len = nums.size();
        sort(nums.begin(),nums.end());
        int index=0;
        while(index<len-3){
            int val = nums[index];
            int pos=index+1;
            while(pos<len-2){
                int ll=pos+1, rr=len-1;
                int posval=nums[pos];
                int tar = target-val-posval;
                while(ll<rr){
                    int lnum=nums[ll], rnum=nums[rr];
                    int sum = lnum+rnum;
                    if(sum==tar){
                        ans.push_back(vector<int>({val,posval,lnum,rnum}));
                        do
                        {
                            ll++;
                        }while(ll<rr&&lnum==nums[ll]);
                        do
                        {
                            rr--;
                        }while(ll<rr&&rnum==nums[rr]);
                    }
                    else if(sum<tar){
                        do{
                            ll++;
                        }while(ll<rr&&nums[ll]==lnum);
                    }
                    else{
                        do{
                            rr--;
                        }while(rr>ll&&nums[rr]==rnum);
                    }
                }
                do{
                    pos++;
                }while(pos<nums.size()-2&&posval==nums[pos]);
            }
            do{
                index++;
            }while(index<nums.size()-3&&val==nums[index]);
        }

        return ans;
    }

// 16. 最接近的三数之和
// 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int index = 0;
        int dif = ~(1<<(sizeof(int)*8-1));
        int ans = 0;
        int len = nums.size();
        while(index<len-2 && (nums[index]*3-target)<dif){
            int ll = index+1;
            int rr = len-1;
            while(ll<rr){
                int sum = nums[index]+nums[ll]+nums[rr];
                if(abs(sum-target)<dif){
                    dif=abs(sum-target);
                    ans=sum;
                }
                if(sum<target) ll++;
                else if(sum>target) rr--;
                else return target;
            }
            index++;
        }
        return ans;
    }


};

int main(){

    

    return 0;
}
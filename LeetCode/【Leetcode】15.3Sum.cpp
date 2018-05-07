//【LeetCode】15. 3Sum
//详解见：https://blog.csdn.net/cinderella_niu/article/details/42455523

//双指针法//O(n^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> results;
		if(nums.size() < 3) return vector<vector<int>>(results.begin(), results.end());
		//对数组排序，重要
		sort(nums.begin(), nums.end());
		//第三个数，循环到倒数第三个数
		for(int pointer1 = 0; pointer1 < nums.size() - 2; pointer1++){
			//第三个数防重复
			if(pointer1>0 && nums[pointer1]==nums[pointer1-1]) continue;
			int l = pointer1 + 1;
			int r = nums.size() - 1;
			while(l<r){
				if(nums[pointer1] + nums[l] + nums[r] == 0){
					results.insert({nums[pointer1], nums[l], nums[r]});
					//第一个第二个数防重复
					do{
						l++;
					}while(l<r && nums[l]==nums[l-1]);
					do{
						r--;
					}while(l<r && nums[r]==nums[r+1]);
				}
				else if(nums[pointer1] + nums[l] + nums[r] > 0)
					r--;
				else
					l++;
			}
		}
		return vector<vector<int>>(results.begin(),results.end());
    }
};
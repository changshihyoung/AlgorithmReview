//【LeetCode】18. 4Sum
//详解见：https://blog.csdn.net/cinderella_niu/article/details/42455523

//双指针法//O(n^3)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> result;
		if(nums.size() < 4) return vector<vector<int>>(result.begin(), result.end());
		//对数组排序
		sort(nums.begin(), nums.end());
		//第四个数（注意循环到倒数第四个）
		for(int pointer1 = 0; pointer1 < nums.size()-3; pointer1++){
			//第四个数防重复
			if(pointer1>0 && nums[pointer1]==nums[pointer1-1]) continue;
			//第三个数（注意循环到倒数第三个）
			for(int pointer2 = pointer1 + 1; pointer2 < nums.size()-2; pointer2++){
				//第三个数防重复
				if(pointer2>pointer1+1 && nums[pointer2]==nums[pointer2-1]) continue;
				int l = pointer2 + 1;
				int r = nums.size() - 1;
				while(l < r){
					if(nums[pointer1] + nums[pointer2] + nums[l] + nums[r] == target){
						result.insert({nums[pointer1], nums[pointer2], nums[l], nums[r]});
						//防重复的同时，l<r的条件不要忘了
						do{
							l++;
						}while(l < r && nums[l-1] == nums[l]);
						do{
							r--;
						}while(l < r && nums[r+1] == nums[r]);
					}
					else if(nums[pointer1] + nums[pointer2] + nums[l] + nums[r] > target)
						r--;
					else
						l++;
				}
			}
		}
		return vector<vector<int>>(result.begin(),result.end());
		
    }
};

//暴力法
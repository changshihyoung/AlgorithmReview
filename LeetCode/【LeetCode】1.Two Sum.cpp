//【LeetCode】1.Two Sum
//详解见：https://changshihyoung.github.io/2017/09/15/LeetCode-1.Two-Sum/

//哈希图法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
		if(nums.size()<=1 || nums.empty())
			return result;
		unordered_map<int, int> index;
		for(int i=1; i<nums.size(); i++){
			index[nums[i-1]] = i-1;
			if(index.count(target-nums[i]) != 0){
				result.push_back(index[target-nums[i]]);
				result.push_back(i);
				break;
			}
		}
		return result;
    }
};

//暴力法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
		if(nums.size()<=1 || nums.empty())
			return result;
		for(int i=0; i<nums.size(); i++){
			for(int j=i+1; j<nums.size(); j++){
				if(nums[i]+nums[j] == target){
					result.push_back(i);
					result.push_back(j);
				}
			}
		}
		return result;
    }
};
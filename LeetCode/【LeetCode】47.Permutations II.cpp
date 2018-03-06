//【LeetCode】47.Permutations II
//详解见：https://changshihyoung.github.io/2017/09/19/LeetCode-46.Permutations-47.Permutations-II-60.Permutation-Sequence/

//找规律法
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
		map<vector<int>,int> resultmap;
		vector<vector<int>> result;
		//先压栈，保留首个序列，兼顾“[1]”的情况
		result.push_back(nums);
		resultmap[nums]++;
        if(nums.size()>1 && !nums.empty()){
			while(true){
				int i = nums.size() - 1;
				while(i>0 && nums[i-1]>=nums[i])  //搜寻的条件要注意，一不小心就写错
					i--;
				if(i == 0)
					reverse(nums.begin(), nums.end());
				else{
					int j = nums.size() - 1;
					while(j>=i && nums[j]<=nums[i-1])  //搜寻的条件要注意，一不小心就写错，找>的数要写while(<=)
						j--;
					swap(nums[i-1],nums[j]);
					reverse(nums.begin()+i, nums.end());
				}
				if(resultmap.count(nums) == 0){
					result.push_back(nums);
					resultmap[nums]++;
				}
				else
					break;
			}
		}
		return result;
    }
};
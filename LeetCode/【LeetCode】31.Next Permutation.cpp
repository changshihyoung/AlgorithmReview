//【LeetCode】31.Next Permutation
//详解见：https://changshihyoung.github.io/2017/09/19/LeetCode-31.Next-Permutation/

//找规律法
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()>1 && !nums.empty()){
			int i = nums.size() - 1;
			while(i>0 && nums[i-1]>=nums[i]) //一定记住是“>=”，找递增序列
				i--;
			if(i == 0)
				reverse(nums.begin(),nums.end());
			else{
				int j = nums.size() - 1;
				while(j>=i && nums[j]<=nums[i-1])
					j--;
				swap(nums[i-1],nums[j]);
				reverse(nums.begin()+i,nums.end());
			}
		}
    }
};
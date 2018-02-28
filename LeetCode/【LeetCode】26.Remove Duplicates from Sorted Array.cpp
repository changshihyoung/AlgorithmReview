//【LeetCode】26.Remove Duplicates from Sorted Array
//详解见：https://changshihyoung.github.io/2017/09/17/LeetCode-26.Remove-Duplicates-from-Sorted-Array/

//引入指针法
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0 || nums.empty())
			return 0;
		int p = 0;
		for(int i=1; i<nums.size(); i++){
			if(nums[i] != nums[p]){
				p++;
				nums[p] = nums[i];
			}
		}
		return p+1;
    }
};

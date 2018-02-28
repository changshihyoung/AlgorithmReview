//【LeetCode】80.Remove Duplicates from Sorted Array II
//详解见：https://changshihyoung.github.io/2017/09/17/LeetCode-80.Remove-Duplicates-from-Sorted-Array-II/

//引入指针法
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //int result = 0;  //可以用p代替，p+1
		if(nums.size() == 0 || nums.empty())
			return 0;
		int p = 0, count = 0;
		for(int i=1; i<nums.size(); i++){
			if(nums[i] != nums[p]){
				p++;
				nums[p] = nums[i];
				//result++;
				count = 0;
			}
			else if(count == 0){
				p++;
				nums[p] = nums[i];
				//result++;
				count++;
			}
		}
		//return result;
		return p+1;
    }
};

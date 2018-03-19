//【LeetCode】81.Search in Rotated Sorted Array II
//详解见：https://changshihyoung.github.io/2017/09/20/LeetCode-33.Search-in-Rotated-Sorted-Array-81.Search-in-Rotated-Sorted-Array-II/

//条件二分法
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()<1 || nums.empty())
			return false;
		int left = 0, right = nums.size() - 1;
		while(left <= right){
			int mid = left + (right - left) / 2;
			if(nums[mid] == target)
				return true;
			else if(nums[mid] < nums[right]){
                //target <= nums[right]和target >= nums[left]的条件需要注意
                //若不加=号，target与边缘相等的情况会被跳过去
				if(target > nums[mid] && target <= nums[right])
					left = mid + 1;
				else
					right = mid - 1;
			}
			else if(nums[mid] > nums[right]){
				if(target < nums[mid] && target >= nums[left])
					right = mid - 1;
				else
					left = mid + 1;
			}			
			//需要注意，不能漏掉“nums[mid] = nums[right])”的情况，否则会在陷入死循环
			else
				right--;
		}
		return false;
    }
};

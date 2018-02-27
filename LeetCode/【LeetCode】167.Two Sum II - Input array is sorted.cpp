//【LeetCode】167.Two Sum II - Input array is sorted
//详解见：https://changshihyoung.github.io/2017/09/27/LeetCode-167.Two-Sum-II-Input-array-is-sorted/

//双指针法
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> result;
        if(numbers.size()<=1 || numbers.empty())
			return result;
		int idx1 = 0, idx2 = numbers.size() - 1;
		while(idx1 < idx2){
			if(numbers[idx1]+numbers[idx2] < target)
				idx1++;
			else if(numbers[idx1]+numbers[idx2] > target)
				idx2--;
			else{
				result.push_back(idx1 + 1);
				result.push_back(idx2 + 1);
				break;
			}				
		}
		return result;	
    }
};


//二分查找法
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> result;
        if(numbers.size() <= 1 || numbers.empty())
			return result;
		for(int i = 0; i < numbers.size(); i++){
			int idx1 = i + 1; 
			int idx2 = numbers.size() - 1;
			int newtarget = target - numbers[i];
			while(idx1 <= idx2){
				int mid = idx1 + (idx2 - idx1)/2;
				if(numbers[mid] == newtarget){
					result.push_back(i + 1);
					result.push_back(mid + 1);
					break;
				}
				else if(numbers[mid] > newtarget)
					idx2 = mid - 1;
				else
					idx1 = mid + 1;					
			}
		}
		return result;
    }
};

//暴力法
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> result;
        if(numbers.size() <= 1 || numbers.empty())  return result;
		for(int i=0; i<numbers.size(); i++ ){
			for(int j=i+1; j<numbers.size(); j++){
				if(numbers[i] + numbers[j] == target){
					result.push_back(i+1);
					result.push_back(j+1);
				}
			}
		}
		return result;	
    }
};
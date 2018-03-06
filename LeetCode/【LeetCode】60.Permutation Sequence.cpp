//【LeetCode】60.Permutation Sequence
//详解见：https://changshihyoung.github.io/2017/09/19/LeetCode-46.Permutations-47.Permutations-II-60.Permutation-Sequence/

//找规律法（超时，需重新找规律，可上网查找）
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
		//构造初始nums序列[1,2,3...]
		for(int idx=1; idx<=n; idx++)
			nums.push_back(idx);
		string result;
		//检查n,k是否符合要求
        if(n>=1 && n<=9 && k<=factorial(n)){
			//Next Permutation过程
			for(int idx=1; idx<=k; idx++){
				result = vector_int_to_string(nums);
				int i = nums.size() - 1;
				while(i>0 && nums[i-1]>=nums[i])
					i--;
				if(i == 0)
					reverse(nums.begin(), nums.end());
				else{
					int j = nums.size() - 1;
					while(j>=i && nums[j]<=nums[i-1])
						j--;
					swap(nums[i-1],nums[j]);
					reverse(nums.begin()+i, nums.end());
				}
			}
		}
		return result;
    }
	int factorial(int x){
		int ans=1;
		for(int i=1; i<=x; i++)
			ans*=i;
		return ans;
	}
	string vector_int_to_string(vector<int>& nums){
		string str;
		for(int i=0; i<nums.size(); i++){
			str = str + to_string(nums[i]);
		}
		return str;
	}
};
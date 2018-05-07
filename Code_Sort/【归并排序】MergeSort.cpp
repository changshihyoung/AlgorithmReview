//【归并排序】MergeSort
//详解见：https://www.cnblogs.com/agui521/p/6918229.html
#include <iostream>
#include <vector>
#include <windows.h>

class Solution {
public:
    //递归
    vector<int> MergeSort1(vector<int>& nums) {
        
    }
	//非递归
	vector<int> MergeSort2(vector<int>& nums) {
        
    }
};





//主函数
void main(){
	//vector初始化：https://blog.csdn.net/yjunyu/article/details/77728410?locationNum=10&fps=1
	int array[10]={9,2,4,7,3,5,8,6,1,10};
	vector<int> nums(arrar, array+10);
	Solution sltn;
	sltn.MergeSort1(nums);
	for(int i = 0; i < nums.size(); i++){
		cout << nums[i] << " ";
	}
	system("PAUSE");
}
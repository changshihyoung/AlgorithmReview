#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#define random(a,b) (rand()%(b-a+1)+a)
using namespace std;
/*�����е��ظ����֣�
1. ���������򣬺�����������ֻҪһ���ͷ���
2. ��2sum�ķ�������map��������ݣ�ÿ�β��� */
class solution{
public:
	int Repeat_1(vector<int> &arr){
		if (arr.size() < 2)
			return -2;		
		sort(arr.begin(), arr.end());
		for (int i = 1; i < arr.size(); i++){
			if (arr[i] == arr[i - 1])
				return arr[i];
		}
		return -1;
	}
	int Repeat_2(vector<int> &arr){
		if (arr.size() < 2)
			return -2;
		map<int, int> MapCount;
		for (int i = 0; i < arr.size(); i++){
			if (MapCount.count(arr[i]) == 0)
				MapCount[arr[i]]++;
			else
				return arr[i];
		}
		return -1;
	}
};
void PrintArr(vector<int> arr){
	for (int i = 0; i < arr.size(); i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main(){
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++){
		arr.push_back(random(0, n - 1));
	}

	//int arr1[6] = { 5, 5, 4, 5, 4, 4 };
	//vector<int> arr2(arr1, arr1 + 6);
	PrintArr(arr);

	solution s;
	cout << "Repeat_2: " << s.Repeat_2(arr) << endl;
	cout << "Repeat_1: " << s.Repeat_1(arr) << endl;

	system("PAUSE");
}
#include <iostream>
#include <cstdlib>
#include <vector>
#define random(a,b) (rand()%(b-a+1)+a)
using namespace std;
/*��ά���������������ϵ������ӣ����������ӣ�
1. �ݹ鷽����һֱ�������µݹ�Ѱ�ң����������/����target������0��������ҵ��ˣ�����1�� 
2. �ҹ��ɷ�����ѡ���һ���������������ʼ�жϣ����������target�����󡿡����С��target�����¡�������ҵ��ˣ�����1��*/
class solution{
public:
	int RecurFind_1(int i, int j, vector<vector<int>> &matrix, int target){
		if (j >= matrix.size() || i >= matrix[0].size())
			return 0;
		if (matrix[j][i] > target)
			return 0;
		else if (matrix[j][i] == target)
			return 1;
		else
			return RecurFind_1(i + 1, j, matrix, target) + RecurFind_1(i, j + 1, matrix, target);
	}
	int RecurFind_2(vector<vector<int>> &matrix, int target){
		if (matrix.size() <= 0)
			return -1;
		int i = matrix[0].size() - 1, j = 0;
		while (i > 0 && j < matrix.size()){
			if (matrix[j][i] == target)
				return 1;
			else if (matrix[j][i] > target)
				i--;
			else
				j++;
		}
		return 0;
	}
};
void PrintMatrix(vector<vector<int>> matrix){
	for (int j = 0; j < matrix.size(); j++){
		for (int i = 0; i < matrix[0].size(); i++){
			cout << matrix[j][i] << " ";
		}
		cout << endl;
	}
}
int main(){
	int n, m;
	cin >> n >> m;
	vector<int> arr;
	arr.reserve(n);
	vector<vector<int>> matrix;
	for (int j = 0; j < m; j++){
		for (int i = 0; i < n; i++){
			arr.push_back(random(i+j, i+j+1));
		}
		matrix.push_back(arr);
		arr.clear();
	}
	PrintMatrix(matrix);

	solution s;
	int target = 4;
	cout << "FindMatrix1: " << s.RecurFind_1(0, 0, matrix, target) << endl;
	cout << "FindMatrix2: " << s.RecurFind_2(matrix, target) << endl;

	system("PAUSE");
}
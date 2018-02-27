//【LeetCode】170.Two Sum III - Data structure design
//详解见：https://changshihyoung.github.io/2017/09/26/LeetCode-170.Two-Sum-III-Data-structure-design/

//直接进行设计
class TwoSum {
public:
    void add(int num){
        Map[num]++;
    }
    bool find(int target) {
        for(auto idx : Map){
			int gap = target - idx.first;
			if(gap != idx.first && Map[gap]!=0)
				return true;  //当前值与另一值之和为target
			else if(gap == idx.first && idx.second>1)
				return true;  //当前值与当前值之和为target，second表示存在另一个当前值
		}
		return false;
    }
private:
    unordered_map<int, int> Map;
};
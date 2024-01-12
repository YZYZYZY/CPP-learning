//O(1) 时间插入、删除和获取随机元素
//设计一个支持在平均 时间复杂度 O(1) 下，执行以下操作的数据结构。
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>

using namespace std;

class RandomizedSet{
    private:
        vector<int> nums;
        unordered_map<int, int> numToIndex;
    public:
        RandomizedSet(){}

        bool insert(int val){
            //numToIndex.end()
            if(numToIndex.find(val) != numToIndex.end()){
                return false;
            }
            numToIndex[val] = nums.size();//这里的size是指向下一个元素的位置，所以这里的size就是下一个元素的位置
            nums.push_back(val);
            return true;
        }

        bool remove(int val){
            if(numToIndex.find(val) == numToIndex.end()){
                return false;
            }
            int lastNum = nums.back();
            int idx = numToIndex[val];
            nums[idx] = lastNum;
            numToIndex[lastNum] = idx;
            nums.pop_back();
            numToIndex.erase(val);
            return true;
        }

        int getRandom(){
            return nums[rand() % nums.size()];
        }

};

int main(){

    RandomizedSet randomizedSet;
    std::cout << std::boolalpha; // 打印布尔值时使用 true/false 而不是 1/0
    std::cout << randomizedSet.insert(1) << std::endl;  // 返回 true
    std::cout << randomizedSet.remove(2) << std::endl;  // 返回 false
    std::cout << randomizedSet.insert(2) << std::endl;  // 返回 true
    std::cout << randomizedSet.getRandom() << std::endl; // 随机返回 1 或 2
    std::cout << randomizedSet.remove(1) << std::endl;  // 返回 true
    std::cout << randomizedSet.insert(2) << std::endl;  // 返回 false
    std::cout << randomizedSet.getRandom() << std::endl; // 总是返回 2

    system("pause"); // 可以根据需要注释或取消注释
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Person {
public:
    string name;
    int age;

    // 构造函数
    Person(string n, int a) : name(n), age(a) {}

    // 重载 < 运算符，根据年龄进行排序
    bool operator < (const Person& p) const {
        return age < p.age;
    }
};

int main() {
    // 创建并初始化Person对象的vector
    vector<Person> people;
    people.push_back(Person("Alice", 30));
    people.push_back(Person("Bob", 25));
    people.push_back(Person("Charlie", 35));

    // 使用std::sort根据年龄排序
    sort(people.begin(), people.end());

    // 输出排序后的Person对象
    for(const auto& person : people) {
        cout << person.name << " is " << person.age << " years old." << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <limits> 

//定义Record类来存储每条记录的详细信息
class Record
{
    public:
        //为什么变量不是private的？
        std::string description;
        double amount;
        bool isIncome;
        //构造函数 初始化列表 参数传递
        Record(std::string desc , double amt, bool income): description(std::move(desc)), amount(amt), isIncome(income) {}
        //重载输出运算符?是重载的string类型的输出运算符吗？
        //这个就是对外的接口？应该不是，因为Record不存在对外的行为
        // const 修饰成员函数，表示这个函数不会修改对象的状态；这样的函数叫做常量成员函数
        std::string ToString() const{
            return (isIncome? "Income:  " : "Expense: ") + std::to_string(amount) + "Description: " + description;
        }
};

//创建一个AccoutBook类来管理这些记录，包括添加、显示、删除和编辑功能
class AccountBook
{
    private:
        std::vector<Record> records;
    public:
        //添加记录 修饰函数参数，表示这个函数不会修改传入的参数对象。
        void AddRecord(const Record& record){
            records.push_back(record);
        }
        //显示记录
        void ShowRecords() const{
            //常引用，表示这个引用不会修改对象的状态
            for(const auto& record: records){
                std::cout << record.ToString() << std::endl;
            }
        }
        //删除记录 size_t 是一种无符号整数类型，通常用于表示大小或者索引。
        void DeleteRecord(size_t index){
            if(index < records.size()){
                records.erase(records.begin() + index);
            }
        }
        //编辑记录 编辑不是修改吗？这怎么感觉是添加？
        void EditRecord(size_t index, const Record& record){
            if(index < records.size()){
                records[index] = record;
            }
        }
        //保存记录到文件 
        //要将一个对象作为函数参数，而函数不需要修改这个对象时，使用 const 引用是一个很好的选择。
        void SaveRecords(const std::string& filename) const{
            std::ofstream file(filename);
            for (const auto& record : records){
                file << record.description << "," << record.amount << "," << record.isIncome << std::endl;
            }
            file.close();
        }
        //从文件中读取记录
        void LoadFromFile(const std::string& filename){
            std::ifstream file(filename);
            std::string description;
            double amount;
            bool isIncome;
            while(file >> description >> amount >> isIncome){
                records.emplace_back(description, amount, isIncome);
            }
            file.close();
        }
};

//创建main函数来处理用户交互（为什么用户交互不单独成为一个类？）
int main(){
    AccountBook book;
    //原本没有这个文件，所以这个函数是创建了一个文件？
    book.LoadFromFile("accouting_procedures\\records.txt");

    bool running = true;
    while(running){
        std::cout << "1. Add record" << std::endl;
        std::cout << "2. Show records" << std::endl;
        std::cout << "3. Delete record" << std::endl;
        std::cout << "4. Edit record" << std::endl;
        std::cout << "5. Save records" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Please select: ";

        int choice;
        std::cin >> choice;

        //为什么在这里还要定义这些变量？这些变量不是在Record类中定义过了吗？
        std::string description;
        double amount;
        bool isIncome;
        size_t index;
        
        switch(choice){
            //输入里面不能有空格吗？有空格还是会出现死循环
            case 1:
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略换行符
                std::cout << "Please input description: ";
                std::getline(std::cin, description);
                std::cin >> description;
                std::cout << "Please input amount: ";
                std::cin >> amount;
                std::cout << "Please input income(0/1): ";
                std::cin >> isIncome;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略换行符
                //这里直接调用的是Record类的构造函数吗？构造函数不是自动调用的吗？
                //临时对象？匿名对象？生命周期只在这个语句中？
                book.AddRecord(Record(description, amount, isIncome));
                break;
            case 2:
                book.ShowRecords();
                break;
            case 3:
                std::cout << "Please input index: ";
                std::cin >> index;
                book.DeleteRecord(index);
                break;
            case 4:
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略换行符
                std::cout << "Please input index: ";
                std::cin >> index;
                std::cout << "Please input description: ";
                std::getline(std::cin, description);
                std::cout << "Please input amount: ";
                std::cin >> amount;
                std::cout << "Please input income (0/1): ";
                std::cin >> isIncome;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 再次忽略换行符
                book.EditRecord(index, Record(description, amount, isIncome));
                break;
            case 5:
                book.SaveRecords("records.txt");
                break;
            case 6:
                running = false;
                break;
            default:
                std::cout << "Invalid option, please try again." << std::endl;
        }
    
        
    }

    return 0;
}

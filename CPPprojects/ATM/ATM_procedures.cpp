#include <iostream>
#include <string>
#include <vector>

using namespace std;

//定义一个Account类来封装与账户相关的操作，如存款、取款、查询余额等
class Account{   
    //数据定义为私有成员，只能通过公有成员函数来访问
    private:
        string accountNumber; //账户号码
        double balance; //账户余额
    
    public:
        //构造函数，用于初始化账户号码和余额，初始化列表
        Account(const string& accountNum, double initialBalance): accountNumber(accountNum), balance(initialBalance) {}
        //存款
        void Deposit(double amount){
            if(amount > 0){
                balance += amount;
            }
        }
        //取款
        bool Withdraw(double amount){
            if(amount > 0 && amount <= balance){
                balance -= amount;
                return true;
            }
            return false;
        }
        //查询余额,修饰成员函数，表示这个函数不会修改对象的状态；这样的函数叫做常量成员函数
        double GetBalance() const{
            return balance;
        }
        //获取账户号码，这两个const的含义是不一样的，第一个表示返回值是常量（是对象，又不想修改就可以用const来修饰），第二个表示这个函数不会修改对象的状态
        const string& GetAccountNumber() const{
            return accountNumber;
        }
};

//创建一个ATMMachine类来封装与ATM机相关的操作，如插卡、输入密码、显示菜单等
class ATMMachine{
    private:
        vector<Account> accounts; //账户列表

    public:
        //构造函数，初始化账户列表.嘶为什么初始的用户信息要写在这里？这不是ATM机的行为吧？
        ATMMachine(){
            //初始化账户列表
            accounts.emplace_back("123456", 1000);
            accounts.emplace_back("654321", 2000);
        }
        
        void run(){
            cout<<"Welcome to the ATM!"<<endl;
            while(true){
                cout<<"Entor your account number: ";
                string accountNumber;
                cin>>accountNumber;
                //查找账户
                Account* account = findAccount(accountNumber);
                if(account){
                    //显示账户菜单
                    showAccountMenu(*account);
                }
                else{
                    cout<<"Invalid account number!"<<endl;
                }

            }

        }

        private:
            //查找账户
            Account* findAccount(const string& accountNum){
                for(auto& account: accounts){
                    if(account.GetAccountNumber() == accountNum){
                        return &account;
                    }
                }
                return nullptr;
            }
            //显示账户菜单
            void showAccountMenu(Account& account){
                int choice;
                do{
                    std::cout << "1. Check Balance" << std::endl;
                    std::cout << "2. Deposit" << std::endl;
                    std::cout << "3. Withdraw" << std::endl;
                    std::cout << "4. Exit" << std::endl;
                    std::cout << "Enter choice: ";
                    cin >> choice;

                    switch(choice){
                        case 1:
                            cout<<"Your balance is: "<<account.GetBalance()<<endl;
                            break;
                        case 2:
                            cout<<"Enter amount to deposit: ";
                            double amount;
                            cin>>amount;
                            account.Deposit(amount);
                            break;
                        case 3:
                            cout<<"Enter amount to withdraw: ";
                            cin>>amount;
                            if(account.Withdraw(amount)){
                                cout<<"Withdraw successfully!"<<endl;
                            }
                            else{
                                cout<<"Withdraw failed!"<<endl;
                            }
                            break;
                        case 4:
                            cout<<"Thank you for using ATM!"<<endl;
                            exit(0);
                        default:
                            cout<<"Invalid choice!"<<endl;
                            break;
                    }
                }while(choice < 1 || choice > 4);
            }

};

//主函数
int main(){
    ATMMachine atm;
    atm.run();
    return 0;
}
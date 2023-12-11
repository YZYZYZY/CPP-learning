#include <iostream>
#include <vector>
#include <conio.h> //用于_kbhit()和_getch()函数
#include <windows.h> //用于Sleep()函数

using namespace std;

//定义方向,强类型枚举
enum class Direction {STOP = 0, LEFT, RIGHT, UP, DOWN};
Direction dir;

const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100]; //蛇的最大长度为100,存储蛇尾部分的坐标
int nTail; //蛇的长度
bool gameOver;

//初始化游戏的函数,为什么边框的位置不用初始化？
void Setup()
{
    gameOver = false;
    //初始化方向 0是停止？
    dir = Direction::STOP;
    //初始化蛇的位置
    x = width / 2;
    y = height / 2;
    //初始化水果的位置 随机位置生成
    fruitX = rand() % width;
    fruitY = rand() % height;
    //初始化分数
    score = 0;
}

//绘制游戏界面的函数,绘制游戏的当前状态，包括蛇，水果和边界
void Draw()
{
    //清屏，是每次绘制游戏界面时都清屏吗？
    system("cls");
    //绘制上边界
    for(int i=0;i < width+2; i++)
        cout << "#";
    cout << endl;

    //绘制游戏界面
    for(int i=0; i<height; i++){
        for(int j=0;j < width; j++){
            if(j==0)
                cout << "#";//绘制左边界
            if(i==y && j==x)
                cout << "O";//绘制蛇头
            else if(i==fruitY && j==fruitX)
                cout << "F";//绘制水果
            else{
                bool print = false;
                //因为蛇的长度是不确定的，所以用循环来绘制蛇尾
                for(int k=0; k<nTail;k++){
                    if(tailX[k]==j && tailY[k]==i){
                        cout << "o";//绘制蛇尾
                        print = true;
                    }
                }
                if(!print)
                    cout << " ";
        }
            if(j==width-1)
                cout << "#";//绘制右边界
        }
        cout << endl;
    }

    //绘制下边界,为什么这里和上边界的代码完全一样？是cout << endl;控制的距离上下边界的距离吗？
    for(int i=0;i < width+2; i++)
        cout << "#";
    cout << endl;
    cout << "Score:" << score << endl;
}

//接收用户输入的函数，怎么保证用户输入时游戏界面同步刷新？只依靠循环？
void Input()
{
    //如果_kbhit()函数返回值为真，说明有按键按下，这些头文件中定义的就是C++接近底层的关键？
    if(_kbhit()){
        //获取按下的键
        switch(_getch()){
            case 'a':
                //为什么要用强类型枚举？不直接用int类型吗？
                dir = Direction::LEFT;
                break;
            case 'd':
                dir = Direction::RIGHT;
                break;
            case 'w':
                dir = Direction::UP;
                break;
            case 's':
                dir = Direction::DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
        }
    }
}

//游戏逻辑的函数.游戏的逻辑就和绘制的逻辑完全分开的，要是我写的话，我会把绘制和逻辑写在一起，这样会不会更好？
void Logic()
{
    //蛇尾部分的坐标
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;

    //蛇尾部分的坐标等于蛇头部分的坐标
    tailX[0] = x;
    tailY[0] = y;

    //蛇尾部分的坐标等于蛇头部分的坐标
    for(int i=1; i<nTail; i++){
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        //蛇尾部分的坐标等于蛇头部分的坐标
        prevX = prev2X;
        prevY = prev2Y;
    }

    //根据方向移动蛇头部分的坐标
    switch(dir){
        case Direction::LEFT:
            x--;
            break;
        case Direction::RIGHT:
            x++;
            break;
        case Direction::UP:
            y--;
            break;
        case Direction::DOWN:
            y++;
            break;
        default:
            break;
    }

    //如果蛇头部分的坐标等于水果的坐标，分数加1，重新生成水果
    if(x==fruitX && y==fruitY){
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }

    //如果蛇头部分的坐标等于边界的坐标，游戏结束
    if(x > width || x < 0 || y > height || y < 0)
        gameOver = true;

    //如果蛇头部分的坐标等于蛇尾部分的坐标，游戏结束
    for(int i=0; i<nTail; i++){
        if(tailX[i]==x && tailY[i]==y)
            gameOver = true;
    }
}

int main()
{
    Setup();
    //这样设计循环的目的是确保即使在等待用户输入时，游戏的状态也能持续更新和绘制。
    while(!gameOver){
        Draw();
        Input();
        Logic();
        //控制游戏暂停，当暂停的时候按键会被存储到缓冲区，直到下一次执行Input()函数时才会被读取。
        Sleep(100);
    }
    //游戏结束后输出分数，并且暂停游戏而不是直接退出
    cout << "Game Over!" << endl;
    cout << "Your score is " << score << endl;
    system("pause");
    return 0;
}
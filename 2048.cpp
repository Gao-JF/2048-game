// 2048.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<stdlib.h>
#include<conio.h>
#include<iomanip>
#include<time.h>
using namespace std;
int w;
int lo;
char restart;
int map[4][4];
void init()
{
    w = 0;
    restart = '0';
    srand(time(NULL));
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            int value = rand() % 10;
            if (value >= 0 && value <= 8)
            {
                map[i][j] = 2;
            }
            else map[i][j] = 4;
        }
    }
}
int win()
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (map[i][j] == 2048)
            {
                cout << "YOU WIN!!" << endl;
                return 1;
            }
        }
    }
    return 0;
}
int lose()
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (map[i][j] == map[i][j + 1])
            {
                return 0;
            }
        }
    }
    for (int j = 0; j < 4; ++j)
    {
        for (int i = 0; i < 3; ++i)
        {
            if (map[i][j] == map[i+1][j])
            {
                return 0;
            }
        }
    }
    cout << "YOU LOSE!!" << endl;
    return 1;
}
int new_number()
{
    int value = rand() % 10;
    if (value >= 0 && value <= 8)
    {
        return 2;
    }
    else return 4;
}
void press_up()
{
    for (int j = 0; j < 4; ++j)
    {
        if (map[0][j] == map[1][j] && map[2][j] == map[3][j])
        {
            map[0][j] *= 2;
            map[2][j] *= 2;
            map[1][j] = map[2][j];
            map[2][j] = new_number();
            map[3][j] = new_number();
        }
        else if (map[0][j] == map[1][j])
        {
            map[0][j] *= 2;
            map[1][j] = map[2][j];
            map[2][j] = map[3][j];
            map[3][j] = new_number();
        }
        else if (map[1][j] == map[2][j])
        {
            map[1][j] *= 2;
            map[2][j] = map[3][j];
            map[3][j] = new_number();
        }
        else if (map[2][j] == map[3][j])
        {
            map[2][j] *= 2;
            map[3][j] = new_number();
        }
    }
}
void press_down()
{
    for (int j = 0; j < 4; ++j)
    {
        if (map[0][j] == map[1][j] && map[2][j] == map[3][j])
        {
            map[1][j] *= 2;
            map[3][j] *= 2;
            map[2][j] = map[1][j];
            map[0][j] = new_number();
            map[1][j] = new_number();
        }
        else if (map[2][j] == map[3][j])
        {
            map[3][j] *= 2;
            map[2][j] = map[1][j];
            map[1][j] = map[0][j];
            map[0][j] = new_number();
        }
        else if (map[1][j] == map[2][j])
        {
            map[2][j] *= 2;
            map[1][j] = map[0][j];
            map[0][j] = new_number();
        }
        else if (map[0][j] == map[1][j])
        {
            map[1][j] *= 2;
            map[0][j] = new_number();
            
        }
    }
}
void press_left()
{
    for (int i = 0; i < 4; ++i)
    {
        if (map[i][0] == map[i][1] && map[i][2] == map[i][3])
        {
            map[i][0] *= 2;
            map[i][2] *= 2;
            map[i][1] = map[i][2];
            map[i][2] = new_number();
            map[i][3] = new_number();
        }
        else if (map[i][0] == map[i][1])
        {
            map[i][0] *= 2;
            map[i][1] = map[i][2];
            map[i][2] = map[i][3];
            map[i][3] = new_number();
        }
        else if (map[i][1] == map[i][2])
        {
            map[i][1] *= 2;
            map[i][2] = map[i][3];
            map[i][3] = new_number();
        }
        else if (map[i][2] == map[i][3])
        {
            map[i][2] *= 2;
            map[i][3] = new_number();
        }
    }
}
void press_right()
{
    for (int i = 0; i < 4; ++i)
    {
            if (map[i][0] == map[i][1] && map[i][2] == map[i][3])
            {
                map[i][1] *= 2;
                map[i][3] *= 2;
                map[i][2] = map[i][1];
                map[i][0] = new_number();
                map[i][1] = new_number();
            }
            else if (map[i][2] == map[i][3])
            {
                map[i][3] *= 2;
                map[i][2] = map[i][1];
                map[i][1] = map[i][0];
                map[i][0] = new_number();
            }
            else if (map[i][1] == map[i][2])
            {
                map[i][2] *= 2;
                map[i][1] = map[i][0];
                map[i][0] = new_number();
            }
            else if (map[i][0] == map[i][1])
            {
                map[i][1] *= 2;
                map[i][0] = new_number();

            }
    }
}
void print()
{
    for (int i = 0; i < 4; ++i)
    {
        cout << "+----+----+----+----+" << endl;
        for (int j = 0; j < 4; ++j)
        {
            cout << "|";
            cout <<fixed<<setw(4)<< map[i][j];
        }
        cout << '|';
        cout << endl;
    }
    cout << "+----+----+----+----+" << endl;
    cout << endl;
    cout << "W(UP),S(DOWN),A(LEFT),D(RIGHT),R(RESTART),Q(QUIT)"<<endl;
}
int main()
{
    while (1)
    {
        system("cls");
        init();
        print();
        while (1)
        {
            int ch;
            if (_kbhit())
            {
                ch = _getch();
                if (ch == 87||ch==119)
                {
                    press_up();
                }
                else if (ch == 83||ch==115)
                {
                    press_down();
                }
                else if (ch == 65||ch==97)
                {
                    press_left();
                }
                else if (ch == 68||ch==100)
                {
                    press_right();
                }
                else if (ch == 82 || ch == 114)
                {
                    restart = 'Y';
                    break;
                }
                else if (ch == 81 || ch == 113)
                {
                    exit(1);
                }
                system("cls");
                print();
                w = win();
                lo = lose();
                if (w == 1)
                {
                    break;
                }
                if (lo == 1)
                {
                    break;
                }
            }
            
        }
        if (w == 1||lo==1)
        {
            cout << "重新开始？(Y/N)" << endl;
            restart = '0';
            while (restart == '0')
            {
                cin >> restart;
                if (restart == 'Y' || restart == 'y')
                {
                    break;
                }
                else if (restart == 'N' || restart == 'n')
                {
                    restart = 'N';
                    break;
                }
                else
                {
                    restart = '0';
                    cout << "输入无效，请重新输入：\n";
                }
            }
            if (restart == 'N')
                break;
        }
        else if (restart == 'Y')
        {
            continue;
        }
        
    }
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

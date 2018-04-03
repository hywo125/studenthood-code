#include "game.h"
#include "gamelib.h"
#include <conio.h>
 ///假设玩家的坐标
int X=2,Y=3;
int main()
{
    int playgogame=0;  ///用户登录的下标
    char key;  ///接受用户输入的按键
   // show();
    seltitle("笑傲江湖");
    selcorlor(10,0);
    ///实现游戏的进入界面
   selposition(25,8);
   goin1();
   clears(25,0,26);
    ///实现游戏的登录界面
    selposition(25,8);
    playgogame = goin2();
    clears(25,0,26);
    selposition(25,0);
    init(playgogame);
    showwelcome();
    showmap(X,Y);
    showinfmation();
    showmainmenu();
    while(1)
    {
        fflush(stdin);
        key = getch();
        fflush(stdin);
        if(key == '1' || key == '2' || key == '3' || key == '4')
        {
            processmainmenu(key,X,Y);
            selposition(15,25);
            continue;
        }
        if(key == 'w' ||key == 72) //上
            Y--;
        else if(key == 's' ||key == 80)  //下
            Y++;
        else if(key == 'a' ||key == 75)  //左
            X--;
        else if(key == 'd' ||key == 77)  //右
            X++;
        else if(key == '0') break;
        if(X > 7) X =0;
        if(X < 0) X =7;
        if(Y > 7) Y =0;
        if(Y < 0) Y =7;
        showmap(X,Y);
        selposition(15,25);
    }



    return 0;
}

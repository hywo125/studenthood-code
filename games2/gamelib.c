/********************************************
 * 文件名: Gamelib.c
 * 描   述: 实现gamelib.h中定义的函数
 * 日   期: 2017.4.23
 * 版   本: 1.0
 * 创建 人: sexx
 ********************************************/
 #include "gamelib.h"

 void seltitle(char *title)
 {
     SetConsoleTitle(title);
 }
void selcorlor(int fore ,int back)
{
    HANDLE winHandle;//句柄
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    ///设置颜色
    SetConsoleTextAttribute(winHandle,fore + back *0x10);
}
void selposition(int x,int y)
{
    HANDLE winHandle;//句柄
    COORD pos = {x ,y};
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    ///设置光标的位置
    SetConsoleCursorPosition(winHandle, pos);

}
void clears(int x,int y,int he)
{
    int i,j;
    for(i=0;i<he;i++)
    {
        selposition(x,y+i);
        for(j=0;j<80;j++)
        {
            printf(" ");
        }
    }
}



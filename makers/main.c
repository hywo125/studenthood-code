/********************************************
 * 文件名: main.E
 * 描   述: 实现整个项目的业务逻辑
 * 日   期: 2017.6.15
 * 版   本: 1.0
 * 创建 人: s
 ********************************************/
#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#include <windows.h>
#include "game.h"
#include "gamelib.h"

int main()
{
    static int x=40,y=5;
    int key;
    int seller_identity;
    seltitle("服装销售系统");
    system("mode con cols=120 lines=38");//设置窗口大小
    system("color 0a");
    if( access("C:/admin.txt",0) == -1 || access("C:/shopkeeper.txt",0) == -1 || access("C:/seller.txt",0) == -1 || access("C:/goodsmonth.txt",0)==-1)
     storge();
    init_all();
    login_in();
    init();

    while(1)
    {
        key = login(x,y);
        switch(key)
        {
            case 'w': y-=3; break;
            case 'd': x+=25; break;
            case 'a': x-=25; break;
            case 's': y+=3; break;
            case 0x1b:quit();
        }
        if(x<40) x =40;
        if(x>65) x =65;
        if(y>8) y=8;
        if(y<5) y=5;
    }
    frees();
    return 0;
}

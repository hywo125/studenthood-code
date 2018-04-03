#ifndef GAMELIB_H_INCLUDED
#define GAMELIB_H_INCLUDED
/********************************************
 * 文件名: Gamelib.h
 * 描   述: 用来定义游戏中常用的系统操作
 * 日   期: 2017.4.23
 * 版   本: 1.0
 * 创建 人: s
 ********************************************/
#include <stdio.h>
#include <windows.h>
/** 设置控制台窗口的标题*/
void seltitle(char *title);
/** 设置前景和背景色颜色*/
//0 黑 2 蓝 3 绿
void selcorlor(int fore ,int back);
/**设置光标的位置*/
void selposition(int x,int y);
/** 删除特定区域的所有内容*/
void clears(int x,int y,int he);
#endif // GAMELIB_H_INCLUDED

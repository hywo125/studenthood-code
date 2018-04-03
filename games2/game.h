#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
/********************************************
 * 文件名: Game.h
 * 描   述: 用来定义游戏核心结构和函数
 * 日   期: 2017.4.23
 * 版   本: 1.0
 * 创建 人: sexx
 ********************************************/
 #include <stdio.h>
 #include <string.h>
 #include <time.h>
 #include <stdlib.h>
 #include <windows.h>


 /***** 游戏结构类型定义
 //玩家,地图, 装备,怪物
 /*地图结构*/
typedef struct _map{
    ///地图的编号
    int id;
    ///地图的名称
    char name[50];
    ///玩家进入的最低等级
    int minlevel;
    ///地图的坐标-x,y
    COORD coord;
    ///地图介绍
    char desc[500];
}Map;


 /**游戏道具类型-武器 防具 消耗品 卡片*/
 typedef enum _proptype{
    weapon,armor,con,card,frag
 }Proptype;

/**游戏道具-武器 防具 消耗品 卡片*/
 typedef struct _prop{
     ///道具编号
    int id;
    ///道具名称
    char name[50];
    ///道具级别
    int level;
    ///道具的库存
    int stock;
    ///道具的单价
    double price;
    ///道具的类型
    Proptype type;
    ///根据类型对应的道具
    union{
        ///武器对应攻击力
        int minattack;
        ///防具对应防御力
        int mindefence;
        ///消耗品对应正价
        int minpower;
    };
    union{
        ///武器对应攻击力
        int maxattack;
        ///防具对应防御力
        int maxdefence;
        ///消耗品对应正价
        int maxpower;
    };
    ///道具的描述
    char desc[100];
}Prop;

 /**玩家*/
typedef struct _player{
    int id;
    char *name;
    char *pass;
    ///玩家生命值
    int life;
    ///玩家等级
    int level;
    ///玩家经验值
    int exp;
    ///玩家血量
    int hp;
    ///玩家内力值
    int mp;
    ///玩家最大内力值
    int mp_max;
    ///玩家金钱
    int gold;
    ///玩家的门派

    ///玩家装备的武器
    Prop weapon;
    ///玩家装备的防具
    Prop armor;
    ///玩家所在地图的坐标
    COORD coord;
    ///玩家的背包

}Player;
/**怪物*/
typedef struct _monster{
    int id;
    char name[50];
    int level;  ///怪物等级
    int hp;  ///怪物的血量
    int att;  ///怪物的攻击力
    int diff; ///怪物的防御力
    int minmoney;  ///杀死怪物掉落的最小金钱
    int maxmoney;  ///杀死怪物掉落的最大金钱
    int exp;  ///杀死怪物获得的经验值
    ///杀死怪物掉落的装备(扩展)

    int state; ///怪物的状态0 死亡,1存活
    COORD coord;  ///怪物的坐标
}Monster;
///实现游戏和显示界面
void goin1();
///实现游戏的登录界面
int goin2();
 ///初始化游戏数据
 void init(int);
 ///写实数据
 void show();
 ///显示游戏欢迎信息
 void showwelcome();
 ///显示游戏地图
 void showmap(int,int);
 ///在信息区显示地图信息
 void showmapinf(int,int);
 ///在信息界面显示玩家的信息资料
 void showplayer();
 ///在信息区显示当前地图的怪物 ,打怪
 void showmonsters(int,int);
 ///信息区显示当前地图的怪物
 void showmapmonsters(int,int);
 ///实现在选择栏中清理数据
 void showinfmations();
 /// 打怪
 void fight(int,int,int);
 ///显示游戏的信息区
 void showinfmation();
 ///显示游戏的主菜单
 void showmainmenu();
 /**实现菜单功能*/
 void processmainmenu(char,int,int);





#endif // GAME_H_INCLUDED

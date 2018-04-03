#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
/********************************************
 * 文件名: g
 * 描   述: 实现整个项目函数和信息的定义
 * 日   期: 2017.6.15
 * 版   本: 1.0
 * 创建 人: s
 ********************************************/




#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**商品*/
typedef struct goods
{

    char name[15]; ///商品名称

    char code[10];///商品代码

    char producer[20]; ///商品制造商

    double price; ///商品价格

    int quantity;///商品数量

}Goods;

/**管理员*/
typedef struct _admin
{
    /**管理员的名称*/
    char id[10];
    /**管理员的密码*/
    char pass[10];



}Admin;
/**店长*/
typedef struct _shopker
{
    /**店长的id*/
    char id[10];
    /**店长的密码*/
    char pass[10];


}Shpker;
/**销售员*/
typedef struct _seller
{
    /**id*/
    char id[10];
    /**名称*/
    char name[10];
    /**密码*/
    char pass[10];
    /**该销售员出售的商品*/
    Goods good;

}Seller;
/**销售表*/
typedef struct goods_report   ///商品报表
{
    Goods good;     ///商品
    Seller assistant;   ///营业员
    char sell_data[20]; ///出售日期
    int number;
}Goodsr;


/**初始化所有数据*/
void init_all();
void init();
/**初始化剩余数据*/
void surplus();
/**初始化销售员信息*/
void init_sell();
/**初始化界面*/
void interfaces();
/**初始化界面*/
void choice_faces();
/**初始化信息区界面*/
void info_face();
/**初始化信息操作区*/
void info_opretion();
/**登录*/
char login(int ,int);
/**初始化管理员操作信息*/
char admin_info(int,int);
/**初始化店长操作信息*/
char shoper_info(int,int);
/**初始化销售员操作信息*/
char seller_info(int,int);
/**某个功能的功能*/
void admin_deal(int,int);
/**某个功能的功能*/
void shoper_deal(int,int);
/**某个功能的功能*/
void seller_deal(int,int);
/**对商品的操作:*/
void choice_goods(char,int,int);
/**商品添加*/
void goods_add();
/**商品删除*/
void goods_del();
/**商品修改*/
void goods_modify();
/**商品查找*/
void goods_search();
/**商品浏览*/
void goods_browse();
/**商品出售*/
void goods_sell();
/**查看本月报表*/
void read_month();
/**获取当前时间*/
char* getnowtime();
/**登录界面和认证*/
void login_in();
/**初始化存储信息*/
void storge();
/**读取管理员的信息*/
char* read_damin();
/**读取店长信息*/
char* read_shpke();
/**读取销售员信息*/
char* read_seller();
/**添加用户*/
void add_user();
/**修改用户密码*/
void modify_pass();
/**修改管理员信息*/
void modify_admin(char *,char *);
/**修改店长信息*/
void modify_shpker(char *,char *);
/**修改销售员信息*/
void modify_seller(char *,char*,int);
/**删除用户*/
void del_user(int);
/**释放空间*/
void frees();
/**退出*/
void quit();



/**查找*/
/**浏览*/
/**修改*/
/**出售*/


#endif // GAME_H_INCLUDED

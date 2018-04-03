/********************************************
 * 文件名: game.C
 * 描   述: 实现整个项目的功能实现
 * 日   期: 2017.6.15
 * 版   本: 1.0
 * 创建 人: s
 ********************************************/
#include <conio.h>
#include <time.h>
#include <io.h>
#include "gamelib.h"
#include "game.h"
#define MINGX 15
#define _QUANYIYT 90
#define CHO_start 5
#define CHO_end 8
#define INFO_start 10
#define INFO_end 24
#define Opre_start 26
#define Opre_end 32


int login_number;   //判断登录身份
int len1;             //现有商品的个数
int len2,len;             //现有销售员个数
int len3;             //销售表销售商品的个数
char key;              //接收管理员的输入选择信息
char key_choice;       //接收商品信息中的输入字符
FILE *adminer,*shpk,*sell,*goods_sells;
/**初始化商品的函数*/
    Goods goodarry[27]={ {"G2000","00000","ggs有限公司",300.0 ,500 },{"雅阁多","00001","雅阁多有限公司", 300.0,400 },
        {"皮特丹东","00002","成都市芳菲乐有限公司",1000.0 ,600 },{"皮尔卡丹","00003","皮尔卡丹有限公司",2000.0 ,200 },{"花花公子","00004","花花公子有限公司", 300.0,100 },
        {"花雨伞","00005","雨伞有限公司",600 ,200 },{"法派","00006","法派有限公司",10100 ,20 },{"宝姿","00007","宝姿有限公司", 300,400 },
        {"保罗世家","00008","袜子有限公司",500 ,200 },{"塔吉","00009","辣条有限公司",100 ,600 },{"巴宝莉","00010","零食有限公司",1000 ,300 },
        {"胜龙","00011","胜龙有限公司",2000 ,200 },{"波动","00012","波动有限公司",200 ,300 },{"NOVELI","00013","NOVELI有限公司",1000 ,50 },
        {"卓凡","00014","卓凡有限公司",2000 ,100 },{"马基堡","00015","马基堡有限公司",300 ,500 },{"汤米","00016","汤米有限公司",500 ,200 },
        {"娃娃鱼","00017","娃娃鱼有限公司",300 ,200 },{"A B C","00018","广东景业",6.00 ,200 },{"苏菲","00019","尤妮佳集团",6.00 ,200 },{.code="00020",.quantity=1},
        {.code="00020",.quantity=1},{.code="00021",.quantity=1},{.code="00022",.quantity=1},{.code="00023",.quantity=1},{.code="00024",.quantity=1},{.code="00025",.quantity=1},{.code="00026",.quantity=1}
    };


/**定义销售员数组*/
    Seller sellerarr[5];
/**初始化商品报表*/
    Goodsr goodrarry[30]={ {.number=1},{.number=1},{.number=1},{.number=1},{.number=1},
    {.number=1},{.number=1},{.number=1},{.number=1},{.number=1},{.number=1},{.number=1},{.number=1},{.number=1},
    {.number=1},{.number=1},{.number=1},{.number=1},{.number=1},{.number=1},{.number=1},{.number=1},{.number=1},
    {.number=1},{.number=1},{.number=1},{.number=1},{.number=1},{.number=1},{.number=1}
    };
    /**初始化所有文件*/
void storge()
{
    char goods_month[25]="可口可乐 0号 2016.2.3 ";
    char adminss[] = "admin 123";
    char shpks[] ="news 123";
    char sellers[]="000 0号 123 00001 001 1号 123 00001 ";
    if(  (goods_sells = fopen("C:/goodsmonth.txt","w"))==NULL)
    {
        fprintf(stderr,"error");
        exit(0);
    }
    fprintf(goods_sells,"%s",goods_month);
    fclose(goods_sells);
    if(  (adminer = fopen("C:/admin.txt","w"))==NULL)
    {
        fprintf(stderr,"error");
        exit(0);
    }
    fprintf(adminer,"%s",adminss);
    fclose(adminer);
    if(  (shpk = fopen("C:/shopkeeper.txt","w"))==NULL)
    {
        fprintf(stderr,"error");
        exit(0);
    }
    fprintf(shpk,"%s",shpks);
    fclose(shpk);
    if(  (sell = fopen("C:/seller.txt","w"))==NULL)
    {
        fprintf(stderr,"error");
        exit(0);
    }
    fprintf(sell,"%s",sellers);
    fclose(sell);
}
/**读取文件中管理员信息*/
char* read_admin()
{
    char *read_admins;
    read_admins=(char *)malloc(sizeof(char)*20);
    if(  (adminer = fopen("C:/admin.txt","r"))==NULL)
    {
        fprintf(stderr,"error");
        exit(0);
    }
    fgets(read_admins,20,adminer);
    fclose(adminer);
    return read_admins;
}
/**读取文件中店长信息*/
char *read_shpke()
{
    char *read_shpker;
    read_shpker=(char *)malloc(sizeof(char)*20);
    if(  (shpk = fopen("C:/shopkeeper.txt","r"))==NULL)
    {
        fprintf(stderr,"error");
        exit(0);
    }
    fgets(read_shpker,20,shpk);
    fclose(shpk);
    return read_shpker;
}
/**读取文件中售货员信息*/
char* read_seller()
{
    char *read_sellers;
    read_sellers=(char *)malloc(sizeof(char)*100);
    if(  (sell = fopen("C:/seller.txt","r"))==NULL)
    {
        fprintf(stderr,"error");
        exit(0);
    }
    fgets(read_sellers,100,sell);
    fclose(sell);
    return read_sellers;
}
/**初始化剩余数据*/
    Admin admin;
    Shpker shpkes;
    Goods *goodsarrys=goodarry;       //指向商品结构体的指针
    Seller *sellerarry = sellerarr;   //指向销售员的指针
    Admin *admins=&admin;             //指向管理员的指针
    Shpker *shpkers= &shpkes;         //指向店长的指针
    Goodsr *goodser = goodrarry;      //指向销售表的指针
/**初始化管理员店长数据*/
void surplus()
{
    int i=0;
    char *adminsss=read_admin();
    char *shpkerss=read_shpke();
    char adminss[10],pass[10];
    while(*adminsss != ' ')
    {
        adminss[i] = *adminsss;
        adminsss++;
        i++;
    }
    adminss[i] = '\0';
    adminsss++;i=0;
    while(*adminsss != '\0')
    {
        pass[i] = *adminsss;
        adminsss++;
        i++;
    }
    pass[i]='\0';
    strcpy(admin.id,adminss);
    strcpy(admin.pass,pass);
    i=0;
    while(*shpkerss != ' ')
    {
        adminss[i] = *shpkerss;
        shpkerss++;
        i++;
    }
    adminss[i] = '\0';
    shpkerss++;i=0;
    while(*shpkerss != '\0')
    {
        pass[i] = *shpkerss;
        shpkerss++;
        i++;
    }
    pass[i]='\0';
    strcpy(shpkes.id,adminss);
    strcpy(shpkes.pass,pass);
}
/**初始化销售员信息*/
void init_sell()
{
    char *selles = read_seller();
    char id[10],name[10],pass[10],code[10];
    int i=0,j,k;
    for(j=0;j<5;j++)
    {
        i=0;
        if(*selles == '\0')break;
        while(*selles != ' ')
        {
            id[i] = *selles;
            selles++;
            i++;
        }
        id[i]='\0';
        selles++;i=0;
        while(*selles != ' ')
        {
            name[i] = *selles;
            selles++;
            i++;
        }
        name[i]='\0';
        selles++;i=0;
        while(*selles != ' ')
        {
            pass[i] = *selles;
            selles++;
            i++;
        }
        pass[i]='\0';
        selles++;i=0;
        while(*selles != ' ')
        {
            code[i] = *selles;
            selles++;
            i++;
        }
        code[i]='\0';
        selles++;
        strcpy(sellerarr[j].id,id);
        strcpy(sellerarr[j].name,name);
        strcpy(sellerarr[j].pass,pass);
        for(k=0;k<len1;k++)
        {
                    if(strcmp((goodsarrys+k)->code,code) == 0)
                        break;
        }
        sellerarr[j].good = *(goodsarrys+i);

    }

    len2=j;



}

void init_all()
{
     for(len1=0; goodarry[len1].quantity !=1;len1++);
     for(len3=0;goodrarry[len3].number!=1;len3++);
     surplus();
     init_sell();
}

/**初始化所有界面*/
void init()
{
    selposition(MINGX,1);
    printf("ESC 退出!");
    interfaces();
    choice_faces();
    info_face();
    info_opretion();
}


/**初始化界面*/
void interfaces()
{
    int i;
    selposition(MINGX,2);
    for(i=0;i<_QUANYIYT;i++) printf("-");
    selposition(MINGX,3);
    printf("|");
    selposition(MINGX+_QUANYIYT,3);
    printf("|");
    selposition(MINGX,4);
    for(i=0;i<_QUANYIYT;i++) printf("-");

}
/**初始化选择区*/
void choice_faces()
{
    int i;
    for(i=0;i<4;i++)
    {
        selposition(MINGX,CHO_start+i);
        printf("|");
        selposition(MINGX+_QUANYIYT,CHO_start+i);
        printf("|");
    }
    selposition(MINGX,9);
    for(i=0;i<_QUANYIYT;i++) printf("-");
}
/**初始化信息区*/
void info_face()
{
    int i;
    for(i=0;i<15;i++)
    {
        selposition(MINGX,INFO_start+i);
        printf("|");
        selposition(MINGX+_QUANYIYT,INFO_start+i);
        printf("|");
    }
    selposition(MINGX,INFO_end+1);
    for(i=0;i<_QUANYIYT;i++) printf("-");
}
/**初始化信息操作区*/
void info_opretion()
{
    int i;
    for(i=0;i<7;i++)
    {
         selposition(MINGX,Opre_start+i);
         printf("|");
         selposition(MINGX+_QUANYIYT,Opre_start+i);
         printf("|");
    }
    selposition(MINGX,Opre_end+1);
     for(i=0;i<_QUANYIYT;i++) printf("-");
}
/**添加用户*/
void add_user()
{
    char id[10],name[10],pass[10];
    char add[40];
    fflush(stdin);
    selposition(MINGX+5,INFO_start);
    printf("按1进入操作:");
    if(getch() == '1'); else return;
    fflush(stdin);
    clears(MINGX+1,INFO_start,1);
    selposition(MINGX+5,INFO_start);
    if(len2 == 5)
    {
        selposition(MINGX+25,INFO_start+7);
        printf("快要倒闭了,添加失败!");
        Sleep(1000);
        return;
    }
    printf("请输入:");
    selposition(MINGX+10,INFO_start+1);
    printf("id:");gets(id);
    selposition(MINGX+35,INFO_start+1);
    printf("name:");gets(name);
    selposition(MINGX+10,INFO_start+3);
    printf("pass:");gets(pass);
    strcpy(add,id);strcat(add," ");strcat(add,name);strcat(add," ");
    strcat(add,pass);strcat(add," ");strcat(add,"00000");strcat(add," ");
    if( (sell = fopen("C:/seller.txt","a+"))==NULL)
    {
        fprintf(stderr,"error");
        exit(0);
    }
    fprintf(sell,"%s",add);
    fclose(sell);
    selposition(MINGX+25,INFO_start+7);
    printf("添加成功!!");
    len++;
    init_all();
    Sleep(1000);
}
/**修改管理员信息*/
void modify_admin(char *id,char *pass)
{
    char add[15];
    strcpy(add,id);strcat(add," ");strcat(add,pass);
    if(  (adminer = fopen("C:/admin.txt","w"))==NULL)
    {
        fprintf(stderr,"error");
        exit(0);
    }
    fprintf(adminer,"%s",add);
    fclose(adminer);
    selposition(MINGX+30,INFO_start+6);
    printf("修改成功!");
    init_all();
    Sleep(1000);
}
/**修改店长信息*/
void modify_shpker(char *id,char *pass)
{
    char add[15];
    strcpy(add,id);strcat(add," ");strcat(add,pass);
    if(  (shpk = fopen("C:/shopkeeper.txt","w+"))==NULL)
    {
        fprintf(stderr,"error");
        exit(0);
    }
    fprintf(shpk,"%s",add);
    fclose(shpk);
    selposition(MINGX+30,INFO_start+6);
    printf("修改成功!");
    init_all();
    Sleep(1000);
}
/**修改销售员信息*/
void modify_seller(char *pass,char *id,int les)
{
    char add[200];int i;
    strcpy(add,"");
    for(i =0;i<len2;i++)
    {
        if(i == les)strcat(add,id);
        else strcat(add,(sellerarry+i)->id);
       strcat(add," ");strcat(add,(sellerarry+i)->name);strcat(add," ");
        if(i == les) strcat(add,pass);
        else strcat(add,(sellerarry+i)->pass);
        strcat(add," ");strcat(add,(sellerarry+i)->good.code);
        strcat(add," ");
    }
    if( (sell = fopen("C:/seller.txt","w+"))==NULL)
    {
        fprintf(stderr,"error");
        exit(0);
    }
    fprintf(sell,"%s",add);
    fclose(sell);
    selposition(MINGX+30,INFO_start+6);
    printf("修改成功!");
    init_all();
    Sleep(1000);
}
/***/
void del_user(int les)
{
    char add[200];int i;
    strcpy(add,"");
    for(i =0;i<len2;i++)
    {
        if(i == les) continue;
        strcat(add,(sellerarry+i)->id);
        strcat(add," ");
        strcat(add,(sellerarry+i)->name);
        strcat(add," ");
        strcat(add,(sellerarry+i)->pass);
        strcat(add," ");strcat(add,(sellerarry+i)->good.code);
        strcat(add," ");
    }
    if( (sell = fopen("C:/seller.txt","w+"))==NULL)
    {
        fprintf(stderr,"error");
        exit(0);
    }
    fprintf(sell,"%s",add);
    fclose(sell);
    selposition(MINGX+30,INFO_start+6);
    printf("删除成功!!");
    init_all();
    Sleep(1000);
}
/**修改信息*/
void modify_pass()
{
    int i;
    char choice;
    char pass[10];
    char id[10];
    choice =getch();
    clears(MINGX+1,INFO_start,15);
    if(choice == '1')
    {
        selposition(MINGX+15,INFO_start+1);
        printf("请输入新id: ");
        gets(id);
        selposition(MINGX+15,INFO_start+3);
        printf("请输入新密码:");
        fflush(stdin);
        gets(pass);
        modify_admin(id,pass);
    }
    else if(choice == '2')
    {
        selposition(MINGX+15,INFO_start+1);
        printf("请输入新id: ");
        gets(id);
        selposition(MINGX+15,INFO_start+3);
        printf("请输入新密码:");
        fflush(stdin);
        gets(pass);
        modify_shpker(id,pass);
    }
    else if(choice == '3')
    {
        char ids[10],pass[10],id[10];
        selposition(MINGX+5,INFO_start);
        printf("请输入要修改的销售员id:");
        gets(ids);
        for(i=0;i<len2;i++)
        {
            if(strcmp( (sellerarry+i)->id ,ids) ==0)
            break;
        }
        if(i == len2)
        {
            selposition(MINGX+25,INFO_start+5);
            printf("无此用户!!");
            return;
        }
        selposition(MINGX+10,INFO_start+1);
        printf("请输入新id:");
        gets(id);
        selposition(MINGX+35,INFO_start+1);
        printf("请输入新密码:");
        gets(pass);
        modify_seller(pass,id,i);
    }
    else if(choice == '4')
    {
        char id[10];
        selposition(MINGX+25,INFO_start+5);
        if(len2<=1){printf("大人,不要再删了,再删就没人了"); return;}
        else   printf("请输入要删除的销售员id:");
        gets(id);
        for(i=0;i<len2;i++)
        {
            if(strcmp( (sellerarry+i)->id ,id) ==0)
            break;
        }
        if(i == len2)
        {
            selposition(MINGX+25,INFO_start+5);
            printf("无此用户!!");
            return;
        }
        del_user(i);
    }
    else return;




}
/**管理员操作界面*/
void admin_deal(int x,int y)
{
    int i;
    clears(MINGX+1,INFO_start,15);
    clears(MINGX+1,Opre_start,7);
    if(x ==MINGX+25 && y == CHO_start)
    {
        selposition(MINGX+30,(INFO_start+INFO_end)/2);
        printf("欢 迎 使 用 此 管 理 系 统");
        selposition(MINGX+5,Opre_start);
        printf("1.修改管理员信息");
        selposition(MINGX+5,Opre_start+1);
        printf("2.修改店长信息");
        selposition(MINGX+5,Opre_start+2);
        printf("3.修改销售员密码");
        selposition(MINGX+5,Opre_start+3);
        printf("4.删除用户(限销售员)");
        selposition(MINGX+5,Opre_start+5);
        printf("请选择:");
        modify_pass();
    }
     if(x == MINGX+50 && y == CHO_start)  ///添加用户
     {
         add_user();
     }
     if(x == MINGX+25 && y == CHO_end)
     {
         selposition(MINGX+5,INFO_start);
         printf("用户信息如下:");
         selposition(MINGX+15,INFO_start+2);
         printf("管理员:%-12s密码:%s",admins->id,admins->pass);
         selposition(MINGX+15,INFO_start+4);
         printf("店长:  %-12s密码:%s",shpkers->id,shpkers->pass);
         selposition(MINGX+15,INFO_start+6);
         printf("销售员:");
         for(i=0;i<len2;i++)
         {
             selposition(MINGX+15,INFO_start+8+i);
             printf("ID:   %-12s密码:%s",(sellerarry+i)->id,(sellerarry+i)->pass);
         }
     }

      if(x == MINGX+50 && y == CHO_end)
      {
          selposition(MINGX+30,(INFO_start+INFO_end)/2);
          printf("欢 迎 使 用 此 管 理 系 统");
          selposition(MINGX+5,Opre_start);
          printf("1.商品添加");
          selposition(MINGX+35,Opre_start);
          printf("2.商品删除");
          selposition(MINGX+5,Opre_start+1);
          printf("3.商品修改");
          selposition(MINGX+35,Opre_start+1);
          printf("4.商品查找");
          selposition(MINGX+5,Opre_start+2);
          printf("5.商品浏览");
          selposition(MINGX+10,Opre_end-2);
          printf("请选择:");
          fflush(stdin);
          key_choice=getch();
          choice_goods(key_choice,x,y);
      }

}
/**管理员选择界面*/
char admin_info(int x,int y)
{
    selposition(MINGX+1,CHO_start);
    printf("您可以:");
    selposition(MINGX+25,CHO_start);
    if(x ==MINGX+25 && y == CHO_start)
    selcorlor(0,7);
    printf("修改密码");
    selcorlor(0xa,0);
    selposition(MINGX+50,CHO_start);
    if(x == MINGX+50 && y == CHO_start)
    selcorlor(0,7);
    printf("添加用户(仅限销售员)");
    selcorlor(0xa,0);
    selposition(MINGX+25,CHO_end);
    if(x == MINGX+25 && y == CHO_end)
    selcorlor(0,7);
    printf("用户信息");
    selcorlor(0xa,0);
    selposition(MINGX+50,CHO_end);
    if(x == MINGX+50 && y == CHO_end)
    selcorlor(0,7);
    printf("商品信息");
    selcorlor(0xa,0);
    selposition(MINGX+30,(INFO_start+INFO_end)/2);
    printf("欢 迎 使 用 此 管 理 系 统");
    admin_deal(x,y);
    key=getch();
    return key;
}
/**店长操作界面*/
void shoper_deal(int x,int y)
{
    int i;
    char key_choices,choices,*nowtimes,id[10],pass[10];
    clears(MINGX+1,INFO_start,15);
    clears(MINGX+1,Opre_start,7);
    selposition(MINGX+30,(INFO_start+INFO_end)/2);
    printf("欢 迎 使 用 此 管 理 系 统");
    selposition(MINGX+5,INFO_start);
    printf("按1进入操作!");
    if(getch() != '1')return;
    fflush(stdin);
    if(x ==MINGX+25 && y == CHO_start)
    {
        clears(MINGX+1,INFO_start,15);
        selposition(MINGX+15,INFO_start+3);
        printf("请输入您的新密码:");
        gets(pass);
        modify_shpker(shpkers->id,pass);
    }
    if(x == MINGX+50 && y == CHO_start)
    {
         clears(MINGX+1,INFO_start,15);
        selposition(MINGX+15,INFO_start+3);
        printf("请输入您的新id:");
        gets(id);
        modify_shpker(id,shpkers->pass);
    }
    if(x == MINGX+25 && y == CHO_end)
    {
        clears(MINGX+1,INFO_start,1);
          selposition(MINGX+5,Opre_start+1);
          printf("3.商品修改");
          selposition(MINGX+35,Opre_start+1);
          printf("4.商品查找");
          selposition(MINGX+5,Opre_start+2);
          printf("5.商品浏览");
          selposition(MINGX+10,Opre_end-2);
          printf("请选择:");
          fflush(stdin);
          key_choices=getche();
          choice_goods(key_choices,x,y);
    }
     if(x == MINGX+50 && y == CHO_end)
     {
           clears(MINGX+1,INFO_start,1);
        selposition(MINGX+5,Opre_start+1);
        printf("1.当日报表");
        selposition(MINGX+35,Opre_start+1);
        printf("2.当月报表");
        selposition(MINGX+20,Opre_start+1+2);
        selposition(MINGX+10,Opre_start+1+2);
        printf("请选择:");
         while(1)
         {

              choices = getche();
              if(choices == '1')  //日报表
              {
                   selposition(MINGX+1,INFO_start);
                   printf("今日报表:");
                    selposition(MINGX+5,INFO_start+1);
                    printf("%-10s %-6s %-11s","商品","销售员","时间");
                    nowtimes = getnowtime();
                    for(i=0;i<len3;i++)
                    {
                        if(strcmp(nowtimes ,(goodser+i)->sell_data)==0)
                        {
                            selposition(MINGX+5,INFO_start+i+2);
                            printf("%-10s %-5s %-10s",(goodser+i)->good.name,(goodser+i)->assistant.name,(goodser+i)->sell_data);
                        }
                        if(goodser->number==1)
                        {
                            selposition(MINGX+30,INFO_start+6);
                            printf("快要倒闭了,本月居然没有东西卖出!!");
                        }

                    }
              }
              if(choices == '2')
              {
                  read_month();
              }
              selposition(MINGX+10,Opre_start+1+2);
              printf("请选择(0退出):");
              if(choices == '0')
              {
                  clears(MINGX+1,INFO_start,15);
                  selposition(MINGX+30,(INFO_start+INFO_end)/2);
                  printf("欢 迎 使 用 此 管 理 系 统");
                  return;
              }
         }
     }
}
/**店长选择界面*/
char shoper_info(int x,int y)
{
    selposition(MINGX+1,CHO_start);
    printf("您可以:");
    selposition(MINGX+25,CHO_start);
    if(x ==MINGX+25 && y == CHO_start)
    selcorlor(0,7);
    printf("修改密码");
    selcorlor(0xa,0);
    selposition(MINGX+50,CHO_start);
    if(x == MINGX+50 && y == CHO_start)
    selcorlor(0,7);
    printf("修改个人信息");
    selcorlor(0xa,0);
    selposition(MINGX+25,CHO_end);
    if(x == MINGX+25 && y == CHO_end)
    selcorlor(0,7);
    printf("商品信息");
    selcorlor(0xa,0);
    selposition(MINGX+50,CHO_end);
    if(x == MINGX+50 && y == CHO_end)
    selcorlor(0,7);
    printf("查看报表");
    selcorlor(0xa,0);
    selposition(MINGX+30,(INFO_start+INFO_end)/2);
    printf("欢 迎 使 用 此 管 理 系 统");
    shoper_deal(x,y);
    key=getch();
    return key;
}
/**查看本月报表*/
void read_month()
{
    char *reads,readss[200],goods[10],sells[10],data[10];
    reads =readss;
    int i,j;
    clears(MINGX+1,INFO_start+2,10);
    selposition(MINGX+1,INFO_start);
    printf("本月报表:");
    selposition(MINGX+5,INFO_start+1);
    printf("%-10s %-6s %-11s","商品","销售员","时间");
     if(  (goods_sells = fopen("C:/goodsmonth.txt","r"))==NULL)
    {
        fprintf(stderr,"error");
        exit(0);
    }
    fgets(reads,200,goods_sells);
    fclose(goods_sells);

    for(j=0;j<13;j++)
    {
        i=0;
        while(*reads != ' ')
        {
            goods[i] = *reads;
            reads++;i++;
        }
        goods[i] ='\0';
        i=0;reads++;
        while(*reads != ' ')
        {
            sells[i] = *reads;
            reads++;i++;
        } sells[i] ='\0';
        i=0;reads++;
        while(*reads != ' ')
        {
            data[i] = *reads;
            reads++;i++;
        }  data[i] ='\0';
        selposition(MINGX+5,INFO_start+2+j);
        printf("%-10s %-5s %-10s",goods,sells,data);
        reads++;
        if(*reads == '\0')break;
    }


}
/**销售员操作界面*/
void seller_deal(int x,int y)
{
    clears(MINGX+1,INFO_start,15);
    clears(MINGX+1,Opre_start,7);
    char choices,*nowtimes;
    int i;
    selposition(MINGX+30,(INFO_start+INFO_end)/2);
    printf("欢 迎 使 用 此 管 理 系 统");
    selposition(MINGX+5,INFO_start);
    printf("按1进入操作!");
    if(getch() != '1')return;
    if(x ==MINGX+25 && y == CHO_start)
        goods_browse();
    if(x == MINGX+50 && y == CHO_start)
        goods_search();
    if(x == MINGX+25 && y == CHO_end)
         goods_sell();
    if(x == MINGX+50 && y == CHO_end)
    {
        clears(MINGX+1,INFO_start,1);
        selposition(MINGX+5,Opre_start+1);
        printf("1.当日报表");
        selposition(MINGX+35,Opre_start+1);
        printf("2.当月报表");
        selposition(MINGX+20,Opre_start+1+2);
        selposition(MINGX+10,Opre_start+1+2);
        printf("请选择:");
         while(1)
         {

              choices = getche();
              if(choices == '1')  //日报表
              {
                  clears(MINGX+1,INFO_start,10);
                   selposition(MINGX+1,INFO_start);
                   printf("今日报表:");
                    selposition(MINGX+5,INFO_start+1);
                    printf("%-10s %-6s %-11s","商品","销售员","时间");
                    nowtimes = getnowtime();
                    for(i=0;i<len3;i++)
                    {
                        if(strcmp(nowtimes ,(goodser+i)->sell_data)==0)
                        {
                            selposition(MINGX+5,INFO_start+i+2);
                            printf("%-10s %-5s %-10s",(goodser+i)->good.name,(goodser+i)->assistant.name,(goodser+i)->sell_data);
                        }
                        if(goodser->number==1)
                        {
                            selposition(MINGX+30,INFO_start+6);
                            printf("快要倒闭了,本月居然没有东西卖出!!");
                        }

                    }
              }
              if(choices == '2')
              {
                  read_month();
              }
              selposition(MINGX+10,Opre_start+1+2);
              printf("请选择(0退出):");
              if(choices == '0')
              {
                  clears(MINGX+1,INFO_start,15);
                  selposition(MINGX+30,(INFO_start+INFO_end)/2);
                  printf("欢 迎 使 用 此 管 理 系 统");
                  return;
              }
         }
    }
}
/**销售员选择界面*/
char seller_info(int x,int y)
{
    selposition(MINGX+1,CHO_start);
    printf("您可以:");
    selposition(MINGX+25,CHO_start);
    if(x ==MINGX+25 && y == CHO_start)
    selcorlor(0,7);
    printf("商品浏览");
    selcorlor(0xa,0);
    selposition(MINGX+50,CHO_start);
    if(x == MINGX+50 && y == CHO_start)
    selcorlor(0,7);
    printf("商品查找");
    selcorlor(0xa,0);
    selposition(MINGX+25,CHO_end);
    if(x == MINGX+25 && y == CHO_end)
    selcorlor(0,7);
    printf("商品出售");
    selcorlor(0xa,0);
    selposition(MINGX+50,CHO_end);
    if(x == MINGX+50 && y == CHO_end)
    selcorlor(0,7);
    printf("查看报表");
    selcorlor(0xa,0);
    selposition(MINGX+30,(INFO_start+INFO_end)/2);
    printf("欢 迎 使 用 此 管 理 系 统");
    seller_deal(x,y);
    fflush(stdin);
    key=getch();
    return key;
}
/**登录界面和认证*/
void login_in()
{
    char id[10],pass[10];int i=0;
    selposition(40,15);
    printf("欢 迎 使 用 本 管 理 系 统");
    Sleep(1000);
    clears(40,15,1);
    while(1)
    {
        selposition(38,8);
        printf("----------------------------------");
        selposition(38,9);
        printf("|请选择登录用户                   |");
        selposition(38,10);
        printf("----------------------------------");
        selposition(38,11);
        printf("|  1.管理员(非管理勿选,后果自负)  |");
        selposition(38,12);
        printf("----------------------------------");
        selposition(38,13);
        printf("|  2.店长                         |");
        selposition(38,14);
        printf("----------------------------------");
        selposition(38,15);
        printf("|  3.销售员                       |");
        selposition(38,16);
        printf("----------------------------------");
        selposition(38,17);
        printf("|  4.退出                         |");
        selposition(38,18);
        printf("----------------------------------");
        selposition(38,19);
        printf("|请选择:                          |");
        selposition(38,20);
        printf("----------------------------------");
        selposition(46,19);
        scanf("%d",&login_number);
        switch(login_number)
        {
        case 1:clears(38,8,15);
                selposition(38,8);
                printf("----------------------------------");
                selposition(38,9);
                printf("|请输入ID:                        |");
                selposition(38,10);
                printf("----------------------------------");
                selposition(38,11);
                printf("|请输入密码:                      |");
                selposition(38,12);
                printf("----------------------------------");
                selposition(48,9);
                fflush(stdin);
                gets(id);
                selposition(50,11);
                fflush(stdin);
                gets(pass);
                if(strcmp(id,admins->id)==0 && strcmp(pass,admins->pass)==0)
                {
                    selposition(45,17);
                    printf("登录成功!!");
                    Sleep(1000);
                    clears(38,8,11);
                    return;
                }
                else{
                    selposition(45,17);
                    printf("登录失败!!");
                    Sleep(1000);
                    break;
                }

        case 2: clears(38,8,15);
                fflush(stdin);
                selposition(38,8);
                printf("----------------------------------");
                selposition(38,9);
                printf("|请输入ID:                        |");
                selposition(38,10);
                printf("----------------------------------");
                selposition(38,11);
                printf("|请输入密码:                      |");
                selposition(38,12);
                printf("----------------------------------");
                selposition(48,9);
                fflush(stdin);
                gets(id);
                selposition(50,11);
                fflush(stdin);
                gets(pass);
                if(strcmp(id,shpkers->id)==0 && strcmp(pass,shpkers->pass)==0)
                {
                    selposition(45,17);
                    printf("登录成功!!");
                    Sleep(1000);
                    clears(38,8,11);
                    return;
                }
                else{
                    selposition(45,17);
                    printf("登录失败!!");
                    Sleep(1000);
                    break;
                }


        case 3:clears(38,8,15);
                fflush(stdin);
                selposition(38,8);
                printf("----------------------------------");
                selposition(38,9);
                printf("|请输入ID:                        |");
                selposition(38,10);
                printf("----------------------------------");
                selposition(38,11);
                printf("|请输入密码:                      |");
                selposition(38,12);
                printf("----------------------------------");
                selposition(48,9);
                fflush(stdin);
                gets(id);
                selposition(50,11);
                fflush(stdin);
                gets(pass);
                for(i=0;i<10;i++)
                {
                    if(strcmp(id,(sellerarry+i)->id)==0 && strcmp(pass,(sellerarry+i)->pass)==0)
                    {
                    selposition(45,17);
                    printf("登录成功!!");
                    Sleep(1000);
                    clears(38,8,11);
                    len = i;
                    return;
                    }
                }
                selposition(45,17);
                    printf("登录失败!!");
                    Sleep(1000);
                    break;
            case 4:exit(0);
        default:selposition(39,17);
                printf("输入错误,请重新输入");
                Sleep(1000);
        }

clears(38,8,15);
    }
}
/**显示当前用户*/
char login(int x,int y)
{
    if(login_number == 1)
    {
        selposition(MINGX+35,3);
        printf("您的身份:管理员");
        key =admin_info(x,y);
        return key;
    }
    else if(login_number == 2)
    {
        selposition(MINGX+35,3);
        printf("您的身份:店长");
        key =shoper_info(x,y);
        return key;
    }
    else if(login_number == 3)
    {
        selposition(MINGX+35,3);
        printf("您的身份:销售员.%s",(sellerarry+len)->name);
        key =seller_info(x,y);
        return key;
    }
    return 0;
}
/**对商品的操作判断界面*/
void choice_goods(char key_choice,int x,int y)
{
    //if(x == MINGX+50 && y == CHO_end)
    switch(key_choice)
    {
        case '1':goods_add(); break;
        case '2':goods_del();  break;
        case '3':goods_modify();  break;
        case '4':goods_search();  break;
        case '5':goods_browse();break;
        default:return;
    }

}
/**商品添加*/
void goods_add()
{

    clears(MINGX+1,INFO_start,15);
    selposition(MINGX+74,INFO_end);
    printf("0退出,任意键继续");
    if(getch()=='0') return;
    clears(MINGX+1,INFO_end,1);
    if(len1>=27)
    {
        selposition(MINGX+33,(INFO_start+INFO_end)/2);
        printf("您的库存已满");
        return;
    }
    selposition(MINGX+5,INFO_start);
    printf("请输入你要添加商品的所有信息:");
    selposition(MINGX+10,INFO_start+1);
    printf("名称:");
    scanf("%s",(goodsarrys+len1)->name);
    selposition(MINGX+50,INFO_start+1);
    fflush(stdin);
    printf("产地:");
    scanf("%s",(goodsarrys+len1)->producer);
    selposition(MINGX+10,INFO_start+2);
    fflush(stdin);
    printf("价格:");
    scanf("%lf",&(goodsarrys+len1)->price);
    selposition(MINGX+50,INFO_start+2);
    fflush(stdin);
    printf("数量:");
    scanf("%d",&(goodsarrys+len1)->quantity);
    len1++;
    selposition(MINGX+15,INFO_start+5);
    printf("添加成功!!");
    Sleep(1000);
}
/**商品删除*/
void goods_del()
{
    int i,j;
    char code[10];
    clears(MINGX+1,INFO_start,15);
    selposition(MINGX+5,INFO_start);
    printf("请输入要删除的商品代码:");
        gets(code);
          for(i=0;i<len1;i++)
        {
                if(strcmp((goodsarrys+i)->code,code) == 0)
                {
                    selposition(MINGX+5,INFO_start+1);
                    printf("%-15s %5s %-5.2lf %-4d",(goodsarrys+i)->name,(goodsarrys+i)->code,(goodsarrys+i)->price,(goodsarrys+i)->quantity);
                     selposition(MINGX+5,INFO_start+2);
                     printf("是否要删除(1,是 2.否): ");
                    break;
                }
        }
        if(len1 <= i)
        {
            selposition(MINGX+5,INFO_start+1);
            printf("仓库没有此物品!");
            Sleep(1000);
        }
        fflush(stdin);
        if(getche()=='1')
        {
            for(j=i;j<26;j++)
            {
                strcpy((goodsarrys+j)->name ,(goodsarrys+j+1)->name);
                strcpy((goodsarrys+j)->code ,(goodsarrys+j+1)->code);
                strcpy((goodsarrys+j)->producer,(goodsarrys+j+1)->producer);
                (goodsarrys+j)->price=(goodsarrys+j+1)->price;
                (goodsarrys+j)->quantity=(goodsarrys+j+1)->quantity;
            }
            selposition(MINGX+5,INFO_start+3);
            len1--;
            printf("已删除");
            Sleep(1000);
        }
        clears(MINGX+1,INFO_start,7);
        return;

}
/**商品修改*/
void goods_modify()
{
    int i;
    char code[10],key_modify;
    clears(MINGX+1,INFO_start,15);
    selposition(MINGX+1,INFO_start);
    printf("请输入要修改商品的代码:");
    while(1)
    {
        gets(code);
         for(i=0;i<len1;i++)
        {
                    if(strcmp((goodsarrys+i)->code,code) == 0)
                    {
                        selposition(MINGX+5,INFO_start+1);
                        printf("%-15s %5s %-5.2lf %-4d",(goodsarrys+i)->name,(goodsarrys+i)->code,(goodsarrys+i)->price,(goodsarrys+i)->quantity);
                        break;
                    }
        }
        if(i == len1)
        {
            selposition(MINGX+5,INFO_start+1);
            printf("无此商品!!");
            Sleep(500);
            clears(MINGX+1,INFO_start,10);
            selposition(MINGX+5,INFO_start);
            printf("请输入要修改商品的代码(回车退出):");
            fflush(stdin);
            if(getch() == 13) return;
            continue;
        }
        selposition(MINGX+1,INFO_start+2);
        printf("请选择要修改的属性:");
        selposition(MINGX+5,INFO_start+4);
        printf("1.名称");
        selposition(MINGX+35,INFO_start+4);
        printf("2.代码");
        selposition(MINGX+5,INFO_start+5);
        printf("3.产地");
        selposition(MINGX+35,INFO_start+5);
        printf("4.价格");
        selposition(MINGX+5,INFO_start+6);
        printf("5.数量");
        selposition(MINGX+5,INFO_start+7);
        printf("请选择:");
        key_modify= getche();
        switch(key_modify)
        {
            case '1': selposition(MINGX+5,INFO_start+8);
                      printf("请输入新的信息:");
                      scanf("%s",(goodsarrys+i)->name);
                      break;
            case '2':selposition(MINGX+5,INFO_start+8);
                     printf("请输入新的信息:");
                     scanf("%s",(goodsarrys+i)->code);
                     break;
            case '3': selposition(MINGX+5,INFO_start+8);
                     printf("请输入新的信息:");
                      scanf("%s",(goodsarrys+i)->producer);
                break;
            case '4': selposition(MINGX+5,INFO_start+8);
                      printf("请输入新的信息:");
                      scanf("%lf",&(goodsarrys+i)->price);
                break;
            case '5': selposition(MINGX+5,INFO_start+8);
                      printf("请输入新的信息:");
                      scanf("%lf",&(goodsarrys+i)->quantity);
                break;
        }
        selposition(MINGX+5,INFO_start+9);
        printf("修改成功!");
        Sleep(500);
        clears(MINGX+1,INFO_start,10);
        selposition(MINGX+5,INFO_start);
        printf("请输入要修改商品的代码(回车退出):");
        fflush(stdin);
        if(getch() == 13) return;

    }
}
/**商品查找*/
void goods_search()
{
    int i;
    char code[10];
    clears(MINGX+1,INFO_start,15);
    selposition(MINGX+5,INFO_start);
    printf("请输入要查找的货物代码:");
    while(1)
    {
        clears(MINGX+1,INFO_start+1,5);
         selposition(MINGX+40,INFO_start);
        gets(code);
        for(i=0;i<len1;i++)
        {
            if(strcmp((goodsarrys+i)->code,code) == 0)
            {
                selposition(MINGX+10,INFO_start+1);
                printf("大人,找到了.");
                selposition(MINGX+15,INFO_start+3);
                printf("%-15s %5s %-5.2lf %-4d",(goodsarrys+i)->name,(goodsarrys+i)->code,(goodsarrys+i)->price,(goodsarrys+i)->quantity);
                break;
            }
        }
        if(i >= len1)
        {
            selposition(MINGX+15,INFO_start+2);
            printf("大人的仓库居然没这件东西!");
        }
        clears(MINGX+1,INFO_start,1);
        selposition(MINGX+5,INFO_start);
        printf("请输入要查找的货物代码(回车退出):");
        fflush(stdin);
        if(getch() == 13) return;
    }
}
void goods_browse()
{
    int i;
    clears(MINGX+1,INFO_start,15);
    selposition(MINGX+5,INFO_start);
    printf("您的仓库有:");
    selposition(MINGX+5,INFO_start+1);
    printf("%-15s %5s %-5s %-4s","名称","货码","价格","库存");
    for(i=0;i<len1;i++)
    {

            if(i>=10 && i<20)
            {
                if(i == 10)
                {
                  selposition(MINGX+60,INFO_end);
                  printf("请按任意键继续...");
                  getch();
                  clears(MINGX+1,INFO_start,15);
                }
                selposition(MINGX+5,INFO_start+2+i-10);

            }
            else if(i>=20)
            {
                if(i == 20)
                {
                  selposition(MINGX+60,INFO_end);
                  printf("请按任意键继续...");
                  getch();
                   clears(MINGX+1,INFO_start,15);
                }
                selposition(MINGX+5,INFO_start+2+i-20);
            }
            else selposition(MINGX+5,INFO_start+2+i);



            printf("%-15s %5s %-5.2lf %-4d",(goodsarrys+i)->name,(goodsarrys+i)->code,(goodsarrys+i)->price,(goodsarrys+i)->quantity);
    }
    selposition(MINGX+75,INFO_end);
    printf("0退出");

}
/**商品出售*/
void goods_sell()
{
    int i;
    char *times,add[200];
    char code[10],key_choice;
    times = getnowtime();
    selposition(0,0);
    puts(times);
    clears(MINGX+1,INFO_start,15);
    selposition(MINGX+5,INFO_start);
    printf("请输入要出售的商品代码:");
    while(1)
    {
        gets(code);
        for(i=0;i<len1;i++)
        {
                    if(strcmp((goodsarrys+i)->code,code) == 0)
                    {
                        selposition(MINGX+5,INFO_start+1);
                        printf("%-15s %5s %-5.2lf %-4d",(goodsarrys+i)->name,(goodsarrys+i)->code,(goodsarrys+i)->price,(goodsarrys+i)->quantity);
                        selposition(MINGX+5,INFO_start+3);
                        printf("是否要出售(1.是 2.否):");
                        key_choice=getche();
                        break;
                    }
        }
        if(i == len1)
        {
            selposition(MINGX+20,INFO_start+4);
            printf("无此商品!!");
            Sleep(500);
            goto l;
        }
        if(key_choice == '1')
        {
            (goodsarrys+i)->quantity-=1;                 //数量减少
            (goodser+len3)->assistant=*(sellerarry+len);     //记录售货员(待完善)
            (goodser+len3)->good=*(goodsarrys+i);        //记录售出商品
            (goodser+len3)->number=0;
            strcpy((goodser+len3)->sell_data,times);                    //处理判断的成员
            len3++;
            (goodser+len3)->number=1;
            strcpy(add,"");strcat(add,(goodsarrys+i)->name);strcat(add," ");
            strcat(add,(sellerarry+len)->name);strcat(add," ");strcat(add,times);strcat(add," ");
            if(  (goods_sells = fopen("C:/goodsmonth.txt","a"))==NULL)
            {
                fprintf(stderr,"error");
                exit(0);
            }
            fprintf(goods_sells,"%s",add);
            fclose(goods_sells);
            selposition(MINGX+20,INFO_start+5);
            printf("出售成功");
            Sleep(500);
        }
        l:clears(MINGX+1,INFO_start,6);
        selposition(MINGX+5,INFO_start);
        printf("请输入要出售的商品代码(回车退出):");
        if(getch() == 13) return;
    }
}
/**获取当前日期*/
char* getnowtime()
{
    char *times;
    times =(char *)malloc(sizeof(char)*15);
    /**获取系统当前时间*/
    time_t nowtime;
	struct tm *timeinfo;
	int year, month, day;
	time( &nowtime );
	timeinfo = localtime( &nowtime );
	year = timeinfo->tm_year + 1900;
	month = timeinfo->tm_mon + 1;
	day = timeinfo->tm_mday;
	/**----------------------*/
	sprintf(times,"%d",year);
	times[4]='.';
	sprintf(times+5,"%d",month);
	times[6]='.';
	sprintf(times+7,"%d",day);
    return times;
}
void frees()
{
    char *read_a =read_admin();
    free(read_a);
    char *read_b =read_shpke();
    free(read_b);
    char *read_c =read_seller();
    free(read_c);
    char *read_d =getnowtime();
    free(read_d);
}
void quit()
{
    clears(MINGX+1,INFO_start,15);
    clears(MINGX+1,Opre_start,7);
    selposition(MINGX+35,INFO_start+6);
    printf("是否退出(1.是 2.否)");
    if(getch() == '1')
    {
        exit(0);
    }
}











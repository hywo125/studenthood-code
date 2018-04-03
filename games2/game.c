/********************************************
 * 文件名: game.c
 * 描   述: 实现游戏的主逻辑
 * 日   期: 2017.4.23
 * 版   本: 1.0
 * 创建 人: sexx
 ********************************************/
#include "game.h"
#define N 81
#define ming_x 15///左边距
#define TITLE_A "欢迎来到笑傲江湖!"
#define ming_y_end 11
#define inf_start_y 12
#define inf_end_y  19
int player_X=2,player_Y=3;

int i,j;
char levelname[7][10] = {"初出茅庐","粗通皮毛","略有小成","心神理会","出类拔萃","所向无敌","天人合一"};
Player players[]={ {922,"唐唐","123",100,3,1,1000,5000,9000,2000,.coord.X=3,.coord.Y=1},
                    {923,"x","123",100,1,1,100,50,900000,1000000,.coord.X=2,.coord.Y=1},
                    {924,"c","123",100,4,1,10000,50000,900000,1000000,.coord.X=4,.coord.Y=1},
                    {925,"d","123",100,9,1,100000,500000,9000000,1000000,.coord.X=3,.coord.Y=0},


};

Monster monsters[] = {
    {1,"四瞳灵狐",1,100,50,20,50,10,10,1,{0,0}},
    {2,"四瞳灵狐",1,100,50,20,50,10,10,1,{0,1}},
    {3,"四瞳灵狐",1,100,50,20,50,10,10,1,{0,2}},
    {4,"四瞳灵狐",1,100,50,20,50,10,10,1,{0,3}},
    {5,"四瞳灵狐",1,100,50,20,50,10,10,1,{0,4}},
    {6,"四瞳灵狐",1,100,50,20,50,10,10,1,{0,5}},
    {7,"风暴美人鱼",2,300,50,50,5,10,10,500,{0,1}},
    {8,"雷霆娜迦",3,300,50,50,5,10,10,600,{0,3}},
    {9,"死神螳螂 ",4,400,50,50,5,10,10,700,{0,4}},
    {10,"吞天巨蟒 ",5,400,50,50,5,10,10,800,{1,0}},
    {11,"雷龙皇  ",6,500,50,50,5,10,10,900,{1,0}},
    {12,"嗜血魔蝠 ",7,500,50,50,5,10,10,1000,{1,0}},
    {13,"九天神雷兽  ",7,500,50,50,5,10,10,1100,{1,0}},
    {14,"火眼金睛兽 ",7,500,50,50,5,10,10,1200,{1,1}},
    {15,"狮麋兽",7,500,50,60,1000,10,10,1300,{2,0}},
    {16,"闪电柏龙驹",7,500,50,60,5,10,10,1400,{2,0}},
    {17,"虚空古龙",7,500,50,60,5,10,10,1500,{2,0}},
    {18,"碧睛狂狮",7,500,50,50,5,10,10,1600,{2,0}},
    {19,"烈焰魔猿",7,500,50,60,5,10,10,1700,{2,0}},
    {20,"暗黑巨龙",7,500,50,60,5,10,10,1800,{3,0}},
    {21,"铁背苍熊 ",7,500,50,60,5,10,10,1900,{3,0}},
    {22,"猛犸巨象 ",7,500,50,50,5,10,10,2000,{3,0}},
    {23,"金毛狮王 ",6,500,50,50,5,10,10,2000,{4,0}},
    {24,"金毛狮王的孙子 ",5,500,50,50,5,10,10,200,{4,0}},
    {25,"金毛狮王的爸爸 ",7,500,50,50,5,10,10,2000,{4,0}}

};

Prop proparry[]={
{1,"帝皇剑",1,5,5000,weapon,.minattack=100,.maxattack=200,"来自上古,历经岁月"},
{2,"帝皇甲",1,5,50500,armor,.mindefence=2,.maxattack=6,"年代久远,曾经辉煌,因为力量的流失品阶下降"},
{3,"六味地黄丸",1,5,500500,con,.minpower=100,.maxpower=500,"未知"},
{3,"六味地黄丸",1,5,500500,con,.minpower=100,.maxpower=500,"未知"},
};
Map maparry[8][8]={
    {{1,"天山",1,{0,0},"这里充满了西域文化"},{2,"楼兰",1,{0,1},"昔日辉煌之地,如今早已消失在历史的薄纱之下昔日辉煌之地,如今早已消失在历史的薄纱之下"},
        {3,"白驼山",1,{0,2},"这是一个充满斗争与危机的时代，同时这也是一个波澜壮阔的时代，不同的人怀着不同的信仰奔向自己的阵地。"},
        {4,"野猪林",1,{0,3},"这里经常有野猪出没,是猎人的家园,也是他们生存下去的希望."},
        {5,"水晶洞",1,{0,4},"这里犹如它的名字一样"},
        {6,"天蚕洞",1,{0,5},"这里充满了锡武文化"},
        {7,"黑风寨",1,{0,6},"这里充满了锡武文化"},{8,"冰火岛",1,{0,7},"这里充满了锡武文化"},
    },
    { {9,"迷宫",1,{1,0},"这里充满了锡武文化"},{10,"凌霄城",1,{1,1},"这里充满了锡武文化"},
      {11,"轩辕岭",1,{1,2},"这里充满了锡武文化"},{12,"华山",1,{1,3},"这里充满了锡武文化"},
      {13,"嵩山",1,{1,4},"这里充满了锡武文化"},{14,"紫荆城",1,{1,5},"这里充满了锡武文化"},
      {15,"快活岭",1,{1,6},"这里充满了锡武文化"},{16,"神龙岛",1,{1,7},"这里充满了锡武文化"},
    },
    { {17,"西域",1,{2,0},"这里充满了锡武文化"},{18,"葫芦谷",1,{2,1},"这里充满了锡武文化"},
      {19,"唐门",1,{2,2},"这里充满了锡武文化"},{20,"终南山",1,{2,3},"这里充满了锡武文化"},
      {21,"石窟",1,{2,4},"这里充满了锡武文化"},{22,"客栈",1,{2,5},"这里充满了锡武文化"},
      {23,"玉皇顶",1,{2,6},"这里充满了锡武文化"},{24,"灵蛇岛",1,{2,7},"这里充满了锡武文化"}
    },
    { {25,"光明顶",1,{3,0},"这里充满了锡武文化"},{26,"摩天崖",1,{3,1},"这里充满了锡武文化"},
      {27,"聚贤庄",1,{3,2},"这里是 <唐门> 的总舵.唐门在江湖上以暗器闻名.但自从唐门的唐老太太过      世后唐家堡一度家道中落，加之唐甜为称霸武林挑起纷争,又使唐门陷入了再度的浩劫，几乎一蹶不振。在这种危难的时刻唐门出现了一群新生力\
量：唐纾、唐斩、唐缺、唐玉。他们整顿内务，肃清奸佞，打出了匡复武林正义的旗帜，\
并且在江湖上行侠仗义，挽回了唐门的声誉，使唐门成为了江湖上的名门正派。"},
      {28,"后山",1,{3,3},"这里充满了锡武文化"},
      {29,"武当山",1,{3,4},"这里充满了锡武文化"},{30,"开封府",1,{3,5},"这里充满了锡武文化"},
      {31,"二十四桥",1,{3,6},"这里充满了锡武文化"},{32,"蓬莱仙境",1,{3,7},"这里充满了锡武文化"}
    },
    { {33,"擂鼓山",1,{4,0},"这里充满了锡武文化"},{34,"峨眉山",1,{4,1},"这里充满了锡武文化"},
      {35,"迷踪林",1,{4,2},"这里充满了锡武文化"},{36,"五虎岭",1,{4,3},"这里充满了锡武文化"},
      {37,"天宁府",1,{4,4},"这里充满了锡武文化"},{38,"积善堂",1,{4,5},"这里充满了锡武文化"},
      {39,"郑江府",1,{4,6},"这里充满了锡武文化"},{40,"桃花岛",1,{4,7},"这里充满了锡武文化"},
    },
    { {41,"恶人谷",1,{5,0},"这里充满了锡武文化"},{42,"大理",1,{5,1},"这里充满了锡武文化"},
      {43,"百花谷",1,{5,2},"这里充满了锡武文化"},{44,"孔雀山庄",1,{5,3},"这里充满了锡武文化"},
      {45,"五霸岗",1,{5,4},"这里充满了锡武文化"},{46,"万仞唐",1,{5,5},"这里充满了锡武文化"},
      {47,"千年古刹",1,{5,6},"这里充满了锡武文化"},{48,"六和塔",1,{5,7},"这里充满了锡武文化"},
    },
    { {49,"玩偶山庄",1,{6,0},"这里充满了锡武文化"},{50,"黑木崖",1,{6,1},"这里充满了锡武文化"},
      {51,"蝴蝶谷",1,{6,2},"这里充满了锡武文化"},{52,"铁花堡",1,{6,3},"这里充满了锡武文化"},
      {53,"霹雳堂",1,{6,4},"这里充满了锡武文化"},{54,"关帝庙",1,{6,5},"这里充满了锡武文化"},
      {55,"麒麟庄",1,{6,6},"这里充满了锡武文化"},{56,"销魂股",1,{6,7},"这里充满了锡武文化"},
    },
    { {57,"石府",1,{7,0},"这里充满了锡武文化"},{58,"晶三角",1,{7,1},"这里充满了锡武文化"},
      {59,"忏悔崖",1,{7,2},"这里充满了锡武文化"},{60,"通吃岛",1,{7,3},"这里充满了锡武文化"},
      {61,"通天观",1,{7,4},"这里充满了锡武文化"},{62,"紫霞亭",1,{7,5},"这里充满了锡武文化"},
      {63,"天启雁",1,{7,6},"这里充满了锡武文化"},{64,"侠客岛",1,{7,7},"这里充满了锡武文化"},
    },


};

Player *currplayer;
void init(int playgogame)
{
    ///默认登录玩家
    currplayer = &players[playgogame];
    ///
    currplayer->weapon = proparry[0];
    currplayer->armor = proparry[1];
}
void show()
{
    int propcount = sizeof(proparry)/sizeof(Prop);
    int j,i;
    for(i=0;i<propcount;i++)
    {
        printf("%d\t%s\t%.0lf\n",proparry[i].id,proparry[i].name,proparry[i].price);
        switch(proparry[i].type)
        {
            case weapon:
                printf("最小攻击力:%d\t最小攻击力:%d\n",proparry[i].minattack,proparry[i].maxattack);
                break;
            case armor:
                printf("最小防御力%d\t最大防御力%d\n",proparry[i].mindefence,proparry[i].maxdefence);
                break;
            case con:
                printf("最小恢复力%d\t最大恢复力%d\n",proparry[i].minpower,proparry[i].maxpower);
        }

    }
    printf("");
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
  //          printf("%-8s",maparry[i].name);
        }

    }
}
///实现游戏的显示界面
void goin1()
{
    char  write1[100][4]= {"欢","迎","来","到","笑","傲","江","湖","我","创","造","世","界","这","里","充","满","了","各","种","奇","闻","趣","事","期","待","你","的","加","入"};
  //  int word = strlen(write1);
    for(i=0;i<30;i++)
    {
        if(i %15 ==0) selposition(25,10+i/15);
        printf("%s  ",write1[i]);
        Sleep(100);
    }
    selposition(25,25);
    fflush(stdin);
    printf("请按任意键继续");
    getch();
    fflush(stdin);
}
///实现游戏的登录界面
int goin2()
{
    int playgogame=0;
    char *goname;
    goname = (char *)malloc(20*sizeof(char));
    char *name;
    name = (char *)malloc(10*sizeof(char));
    char *gopass;
    gopass = (char *)malloc(20*sizeof(char));
    char *pass;
    pass = (char *)malloc(10*sizeof(char));
    char playerwrite1;
    while(1)
    {
        clears(ming_x,0,25);
        selposition(ming_x,7);
        for(i=0;i<50;i++)printf("-");
        selposition(ming_x,8);
        printf("| 1.用户登录");
        for(i=0;i<37;i++) printf(" ");
        printf("|");
        selposition(ming_x,9);
         for(i=0;i<50;i++)printf("-");
        selposition(ming_x,10);
        printf("| 2.玩家注册(0退出)");
        for(i=0;i<30;i++) printf(" ");
        printf("|");
        selposition(ming_x,11);
        for(i=0;i<50;i++) printf("-");
        selposition(ming_x,12);
        printf("|");
        for(i=0;i<48;i++) printf(" ");
        printf("|");
        selposition(ming_x,13);
        for(i=0;i<50;i++) printf("-");
        selposition(ming_x+1,12);
        playerwrite1 = getch();
        switch(playerwrite1)
        {
        case '1':
            clears(ming_x,8,5);
            selposition(ming_x,8);
            printf("请输入用户名:");
            gets(goname);
            selposition(ming_x,9);
            printf("请输入密码:");
            gets(gopass);
            for(i=0;i<sizeof(players)/sizeof(Player);i++)
            {
                name = players[i].name;
                pass = players[i].pass;
                   if(strcmp(goname,name) == 0&&strcmp(gopass,pass )== 0)
                {
                    selposition(ming_x,10);
                    playgogame = i;
                    printf("登陆成功!");
                    Sleep(1000);
                    goto s;
                    break;
                }
            }

            break;
        case '2':
            clears(ming_x,8,26);

            break;
        case '0':
            exit(0);
        default: //selposition(ming_x+1,14);
            // printf("致命错误,强制退出");
            // Sleep(1000);
            // exit(0);
             getchar();
        }
    }
    s:;
    return playgogame;

}





///显示游戏欢迎信息
 void showwelcome()
 {
     selposition(ming_x,0);
     for(i=0;i<N;i++)  printf("-");
     selposition(ming_x-1,1);
     printf("|");
     selposition(ming_x+30,1);
     printf("%s",TITLE_A);
     selposition(ming_x+N,1);
     printf("|");
     selposition(ming_x,2);
     for(i=0;i<N;i++)  printf("-");
 }

 ///显示游戏地图
 void showmap(int X,int Y)
 {
    for(i=0;i<8;i++)
    {
        selposition(ming_x-1,3+i);
        printf("|");
        selposition(ming_x+1,3+i);
        for(j=0;j<8;j++)
        {
            if(j == X && i == Y)
            {
                selcorlor(0,10);
            }
            printf("%-10s",maparry[i][j].name);
            selcorlor(10,0);
            if(j == 7) printf("|");
        }
    }
    selposition(ming_x,ming_y_end);
    for(i=0;i<N;i++)  printf("-");
    showmapinf(Y,X);
 }
  ///在信息区显示地图信息
 void showmapinf(int X,int Y)
 {
     ///清除信息区的所有信息
     clears(ming_x,inf_start_y,7);
     ///打印地图的信息
    char *desc = maparry[X][Y].desc;
    int len = strlen(desc);
    int i;
    selposition(ming_x+25,inf_start_y);
    printf("当前玩家所在地图<%s>", maparry[X][Y].name);
    selposition(ming_x+10,inf_start_y+1);
    for(i=0;i<len;i++)
    {

        if(i%72 == 0 && i !=0)
        {
            selposition(ming_x+3,inf_start_y+1+i/72);
        }
        printf("%c",desc[i]);
    }
 }
 ///显示游戏的信息区---一共七行
 void showinfmation()
 {

     for(i=0;i<7;i++)
     {
         selposition(ming_x-1,inf_start_y+i);
         printf("|");
         selposition(ming_x+N,inf_start_y+i);
         printf("|");
     }
     selposition(ming_x,inf_end_y);
     for(i=0;i<N;i++) printf("-");
 }
 ///清除游戏的菜单
 void showinfmations()
 {
     ///清理显示栏的所有信息
     clears(ming_x,inf_end_y+1,7);
     selposition(ming_x+25,inf_end_y+1);
     printf("请按任意键继续......");
     getch();
 }
 ///显示游戏的主菜单
 void showmainmenu()
 {
     clears(ming_x,inf_end_y+1,7);
     selposition(ming_x,inf_end_y+1);
     printf("1.自我欣赏");
     selposition(ming_x,inf_end_y+2);
     printf("2.打怪");
    selposition(ming_x,inf_end_y+3);
     printf("3.查看怪物信息");
     selposition(ming_x,inf_end_y+4);
     printf("4.回总舵");
     selposition(ming_x,inf_end_y+5);
     printf("5.购买装备(0退出)");
 }
/**实现菜单功能*/
 void processmainmenu(char key,int X,int Y)
 {
     switch(key)
     {
     case '1':
        showplayer();      ///显示玩家信息
        showinfmations();  ///清理菜单显示区
        showmainmenu();    ///打印菜单
        break;
     case '2':
        showmonsters(X,Y); ///显示怪物信息
        clears(ming_x,inf_end_y-1,1);
        showinfmations();  ///清理菜单显示区
        showmainmenu();    ///打印菜单

        break;
     case '3':
        showmapmonsters(X,Y);
        showinfmations();  ///清理菜单显示区
        showmainmenu();    ///打印菜单
        break;
     case '4':
        showmap(player_X,player_Y);
        break;
    case '5':

        break;

     }
 }
  ///在信息界面显示玩家的信息资料
 void showplayer()
 {
     ///清理信息区的所有信息
     clears(ming_x,inf_start_y,7);
     ///将光标定位到信息区的开头
     selposition(ming_x+25,inf_start_y);
     printf("大侠<%s>的个人信息",currplayer->name);
     selposition(ming_x+10,inf_start_y+1);
     printf("等级:%d\t血量:%d\t内力:%d\t经验值:%d  金钱:%d\t",currplayer->level,currplayer->hp,currplayer->mp,currplayer->exp,currplayer->gold);
     selposition(ming_x+10,inf_start_y+2);
     printf("当前武器:%s<攻击力%d-%d> ",currplayer->weapon.name,currplayer->weapon.minattack,currplayer->weapon.maxattack);
     printf("当前防具:%s<防御力%d-%d>",currplayer->armor.name,currplayer->armor.mindefence,currplayer->armor.maxdefence);
     /*********************************/   ///完成玩家背包信息 其他信息

 }
 /**打印地图的怪物*/
 void showmapmonsters(int X,int Y)
 {
     clears(ming_x,inf_start_y,6);
      ///先获得怪物的总数
      int monstercount = sizeof(monsters)/sizeof(Monster);
      ///当前地图怪物的下表数组
      int monstermap[9];
      ///当前地图的怪物数量
      int mapmonstercount = 0;
      for(i=0;i<monstercount;i++)
      {
          if(monsters[i].coord.X == X && monsters[i].coord.Y == Y && monsters[i].state != 0)
          {
              monstermap[mapmonstercount] = i;
              mapmonstercount++;
              if(mapmonstercount == 6)break;
          }
      }
      ///打印当前地图的怪物
      selposition(ming_x+15,inf_start_y);
      if(mapmonstercount == 0)
      {
          printf("真是个不毛之地,这里人烟稀少,怪物都不来光顾了");
          return;
      }
      selposition(ming_x+25,inf_start_y+1);
      printf("当前地图的怪物:");
      selposition(ming_x+5,inf_start_y+2);
      for(i=0;i<mapmonstercount;i++)
      {
          if(i % 3 == 0 && i != 0)
          selposition(ming_x+5,inf_start_y+2+i/2);
          printf("%d %s<%d %s> ",monsters[monstermap[i]].id,monsters[monstermap[i]].name,monsters[monstermap[i]].level,levelname[monsters[monstermap[i]].level-1]);
      }
 }



 /**在相应的地图上打印怪物的信息和打怪*/
  void showmonsters(int X,int Y)
  {
      clears(ming_x,inf_start_y,7);
      ///先获得怪物的总数
      int monstercount = sizeof(monsters)/sizeof(Monster);
      ///当前地图怪物的下表数组
      int monstermap[9];
      ///当前地图的怪物数量
      int mapmonstercount = 0;
      for(i=0;i<monstercount;i++)
      {
          if(monsters[i].coord.X == X && monsters[i].coord.Y == Y && monsters[i].state != 0)
          {
              monstermap[mapmonstercount] = i;
              mapmonstercount++;
              if(mapmonstercount == 6)break;
          }
      }
      ///打印当前地图的怪物
      selposition(ming_x+15,inf_start_y);
      if(mapmonstercount == 0)
      {
          printf("真是个不毛之地,这里人烟稀少,怪物都不来光顾了");
          return;
      }
      selposition(ming_x+25,inf_start_y+1);
      printf("当前地图的怪物:");
      selposition(ming_x+5,inf_start_y+2);
      for(i=0;i<mapmonstercount;i++)
      {
          if(i % 3 == 0 && i != 0)
          selposition(ming_x+5,inf_start_y+2+i/2);
          printf("%d %s<%d %s> ",monsters[monstermap[i]].id,monsters[monstermap[i]].name,monsters[monstermap[i]].level,levelname[monsters[monstermap[i]].level-1]);
      }
/**实现玩家pk怪物*/
     ///玩家输入怪物的id;
      int pkmonsterid =-1;
      while(pkmonsterid != 0)
      {
        ///得到输入函数的返回值
        int err,pkmonsters = pkmonsterid;
        clears(ming_x,inf_end_y-2,1);
        selposition(ming_x,inf_start_y+5);
        printf("请输入pk怪物编号(0退出):");
        err = scanf("%d",&pkmonsterid);
        if(pkmonsterid == 0) break;
        clears(ming_x,inf_end_y-1,1);
        ///清理输入的缓冲区
        fflush(stdin);
        if(err == 0)
        {
            selposition(ming_x,inf_start_y+6);
            printf("输入错误");
            continue;
        }
        if(pkmonsterid == pkmonsters)
        {
            clears(ming_x,inf_end_y-1,1);
            fflush(stdin);
            selposition(ming_x,inf_end_y-1);
            printf("无此怪物!");
            continue;
        }
        for(i=0;i<mapmonstercount;i++)
        {
            if(pkmonsterid == monsters[monstermap[i]].id)
            {
                ///打怪
                fight(pkmonsterid,X,Y);
                showmapmonsters(X,Y);
                break;
            }
            if(i >= mapmonstercount-1)
            {
                selposition(ming_x,inf_end_y-1);
                printf("无此怪物!");
            }
        }
      }
  }
  void fight(int pkmonster,int X,int Y)
  {
     int monsterattack;
     int playerattack;
     srand(time(NULL));
     int fightcount=0;
     while(1)
     {
         monsterattack = rand()%(monsters[pkmonster].att-21)+20;
         playerattack = rand()%(currplayer->weapon.maxattack - currplayer->weapon.minattack +1) +currplayer->weapon.minattack;
         monsters[pkmonster].hp -= playerattack;
         currplayer->hp -= monsterattack;
         clears(ming_x,inf_end_y-1,1);
         selposition(ming_x,inf_end_y-1);
         if(currplayer->hp<=0)
         {
             clears(ming_x,inf_end_y-1,1);
             selposition(ming_x,inf_end_y-1);
             printf("江湖公告:大侠<%s>在打怪中死亡",currplayer->name);
             currplayer-> hp =0;
             break;
         }
         if(monsters[pkmonster].hp <= 0)
         {
             clears(ming_x,inf_end_y-1,1);
             selposition(ming_x,inf_end_y-1);
             printf("<%s>被您杀死,获得%d点经验,%d金钱",monsters[pkmonster-1].name,monsters[pkmonster].exp,monsters[pkmonster].maxmoney);
             break;
         }
          selposition(ming_x,inf_end_y-1);
         fightcount++;
         printf("第%d轮:玩家攻击:%d 怪物攻击:%d 怪物血量%d",fightcount,playerattack,monsterattack,monsters[pkmonster].hp);
         Sleep(800);
     }
     currplayer->exp+=monsters[pkmonster].exp;
     monsters[pkmonster].hp =0;
     monsters[pkmonster-1].state =0;
     currplayer->gold += monsters[pkmonster].maxmoney;

  }












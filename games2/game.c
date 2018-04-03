/********************************************
 * �ļ���: game.c
 * ��   ��: ʵ����Ϸ�����߼�
 * ��   ��: 2017.4.23
 * ��   ��: 1.0
 * ���� ��: sexx
 ********************************************/
#include "game.h"
#define N 81
#define ming_x 15///��߾�
#define TITLE_A "��ӭ����Ц������!"
#define ming_y_end 11
#define inf_start_y 12
#define inf_end_y  19
int player_X=2,player_Y=3;

int i,j;
char levelname[7][10] = {"����é®","��ͨƤë","����С��","�������","�������","�����޵�","���˺�һ"};
Player players[]={ {922,"����","123",100,3,1,1000,5000,9000,2000,.coord.X=3,.coord.Y=1},
                    {923,"x","123",100,1,1,100,50,900000,1000000,.coord.X=2,.coord.Y=1},
                    {924,"c","123",100,4,1,10000,50000,900000,1000000,.coord.X=4,.coord.Y=1},
                    {925,"d","123",100,9,1,100000,500000,9000000,1000000,.coord.X=3,.coord.Y=0},


};

Monster monsters[] = {
    {1,"��ͫ���",1,100,50,20,50,10,10,1,{0,0}},
    {2,"��ͫ���",1,100,50,20,50,10,10,1,{0,1}},
    {3,"��ͫ���",1,100,50,20,50,10,10,1,{0,2}},
    {4,"��ͫ���",1,100,50,20,50,10,10,1,{0,3}},
    {5,"��ͫ���",1,100,50,20,50,10,10,1,{0,4}},
    {6,"��ͫ���",1,100,50,20,50,10,10,1,{0,5}},
    {7,"�籩������",2,300,50,50,5,10,10,500,{0,1}},
    {8,"��������",3,300,50,50,5,10,10,600,{0,3}},
    {9,"������� ",4,400,50,50,5,10,10,700,{0,4}},
    {10,"������� ",5,400,50,50,5,10,10,800,{1,0}},
    {11,"������  ",6,500,50,50,5,10,10,900,{1,0}},
    {12,"��Ѫħ�� ",7,500,50,50,5,10,10,1000,{1,0}},
    {13,"����������  ",7,500,50,50,5,10,10,1100,{1,0}},
    {14,"���۽��� ",7,500,50,50,5,10,10,1200,{1,1}},
    {15,"ʨ����",7,500,50,60,1000,10,10,1300,{2,0}},
    {16,"���������",7,500,50,60,5,10,10,1400,{2,0}},
    {17,"��չ���",7,500,50,60,5,10,10,1500,{2,0}},
    {18,"�̾���ʨ",7,500,50,50,5,10,10,1600,{2,0}},
    {19,"����ħԳ",7,500,50,60,5,10,10,1700,{2,0}},
    {20,"���ھ���",7,500,50,60,5,10,10,1800,{3,0}},
    {21,"�������� ",7,500,50,60,5,10,10,1900,{3,0}},
    {22,"������� ",7,500,50,50,5,10,10,2000,{3,0}},
    {23,"��ëʨ�� ",6,500,50,50,5,10,10,2000,{4,0}},
    {24,"��ëʨ�������� ",5,500,50,50,5,10,10,200,{4,0}},
    {25,"��ëʨ���İְ� ",7,500,50,50,5,10,10,2000,{4,0}}

};

Prop proparry[]={
{1,"�ۻʽ�",1,5,5000,weapon,.minattack=100,.maxattack=200,"�����Ϲ�,��������"},
{2,"�ۻʼ�",1,5,50500,armor,.mindefence=2,.maxattack=6,"�����Զ,�����Ի�,��Ϊ��������ʧƷ���½�"},
{3,"��ζ�ػ���",1,5,500500,con,.minpower=100,.maxpower=500,"δ֪"},
{3,"��ζ�ػ���",1,5,500500,con,.minpower=100,.maxpower=500,"δ֪"},
};
Map maparry[8][8]={
    {{1,"��ɽ",1,{0,0},"��������������Ļ�"},{2,"¥��",1,{0,1},"���ջԻ�֮��,���������ʧ����ʷ�ı�ɴ֮�����ջԻ�֮��,���������ʧ����ʷ�ı�ɴ֮��"},
        {3,"����ɽ",1,{0,2},"����һ������������Σ����ʱ����ͬʱ��Ҳ��һ������׳����ʱ������ͬ���˻��Ų�ͬ�����������Լ�����ء�"},
        {4,"Ұ����",1,{0,3},"���ﾭ����Ұ���û,�����˵ļ�԰,Ҳ������������ȥ��ϣ��."},
        {5,"ˮ����",1,{0,4},"����������������һ��"},
        {6,"��϶�",1,{0,5},"��������������Ļ�"},
        {7,"�ڷ�կ",1,{0,6},"��������������Ļ�"},{8,"����",1,{0,7},"��������������Ļ�"},
    },
    { {9,"�Թ�",1,{1,0},"��������������Ļ�"},{10,"������",1,{1,1},"��������������Ļ�"},
      {11,"��ԯ��",1,{1,2},"��������������Ļ�"},{12,"��ɽ",1,{1,3},"��������������Ļ�"},
      {13,"��ɽ",1,{1,4},"��������������Ļ�"},{14,"�Ͼ���",1,{1,5},"��������������Ļ�"},
      {15,"�����",1,{1,6},"��������������Ļ�"},{16,"������",1,{1,7},"��������������Ļ�"},
    },
    { {17,"����",1,{2,0},"��������������Ļ�"},{18,"��«��",1,{2,1},"��������������Ļ�"},
      {19,"����",1,{2,2},"��������������Ļ�"},{20,"����ɽ",1,{2,3},"��������������Ļ�"},
      {21,"ʯ��",1,{2,4},"��������������Ļ�"},{22,"��ջ",1,{2,5},"��������������Ļ�"},
      {23,"��ʶ�",1,{2,6},"��������������Ļ�"},{24,"���ߵ�",1,{2,7},"��������������Ļ�"}
    },
    { {25,"������",1,{3,0},"��������������Ļ�"},{26,"Ħ����",1,{3,1},"��������������Ļ�"},
      {27,"����ׯ",1,{3,2},"������ <����> ���ܶ�.�����ڽ������԰�������.���Դ����ŵ�����̫̫��      �����Ƽұ�һ�ȼҵ����䣬��֮����Ϊ�ư������������,��ʹ�����������ٶȵĺƽ٣�����һ�겻��������Σ�ѵ�ʱ�����ų�����һȺ������\
������磡���ն����ȱ�������������������������������˿︴������������ģ�\
�����ڽ������������壬��������ŵ�������ʹ���ų�Ϊ�˽����ϵ��������ɡ�"},
      {28,"��ɽ",1,{3,3},"��������������Ļ�"},
      {29,"�䵱ɽ",1,{3,4},"��������������Ļ�"},{30,"���⸮",1,{3,5},"��������������Ļ�"},
      {31,"��ʮ����",1,{3,6},"��������������Ļ�"},{32,"�����ɾ�",1,{3,7},"��������������Ļ�"}
    },
    { {33,"�޹�ɽ",1,{4,0},"��������������Ļ�"},{34,"��üɽ",1,{4,1},"��������������Ļ�"},
      {35,"������",1,{4,2},"��������������Ļ�"},{36,"�廢��",1,{4,3},"��������������Ļ�"},
      {37,"������",1,{4,4},"��������������Ļ�"},{38,"������",1,{4,5},"��������������Ļ�"},
      {39,"֣����",1,{4,6},"��������������Ļ�"},{40,"�һ���",1,{4,7},"��������������Ļ�"},
    },
    { {41,"���˹�",1,{5,0},"��������������Ļ�"},{42,"����",1,{5,1},"��������������Ļ�"},
      {43,"�ٻ���",1,{5,2},"��������������Ļ�"},{44,"��ȸɽׯ",1,{5,3},"��������������Ļ�"},
      {45,"��Ը�",1,{5,4},"��������������Ļ�"},{46,"������",1,{5,5},"��������������Ļ�"},
      {47,"ǧ���ɲ",1,{5,6},"��������������Ļ�"},{48,"������",1,{5,7},"��������������Ļ�"},
    },
    { {49,"��żɽׯ",1,{6,0},"��������������Ļ�"},{50,"��ľ��",1,{6,1},"��������������Ļ�"},
      {51,"������",1,{6,2},"��������������Ļ�"},{52,"������",1,{6,3},"��������������Ļ�"},
      {53,"������",1,{6,4},"��������������Ļ�"},{54,"�ص���",1,{6,5},"��������������Ļ�"},
      {55,"����ׯ",1,{6,6},"��������������Ļ�"},{56,"�����",1,{6,7},"��������������Ļ�"},
    },
    { {57,"ʯ��",1,{7,0},"��������������Ļ�"},{58,"������",1,{7,1},"��������������Ļ�"},
      {59,"�����",1,{7,2},"��������������Ļ�"},{60,"ͨ�Ե�",1,{7,3},"��������������Ļ�"},
      {61,"ͨ���",1,{7,4},"��������������Ļ�"},{62,"��ϼͤ",1,{7,5},"��������������Ļ�"},
      {63,"������",1,{7,6},"��������������Ļ�"},{64,"���͵�",1,{7,7},"��������������Ļ�"},
    },


};

Player *currplayer;
void init(int playgogame)
{
    ///Ĭ�ϵ�¼���
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
                printf("��С������:%d\t��С������:%d\n",proparry[i].minattack,proparry[i].maxattack);
                break;
            case armor:
                printf("��С������%d\t��������%d\n",proparry[i].mindefence,proparry[i].maxdefence);
                break;
            case con:
                printf("��С�ָ���%d\t���ָ���%d\n",proparry[i].minpower,proparry[i].maxpower);
        }

    }
    printf("");
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
  //          printf("%-8s",maparry[i].name);
        }

    }
}
///ʵ����Ϸ����ʾ����
void goin1()
{
    char  write1[100][4]= {"��","ӭ","��","��","Ц","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","Ȥ","��","��","��","��","��","��","��"};
  //  int word = strlen(write1);
    for(i=0;i<30;i++)
    {
        if(i %15 ==0) selposition(25,10+i/15);
        printf("%s  ",write1[i]);
        Sleep(100);
    }
    selposition(25,25);
    fflush(stdin);
    printf("�밴���������");
    getch();
    fflush(stdin);
}
///ʵ����Ϸ�ĵ�¼����
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
        printf("| 1.�û���¼");
        for(i=0;i<37;i++) printf(" ");
        printf("|");
        selposition(ming_x,9);
         for(i=0;i<50;i++)printf("-");
        selposition(ming_x,10);
        printf("| 2.���ע��(0�˳�)");
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
            printf("�������û���:");
            gets(goname);
            selposition(ming_x,9);
            printf("����������:");
            gets(gopass);
            for(i=0;i<sizeof(players)/sizeof(Player);i++)
            {
                name = players[i].name;
                pass = players[i].pass;
                   if(strcmp(goname,name) == 0&&strcmp(gopass,pass )== 0)
                {
                    selposition(ming_x,10);
                    playgogame = i;
                    printf("��½�ɹ�!");
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
            // printf("��������,ǿ���˳�");
            // Sleep(1000);
            // exit(0);
             getchar();
        }
    }
    s:;
    return playgogame;

}





///��ʾ��Ϸ��ӭ��Ϣ
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

 ///��ʾ��Ϸ��ͼ
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
  ///����Ϣ����ʾ��ͼ��Ϣ
 void showmapinf(int X,int Y)
 {
     ///�����Ϣ����������Ϣ
     clears(ming_x,inf_start_y,7);
     ///��ӡ��ͼ����Ϣ
    char *desc = maparry[X][Y].desc;
    int len = strlen(desc);
    int i;
    selposition(ming_x+25,inf_start_y);
    printf("��ǰ������ڵ�ͼ<%s>", maparry[X][Y].name);
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
 ///��ʾ��Ϸ����Ϣ��---һ������
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
 ///�����Ϸ�Ĳ˵�
 void showinfmations()
 {
     ///������ʾ����������Ϣ
     clears(ming_x,inf_end_y+1,7);
     selposition(ming_x+25,inf_end_y+1);
     printf("�밴���������......");
     getch();
 }
 ///��ʾ��Ϸ�����˵�
 void showmainmenu()
 {
     clears(ming_x,inf_end_y+1,7);
     selposition(ming_x,inf_end_y+1);
     printf("1.��������");
     selposition(ming_x,inf_end_y+2);
     printf("2.���");
    selposition(ming_x,inf_end_y+3);
     printf("3.�鿴������Ϣ");
     selposition(ming_x,inf_end_y+4);
     printf("4.���ܶ�");
     selposition(ming_x,inf_end_y+5);
     printf("5.����װ��(0�˳�)");
 }
/**ʵ�ֲ˵�����*/
 void processmainmenu(char key,int X,int Y)
 {
     switch(key)
     {
     case '1':
        showplayer();      ///��ʾ�����Ϣ
        showinfmations();  ///����˵���ʾ��
        showmainmenu();    ///��ӡ�˵�
        break;
     case '2':
        showmonsters(X,Y); ///��ʾ������Ϣ
        clears(ming_x,inf_end_y-1,1);
        showinfmations();  ///����˵���ʾ��
        showmainmenu();    ///��ӡ�˵�

        break;
     case '3':
        showmapmonsters(X,Y);
        showinfmations();  ///����˵���ʾ��
        showmainmenu();    ///��ӡ�˵�
        break;
     case '4':
        showmap(player_X,player_Y);
        break;
    case '5':

        break;

     }
 }
  ///����Ϣ������ʾ��ҵ���Ϣ����
 void showplayer()
 {
     ///������Ϣ����������Ϣ
     clears(ming_x,inf_start_y,7);
     ///����궨λ����Ϣ���Ŀ�ͷ
     selposition(ming_x+25,inf_start_y);
     printf("����<%s>�ĸ�����Ϣ",currplayer->name);
     selposition(ming_x+10,inf_start_y+1);
     printf("�ȼ�:%d\tѪ��:%d\t����:%d\t����ֵ:%d  ��Ǯ:%d\t",currplayer->level,currplayer->hp,currplayer->mp,currplayer->exp,currplayer->gold);
     selposition(ming_x+10,inf_start_y+2);
     printf("��ǰ����:%s<������%d-%d> ",currplayer->weapon.name,currplayer->weapon.minattack,currplayer->weapon.maxattack);
     printf("��ǰ����:%s<������%d-%d>",currplayer->armor.name,currplayer->armor.mindefence,currplayer->armor.maxdefence);
     /*********************************/   ///�����ұ�����Ϣ ������Ϣ

 }
 /**��ӡ��ͼ�Ĺ���*/
 void showmapmonsters(int X,int Y)
 {
     clears(ming_x,inf_start_y,6);
      ///�Ȼ�ù��������
      int monstercount = sizeof(monsters)/sizeof(Monster);
      ///��ǰ��ͼ������±�����
      int monstermap[9];
      ///��ǰ��ͼ�Ĺ�������
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
      ///��ӡ��ǰ��ͼ�Ĺ���
      selposition(ming_x+15,inf_start_y);
      if(mapmonstercount == 0)
      {
          printf("���Ǹ���ë֮��,��������ϡ��,���ﶼ���������");
          return;
      }
      selposition(ming_x+25,inf_start_y+1);
      printf("��ǰ��ͼ�Ĺ���:");
      selposition(ming_x+5,inf_start_y+2);
      for(i=0;i<mapmonstercount;i++)
      {
          if(i % 3 == 0 && i != 0)
          selposition(ming_x+5,inf_start_y+2+i/2);
          printf("%d %s<%d %s> ",monsters[monstermap[i]].id,monsters[monstermap[i]].name,monsters[monstermap[i]].level,levelname[monsters[monstermap[i]].level-1]);
      }
 }



 /**����Ӧ�ĵ�ͼ�ϴ�ӡ�������Ϣ�ʹ��*/
  void showmonsters(int X,int Y)
  {
      clears(ming_x,inf_start_y,7);
      ///�Ȼ�ù��������
      int monstercount = sizeof(monsters)/sizeof(Monster);
      ///��ǰ��ͼ������±�����
      int monstermap[9];
      ///��ǰ��ͼ�Ĺ�������
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
      ///��ӡ��ǰ��ͼ�Ĺ���
      selposition(ming_x+15,inf_start_y);
      if(mapmonstercount == 0)
      {
          printf("���Ǹ���ë֮��,��������ϡ��,���ﶼ���������");
          return;
      }
      selposition(ming_x+25,inf_start_y+1);
      printf("��ǰ��ͼ�Ĺ���:");
      selposition(ming_x+5,inf_start_y+2);
      for(i=0;i<mapmonstercount;i++)
      {
          if(i % 3 == 0 && i != 0)
          selposition(ming_x+5,inf_start_y+2+i/2);
          printf("%d %s<%d %s> ",monsters[monstermap[i]].id,monsters[monstermap[i]].name,monsters[monstermap[i]].level,levelname[monsters[monstermap[i]].level-1]);
      }
/**ʵ�����pk����*/
     ///�����������id;
      int pkmonsterid =-1;
      while(pkmonsterid != 0)
      {
        ///�õ����뺯���ķ���ֵ
        int err,pkmonsters = pkmonsterid;
        clears(ming_x,inf_end_y-2,1);
        selposition(ming_x,inf_start_y+5);
        printf("������pk������(0�˳�):");
        err = scanf("%d",&pkmonsterid);
        if(pkmonsterid == 0) break;
        clears(ming_x,inf_end_y-1,1);
        ///��������Ļ�����
        fflush(stdin);
        if(err == 0)
        {
            selposition(ming_x,inf_start_y+6);
            printf("�������");
            continue;
        }
        if(pkmonsterid == pkmonsters)
        {
            clears(ming_x,inf_end_y-1,1);
            fflush(stdin);
            selposition(ming_x,inf_end_y-1);
            printf("�޴˹���!");
            continue;
        }
        for(i=0;i<mapmonstercount;i++)
        {
            if(pkmonsterid == monsters[monstermap[i]].id)
            {
                ///���
                fight(pkmonsterid,X,Y);
                showmapmonsters(X,Y);
                break;
            }
            if(i >= mapmonstercount-1)
            {
                selposition(ming_x,inf_end_y-1);
                printf("�޴˹���!");
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
             printf("��������:����<%s>�ڴ��������",currplayer->name);
             currplayer-> hp =0;
             break;
         }
         if(monsters[pkmonster].hp <= 0)
         {
             clears(ming_x,inf_end_y-1,1);
             selposition(ming_x,inf_end_y-1);
             printf("<%s>����ɱ��,���%d�㾭��,%d��Ǯ",monsters[pkmonster-1].name,monsters[pkmonster].exp,monsters[pkmonster].maxmoney);
             break;
         }
          selposition(ming_x,inf_end_y-1);
         fightcount++;
         printf("��%d��:��ҹ���:%d ���﹥��:%d ����Ѫ��%d",fightcount,playerattack,monsterattack,monsters[pkmonster].hp);
         Sleep(800);
     }
     currplayer->exp+=monsters[pkmonster].exp;
     monsters[pkmonster].hp =0;
     monsters[pkmonster-1].state =0;
     currplayer->gold += monsters[pkmonster].maxmoney;

  }












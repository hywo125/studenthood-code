#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
/********************************************
 * �ļ���: Game.h
 * ��   ��: ����������Ϸ���Ľṹ�ͺ���
 * ��   ��: 2017.4.23
 * ��   ��: 1.0
 * ���� ��: sexx
 ********************************************/
 #include <stdio.h>
 #include <string.h>
 #include <time.h>
 #include <stdlib.h>
 #include <windows.h>


 /***** ��Ϸ�ṹ���Ͷ���
 //���,��ͼ, װ��,����
 /*��ͼ�ṹ*/
typedef struct _map{
    ///��ͼ�ı��
    int id;
    ///��ͼ������
    char name[50];
    ///��ҽ������͵ȼ�
    int minlevel;
    ///��ͼ������-x,y
    COORD coord;
    ///��ͼ����
    char desc[500];
}Map;


 /**��Ϸ��������-���� ���� ����Ʒ ��Ƭ*/
 typedef enum _proptype{
    weapon,armor,con,card,frag
 }Proptype;

/**��Ϸ����-���� ���� ����Ʒ ��Ƭ*/
 typedef struct _prop{
     ///���߱��
    int id;
    ///��������
    char name[50];
    ///���߼���
    int level;
    ///���ߵĿ��
    int stock;
    ///���ߵĵ���
    double price;
    ///���ߵ�����
    Proptype type;
    ///�������Ͷ�Ӧ�ĵ���
    union{
        ///������Ӧ������
        int minattack;
        ///���߶�Ӧ������
        int mindefence;
        ///����Ʒ��Ӧ����
        int minpower;
    };
    union{
        ///������Ӧ������
        int maxattack;
        ///���߶�Ӧ������
        int maxdefence;
        ///����Ʒ��Ӧ����
        int maxpower;
    };
    ///���ߵ�����
    char desc[100];
}Prop;

 /**���*/
typedef struct _player{
    int id;
    char *name;
    char *pass;
    ///�������ֵ
    int life;
    ///��ҵȼ�
    int level;
    ///��Ҿ���ֵ
    int exp;
    ///���Ѫ��
    int hp;
    ///�������ֵ
    int mp;
    ///����������ֵ
    int mp_max;
    ///��ҽ�Ǯ
    int gold;
    ///��ҵ�����

    ///���װ��������
    Prop weapon;
    ///���װ���ķ���
    Prop armor;
    ///������ڵ�ͼ������
    COORD coord;
    ///��ҵı���

}Player;
/**����*/
typedef struct _monster{
    int id;
    char name[50];
    int level;  ///����ȼ�
    int hp;  ///�����Ѫ��
    int att;  ///����Ĺ�����
    int diff; ///����ķ�����
    int minmoney;  ///ɱ������������С��Ǯ
    int maxmoney;  ///ɱ��������������Ǯ
    int exp;  ///ɱ�������õľ���ֵ
    ///ɱ����������װ��(��չ)

    int state; ///�����״̬0 ����,1���
    COORD coord;  ///���������
}Monster;
///ʵ����Ϸ����ʾ����
void goin1();
///ʵ����Ϸ�ĵ�¼����
int goin2();
 ///��ʼ����Ϸ����
 void init(int);
 ///дʵ����
 void show();
 ///��ʾ��Ϸ��ӭ��Ϣ
 void showwelcome();
 ///��ʾ��Ϸ��ͼ
 void showmap(int,int);
 ///����Ϣ����ʾ��ͼ��Ϣ
 void showmapinf(int,int);
 ///����Ϣ������ʾ��ҵ���Ϣ����
 void showplayer();
 ///����Ϣ����ʾ��ǰ��ͼ�Ĺ��� ,���
 void showmonsters(int,int);
 ///��Ϣ����ʾ��ǰ��ͼ�Ĺ���
 void showmapmonsters(int,int);
 ///ʵ����ѡ��������������
 void showinfmations();
 /// ���
 void fight(int,int,int);
 ///��ʾ��Ϸ����Ϣ��
 void showinfmation();
 ///��ʾ��Ϸ�����˵�
 void showmainmenu();
 /**ʵ�ֲ˵�����*/
 void processmainmenu(char,int,int);





#endif // GAME_H_INCLUDED

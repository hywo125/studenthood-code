#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
/********************************************
 * �ļ���: g
 * ��   ��: ʵ��������Ŀ��������Ϣ�Ķ���
 * ��   ��: 2017.6.15
 * ��   ��: 1.0
 * ���� ��: s
 ********************************************/




#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**��Ʒ*/
typedef struct goods
{

    char name[15]; ///��Ʒ����

    char code[10];///��Ʒ����

    char producer[20]; ///��Ʒ������

    double price; ///��Ʒ�۸�

    int quantity;///��Ʒ����

}Goods;

/**����Ա*/
typedef struct _admin
{
    /**����Ա������*/
    char id[10];
    /**����Ա������*/
    char pass[10];



}Admin;
/**�곤*/
typedef struct _shopker
{
    /**�곤��id*/
    char id[10];
    /**�곤������*/
    char pass[10];


}Shpker;
/**����Ա*/
typedef struct _seller
{
    /**id*/
    char id[10];
    /**����*/
    char name[10];
    /**����*/
    char pass[10];
    /**������Ա���۵���Ʒ*/
    Goods good;

}Seller;
/**���۱�*/
typedef struct goods_report   ///��Ʒ����
{
    Goods good;     ///��Ʒ
    Seller assistant;   ///ӪҵԱ
    char sell_data[20]; ///��������
    int number;
}Goodsr;


/**��ʼ����������*/
void init_all();
void init();
/**��ʼ��ʣ������*/
void surplus();
/**��ʼ������Ա��Ϣ*/
void init_sell();
/**��ʼ������*/
void interfaces();
/**��ʼ������*/
void choice_faces();
/**��ʼ����Ϣ������*/
void info_face();
/**��ʼ����Ϣ������*/
void info_opretion();
/**��¼*/
char login(int ,int);
/**��ʼ������Ա������Ϣ*/
char admin_info(int,int);
/**��ʼ���곤������Ϣ*/
char shoper_info(int,int);
/**��ʼ������Ա������Ϣ*/
char seller_info(int,int);
/**ĳ�����ܵĹ���*/
void admin_deal(int,int);
/**ĳ�����ܵĹ���*/
void shoper_deal(int,int);
/**ĳ�����ܵĹ���*/
void seller_deal(int,int);
/**����Ʒ�Ĳ���:*/
void choice_goods(char,int,int);
/**��Ʒ���*/
void goods_add();
/**��Ʒɾ��*/
void goods_del();
/**��Ʒ�޸�*/
void goods_modify();
/**��Ʒ����*/
void goods_search();
/**��Ʒ���*/
void goods_browse();
/**��Ʒ����*/
void goods_sell();
/**�鿴���±���*/
void read_month();
/**��ȡ��ǰʱ��*/
char* getnowtime();
/**��¼�������֤*/
void login_in();
/**��ʼ���洢��Ϣ*/
void storge();
/**��ȡ����Ա����Ϣ*/
char* read_damin();
/**��ȡ�곤��Ϣ*/
char* read_shpke();
/**��ȡ����Ա��Ϣ*/
char* read_seller();
/**����û�*/
void add_user();
/**�޸��û�����*/
void modify_pass();
/**�޸Ĺ���Ա��Ϣ*/
void modify_admin(char *,char *);
/**�޸ĵ곤��Ϣ*/
void modify_shpker(char *,char *);
/**�޸�����Ա��Ϣ*/
void modify_seller(char *,char*,int);
/**ɾ���û�*/
void del_user(int);
/**�ͷſռ�*/
void frees();
/**�˳�*/
void quit();



/**����*/
/**���*/
/**�޸�*/
/**����*/


#endif // GAME_H_INCLUDED

/********************************************
 * �ļ���: game.C
 * ��   ��: ʵ��������Ŀ�Ĺ���ʵ��
 * ��   ��: 2017.6.15
 * ��   ��: 1.0
 * ���� ��: s
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


int login_number;   //�жϵ�¼���
int len1;             //������Ʒ�ĸ���
int len2,len;             //��������Ա����
int len3;             //���۱�������Ʒ�ĸ���
char key;              //���չ���Ա������ѡ����Ϣ
char key_choice;       //������Ʒ��Ϣ�е������ַ�
FILE *adminer,*shpk,*sell,*goods_sells;
/**��ʼ����Ʒ�ĺ���*/
    Goods goodarry[27]={ {"G2000","00000","ggs���޹�˾",300.0 ,500 },{"�Ÿ��","00001","�Ÿ�����޹�˾", 300.0,400 },
        {"Ƥ�ص���","00002","�ɶ��з��������޹�˾",1000.0 ,600 },{"Ƥ������","00003","Ƥ���������޹�˾",2000.0 ,200 },{"��������","00004","�����������޹�˾", 300.0,100 },
        {"����ɡ","00005","��ɡ���޹�˾",600 ,200 },{"����","00006","�������޹�˾",10100 ,20 },{"����","00007","�������޹�˾", 300,400 },
        {"��������","00008","�������޹�˾",500 ,200 },{"����","00009","�������޹�˾",100 ,600 },{"�ͱ���","00010","��ʳ���޹�˾",1000 ,300 },
        {"ʤ��","00011","ʤ�����޹�˾",2000 ,200 },{"����","00012","�������޹�˾",200 ,300 },{"NOVELI","00013","NOVELI���޹�˾",1000 ,50 },
        {"׿��","00014","׿�����޹�˾",2000 ,100 },{"�����","00015","��������޹�˾",300 ,500 },{"����","00016","�������޹�˾",500 ,200 },
        {"������","00017","���������޹�˾",300 ,200 },{"A B C","00018","�㶫��ҵ",6.00 ,200 },{"�շ�","00019","���ݼѼ���",6.00 ,200 },{.code="00020",.quantity=1},
        {.code="00020",.quantity=1},{.code="00021",.quantity=1},{.code="00022",.quantity=1},{.code="00023",.quantity=1},{.code="00024",.quantity=1},{.code="00025",.quantity=1},{.code="00026",.quantity=1}
    };


/**��������Ա����*/
    Seller sellerarr[5];
/**��ʼ����Ʒ����*/
    Goodsr goodrarry[30]={ {.number=1},{.number=1},{.number=1},{.number=1},{.number=1},
    {.number=1},{.number=1},{.number=1},{.number=1},{.number=1},{.number=1},{.number=1},{.number=1},{.number=1},
    {.number=1},{.number=1},{.number=1},{.number=1},{.number=1},{.number=1},{.number=1},{.number=1},{.number=1},
    {.number=1},{.number=1},{.number=1},{.number=1},{.number=1},{.number=1},{.number=1}
    };
    /**��ʼ�������ļ�*/
void storge()
{
    char goods_month[25]="�ɿڿ��� 0�� 2016.2.3 ";
    char adminss[] = "admin 123";
    char shpks[] ="news 123";
    char sellers[]="000 0�� 123 00001 001 1�� 123 00001 ";
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
/**��ȡ�ļ��й���Ա��Ϣ*/
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
/**��ȡ�ļ��е곤��Ϣ*/
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
/**��ȡ�ļ����ۻ�Ա��Ϣ*/
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
/**��ʼ��ʣ������*/
    Admin admin;
    Shpker shpkes;
    Goods *goodsarrys=goodarry;       //ָ����Ʒ�ṹ���ָ��
    Seller *sellerarry = sellerarr;   //ָ������Ա��ָ��
    Admin *admins=&admin;             //ָ�����Ա��ָ��
    Shpker *shpkers= &shpkes;         //ָ��곤��ָ��
    Goodsr *goodser = goodrarry;      //ָ�����۱��ָ��
/**��ʼ������Ա�곤����*/
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
/**��ʼ������Ա��Ϣ*/
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

/**��ʼ�����н���*/
void init()
{
    selposition(MINGX,1);
    printf("ESC �˳�!");
    interfaces();
    choice_faces();
    info_face();
    info_opretion();
}


/**��ʼ������*/
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
/**��ʼ��ѡ����*/
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
/**��ʼ����Ϣ��*/
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
/**��ʼ����Ϣ������*/
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
/**����û�*/
void add_user()
{
    char id[10],name[10],pass[10];
    char add[40];
    fflush(stdin);
    selposition(MINGX+5,INFO_start);
    printf("��1�������:");
    if(getch() == '1'); else return;
    fflush(stdin);
    clears(MINGX+1,INFO_start,1);
    selposition(MINGX+5,INFO_start);
    if(len2 == 5)
    {
        selposition(MINGX+25,INFO_start+7);
        printf("��Ҫ������,���ʧ��!");
        Sleep(1000);
        return;
    }
    printf("������:");
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
    printf("��ӳɹ�!!");
    len++;
    init_all();
    Sleep(1000);
}
/**�޸Ĺ���Ա��Ϣ*/
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
    printf("�޸ĳɹ�!");
    init_all();
    Sleep(1000);
}
/**�޸ĵ곤��Ϣ*/
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
    printf("�޸ĳɹ�!");
    init_all();
    Sleep(1000);
}
/**�޸�����Ա��Ϣ*/
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
    printf("�޸ĳɹ�!");
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
    printf("ɾ���ɹ�!!");
    init_all();
    Sleep(1000);
}
/**�޸���Ϣ*/
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
        printf("��������id: ");
        gets(id);
        selposition(MINGX+15,INFO_start+3);
        printf("������������:");
        fflush(stdin);
        gets(pass);
        modify_admin(id,pass);
    }
    else if(choice == '2')
    {
        selposition(MINGX+15,INFO_start+1);
        printf("��������id: ");
        gets(id);
        selposition(MINGX+15,INFO_start+3);
        printf("������������:");
        fflush(stdin);
        gets(pass);
        modify_shpker(id,pass);
    }
    else if(choice == '3')
    {
        char ids[10],pass[10],id[10];
        selposition(MINGX+5,INFO_start);
        printf("������Ҫ�޸ĵ�����Աid:");
        gets(ids);
        for(i=0;i<len2;i++)
        {
            if(strcmp( (sellerarry+i)->id ,ids) ==0)
            break;
        }
        if(i == len2)
        {
            selposition(MINGX+25,INFO_start+5);
            printf("�޴��û�!!");
            return;
        }
        selposition(MINGX+10,INFO_start+1);
        printf("��������id:");
        gets(id);
        selposition(MINGX+35,INFO_start+1);
        printf("������������:");
        gets(pass);
        modify_seller(pass,id,i);
    }
    else if(choice == '4')
    {
        char id[10];
        selposition(MINGX+25,INFO_start+5);
        if(len2<=1){printf("����,��Ҫ��ɾ��,��ɾ��û����"); return;}
        else   printf("������Ҫɾ��������Աid:");
        gets(id);
        for(i=0;i<len2;i++)
        {
            if(strcmp( (sellerarry+i)->id ,id) ==0)
            break;
        }
        if(i == len2)
        {
            selposition(MINGX+25,INFO_start+5);
            printf("�޴��û�!!");
            return;
        }
        del_user(i);
    }
    else return;




}
/**����Ա��������*/
void admin_deal(int x,int y)
{
    int i;
    clears(MINGX+1,INFO_start,15);
    clears(MINGX+1,Opre_start,7);
    if(x ==MINGX+25 && y == CHO_start)
    {
        selposition(MINGX+30,(INFO_start+INFO_end)/2);
        printf("�� ӭ ʹ �� �� �� �� ϵ ͳ");
        selposition(MINGX+5,Opre_start);
        printf("1.�޸Ĺ���Ա��Ϣ");
        selposition(MINGX+5,Opre_start+1);
        printf("2.�޸ĵ곤��Ϣ");
        selposition(MINGX+5,Opre_start+2);
        printf("3.�޸�����Ա����");
        selposition(MINGX+5,Opre_start+3);
        printf("4.ɾ���û�(������Ա)");
        selposition(MINGX+5,Opre_start+5);
        printf("��ѡ��:");
        modify_pass();
    }
     if(x == MINGX+50 && y == CHO_start)  ///����û�
     {
         add_user();
     }
     if(x == MINGX+25 && y == CHO_end)
     {
         selposition(MINGX+5,INFO_start);
         printf("�û���Ϣ����:");
         selposition(MINGX+15,INFO_start+2);
         printf("����Ա:%-12s����:%s",admins->id,admins->pass);
         selposition(MINGX+15,INFO_start+4);
         printf("�곤:  %-12s����:%s",shpkers->id,shpkers->pass);
         selposition(MINGX+15,INFO_start+6);
         printf("����Ա:");
         for(i=0;i<len2;i++)
         {
             selposition(MINGX+15,INFO_start+8+i);
             printf("ID:   %-12s����:%s",(sellerarry+i)->id,(sellerarry+i)->pass);
         }
     }

      if(x == MINGX+50 && y == CHO_end)
      {
          selposition(MINGX+30,(INFO_start+INFO_end)/2);
          printf("�� ӭ ʹ �� �� �� �� ϵ ͳ");
          selposition(MINGX+5,Opre_start);
          printf("1.��Ʒ���");
          selposition(MINGX+35,Opre_start);
          printf("2.��Ʒɾ��");
          selposition(MINGX+5,Opre_start+1);
          printf("3.��Ʒ�޸�");
          selposition(MINGX+35,Opre_start+1);
          printf("4.��Ʒ����");
          selposition(MINGX+5,Opre_start+2);
          printf("5.��Ʒ���");
          selposition(MINGX+10,Opre_end-2);
          printf("��ѡ��:");
          fflush(stdin);
          key_choice=getch();
          choice_goods(key_choice,x,y);
      }

}
/**����Աѡ�����*/
char admin_info(int x,int y)
{
    selposition(MINGX+1,CHO_start);
    printf("������:");
    selposition(MINGX+25,CHO_start);
    if(x ==MINGX+25 && y == CHO_start)
    selcorlor(0,7);
    printf("�޸�����");
    selcorlor(0xa,0);
    selposition(MINGX+50,CHO_start);
    if(x == MINGX+50 && y == CHO_start)
    selcorlor(0,7);
    printf("����û�(��������Ա)");
    selcorlor(0xa,0);
    selposition(MINGX+25,CHO_end);
    if(x == MINGX+25 && y == CHO_end)
    selcorlor(0,7);
    printf("�û���Ϣ");
    selcorlor(0xa,0);
    selposition(MINGX+50,CHO_end);
    if(x == MINGX+50 && y == CHO_end)
    selcorlor(0,7);
    printf("��Ʒ��Ϣ");
    selcorlor(0xa,0);
    selposition(MINGX+30,(INFO_start+INFO_end)/2);
    printf("�� ӭ ʹ �� �� �� �� ϵ ͳ");
    admin_deal(x,y);
    key=getch();
    return key;
}
/**�곤��������*/
void shoper_deal(int x,int y)
{
    int i;
    char key_choices,choices,*nowtimes,id[10],pass[10];
    clears(MINGX+1,INFO_start,15);
    clears(MINGX+1,Opre_start,7);
    selposition(MINGX+30,(INFO_start+INFO_end)/2);
    printf("�� ӭ ʹ �� �� �� �� ϵ ͳ");
    selposition(MINGX+5,INFO_start);
    printf("��1�������!");
    if(getch() != '1')return;
    fflush(stdin);
    if(x ==MINGX+25 && y == CHO_start)
    {
        clears(MINGX+1,INFO_start,15);
        selposition(MINGX+15,INFO_start+3);
        printf("����������������:");
        gets(pass);
        modify_shpker(shpkers->id,pass);
    }
    if(x == MINGX+50 && y == CHO_start)
    {
         clears(MINGX+1,INFO_start,15);
        selposition(MINGX+15,INFO_start+3);
        printf("������������id:");
        gets(id);
        modify_shpker(id,shpkers->pass);
    }
    if(x == MINGX+25 && y == CHO_end)
    {
        clears(MINGX+1,INFO_start,1);
          selposition(MINGX+5,Opre_start+1);
          printf("3.��Ʒ�޸�");
          selposition(MINGX+35,Opre_start+1);
          printf("4.��Ʒ����");
          selposition(MINGX+5,Opre_start+2);
          printf("5.��Ʒ���");
          selposition(MINGX+10,Opre_end-2);
          printf("��ѡ��:");
          fflush(stdin);
          key_choices=getche();
          choice_goods(key_choices,x,y);
    }
     if(x == MINGX+50 && y == CHO_end)
     {
           clears(MINGX+1,INFO_start,1);
        selposition(MINGX+5,Opre_start+1);
        printf("1.���ձ���");
        selposition(MINGX+35,Opre_start+1);
        printf("2.���±���");
        selposition(MINGX+20,Opre_start+1+2);
        selposition(MINGX+10,Opre_start+1+2);
        printf("��ѡ��:");
         while(1)
         {

              choices = getche();
              if(choices == '1')  //�ձ���
              {
                   selposition(MINGX+1,INFO_start);
                   printf("���ձ���:");
                    selposition(MINGX+5,INFO_start+1);
                    printf("%-10s %-6s %-11s","��Ʒ","����Ա","ʱ��");
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
                            printf("��Ҫ������,���¾�Ȼû�ж�������!!");
                        }

                    }
              }
              if(choices == '2')
              {
                  read_month();
              }
              selposition(MINGX+10,Opre_start+1+2);
              printf("��ѡ��(0�˳�):");
              if(choices == '0')
              {
                  clears(MINGX+1,INFO_start,15);
                  selposition(MINGX+30,(INFO_start+INFO_end)/2);
                  printf("�� ӭ ʹ �� �� �� �� ϵ ͳ");
                  return;
              }
         }
     }
}
/**�곤ѡ�����*/
char shoper_info(int x,int y)
{
    selposition(MINGX+1,CHO_start);
    printf("������:");
    selposition(MINGX+25,CHO_start);
    if(x ==MINGX+25 && y == CHO_start)
    selcorlor(0,7);
    printf("�޸�����");
    selcorlor(0xa,0);
    selposition(MINGX+50,CHO_start);
    if(x == MINGX+50 && y == CHO_start)
    selcorlor(0,7);
    printf("�޸ĸ�����Ϣ");
    selcorlor(0xa,0);
    selposition(MINGX+25,CHO_end);
    if(x == MINGX+25 && y == CHO_end)
    selcorlor(0,7);
    printf("��Ʒ��Ϣ");
    selcorlor(0xa,0);
    selposition(MINGX+50,CHO_end);
    if(x == MINGX+50 && y == CHO_end)
    selcorlor(0,7);
    printf("�鿴����");
    selcorlor(0xa,0);
    selposition(MINGX+30,(INFO_start+INFO_end)/2);
    printf("�� ӭ ʹ �� �� �� �� ϵ ͳ");
    shoper_deal(x,y);
    key=getch();
    return key;
}
/**�鿴���±���*/
void read_month()
{
    char *reads,readss[200],goods[10],sells[10],data[10];
    reads =readss;
    int i,j;
    clears(MINGX+1,INFO_start+2,10);
    selposition(MINGX+1,INFO_start);
    printf("���±���:");
    selposition(MINGX+5,INFO_start+1);
    printf("%-10s %-6s %-11s","��Ʒ","����Ա","ʱ��");
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
/**����Ա��������*/
void seller_deal(int x,int y)
{
    clears(MINGX+1,INFO_start,15);
    clears(MINGX+1,Opre_start,7);
    char choices,*nowtimes;
    int i;
    selposition(MINGX+30,(INFO_start+INFO_end)/2);
    printf("�� ӭ ʹ �� �� �� �� ϵ ͳ");
    selposition(MINGX+5,INFO_start);
    printf("��1�������!");
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
        printf("1.���ձ���");
        selposition(MINGX+35,Opre_start+1);
        printf("2.���±���");
        selposition(MINGX+20,Opre_start+1+2);
        selposition(MINGX+10,Opre_start+1+2);
        printf("��ѡ��:");
         while(1)
         {

              choices = getche();
              if(choices == '1')  //�ձ���
              {
                  clears(MINGX+1,INFO_start,10);
                   selposition(MINGX+1,INFO_start);
                   printf("���ձ���:");
                    selposition(MINGX+5,INFO_start+1);
                    printf("%-10s %-6s %-11s","��Ʒ","����Ա","ʱ��");
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
                            printf("��Ҫ������,���¾�Ȼû�ж�������!!");
                        }

                    }
              }
              if(choices == '2')
              {
                  read_month();
              }
              selposition(MINGX+10,Opre_start+1+2);
              printf("��ѡ��(0�˳�):");
              if(choices == '0')
              {
                  clears(MINGX+1,INFO_start,15);
                  selposition(MINGX+30,(INFO_start+INFO_end)/2);
                  printf("�� ӭ ʹ �� �� �� �� ϵ ͳ");
                  return;
              }
         }
    }
}
/**����Աѡ�����*/
char seller_info(int x,int y)
{
    selposition(MINGX+1,CHO_start);
    printf("������:");
    selposition(MINGX+25,CHO_start);
    if(x ==MINGX+25 && y == CHO_start)
    selcorlor(0,7);
    printf("��Ʒ���");
    selcorlor(0xa,0);
    selposition(MINGX+50,CHO_start);
    if(x == MINGX+50 && y == CHO_start)
    selcorlor(0,7);
    printf("��Ʒ����");
    selcorlor(0xa,0);
    selposition(MINGX+25,CHO_end);
    if(x == MINGX+25 && y == CHO_end)
    selcorlor(0,7);
    printf("��Ʒ����");
    selcorlor(0xa,0);
    selposition(MINGX+50,CHO_end);
    if(x == MINGX+50 && y == CHO_end)
    selcorlor(0,7);
    printf("�鿴����");
    selcorlor(0xa,0);
    selposition(MINGX+30,(INFO_start+INFO_end)/2);
    printf("�� ӭ ʹ �� �� �� �� ϵ ͳ");
    seller_deal(x,y);
    fflush(stdin);
    key=getch();
    return key;
}
/**��¼�������֤*/
void login_in()
{
    char id[10],pass[10];int i=0;
    selposition(40,15);
    printf("�� ӭ ʹ �� �� �� �� ϵ ͳ");
    Sleep(1000);
    clears(40,15,1);
    while(1)
    {
        selposition(38,8);
        printf("----------------------------------");
        selposition(38,9);
        printf("|��ѡ���¼�û�                   |");
        selposition(38,10);
        printf("----------------------------------");
        selposition(38,11);
        printf("|  1.����Ա(�ǹ�����ѡ,����Ը�)  |");
        selposition(38,12);
        printf("----------------------------------");
        selposition(38,13);
        printf("|  2.�곤                         |");
        selposition(38,14);
        printf("----------------------------------");
        selposition(38,15);
        printf("|  3.����Ա                       |");
        selposition(38,16);
        printf("----------------------------------");
        selposition(38,17);
        printf("|  4.�˳�                         |");
        selposition(38,18);
        printf("----------------------------------");
        selposition(38,19);
        printf("|��ѡ��:                          |");
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
                printf("|������ID:                        |");
                selposition(38,10);
                printf("----------------------------------");
                selposition(38,11);
                printf("|����������:                      |");
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
                    printf("��¼�ɹ�!!");
                    Sleep(1000);
                    clears(38,8,11);
                    return;
                }
                else{
                    selposition(45,17);
                    printf("��¼ʧ��!!");
                    Sleep(1000);
                    break;
                }

        case 2: clears(38,8,15);
                fflush(stdin);
                selposition(38,8);
                printf("----------------------------------");
                selposition(38,9);
                printf("|������ID:                        |");
                selposition(38,10);
                printf("----------------------------------");
                selposition(38,11);
                printf("|����������:                      |");
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
                    printf("��¼�ɹ�!!");
                    Sleep(1000);
                    clears(38,8,11);
                    return;
                }
                else{
                    selposition(45,17);
                    printf("��¼ʧ��!!");
                    Sleep(1000);
                    break;
                }


        case 3:clears(38,8,15);
                fflush(stdin);
                selposition(38,8);
                printf("----------------------------------");
                selposition(38,9);
                printf("|������ID:                        |");
                selposition(38,10);
                printf("----------------------------------");
                selposition(38,11);
                printf("|����������:                      |");
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
                    printf("��¼�ɹ�!!");
                    Sleep(1000);
                    clears(38,8,11);
                    len = i;
                    return;
                    }
                }
                selposition(45,17);
                    printf("��¼ʧ��!!");
                    Sleep(1000);
                    break;
            case 4:exit(0);
        default:selposition(39,17);
                printf("�������,����������");
                Sleep(1000);
        }

clears(38,8,15);
    }
}
/**��ʾ��ǰ�û�*/
char login(int x,int y)
{
    if(login_number == 1)
    {
        selposition(MINGX+35,3);
        printf("�������:����Ա");
        key =admin_info(x,y);
        return key;
    }
    else if(login_number == 2)
    {
        selposition(MINGX+35,3);
        printf("�������:�곤");
        key =shoper_info(x,y);
        return key;
    }
    else if(login_number == 3)
    {
        selposition(MINGX+35,3);
        printf("�������:����Ա.%s",(sellerarry+len)->name);
        key =seller_info(x,y);
        return key;
    }
    return 0;
}
/**����Ʒ�Ĳ����жϽ���*/
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
/**��Ʒ���*/
void goods_add()
{

    clears(MINGX+1,INFO_start,15);
    selposition(MINGX+74,INFO_end);
    printf("0�˳�,���������");
    if(getch()=='0') return;
    clears(MINGX+1,INFO_end,1);
    if(len1>=27)
    {
        selposition(MINGX+33,(INFO_start+INFO_end)/2);
        printf("���Ŀ������");
        return;
    }
    selposition(MINGX+5,INFO_start);
    printf("��������Ҫ�����Ʒ��������Ϣ:");
    selposition(MINGX+10,INFO_start+1);
    printf("����:");
    scanf("%s",(goodsarrys+len1)->name);
    selposition(MINGX+50,INFO_start+1);
    fflush(stdin);
    printf("����:");
    scanf("%s",(goodsarrys+len1)->producer);
    selposition(MINGX+10,INFO_start+2);
    fflush(stdin);
    printf("�۸�:");
    scanf("%lf",&(goodsarrys+len1)->price);
    selposition(MINGX+50,INFO_start+2);
    fflush(stdin);
    printf("����:");
    scanf("%d",&(goodsarrys+len1)->quantity);
    len1++;
    selposition(MINGX+15,INFO_start+5);
    printf("��ӳɹ�!!");
    Sleep(1000);
}
/**��Ʒɾ��*/
void goods_del()
{
    int i,j;
    char code[10];
    clears(MINGX+1,INFO_start,15);
    selposition(MINGX+5,INFO_start);
    printf("������Ҫɾ������Ʒ����:");
        gets(code);
          for(i=0;i<len1;i++)
        {
                if(strcmp((goodsarrys+i)->code,code) == 0)
                {
                    selposition(MINGX+5,INFO_start+1);
                    printf("%-15s %5s %-5.2lf %-4d",(goodsarrys+i)->name,(goodsarrys+i)->code,(goodsarrys+i)->price,(goodsarrys+i)->quantity);
                     selposition(MINGX+5,INFO_start+2);
                     printf("�Ƿ�Ҫɾ��(1,�� 2.��): ");
                    break;
                }
        }
        if(len1 <= i)
        {
            selposition(MINGX+5,INFO_start+1);
            printf("�ֿ�û�д���Ʒ!");
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
            printf("��ɾ��");
            Sleep(1000);
        }
        clears(MINGX+1,INFO_start,7);
        return;

}
/**��Ʒ�޸�*/
void goods_modify()
{
    int i;
    char code[10],key_modify;
    clears(MINGX+1,INFO_start,15);
    selposition(MINGX+1,INFO_start);
    printf("������Ҫ�޸���Ʒ�Ĵ���:");
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
            printf("�޴���Ʒ!!");
            Sleep(500);
            clears(MINGX+1,INFO_start,10);
            selposition(MINGX+5,INFO_start);
            printf("������Ҫ�޸���Ʒ�Ĵ���(�س��˳�):");
            fflush(stdin);
            if(getch() == 13) return;
            continue;
        }
        selposition(MINGX+1,INFO_start+2);
        printf("��ѡ��Ҫ�޸ĵ�����:");
        selposition(MINGX+5,INFO_start+4);
        printf("1.����");
        selposition(MINGX+35,INFO_start+4);
        printf("2.����");
        selposition(MINGX+5,INFO_start+5);
        printf("3.����");
        selposition(MINGX+35,INFO_start+5);
        printf("4.�۸�");
        selposition(MINGX+5,INFO_start+6);
        printf("5.����");
        selposition(MINGX+5,INFO_start+7);
        printf("��ѡ��:");
        key_modify= getche();
        switch(key_modify)
        {
            case '1': selposition(MINGX+5,INFO_start+8);
                      printf("�������µ���Ϣ:");
                      scanf("%s",(goodsarrys+i)->name);
                      break;
            case '2':selposition(MINGX+5,INFO_start+8);
                     printf("�������µ���Ϣ:");
                     scanf("%s",(goodsarrys+i)->code);
                     break;
            case '3': selposition(MINGX+5,INFO_start+8);
                     printf("�������µ���Ϣ:");
                      scanf("%s",(goodsarrys+i)->producer);
                break;
            case '4': selposition(MINGX+5,INFO_start+8);
                      printf("�������µ���Ϣ:");
                      scanf("%lf",&(goodsarrys+i)->price);
                break;
            case '5': selposition(MINGX+5,INFO_start+8);
                      printf("�������µ���Ϣ:");
                      scanf("%lf",&(goodsarrys+i)->quantity);
                break;
        }
        selposition(MINGX+5,INFO_start+9);
        printf("�޸ĳɹ�!");
        Sleep(500);
        clears(MINGX+1,INFO_start,10);
        selposition(MINGX+5,INFO_start);
        printf("������Ҫ�޸���Ʒ�Ĵ���(�س��˳�):");
        fflush(stdin);
        if(getch() == 13) return;

    }
}
/**��Ʒ����*/
void goods_search()
{
    int i;
    char code[10];
    clears(MINGX+1,INFO_start,15);
    selposition(MINGX+5,INFO_start);
    printf("������Ҫ���ҵĻ������:");
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
                printf("����,�ҵ���.");
                selposition(MINGX+15,INFO_start+3);
                printf("%-15s %5s %-5.2lf %-4d",(goodsarrys+i)->name,(goodsarrys+i)->code,(goodsarrys+i)->price,(goodsarrys+i)->quantity);
                break;
            }
        }
        if(i >= len1)
        {
            selposition(MINGX+15,INFO_start+2);
            printf("���˵Ĳֿ��Ȼû�������!");
        }
        clears(MINGX+1,INFO_start,1);
        selposition(MINGX+5,INFO_start);
        printf("������Ҫ���ҵĻ������(�س��˳�):");
        fflush(stdin);
        if(getch() == 13) return;
    }
}
void goods_browse()
{
    int i;
    clears(MINGX+1,INFO_start,15);
    selposition(MINGX+5,INFO_start);
    printf("���Ĳֿ���:");
    selposition(MINGX+5,INFO_start+1);
    printf("%-15s %5s %-5s %-4s","����","����","�۸�","���");
    for(i=0;i<len1;i++)
    {

            if(i>=10 && i<20)
            {
                if(i == 10)
                {
                  selposition(MINGX+60,INFO_end);
                  printf("�밴���������...");
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
                  printf("�밴���������...");
                  getch();
                   clears(MINGX+1,INFO_start,15);
                }
                selposition(MINGX+5,INFO_start+2+i-20);
            }
            else selposition(MINGX+5,INFO_start+2+i);



            printf("%-15s %5s %-5.2lf %-4d",(goodsarrys+i)->name,(goodsarrys+i)->code,(goodsarrys+i)->price,(goodsarrys+i)->quantity);
    }
    selposition(MINGX+75,INFO_end);
    printf("0�˳�");

}
/**��Ʒ����*/
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
    printf("������Ҫ���۵���Ʒ����:");
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
                        printf("�Ƿ�Ҫ����(1.�� 2.��):");
                        key_choice=getche();
                        break;
                    }
        }
        if(i == len1)
        {
            selposition(MINGX+20,INFO_start+4);
            printf("�޴���Ʒ!!");
            Sleep(500);
            goto l;
        }
        if(key_choice == '1')
        {
            (goodsarrys+i)->quantity-=1;                 //��������
            (goodser+len3)->assistant=*(sellerarry+len);     //��¼�ۻ�Ա(������)
            (goodser+len3)->good=*(goodsarrys+i);        //��¼�۳���Ʒ
            (goodser+len3)->number=0;
            strcpy((goodser+len3)->sell_data,times);                    //�����жϵĳ�Ա
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
            printf("���۳ɹ�");
            Sleep(500);
        }
        l:clears(MINGX+1,INFO_start,6);
        selposition(MINGX+5,INFO_start);
        printf("������Ҫ���۵���Ʒ����(�س��˳�):");
        if(getch() == 13) return;
    }
}
/**��ȡ��ǰ����*/
char* getnowtime()
{
    char *times;
    times =(char *)malloc(sizeof(char)*15);
    /**��ȡϵͳ��ǰʱ��*/
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
    printf("�Ƿ��˳�(1.�� 2.��)");
    if(getch() == '1')
    {
        exit(0);
    }
}











#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "head.h"

#define MING 20
#define INFO 4   //18
#define CHOICE 22   //10

Books books[30];
User users[5];
Books *str_books = books;
User *str_users = users;
int len1;  //ͼ�����
int len2;  //�û�����
/**��ʼ������*/
void init()
{
    int i;
     clears(MING+1,INFO,18);
    selposition(MING+30,INFO+9);
    printf("��ӭʹ�ô�ϵͳ!!");
    selposition(MING+1,1);
    for(i=0;i<80;i++)printf("-");
    selposition(MING,2);
    printf("|");
    selposition(MING+25,2);
    printf("WELCOME THIS SYSTEM");
    selposition(MING+81,2);
    printf("|");
    selposition(MING+1,3);
    for(i=0;i<80;i++)printf("-");
    for(i=0;i<18;i++)
    {
        selposition(MING,4+i);
        printf("|");
        selposition(MING+81,4+i);
        printf("|");
    }
    selposition(MING+1,22);
    for(i=0;i<80;i++)printf("-");
    for(i=0;i<10;i++)
    {
        selposition(MING,22+i);
        printf("|");
        selposition(MING+81,22+i);
        printf("|");
    }
    selposition(MING+1,32);
    for(i=0;i<80;i++)printf("-");
}

/**��Ϣ��ʼ��*/
void storage_info()
{
    char user[20]="admin 123 ";
    char booker[400]="admin ���֮�� <���֮��С��> ������� ���ӹ�ҵ���� 2009.3.1 40 admin aaa <���֮��С��> ������� ���ӹ�ҵ���� 2009.3.1 40 ";
    if( (bookss =fopen("e:/bookinfo.txt","w+") ) ==NULL)
    {
        printf("error");
        exit(0);
    }
    fprintf(bookss,"%s",booker);
    fclose(bookss);
    if( (login_user =fopen("e:/admininfo.txt","w+") ) ==NULL)
    {
        printf("error");
        exit(0);
    }
    fprintf(login_user,"%s",user);
    fclose(login_user);
}

void read_info()
{
    char *booker;
    char *user;

    booker = (char *)malloc(sizeof(char)*10000);
    user =(char *)malloc( sizeof(char)*20);

    if( (bookss =fopen("e:/bookinfo.txt","r") ) ==NULL)
    {
        printf("error");
        exit(0);
    }
    fgets(booker,10000,bookss);
    fclose(bookss);

    deal_book(booker);

    if( (login_user =fopen("e:\\admininfo.txt","r+") ) ==NULL)
    {
        printf("error");
        exit(0);
    }
    fgets(user,20,login_user);
    fclose(login_user);
    deal_user(user);
    free(booker);
    free(user);

}
void login()
{
    int i;
    char id[10],pass[10];
    selposition(43,10);
        for(i=0;i<30;i++)printf("-");
        selposition(45,11);
        printf("�û���:");
        selposition(45,13);
        printf("����:");
        selposition(43,14);
        for(i=0;i<30;i++)printf("-");
    while(1)
    {
        selposition(52,11);
        gets(id);
        selposition(51,13);
        gets(pass);
        if( strcmp(str_users->user_s,id) == 0 && strcmp( str_users->pass,pass ) ==0)
        {
            selposition(50,17);
            printf("��¼�ɹ�");
            Sleep(1000);
            clears(43,10,15);
            break;
        }
        selposition(50,17);
            printf("��¼ʧ��");
            Sleep(1000);
            clears(52,11,1);
            clears(51,13,1);
            clears(50,17,1);
    }

}
/**�����ȡͼ����Ϣ*/
void deal_book(char *booker)
{
    int i=0,j;
    char info[30];
    for(j=0;j<30;j++)
    {
        i=0;
        while(*booker != ' ')    //��¼��
        {
            info[i] = *booker;
            i++;booker++;
        }
        info[i] ='\0';
        strcpy((str_books+j)->loginNo,info);
        i=0;booker++;
        while(*booker !=' ')    //����
        {
            info[i]=*booker;
            i++;booker++;
        }
        info[i] ='\0';
        strcpy((str_books+j)->name,info);
        i=0;booker++;
        while(*booker !=' ')    //������
        {
            info[i]=*booker;
            i++;booker++;
        }
        info[i] ='\0';
        strcpy( (str_books+j)->author,info);
        booker++;i=0;
         while(*booker !=' ')    //�����
        {
            info[i]=*booker;
            i++;booker++;
        }
        info[i] ='\0';
        strcpy((str_books+j)->classNo,info);

        i=0;booker++;
         while(*booker !=' ')    //���浥λ
        {
            info[i]=*booker;
            i++;booker++;
        }
        info[i] ='\0';
        strcpy((str_books+j)->publisher,info);
        booker++;i=0;
         while(*booker !=' ')    //����ʱ��
        {
            info[i]=*booker;
            i++;booker++;
        }
        info[i] ='\0';
        strcpy((str_books+j)->pubTime,info);
        booker++;i=0;
         while(*booker !=' ')   //�۸�
        {
            info[i]=*booker;
            i++;booker++;
        }
        info[i] ='\0';
        strcpy((str_books+j)->price,info);
        booker++;
        if(*booker == '\0')
        {
            len1=j;
             break;
        }
    }
}
/**�����ȡ���û���Ϣ*/
void deal_user(char *user)
{

    int i;
    char info[10];
    selposition(0,0);
        i=0;
        while(*user != ' ')
        {
            info[i] = *user;
            user++;i++;
        }
        info[i]='\0';i=0;user++;
        strcpy( str_users->user_s,info);
        while(*user != ' ')
        {
            info[i] = *user;
            user++;i++;
        }
        info[i]='\0';i=0;user++;
        strcpy(str_users->pass,info);
}
/**ѡ����*/
void init_choice()
{
    char choice;
    selposition(MING+30,INFO+9);
    printf("��ӭʹ�ô�ϵͳ!!");
    selposition(MING+30,CHOICE+1);
    printf("1.���ͼ��");
    selposition(MING+30,CHOICE+2);
    printf("2.����ͼ��");
    selposition(MING+30,CHOICE+3);
    printf("3.���ͼ��");
    selposition(MING+30,CHOICE+4);
    printf("4.ɾ��ͼ��");
    selposition(MING+30,CHOICE+5);
    printf("5.�޸�ͼ����Ϣ");


    while(1)
    {
        selposition(MING+25,CHOICE+7);
         printf("��ѡ��:");
        choice=getche();
        books_choice(choice);
    }

}
void books_choice(char choice)
{
    switch(choice)
    {
        case '1': book_add();     break;
        case '2': book_search();  break;
        case '3':  book_browse(); break;
        case '4': book_del();     break;
        case '5': book_modify();  break;
        case 0x1b:exit(0);
        default:selposition(MING+30,CHOICE+8);
                printf("�Ѿ�û�����ֲ�����!!");
                Sleep(1000);
    }
    clears(MING+1,INFO,18);
    selposition(MING+30,INFO+9);
    printf("��ӭʹ�ô�ϵͳ!!");
    clears(MING+1,CHOICE+7,2);
}
/**����*/
void book_add()
{
    clears(MING+1,INFO,18);
    char name[10],author[10],classNO[10], publisher[10],pubTime[20],price[10];
    selposition(MING+5,INFO);
    printf("������:");
    selposition(MING+6,INFO+1);
    printf("����:");
    fflush(stdin);
    scanf("%s",name);
    selposition(MING+45,INFO+1);
    printf("����:");
    fflush(stdin);
    scanf("%s",author);
    selposition(MING+6,INFO+2);
    printf("�����:");
    fflush(stdin);
    scanf("%s",classNO);
    selposition(MING+45,INFO+2);
    printf("���浥λ:");
    fflush(stdin);
    scanf("%s",publisher);
    selposition(MING+6,INFO+3);
    printf("����ʱ��:");
    fflush(stdin);
    scanf("%s",pubTime);
    selposition(MING+45,INFO+3);
    printf("�۸�:");
    fflush(stdin);
    scanf("%s",price);
    book_adds(name,author,classNO,publisher,pubTime,price);
}
void book_adds(char *name,char *author,char *classNO, char *publisher,char *pubTime,char *price)
{
    selposition(0,0);
    printf("asd");
    char add[1000];
    strcpy(add,"");strcat(add,"admin");strcat(add," ");strcat(add,name);strcat(add," ");strcat(add,author);strcat(add," ");strcat(add,classNO);
    strcat(add," ");strcat(add,publisher);strcat(add," ");strcat(add,pubTime);strcat(add," ");
    strcat(add,price);strcat(add," ");
    if( (bookss =fopen("e:/bookinfo.txt","a") ) ==NULL)
    {
        printf("error");
        exit(0);
    }
    fprintf(bookss,"%s",add);
    fclose(bookss);
    selposition(MING+25,INFO+4);
    printf("��ӳɹ�!!");
    Sleep(1000);
    read_info();
}

/**����*/
void book_search()
{
    char search[10];int i;
     clears(MING+1,INFO,18);
     selposition(MING+5,INFO+1);
     printf("������������������:");
     gets(search);
     for(i=0;i<=len1;i++)
     {
         if( strcmp( (str_books+i)->name,search) ==0 || strcmp( (str_books+i)->author,search)==0  )
         {
             selposition(MING+25,INFO+3);
              printf("����,�����ҵ���!!");
              selposition(MING+2,INFO+4);
              printf("%s %s %s %s %s %s",(str_books+i)->name,(str_books+i)->author,(str_books+i)->classNo,(str_books+i)->publisher,(str_books+i)->pubTime,(str_books+i)->price);
              break;
         }

     }
     if(len1 > i){
        selposition(MING+25,INFO+3);
        printf("֪ʶ����������,�����鶼û��,����ͼ���!");
     }
}
/**���*/
void book_browse()
{
    int i;
     clears(MING+1,INFO,18);
     selposition(MING+1,INFO+15);
     printf("0�˳�");
     selposition(MING+5,INFO+1);
     printf("%-10s %-15s %-10s %-10s %-10s %-4s","����","������","�����","������","����ʱ��","�۸�");
     for(i=0;i<=len1;i++)
     {
         if(i>=10)
         {
             if(i==10) clears(MING+1,INFO+2,12);
             selposition(MING+2,INFO+2+i-10);
             selposition(MING+70,INFO+15);
             printf("�밴���������....");
             fflush(stdin);
             getch();
         }
         else if(i>=20)
         {
             if(i==20)  clears(MING+1,INFO+1,12);
             selposition(MING+2,INFO+2+i-20);
         }
         else selposition(MING+2,INFO+2+i);
         printf("%-10s %-15s %-10s %-10s %-10s %-4s",(str_books+i)->name,(str_books+i)->author,(str_books+i)->classNo,(str_books+i)->publisher,(str_books+i)->pubTime,(str_books+i)->price);
     }
     if(i == 0)
     {
         selposition(MING+25,INFO+3);
        printf("�տ���Ҳ,���󶼲��������");
     }
     if(getch() == '0')
       clears(MING+1,INFO,18);
}
/**ɾ��*/
void book_del()
{
    int i;char choice;
    char del_book[10];
     clears(MING+1,INFO,18);
     selposition(MING+5,INFO);
     printf("������Ҫɾ��������:");
     gets(del_book);
     if(len1 == 0)
     {
         selposition(MING+25,INFO+6);
         printf("��һ������,���Ű�!!");
         Sleep(1000);
         return;
     }
      for(i=0;i<=len1;i++)
     {
         if( strcmp( (str_books+i)->name,del_book) ==0 || strcmp( (str_books+i)->author,del_book)==0  )
         {

              selposition(MING+2,INFO+3);
              printf("%s %s %s %s %s %s",(str_books+i)->name,(str_books+i)->author,(str_books+i)->classNo,(str_books+i)->publisher,(str_books+i)->pubTime,(str_books+i)->price);
               selposition(MING+25,INFO+4);
              printf("�Ƿ�Ҫɾ�� 1.�� 2.��");
              choice = getche();
              if(choice == '1')
              del_bookss(i);
              break;
         }
     }
     if(len1 < i){
        selposition(MING+20,INFO+5);
        printf("֪ʶ����������,�����鶼û��,����ͼ���!");
        Sleep(1500);
     }
}
void del_bookss(int del)
{
    int i;
    char add[10000];
    for(i=0;i<=len1;i++)
    {
         if(i ==0)  strcpy(add,"");
        if(del ==i) continue;
        strcat(add,(str_books+i)->loginNo);strcat(add," ");strcat(add,(str_books+i)->name);strcat(add," ");
        strcat(add,(str_books+i)->author);strcat(add," ");strcat(add,(str_books+i)->classNo);
        strcat(add," ");strcat(add,(str_books+i)->publisher);strcat(add," ");strcat(add,(str_books+i)->pubTime);strcat(add," ");
        strcat(add,(str_books+i)->price);strcat(add," ");
    }
    if( (bookss =fopen("e:/bookinfo.txt","w+") ) ==NULL)
    {
        printf("error");
        exit(0);
    }
    fprintf(bookss,"%s",add);
    fclose(bookss);
    selposition(MING+25,INFO+6);
    printf("ɾ���ɹ�!!");
    Sleep(1000);
    read_info();
}
/**�޸�*/
void book_modify()
{
    int i;
    char modify_books[10];
     clears(MING+1,INFO,18);
     selposition(MING+5,INFO);
     printf("������Ҫ�޸�ͼ�������:");
     gets(modify_books);
    for(i=0;i<=len1;i++)
     {
         if( strcmp( (str_books+i)->name,modify_books) ==0 || strcmp( (str_books+i)->author,modify_books)==0  )
         {

              selposition(MING+2,INFO+3);
              printf("%s %s %s %s %s %s",(str_books+i)->name,(str_books+i)->author,(str_books+i)->classNo,(str_books+i)->publisher,(str_books+i)->pubTime,(str_books+i)->price);
               selposition(MING+5,INFO+4);
              printf("��ѡ���޸�����:");
              selposition(MING+5,INFO+5);printf("1.����(0�˳�");selposition(MING+45,INFO+5);printf("2.����");
              selposition(MING+5,INFO+6);printf("3.�����");selposition(MING+45,INFO+6);printf("4.������");
              selposition(MING+5,INFO+7);printf("5.����ʱ��");selposition(MING+45,INFO+7);printf("6.�۸�");
              selposition(MING+25,INFO+8);
              printf("��ѡ��:");
              modify_bookss(i);
              break;
         }
     }
     if(len1 < i){
        selposition(MING+20,INFO+5);
        printf("֪ʶ����������,�����鶼û��,����ͼ���!");
        Sleep(1500);
     }
}
void modify_bookss(int k)
{
    int choice;
    char choices,modify[30];
    scanf("%d",&choice);
    selposition(MING+15,INFO+10);
    fflush(stdin);
    printf("�������µ���Ϣ:");
    gets(modify);
    selposition(MING+25,INFO+11);
    printf("�Ƿ��޸�(1.�� 2.��)");
    choices = getch();
    if(choices == '1')
    switch(choice)
    {
        case 1:modify_book(modify,k,choice);break;
        case 2:modify_book(modify,k,choice);break;
        case 3:modify_book(modify,k,choice);break;
        case 4:modify_book(modify,k,choice);break;
        case 5:modify_book(modify,k,choice);break;
        case 6:modify_book(modify,k,choice);break;
        case 0:break;
        default:selposition(MING+35,INFO+12);
            printf("����ʧ��,ȡ������!");
            break;
    }
}
void modify_book(char *modify,int k,int choice)
{
    int i;char add[10000];
    if(choice == 1) strcpy((str_books+k)->name,modify);
    else if(choice == 2) strcpy((str_books+k)->author,modify);
    else if(choice == 3) strcpy((str_books+k)->classNo,modify);
    else if(choice == 4) strcpy((str_books+k)->publisher,modify);
    else if(choice == 5) strcpy((str_books+k)->pubTime,modify);
    else if(choice == 6) strcpy((str_books+k)->price,modify);
    for(i=0;i<=len1;i++)
    {
         if(i ==0)  strcpy(add,"");
        strcat(add,(str_books+i)->loginNo);strcat(add," ");strcat(add,(str_books+i)->name);strcat(add," ");
        strcat(add,(str_books+i)->author);strcat(add," ");strcat(add,(str_books+i)->classNo);
        strcat(add," ");strcat(add,(str_books+i)->publisher);strcat(add," ");strcat(add,(str_books+i)->pubTime);strcat(add," ");
        strcat(add,(str_books+i)->price);strcat(add," ");
    }
    if( (bookss =fopen("e:/bookinfo.txt","w+") ) ==NULL)
    {
        printf("error");
        exit(0);
    }
    fprintf(bookss,"%s",add);
    fclose(bookss);
    clears(MING+1,INFO,18);
    selposition(MING+25,INFO+6);
    printf("�޸ĳɹ�!!");
    Sleep(1000);
    read_info();
}





















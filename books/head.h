#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED





FILE *login_user,*bookss;

typedef struct _book
{
  char loginNo[10];    //��¼��
  char name[20];      //����
  char author[20];     //������
  char classNo[10];    //�����
  char publisher[20];   //���浥λ
  char pubTime[20];   //����ʱ��
  char price[10];         //�۸�
}Books;   //ͼ����Ϣ�ṹ��

typedef struct _user
{
    char user_s[10];
    char pass[10];
}User;
/**��ʼ������*/
void init();
/**��ʼ��ѡ����*/
void init_choice();
/**ѡ����Ϣ����*/
void books_choice(char);
/**��ʼ���ļ���Ϣ*/
void storage_info();
/**����*/
void read_info();
/**�����ȡͼ����Ϣ*/
void deal_book(char *);
/**�����ȡ���û���Ϣ*/
void deal_user(char *);
/**����*/
void book_add();
void book_adds(char*,char*,char*,char*,char*,char*);
/**����*/
void book_search();
/**���*/
void book_browse();
/**ɾ��*/
void book_del();
void del_bookss(int);
/**�޸�*/
void book_modify();
void modify_book(char*,int,int);
void modify_bookss(int);
/**��¼*/
void login();











#endif // HEAD_H_INCLUDED

#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED





FILE *login_user,*bookss;

typedef struct _book
{
  char loginNo[10];    //登录号
  char name[20];      //书名
  char author[20];     //作者名
  char classNo[10];    //分类号
  char publisher[20];   //出版单位
  char pubTime[20];   //出版时间
  char price[10];         //价格
}Books;   //图书信息结构体

typedef struct _user
{
    char user_s[10];
    char pass[10];
}User;
/**初始化界面*/
void init();
/**初始化选择区*/
void init_choice();
/**选择信息处理*/
void books_choice(char);
/**初始化文件信息*/
void storage_info();
/**存入*/
void read_info();
/**处理读取图书信息*/
void deal_book(char *);
/**处理读取的用户信息*/
void deal_user(char *);
/**增加*/
void book_add();
void book_adds(char*,char*,char*,char*,char*,char*);
/**查找*/
void book_search();
/**浏览*/
void book_browse();
/**删除*/
void book_del();
void del_bookss(int);
/**修改*/
void book_modify();
void modify_book(char*,int,int);
void modify_bookss(int);
/**登录*/
void login();











#endif // HEAD_H_INCLUDED

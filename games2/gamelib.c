/********************************************
 * �ļ���: Gamelib.c
 * ��   ��: ʵ��gamelib.h�ж���ĺ���
 * ��   ��: 2017.4.23
 * ��   ��: 1.0
 * ���� ��: sexx
 ********************************************/
 #include "gamelib.h"

 void seltitle(char *title)
 {
     SetConsoleTitle(title);
 }
void selcorlor(int fore ,int back)
{
    HANDLE winHandle;//���
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    ///������ɫ
    SetConsoleTextAttribute(winHandle,fore + back *0x10);
}
void selposition(int x,int y)
{
    HANDLE winHandle;//���
    COORD pos = {x ,y};
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    ///���ù���λ��
    SetConsoleCursorPosition(winHandle, pos);

}
void clears(int x,int y,int he)
{
    int i,j;
    for(i=0;i<he;i++)
    {
        selposition(x,y+i);
        for(j=0;j<80;j++)
        {
            printf(" ");
        }
    }
}



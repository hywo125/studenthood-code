#ifndef GAMELIB_H_INCLUDED
#define GAMELIB_H_INCLUDED
/********************************************
 * �ļ���: Gamelib.h
 * ��   ��: ����������Ϸ�г��õ�ϵͳ����
 * ��   ��: 2017.4.23
 * ��   ��: 1.0
 * ���� ��: s
 ********************************************/
#include <stdio.h>
#include <windows.h>
/** ���ÿ���̨���ڵı���*/
void seltitle(char *title);
/** ����ǰ���ͱ���ɫ��ɫ*/
//0 �� 2 �� 3 ��
void selcorlor(int fore ,int back);
/**���ù���λ��*/
void selposition(int x,int y);
/** ɾ���ض��������������*/
void clears(int x,int y,int he);
#endif // GAMELIB_H_INCLUDED

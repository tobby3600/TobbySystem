#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <windows.h>
using namespace std;
void Rand_Color_Behind(){
	Sleep(100);
	printf("Rand Color Start!(Just for fun)\n");
	while(1){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|int(Get_Rand(false,0)));
//		Sleep(1);
	}
}
int main(){
	cout<<"ԭɫ��û������������ɫ��"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);//������ɫ���
	cout<<"��ɫ����ɫ��ɫ��ɫ��ӣ�"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);//���ú�ɫ
	cout<<"��ɫ�����õ���ɫΪ��ɫ��"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);//������ɫ
	cout<<"��ɫ�����õ���ɫΪ��ɫ��"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
	//������ɫ
	cout<<"��ɫ�����õ���ɫΪ��ɫ��"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);//���ú�ɫ����ɫ���
	cout<<"��ɫ����ɫ����ɫ���ɫ��"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);//���ú�ɫ����ɫ���
	cout<<"��ɫ����ɫ����ɫ���ɫ��"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);//������ɫ����ɫ���
	cout<<"��ɫ����ɫ����ɫ���ɫ��"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);//������ɫ��û�������ɫ����Ϊԭɫ
	cout<<endl;
}

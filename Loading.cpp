#include <bits/stdc++.h>
#include <windows.h> //system()
#include <conio.h> //_kbhit(),getch()
#include <iostream> 
#include <fstream> 
#include <stdlib.h> 
#include <string> 
#include <cstring> 
#include <cmath> 
#include <thread> //���߳� 
#include <chrono>

using namespace std;

void gotoxy(int x, int y) //xΪ������,yΪ������
{
    COORD pos = {x,y};//��������
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//����һ�����
    SetConsoleCursorPosition(hOut, pos);
}

//ɾ����i��
void clearline(int i)
{
    gotoxy(0,i-1);
    for(int j=0;j<=20;j++)
        cout<<" ";
    cout.flush();
    gotoxy(0,i-1);
}

bool isFileExists_fopen(string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }   
}

struct Arrow{
	int x,y;//������ 
};

void HideCursor(int x) //�������
{
    CONSOLE_CURSOR_INFO cursor_info = {1, x}; //��ߵ�0�����겻�ɼ�
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

Arrow getxy(){
	HANDLE hStdout;
	CONSOLE_SCREEN_BUFFER_INFO pBuffer; 
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
	GetConsoleScreenBufferInfo(hStdout, &pBuffer); 
	Arrow tmp;
	tmp.x=pBuffer.dwCursorPosition.X;
	tmp.y=pBuffer.dwCursorPosition.Y;
	return tmp; 
}

void Start(){
	system("cls");
	gotoxy(20,5);
	puts("Welcome!");
	Sleep(800);
}

void Loading(){
	system("cls");
	gotoxy(5,5);
	printf("\nLoading...\n","");
	
	gotoxy(5,7);
	printf("[");
	printf("                 ");
	printf("]");//7,22
	gotoxy(6,7);
	for(int i=1;i<=18;i++){
		Sleep(150);
		printf("=");
		gotoxy(6+i,7);
		printf("\b");
	}
	gotoxy(23,7);
//	Arrow now=getxy();
//	printf("[               ]");
//	Arrow end=getxy();
//	now.x++;
//	end.x--;
//	int tx=now.x,ty=now.y;
//	while(tx!=end.x&&ty!=end.y){
//		Sleep(100);
//		printf("=");
//		Arrow tmp=getxy();
//		gotoxy(tmp.x+1,tmp.y);
//		printf("\b");
//		tx++;
//	}
//	gotoxy(end.x+1,end.y);
	printf("\n\nOK!\n");
}

int main(){
	Start();
	Loading();
	system("LoadMain.bat");
	return 0;
}
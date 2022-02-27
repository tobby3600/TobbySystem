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
	cout<<"原色（没有设置字体颜色）"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);//设置三色相加
	cout<<"白色（红色绿色蓝色相加）"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);//设置红色
	cout<<"红色（设置的颜色为红色）"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);//设置绿色
	cout<<"绿色（设置的颜色为绿色）"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
	//设置蓝色
	cout<<"蓝色（设置的颜色为蓝色）"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);//设置红色和绿色相加
	cout<<"黄色（红色和绿色相加色）"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);//设置红色和蓝色相加
	cout<<"粉色（红色和蓝色相加色）"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);//设置绿色和蓝色相加
	cout<<"青色（绿色和蓝色相加色）"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);//设置颜色，没有添加颜色，故为原色
	cout<<endl;
}

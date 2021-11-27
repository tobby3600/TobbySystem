/*
	TobbySystem
	Beta 0.4
	2021/11/21
*/

#include <bits/stdc++.h> 
#include <windows.h> //system()
#include <conio.h> //_kbhit(),getch()
#include <iostream> 
#include <fstream> 
#include <stdlib.h> 
#include <string> 
#include <cstring> 
#include <cmath> 
#include <thread> //多线程 
#include <chrono>

using namespace std;

const string PassWord = "123456";
const string Name_Editer = "Tobby Text Editer.exe";
const string Name_Calcer = "Tobby Calcer.exe";
const string Name_Management = "Tobby App Management.exe";
const double Version = 0.4;
const string _Type = "Beta";
const string _Date = "2021/11/21";

string Path="Main#";
int Tx,Ty;
bool Started=false; 

void _Exit(){
	system("cls");
	printf("------------Tobby System------------\n");
	printf("Good Bye~\n");
	getchar();
	getchar(); 
	exit(0); 
}
void _About(){
	system("cls");
	printf("------------Tobby System------------\n");
	printf("Version:%.2lf\n",Version);
	printf("Type:"); 
	cout<<_Type;
	printf("\nAuthor:Tobby SQL\n");
	printf("\n");
	getchar();
	getchar();
}
void login();
void gomain();
void relogin(){
	system("cls");
	Path="Main#";
	gomain();
}
void gotoxy(int x, int y) //x为列坐标,y为行坐标
{
    COORD pos = {x,y};//定义坐标
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//设置一个句柄
    SetConsoleCursorPosition(hOut, pos);
}
//删除第i行
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
void RunHelp(){
	printf("---------------Tobby System Help-------------------\n");
	printf("* Help | help -get help\n");
	printf("* Exit | exit -exit the system\n");
	
	printf("Edit | edit -text editer,surport zh_cn\n");
	printf("Calc | calc -calc numbers,surport zh_cn\n");
	printf("About | about -about the system\n");
	printf("Apps | apps -install and run apps\n");
	printf("Cls | cls -clean output\n");
	printf("Cmd | cmd -go to Windows CMD\n");
	
	printf("!Log | log <string:opt> -logout or re_login,opt can be:re,out\n");
	printf("		-remember to keep space!\n");
	printf("!View | view <string:name|path> -view a file\n");
	                               
	printf("\n\n* means that could used before login\nIf you need to enter a compound command (for example, a command that contains spaces), please add ! before the command\nPress Any Key To Continue!\n");
	getchar();getchar();
}
void getxy_hind();
void Start_Behind(){
	thread Ti(getxy_hind);
	Ti.detach();
} 
void Pts_Path(){
	for(int i=0;i<Path.size();++i){
		if(Path[i]=='#'){
			break;
		}else if(Path[i]=='/'){
			printf("/"); 
		}else{
			printf("%c",Path[i]);	
		}
	}
}
void RunEditer(){
	string name="Tobby Text Editer.exe";
	if(isFileExists_fopen(name)){
		system(Name_Editer.c_str());
		system("RunEditer.bat");
	}else{
		system("cls");
		printf("Error:Main->Editer was not found.");
		printf("\nPleace Restart or Download on Tobby Server.\n");
		getchar();
		getchar();
		login();
	}
}
void RunCalcer(){
	string name="Tobby Calcer.exe";
	if(isFileExists_fopen(name)){
		system(Name_Calcer.c_str());
		system("RunCalcer.bat");
	}else{
		system("cls");
		printf("Error:Main->Calcer was not found.");
		printf("\nPleace Restart or Download on Tobby Server.\n");
		getchar();
		getchar();
		login();
	}
}
void RunApps(){
	string name="Tobby App Management.exe";
	if(isFileExists_fopen(name)){
		system(Name_Management.c_str());
		system("RunManagement.bat");
	}else{
		system("cls");
		printf("Error:Main->Management was not found.");
		printf("\nPleace Restart or Download on Tobby Server.\n");
		getchar();
		getchar();
		login();
	}
}
void RunCls(){
	system("cls");
	printf("--------------------CLS--------------------\n");
}
void RunFmd(){
	string fot;
	cin>>fot;
	if(fot=="Log"||fot=="log"){
		string f2;
		cin>>f2;
		if(f2=="out"){
			login();
			printf("\n\n          -Logout succesfuly.\n");
		}else if(f2=="re"){
			relogin();
			printf("\n\n          -Relogin succesfuly.\n"); 
		}else{
			printf("No such <string:opt>:");
			cout<<f2;
			printf(" ,Run Faid!\n"); 
		}
	}else if(fot=="View"||fot=="view"){
		
		char f3[101];
		cin.getline(f3,101);
		string f2=f3;
		f2="more "+f2;
//		cout<<endl<<f2<<endl;
		system(f2.c_str());
	}else{
		printf("No such commond:");
		cout<<fot;
		printf(" ,Run Faid!\n"); 
	}
}
void Runmd(string opt){
	int len=opt.size();
	bool Run=false;
	if(len==1){
		if(opt=="!"){
			Run=true;
			RunFmd();
		}
	}else if(len==2){
		
	}else if(len==3){
		if(opt=="Cls"||opt=="cls"){
			Run=true;
			RunCls();
		}
		if(opt=="Cmd"||opt=="cmd"){
			Run=true;
			system("cmd");
		}
	}else if(len==4){
		if(opt=="help"||opt=="Help"){
			Run=true;
			RunHelp();
		}
		if(opt=="Edit"||opt=="edit"){
			Run=true;
			RunEditer();
		}
		if(opt=="Calc"||opt=="calc"){
			Run=true;
			RunCalcer();
			puts(""); 
		}
		if(opt=="Exit"||opt=="exit"){
			Run=true;
			_Exit();
		}
		if(opt=="Apps"||opt=="apps"){
			Run=true;
			RunApps();
		}
	}else if(len==5){
		if(opt=="About"||opt=="about"){
			Run=true;
			_About();
		}
	}else{
		
	}
	if(!Run){
		printf("\nCommond Error!\n");
	}
} 
void menu(){
	Pts_Path();
	printf(">");
	string opt;
	cin>>opt;
	Runmd(opt);
}
void gomain(){
	system("cls");
	printf("---------TobbySystem---------\n");
	while(1){
		menu();	
	}
}

void login(){
	Sleep(450);
	system("cls");
	COORD info = GetLargestConsoleWindowSize(GetStdHandle(STD_OUTPUT_HANDLE));
	Tx=info.X;
	Ty=info.Y;
	printf("---------TobbySystem Login---------\n");
	printf("		Version:%.2lf\n",Version);
	printf("		Type:"); 
	cout<<_Type;
	puts("");
	printf("		Date:"); 
	cout<<_Date;
	puts("");
	printf("		Window height:%d\n		Window width:%d\n",Tx,Ty);
	printf("\n\n\n");
	printf("%8cPress Enter to continue,F1 for help,F2 to start behinder,Esc to exit\n",' ');
	int ch; 
	while (1){
        if (_kbhit()){//如果有按键按下，则_kbhit()函数返回真
            ch = _getch();//使用_getch()函数获取按下的键值
            break; 
		}
    }
	if(ch == 13){//Enter
		system("cls");
		printf("\n\n          Login          \n\n          Enter Password(defult:123456):");
		string psw;
		cin>>psw;
		if(psw==PassWord){
			gomain();
		}else{
			printf("\n          Password Error!       \n          Enter Again:");
			cin>>psw;
			if(psw==PassWord){
				gomain();
			}else{
				printf("\n\n          Error!");
				login();
			}
		}
	}else if(ch == 59){
		system("cls");
		RunHelp();
		login();
	}else if(ch == 27){
		_Exit();
	}else if(ch == 60){
		if(Started){
			printf("\n\ncan't start Main>Behinder:had been started.\n");
		}else{
			printf("\n\nIt's a test Mod.It may hit your system.Choose:(Y for Start,N or Others for No)\n");
			char cos;
			cin>>cos;
			if(cos=='Y'){
				Started=true;
				Start_Behind();	
				login();
				printf("\n\nBehinder start succesfuly.\n");	
			}else{
				Started=false;
				login();
			}	
		}
	}else{
		Sleep(300);
		printf("Unknow Key Input: %d",ch);
		printf("\n");
		login(); 
	}
}
void getxy_hind(){
	
	while(1){
		COORD info = GetLargestConsoleWindowSize(GetStdHandle(STD_OUTPUT_HANDLE));
		Tx=info.X;
		Ty=info.Y; 
	}
	
	
}
int main(){
	
	system("@echo off");
	system("title TobbySystem");
	system("cls");
//	thread Ti(getxy_hind);
//	Ti.detach();
	login();
	
	return 0;
} 

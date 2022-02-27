/*
	TobbySystem Shell Runner
	附带于 TSM Beta 0.9
	2022/2/12
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
//#include "BigInteger.h" //大整数

using namespace std;

/* 常量区 */
const string PassWord = "123456";//默认密码
const string Name_Editer = "Tobby Text Editer.exe";
const string Name_Calcer = "Tobby Calcer.exe";
const string Name_Management = "Tobby App Management.exe";
//系统程序名称
const double Version = 0.9;
const string _Type = "Beta";
const string _Date = "2022/2/12";
//版本信息

uniform_int_distribution<unsigned long long> big_rand(0,999999999);
default_random_engine defult_rand;
default_random_engine time_rand(time(0));
/*
	高级随机数调用方式:big_rand(time_rand)%k 
*/ 
string Path="Main#";
int Tx,Ty;
bool Started=false; 

void Reset_Color(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
}

void _Exit(){
	system(" ");
	printf("------------Tobby System------------\n");
	printf("Good Bye~\n");
	getchar();
	getchar(); 
	exit(0); 
}

unsigned long long Get_Rand(bool f,unsigned p){//取随机数
	if(f==false){
		return big_rand(time_rand);//无模数 
	}else{
		return big_rand(time_rand)%p;//有模数 
	}
}

void Print_Rand_Color(string s){//打印随机颜色字符(不带转义)
	int len=s.size();
	for(int i=0;i<len;i++){
		int rd=int(big_rand(time_rand)%6);
		if(rd==1){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);//设置红色	
		}else if(rd==2){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);//设置绿色	
		}else if(rd==3){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);//设置蓝色
		}else if(rd==4){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);//设置红色和绿色相加
		}else if(rd==5){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);//设置红色和蓝色相加
		}else{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);//设置绿色和蓝色相加
		}
		cout<<s[i];
	}
	Reset_Color();
}

void _About(){//关于
	system(" ");
	Print_Rand_Color("------------Tobby System------------");
	Reset_Color();
	printf("\n");
	printf("Version:%.2lf\n",Version);
	printf("Type:"); 
	cout<<_Type;
	printf("\nAuthor:Tobby SQL\n");
	printf("Website:http://110.42.165.123\n");
	printf("Github:https://github.com/tobby3600/TobbySystem\n");
	printf("Update "); 
	cout<<_Date<<endl<<endl;
	getchar();
	getchar();
}
void login();
void gomain();

void relogin(){//重新登入
	system(" ");
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

void Rand_Color_Behind(){//全局随机颜色
	Sleep(100);
	printf("Rand Color Start!(Just for fun)\n");
	while(1){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|int(Get_Rand(false,0)));
//		Sleep(1);
	}
}

bool isFileExists_fopen(string& name) {//判断文件是否存在
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }   
}

struct Arrow{
	int x,y;
	Arrow () {}
	Arrow (int a,int b){
		x=a,y=b;
	}
};

string _MessageBox[51];
//string _U_MessageBox[51];//通知框
//string _C_MessageBox[51];//选择通知框
int num_MessageBox;
int MessageBox_InputX=1;
int MessageBox_InputY=1;//输入开始位置
int MessageBox_Text_Width=19;
int MessageBox_Text_Hight=3;
int MessageBox_Text_Max=MessageBox_Text_Width*MessageBox_Text_Hight;//最大输入字符
int MessageBox_DefultX=30;
int MessageBox_DefultY=9;
void add_Message_Box(){
	int p=0;
//	_U_MessageBox[++p]="+-----Attention-----+";
//	_U_MessageBox[++p]="|                   |";
//	_U_MessageBox[++p]="|                   |";
//	_U_MessageBox[++p]="|                   |";
//	_U_MessageBox[++p]="|-------------------|";
//	_U_MessageBox[++p]="|    OK(Input O)    |";
//	_U_MessageBox[++p]="+-------------------+";
//	num_MessageBox=p;
//	p=0;
//	_C_MessageBox[++p]="+-----Attention-----+";
//	_C_MessageBox[++p]="|                   |";
//	_C_MessageBox[++p]="|                   |";
//	_C_MessageBox[++p]="|                   |";
//	_C_MessageBox[++p]="|-------------------|";
//	_C_MessageBox[++p]="|  YES(Y) |  NO(O)  |";
//	_C_MessageBox[++p]="+-------------------+";
//	num_MessageBox=p;
//	p=0;
	_MessageBox[++p]="+-----Attention-----+";
	_MessageBox[++p]="|                   |";
	_MessageBox[++p]="|                   |";
	_MessageBox[++p]="|                   |";
	_MessageBox[++p]="|-------------------|";
	_MessageBox[++p]="|    OK(Input O)    |";
	_MessageBox[++p]="+-------------------+";
	num_MessageBox=p;
}

void HideCursor(int x) //光标隐藏
{
    CONSOLE_CURSOR_INFO cursor_info = {1, x}; //后边的0代表光标不可见
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

Arrow getWindowxy(){
	COORD info = GetLargestConsoleWindowSize(GetStdHandle(STD_OUTPUT_HANDLE));
	int Tx=info.X;
	int Ty=info.Y;
	Arrow tmp;
//	tmp.x=Tx;
//	tmp.y=Ty;
	tmp.x=100;
	tmp.y=23;
	return tmp;
}

bool Is_MessageBox=false;
void printMessageBox(string Text){
	if(Is_MessageBox) return;
	Arrow NOW=getxy();
	gotoxy(MessageBox_DefultX,MessageBox_DefultY);
//	printf("!num_MessageBox:%d\n",num_MessageBox);
	for(int i=0;i<=num_MessageBox;i++){
//		Sleep(100);
		int len=_MessageBox[i].size();
//		cout<<_MessageBox[i];
		Print_Rand_Color(_MessageBox[i]);
		Arrow now=getxy();
		gotoxy(now.x+len,now.y);
		for(int j=1;j<=len;j++){
			printf("\b");
		}
		gotoxy(MessageBox_DefultX,MessageBox_DefultY+i);
	}
	gotoxy(MessageBox_DefultX+MessageBox_InputX,MessageBox_DefultY+MessageBox_InputY);
	int cnt=0;
	for(int j=1;j<=MessageBox_Text_Hight;j++){
		for(int i=1;i<=MessageBox_Text_Width;i++){
//			Sleep(80);
			if(i==MessageBox_Text_Width){
//				gotoxy(MessageBox_DefultX+MessageBox_InputX+MessageBox_Text_Hight,MessageBox_DefultY+MessageBox_InputY);
				Arrow now=getxy();
				gotoxy(now.x+MessageBox_Text_Width,now.y);
				for(int k=1;k<=MessageBox_Text_Width;k++){
//					Sleep(20);
					printf("\b");
				}
				if(j!=MessageBox_Text_Hight)
					gotoxy(MessageBox_DefultX+MessageBox_InputX,MessageBox_DefultY+MessageBox_InputY+j);
			}else{
				if(cnt==Text.size()){
					cout<<" ";
				}else{
					cout<<Text[cnt];
					cnt++;
				}
			}
		}
	}
	Is_MessageBox=true;
//	while(1){
//		if(_kbhit()){
//			int ch=getch();
//			if(ch==79||ch==111){
//				Is_MessageBox=false;
//				break;
//			}
//		}
//	}
	Sleep(100);
	gotoxy(NOW.x,NOW.y);
}

void RunHelp(){//获取帮助
	Print_Rand_Color("---------------Tobby System Help-------------------");
	printf("\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
	cout<<"*";
	Reset_Color();
	printf(" Help | help -get help\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
	cout<<"*";
	Reset_Color();
	printf(" Exit | exit -exit the system\n");
	
	printf("Edit | edit -text editer,surport zh_cn\n");
	printf("Calc | calc -calc numbers,surport zh_cn\n");
	printf("About | about -about the system\n");
	printf("Apps | apps -install and run apps\n");
	printf("  |   -clean output\n");
	printf("Cmd | cmd -go to Windows CMD\n");
	
	printf("!Log | log <string:opt> -logout or re_login,opt can be:re,out\n");
	printf("		                -remember to keep space!\n");
	printf("!View | view <string:name|path> -view a file\n");
	printf("!Echo | echo <string:text> -echo a text\n");
	printf("!Msg | msg <string:text> -print a messagebox with text\n");
	        
	printf("# <string:text> -Used to annotate code, no practical use\n");        
	printf("\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
	cout<<"*";
	Reset_Color();		                       
	printf(" means that could used before login\nIf you need to enter a compound command (for example, a command that contains spaces), please add ! before the command\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
	printf("Press Any Key To Continue!\n");
	Reset_Color();
	getchar();getchar();
}
void getxy_hind();

void Start_Behind(){
	thread Ti(getxy_hind);
	Ti.detach();
} 

void Pts_Path(){//打印路径
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
		system(" ");
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
		system(" ");
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
		system(" ");
		printf("Error:Main->Management was not found.");
		printf("\nPleace Restart or Download on Tobby Server.\n");
		getchar();
		getchar();
		login();
	}
}

void RunCls(){
	system(" ");
	printf("-------------------- --------------------\n");
}

void RunFmd(){
	string fot;
	cin>>fot;
	if(fot=="Log"||fot=="log"){
		string f2;
		cin>>f2;
		if(f2=="out"){
			login();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
			printf("\n\n          -Logout succesfuly.\n");
			Reset_Color();
		}else if(f2=="re"){
			relogin();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
			printf("\n\n          -Relogin succesfuly.\n"); 
			Reset_Color();
		}else{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
			printf("No such <string:opt>:");
			cout<<f2;
			printf(" ,Run Faid!\n"); 
			Reset_Color();
		}
	}else if(fot=="View"||fot=="view"){
		
		char f3[101];
		cin.getline(f3,101);
		string f2=f3;
		f2="more "+f2;
//		cout<<endl<<f2<<endl;
		system(f2.c_str());
	}else if(fot=="Echo"||fot=="echo"){
		string Txt;
		cin>>Txt;
		cout<<Txt<<endl;
	}else if(fot=="Msg"||fot=="msg"){
		string Txt;
		cin>>Txt;
		if(Txt.size()>MessageBox_Text_Max){
			printf("Error:too long!\n");
			return;
		}
		printMessageBox(Txt);
		system(" ");
	}else{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
		printf("No such commond:");
		cout<<fot;
		printf(" ,Run Faid!\n");
		Reset_Color(); 
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
		if(opt=="#"){
			Run=true;
			string t;
			cin>>t;
		}
	}else if(len==2){
		
	}else if(len==3){
		if(opt==" "||opt==" "){
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
		if(opt=="-end-"){
			Run=true;
			printf("End Running...\n");
			system("PAUSE");
			system("PAUSE");
			system("PAUSE");
			system("PAUSE");
			fclose(stdin);
			exit(0);
		}
	}else{
		if(opt=="-start-"){
			Run=true;
			printf("Start Running...\n");
		}
		
	}
	if(!Run){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
		printf("\nCommond Error!%s:No such Command or file!\n",opt.c_str());
		Reset_Color();
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
	while(1){
		menu();	
	}
}

void psw_input(){
	system(" ");
	printf("Tobby System Shell Runner \n");
	gomain();
}

void login(){
	psw_input();
}

void getxy_hind(){
	
	while(1){
		COORD info = GetLargestConsoleWindowSize(GetStdHandle(STD_OUTPUT_HANDLE));
		Tx=info.X;
		Ty=info.Y; 
	}
	
	
}

void Load(){//加载系统
	
	add_Message_Box();
}

int main(int argc, char* argv[]){
	freopen("Demo.tbs","r",stdin);

	system("@echo off");
	system("title TobbySystemShellRunner");
	system("cls");
	system("del gmon.out");
//	thread Ti(getxy_hind);
//	Ti.detach();
	Load();
	login();
	fclose(stdin);
	return 0;
} 
/*
	TobbySystem
	Beta 0.9
	2022/2/12
*/

/*
	重大改动:
	-Beta 0.8删除了大整数支持.
*/

/*
	Update 2022/2/12
	-用户系统修复BUG
	-增加通知框支持
	-优化代码
	-重定义打开方式
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

const int User_System = 0;//系统
const int User_Root = 1;//管理员
const int User_VIP = 2;//高级用户
const int User_Normal = 3;//一般用户
const int User_Visiter = 4;//访客

struct User{//用户结构体
	string name;//用户名称
	string reg_time;//注册时间
	int type;//用户类型
	int des_num;//用户介绍行数
	string des[110];//用户介绍
	int password;//用户密码
}users[110];
int user_num;//用户数量

string now_user = "NULL";//当前用户

int User_Find(string name){//返回用户编号,不存在返回-1
	int p=-1;
	for(int i=1;i<=user_num;i++){
		if(users[i].name==name){
			p=i;
			break;
		}
	}
	return p;
}

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
	system("cls");
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
	system("cls");
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
	while(1){
		if(_kbhit()){
			int ch=getch();
			if(ch==79||ch==111){
				Is_MessageBox=false;
				break;
			}
		}
	}
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
	printf("Cls | cls -clean output\n");
	printf("Cmd | cmd -go to Windows CMD\n");
	printf("Um | um -user management\n");
	
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

void OpU(){
	printf("\n          User List:\n");
	for(int i=1;i<=user_num;i++){
		cout<<"          ["<<i<<"]"<<" "<<users[i].name<<" \n";
	}
	printf("          Please enter the ID of the user you want to operate:");
	int Tmp;
	scanf("%d",&Tmp);
	if(Tmp<1||Tmp>user_num){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
		printf("Error:No such user.\n");
		Reset_Color();
		return;
	}
	int tp=User_Find(now_user);
	int nt=users[tp].type;
	if(users[Tmp].type<=nt){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
		printf("You can't OPR this user.\n");
		Reset_Color();
		return;
	}
	printf("\n%10c[",' ');
	cout<<users[Tmp].name;
	printf("]\n%10cOld Describe:\n",' ');
	for(int i=1;i<=users[Tmp].des_num;i++){
		cout<<"          | "<<users[Tmp].des[i]<<" |\n";
	}
	printf("You want to:\n");
	printf("[1] Modify User Name\n");
	printf("[2] Modify User Describe\n");
	int opt;
	cin>>opt;
	if(opt==1){
		string ctm;
		printf("Input New User Name:");
		cin>>ctm;
		if(User_Find(ctm)!=-1){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
			printf("Sorry,this name is already in use.\n");
			Reset_Color();
			return;
		}
		users[Tmp].name=ctm;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
		printf("Modify succesfully.\n");
		Reset_Color();
	}
	if(opt==2){
		int ttm;
		printf("Input the number of lines for the description:");
		cin>>ttm;
		if(ttm<1||ttm>100){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
			printf("This number of lines is not legal.\n");
			Reset_Color();
			return;
		}
		users[Tmp].des_num=ttm;
		for(int i=1;i<=ttm;i++){
			string cct;
			printf("Input the Description line %d :",i);
			cin>>cct;
			users[Tmp].des[i]=cct;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
		printf("Modify succesfully.\n");
		Reset_Color();
	}
}

void CrtU(){
	printf("----Creat User----\n");
	User utm;
	string ctm;
	printf("Input user name:");
	cin>>ctm;
	utm.name=ctm;
	if(User_Find(ctm)!=-1){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
		printf("Sorry,this name is been used.\n");
		Reset_Color();
		return;
	}
	printf("Input Reginster Time(usually is the current time):");
	string cct;
	cin>>cct;
	utm.reg_time=cct;
	int ttm;
	printf("Input the number of lines for the description:");
	cin>>ttm;
	if(ttm<1||ttm>100){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
		printf("This number of lines is not legal.\n");
		Reset_Color();
		return;
	}
	utm.des_num=ttm;
	for(int i=1;i<=ttm;i++){
		string cctt;
		printf("Input the Description line %d (don't input space but use ^):",i);
		cin>>cctt;
		for(int i=0;i<cctt.size();i++){
			if(cctt[i]=='^'){
				cctt[i]=' ';
			}
		}
//		char chtt[110];
//		scanf("%[^\n]",&chtt);
//		for(int i=0;i<100;i++){
//			cctt[i]=chtt[i];
//		}
		utm.des[i]=cctt;
//		printf("\n");
	}
	printf("Choose the type of the user:\n");
	printf("[0] System(LOCKED)\n");
	printf("[1] Root(You must be root)\n");
	printf("[2] VIP(You must be root)\n");
	printf("[3] Normal(You must be root or VIP)\n");
	printf("[4] Visiter(LOCKED)\n");
	printf("Please Input the num of the type:");
	int typ;
	cin>>typ;
	if(typ<1||typ>3){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
		printf("This type isn't availabe.\n");
		Reset_Color();
		return;
	}
	int tp=User_Find(now_user);
	int nt=users[tp].type;
	if(typ==1){
		if(!nt||nt==1){
			utm.type=1;
		}else{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
			printf("You can't Choose This Type.\n");
			Reset_Color();
			return ;
		}
	}
	if(typ==2){
		if(!nt||nt==1){
			utm.type=2;
		}else{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
			printf("You can't Choose This Type.\n");
			Reset_Color();
			return;
		}
	}
	if(typ==3){
		if(!nt||nt==1||nt==2){
			utm.type=3;
		}else{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
			printf("You can't Choose This Type.\n");
			Reset_Color();
			return;
		}
	}
	printf("Input the password(only numbers):");
	int tpp;
	cin>>tpp;
	utm.password=tpp;
	user_num++;
	users[user_num]=utm;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
	printf("Creat User Succesfully.\n");
	Reset_Color();
}

void DlU(){
	int tp=User_Find(now_user);
	int nt=users[tp].type;
	if(!nt||nt==1){
		printf("\n          User List:\n");
		for(int i=1;i<=user_num;i++){
			cout<<"          ["<<i<<"]"<<" "<<users[i].name<<" \n";
		}
		printf("          Please enter the ID of the user you want to Delete:");
		int ttm;
		cin>>ttm;
		if(ttm<1||ttm>user_num){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
			printf("No such User.\n");
			Reset_Color();
			return;
		}
		if(user_num==1){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
			printf("No enough user.\n");
			Reset_Color();
			return;
		}
		if(nt<users[ttm].type){
			for(int i=ttm;i<user_num;i++){
				users[i]=users[i+1];
			}
			user_num--;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
			printf("Delete succesfully.\n");
			Reset_Color();
		}else{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
			printf("You can't Delete this user.\n");
			Reset_Color();
			return;
		}
	}else{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
		printf("You can't Do This.\n");
		Reset_Color();
	}
}

void RunUm(){
	system("cls");
	Print_Rand_Color("----------TobbySystem User Management----------");
	printf("\n");
	printf("[1] Operate User(Change Password,Change Describe,etc)\n");
	printf("[2] Creat User\n");
	printf("[3] Delete User\n");
	printf("Plese Input what you want to do:");
	int opt;
	cin>>opt;
	if(opt==1){
		OpU();
	}
	if(opt==2){
		CrtU();
	}
	if(opt==3){
		DlU();
	}
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
		system("cls");
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
		if(opt=="Um"||opt=="um"){
			Run=true;
			RunUm();
		}
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
	system("cls");
	printf("---------TobbySystem---------\n");
	printf("Welcome, ");
	cout<<now_user;
	printf(" !\n");
	string tttttm="Hello "+now_user+" !";
	printMessageBox(tttttm);
	system("cls");
	printf("---------TobbySystem---------\n");
	printf("Welcome, ");
	cout<<now_user;
	printf(" !\n");
	while(1){
		menu();	
	}
}

bool Get_In(int up){
	printf("\n%10c[",' ');
	cout<<users[up].name;
	printf("]\n%10cDescribe:\n",' ');
	for(int i=1;i<=users[up].des_num;i++){
		cout<<"          | "<<users[up].des[i]<<" |\n";
	}
	printf("\n\n          Enter Password:");
	int psw;
	cin>>psw;
	if(psw==users[up].password){
		now_user=users[up].name;
		gomain();
	}else{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
		printf("\n          Password Error!       ");
		Reset_Color();
		printf("\n          Enter Again:");
		cin>>psw;
		if(psw==users[up].password){
			now_user=users[up].name;
			gomain();
		}else{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
			printf("\n\n          Error!");
			Reset_Color();
			login();
		}
	}
}

void psw_input(){
	system("cls");
	/*string name="login.info";
	if(isFileExists_fopen(name)){
		FILE * fp;
   		fp=fopen("file.txt","r");
   		int f;
		fscanf_s(fp,"%d",&f);
		string _psw;
		fscanf_s(fp,"%s",_psw);
//		printf("!%c\n",_psw);
		string __psw=_psw;
		if(__psw==PassWord&&f==1){
			gomain();
		}else{
			if(f==0){
				printf("Auto Login Failed:User close auto login!\n");
			}else{
				printf("Auto Login Failed:Password Error!Cheak if Main->login.info is right!\n");
			}
		}
		fclose(fp);
	}else{
		printf("[Tips]Yon can creat a Auto Login File to Login Fastly.Put it in Main->login.info and write 1$enter$<your psw>!\n");
	}
	*/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
	printf("[Note]Now you can select a user and then login.Enjoy.\n");
	Reset_Color();
	printf("\n\n          Login        ");
	printf("\n          User List:\n");
	for(int i=1;i<=user_num;i++){
//		printf("          [%d] %c Re:%c \n",i,users[i].name.c_str(),users[i].reg_time);
		cout<<"          ["<<i<<"]"<<" "<<users[i].name<<" Re:"<<users[i].reg_time<<" \n";
	}
	printf("          Input User Number:");
	int Tmp;
	scanf("%d",&Tmp);
	if(Tmp<1||Tmp>user_num){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
		printf("Error:No such user.\n");
		Reset_Color();
		login();
	}
	Get_In(Tmp);
}

void login(){
	Sleep(450);
	system("cls");
	COORD info = GetLargestConsoleWindowSize(GetStdHandle(STD_OUTPUT_HANDLE));
	Tx=info.X;
	Ty=info.Y;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
//	printf("---------TobbySystem Login---------\n");
	Print_Rand_Color("---------TobbySystem Login---------");
	printf("\n");
	Reset_Color();
	printf("		Version:");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
	printf("%.2lf\n",Version);
	Reset_Color();
	printf("		Type:"); 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
	cout<<_Type;
	puts("");
	Reset_Color();	
	printf("		Date:"); 
	cout<<_Date;
	puts("");
	printf("		Window height:%d\n		Window width:%d\n",Tx,Ty);
	printf("\n\n");
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
//	cout<<"C";
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
//	cout<<"o";
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
//	cout<<"l";
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
//	cout<<"f";
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
//	cout<<"u";
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
//	cout<<"l";
	Reset_Color();
	Print_Rand_Color("User Management System");
	Print_Rand_Color(" Update!");
	Reset_Color();
	puts(""); 
	puts("\n"); 
//	printf("%8cPress Enter to continue,F1 for help,F2 to start behinder,Esc to exit,F3 to goto TobbySystemWindows,F4 to start Rand Color Behind(New!)\n",' ');
	
	printf("%8cPress ",' ');
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
	printf("Enter");
	Reset_Color();
	printf(" to continue,");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
	printf("F1");
	Reset_Color();
	printf(" for help,");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
	cout<<"F2";
	Reset_Color();
	cout<<" to start behinder,";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
	cout<<"Esc";
	Reset_Color();
	cout<<" to exit,";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
	cout<<"F3";
	Reset_Color();
	cout<<" to goto TobbySystemWindows,";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
	cout<<"F4";
	Reset_Color();
	cout<<" to start Rand Color Behind(New!)\n";
	
	int ch; 
	while (1){
        if (_kbhit()){//如果有按键按下，则_kbhit()函数返回真
            ch = _getch();//使用_getch()函数获取按下的键值
            break; 
		}
    }
	if(ch == 13){//Enter
		psw_input();
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
	}else if(ch == 61){
		printMessageBox("Windows is Loading...");
		system("WindowsLoader.bat");
	}else if(ch==62){
		thread Tt(Rand_Color_Behind);
		Tt.detach();
		login();
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

void Load(){//加载系统
	
	user_num++;
	users[user_num].name = "Admin";
	users[user_num].type = User_Root;
	users[user_num].reg_time = "2022/1/31";
	users[user_num].password = 123456;
	users[user_num].des[++users[user_num].des_num] = "System Built-In Account";
	users[user_num].des[++users[user_num].des_num] = "Default Password:123456";
	user_num++;
	users[user_num].name = "Tobby";
	users[user_num].type = User_System;
	users[user_num].reg_time = "1949/10/01";
	users[user_num].password = 123567;
	users[user_num].des[++users[user_num].des_num] = "System Built-In Account";
	users[user_num].des[++users[user_num].des_num] = "The Creater of this System";
	users[user_num].des[++users[user_num].des_num] = "Happy New Year";
	user_num++;
	users[user_num].name = "Guest";
	users[user_num].type = User_Visiter;
	users[user_num].reg_time = "2022/1/31";
	users[user_num].password = 123456;
	users[user_num].des[++users[user_num].des_num] = "System Built-In Account";
	users[user_num].des[++users[user_num].des_num] = "The Guest";
	users[user_num].des[++users[user_num].des_num] = "PassWord:123456";
	
	add_Message_Box();
}

int main(int argc, char* argv[]){
	
	/*
	string name="Locker.exe";
	if(isFileExists_fopen(name)){
		system("Locker.exe");
		system("cls");	
	}else{
		printf("Main->Locker was not found!\n");
		printf("System Can't run.Please download it from:https://github.com/tobby3600/TobbySystem \n");
		return 0;//反作弊装置 
	}
	*/
	 
	
	system("@echo off");
	system("title TobbySystem");
	system("cls");
	system("del gmon.out");
//	thread Ti(getxy_hind);
//	Ti.detach();
	Load();
	login();
	
	return 0;
} 

#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

struct APPS{
	string name;
	double version;
	string path;
	string des[51];
	int des_num;
}apps[10001];
int app_num;

uniform_int_distribution<unsigned long long> big_rand(0,999999999);
default_random_engine defult_rand;
default_random_engine time_rand(time(0));
/*
	高级随机数调用方式:big_rand(time_rand)%k 
*/ 

void Reset_Color(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
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

bool isFileExists_fopen(string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }   
}

void ADD_Defult_APP(){
	apps[++app_num].name="Queue Program";
	apps[app_num].version=1.5;
	apps[app_num].path="RunQueue.bat";
	apps[app_num].des_num=2;
	apps[app_num].des[1]="-队列程序,模拟一个队列的操作";
	apps[app_num].des[2]="-样例应用";
	
	apps[++app_num].name="Lynx browser";
	apps[app_num].version=1.0;
	apps[app_num].path="RunLynx.bat";
	apps[app_num].des_num=3;
	apps[app_num].des[1]="-第三方浏览器";
	apps[app_num].des[2]="-目前唯一还可用的纯文字浏览器";
	apps[app_num].des[3]="-附带GUI,但不建议使用"; 
	
	apps[++app_num].name="Tobby BigInteger Calcer";
	apps[app_num].version=1.0;
	apps[app_num].path="RunBigIntCalc.bat";
	apps[app_num].des_num=3;
	apps[app_num].des[1]="-Tobby Calcer附属组件";
	apps[app_num].des[2]="-可计算超超超大整数";
	apps[app_num].des[3]="-支持负数"; 
	
}

void Read_APPs(){
	printf("App配置读取失败!自动使用默认配置!\n");
	ADD_Defult_APP();
	/*
	string Name="apps.info";
	if(!isFileExists_fopen(Name)){
		printf("无法读取App配置文件,自动使用默认配置!\n");
		ADD_Defult_APP();
		return;
	}
	freopen("apps.info","r",stdin);
	int num;
	cin>>num;
	for(int i=1;i<=num;i++){
		app_num++;
		string name;
		double version;
		string path;
		int des_num;
		string des[1001];
		getline(cin,name);
//		cout<<name<<endl; 
		apps[app_num].name=name;
		cin>>version;
//		cout<<version<<endl;
		apps[app_num].version=version;
		getline(cin,path);
//		cout<<path<<endl;
		apps[app_num].path=path;
		cin>>des_num;
//		cout<<des_num<<endl;
		apps[app_num].des_num=des_num;
		for(int j=1;j<=des_num;j++){
			getline(cin,des[j]);
//			cout<<des[j]<<endl;
			apps[app_num].des[j]=des[j];
		} 
	}
	fclose(stdin);
	printf("App读取成功!\n");
	return;*/
}

void PrintApps(){
	printf("\n应用列表:\n");
	for(int i=1;i<=app_num;++i){
		printf("%d.",i);
		cout<<apps[i].name<<endl;
		printf("版本:%.2lf\n",apps[i].version);
		printf("描述:\n");
		for(int j=1;j<=apps[i].des_num;++j){
			cout<<apps[i].des[j]<<endl;
		}
		printf("\n");
	}
}

int main() {
//	ADD_Defult_APP(); 
	Read_APPs();
	printf("\n");
	Print_Rand_Color("-----Tobby App Management Beta 0.4----");
	printf("\n");
	printf("选择操作:\n");
	printf("1.安装应用(制作中)\n");
	printf("2.打开应用\n");
	printf("3.返回Main\n");
	Sleep(500);
	int n=2;
	cin>>n; 
	if(n==1){
			printf("功能制作中...\n");	
	}else if(n==2){
		PrintApps();
		printf("请选择:");
		int opt;
		cin>>opt;
		if(opt>=0&&opt<=app_num){
			printf("\n-----Start Run App-----\n");
			system(apps[opt].path.c_str()); 
			printf("\n-----End Run App-----\n");
		}else{
			printf("\nApp未找到\n");
		}
	}else if(n==3){
		return 0;
	}else{
		printf("Unknown Command:%d\n",n); 
	}	
	return 0;
}

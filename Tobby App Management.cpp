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
	�߼���������÷�ʽ:big_rand(time_rand)%k 
*/ 

void Reset_Color(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
}

void Print_Rand_Color(string s){//��ӡ�����ɫ�ַ�(����ת��)
	int len=s.size();
	for(int i=0;i<len;i++){
		int rd=int(big_rand(time_rand)%6);
		if(rd==1){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);//���ú�ɫ	
		}else if(rd==2){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);//������ɫ	
		}else if(rd==3){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);//������ɫ
		}else if(rd==4){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);//���ú�ɫ����ɫ���
		}else if(rd==5){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);//���ú�ɫ����ɫ���
		}else{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);//������ɫ����ɫ���
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
	apps[app_num].des[1]="-���г���,ģ��һ�����еĲ���";
	apps[app_num].des[2]="-����Ӧ��";
	
	apps[++app_num].name="Lynx browser";
	apps[app_num].version=1.0;
	apps[app_num].path="RunLynx.bat";
	apps[app_num].des_num=3;
	apps[app_num].des[1]="-�����������";
	apps[app_num].des[2]="-ĿǰΨһ�����õĴ����������";
	apps[app_num].des[3]="-����GUI,��������ʹ��"; 
	
	apps[++app_num].name="Tobby BigInteger Calcer";
	apps[app_num].version=1.0;
	apps[app_num].path="RunBigIntCalc.bat";
	apps[app_num].des_num=3;
	apps[app_num].des[1]="-Tobby Calcer�������";
	apps[app_num].des[2]="-�ɼ��㳬����������";
	apps[app_num].des[3]="-֧�ָ���"; 
	
}

void Read_APPs(){
	printf("App���ö�ȡʧ��!�Զ�ʹ��Ĭ������!\n");
	ADD_Defult_APP();
	/*
	string Name="apps.info";
	if(!isFileExists_fopen(Name)){
		printf("�޷���ȡApp�����ļ�,�Զ�ʹ��Ĭ������!\n");
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
	printf("App��ȡ�ɹ�!\n");
	return;*/
}

void PrintApps(){
	printf("\nӦ���б�:\n");
	for(int i=1;i<=app_num;++i){
		printf("%d.",i);
		cout<<apps[i].name<<endl;
		printf("�汾:%.2lf\n",apps[i].version);
		printf("����:\n");
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
	printf("ѡ�����:\n");
	printf("1.��װӦ��(������)\n");
	printf("2.��Ӧ��\n");
	printf("3.����Main\n");
	Sleep(500);
	int n=2;
	cin>>n; 
	if(n==1){
			printf("����������...\n");	
	}else if(n==2){
		PrintApps();
		printf("��ѡ��:");
		int opt;
		cin>>opt;
		if(opt>=0&&opt<=app_num){
			printf("\n-----Start Run App-----\n");
			system(apps[opt].path.c_str()); 
			printf("\n-----End Run App-----\n");
		}else{
			printf("\nAppδ�ҵ�\n");
		}
	}else if(n==3){
		return 0;
	}else{
		printf("Unknown Command:%d\n",n); 
	}	
	return 0;
}

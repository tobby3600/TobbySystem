#include<bits/stdc++.h>

using namespace std;

struct APPS{
	string name;
	double version;
	string path;
	string des[51];
	int des_num;
}apps[10001];
int app_num;

void ADD_Defult_APP(){
	apps[++app_num].name="Queue Program";
	apps[app_num].version=1.5;
	apps[app_num].path="RunQueue.bat";
	apps[app_num].des_num=2;
	apps[app_num].des[1]="-���г���,ģ��һ�����еĲ���";
	apps[app_num].des[2]="-����Ӧ��";
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
	ADD_Defult_APP(); 
	printf("\n-----Tobby App Management Beta 0.2----\n");
	printf("ѡ�����:\n");
	printf("1.��װӦ��(������)\n");
	printf("2.��Ӧ��\n");
	printf("3.����Main\n");
	int n;
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
	}
	return 0;
}
/*
	TobbySystem �������� 
*/
#include<bits/stdc++.h>

using namespace std;
bool isFileExists_fopen(string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }   
}
int main(){
	string name="����TobbySQL�Ͻ���Ϯ";
	if(isFileExists_fopen(name)){
		printf("��ʹ�õ����������!\n"); 
		return 0;
	}
	while(1){
		system("cls");
		printf("�����Գ�Ϯ������,���ο�����ע������,������ԭʼ����!\n");
		printf("��ַ:https://github.com/tobby3600/TobbySystem\n");
		system("PAUSE");
	}
	return 0;
}

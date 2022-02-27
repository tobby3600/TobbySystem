/*
	TobbySystem 防盗程序 
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
	string name="作者TobbySQL严禁抄袭";
	if(isFileExists_fopen(name)){
		printf("您使用的是正版软件!\n"); 
		return 0;
	}
	while(1){
		system("cls");
		printf("请勿尝试抄袭本程序,二次开发请注明出处,请下载原始程序!\n");
		printf("地址:https://github.com/tobby3600/TobbySystem\n");
		system("PAUSE");
	}
	return 0;
}

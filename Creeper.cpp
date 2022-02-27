#include <bits/stdc++.h>
#include <chrono>
#include <windows.h> //system()
#include <conio.h> //_kbhit(),getch()

using namespace std;
int main() {
	string m[100];
	int p=0;
	m[p++]="00000000000000000000000";
	m[p++]="00000111000000011100000";
	m[p++]="00000111000000011100000";
	m[p++]="00000111000000011100000";
	m[p++]="00000000011111000000000";
	m[p++]="00000000011111000000000";
	m[p++]="000000111111111110000000";
	m[p++]="000000111111111110000000";
	m[p++]="000000111100011110000000";
	m[p++]="00000000000000000000000";
	m[p++]="00000000000000000000000";
	ios::sync_with_stdio(false);
//	freopen("Creeper.txt","r",stdin);
//	string s;
//	while(cin>>s){
//		for(int i=0;i<s.size();i++){
//			if(s[i]=='0'){
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
//				cout<<"O";
//			}
//			if(s[i]=='1'){
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);
//				cout<<"O";
//			}
//		}
//		printf("\n");
//	}
	for(int i=1;i<=11;i++){
		string s=m[i-1];
//		cout<<"!"<<s<<endl;
		for(int j=1;j<=s.size();j++){
			if(s[j-1]=='0'){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
				cout<<"O";
			}
			if(s[j-1]=='1'){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);
				cout<<"X";
			}
		}
		printf("\n");
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);
	fclose(stdin);
	return 0;
}
#include<bits/stdc++.h>
#include <chrono>
#include <windows.h> //system()
#include <conio.h> //_kbhit(),getch()
#include "BigInteger.h" //大整数

using namespace std;

uniform_int_distribution<unsigned long long> big_rand(0,999999999);
default_random_engine defult_rand;
default_random_engine time_rand(time(0));

unsigned long long Get_Rand(bool f,unsigned p){
	if(f==false){
		return big_rand(time_rand);//无模数 
	}else{
		return big_rand(time_rand)%p;//有模数 
	}
}

void Reset_Color(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
}

int main() {
	Reset_Color();
	ios::sync_with_stdio(false);
	printf("Tobby Calcer>Tools>BigInteger Calc\n");
	printf("随机生成的例子:\n");
	if(Get_Rand(false,0)%2==0){
		printf("-");
	}
	for(int i=1;i<=Get_Rand(true,350);i++){
		printf("%d",Get_Rand(true,15));
	}
	printf("\n");
	if(Get_Rand(false,0)%2==0){
		printf("-");
	}
	for(int i=1;i<=Get_Rand(true,350);i++){
		printf("%d",Get_Rand(true,15));
	}
	printf("\n");
	printf("请输入两个巨大整数(最大");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_RED|FOREGROUND_BLUE);
	printf("10^8");
	Reset_Color();
	puts("位数,支持负数),自动输出+,-,*,/,%,abs结果(空格隔开)");
	BigInteger a,b;
	cin>>a>>b;
	cout<<a;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);cout<<" + ";Reset_Color();cout<<b<<" = "<<a+b<<endl;
	cout<<a<<" - "<<b<<" = "<<a-b<<endl;
	cout<<a<<" * "<<b<<" = "<<a*b<<endl;
	cout<<a<<" / "<<b<<" = "<<a/b<<endl;
	cout<<a<<" % "<<b<<" = "<<a%b<<endl;
	cout<<"|"<<a<<"|"<<" = "<<a.abs()<<endl;
	cout<<"|"<<b<<"|"<<" = "<<b.abs()<<endl;
	system("PAUSE");
	return 0;
}
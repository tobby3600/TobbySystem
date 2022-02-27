#include<bits/stdc++.h>
#include<windows.h>

using namespace std;
int main(){
	printf("Tobby System Auto Update&Installer:\n");
	system("md TobbySystem");
	system("cd TobbySystem");
	system("wget http://110.42.165.123/TobbySystem.zip");
	system("7z x -tzip -y TobbySystem.zip");
	printf("Del Zip?If no,exit please.\n");
	system("PAUSE");
	system("del TobbySystem.zip");
	return 0;
}

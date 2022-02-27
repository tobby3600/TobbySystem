#include<bits/stdc++.h>
#include<windows.h>

using namespace std;
int main(){
	printf("Tobby System Downloader:\n");
	system("md TobbySystem");
	system("cd TobbySystem");
	printf("");
	system("axel -n 10 http://110.42.165.123/TobbySystem.zip");
//	system("wget http://110.42.165.123/TobbySystem.zip");
	system("7z x -tzip -y TobbySystem.zip");
	system("del TobbySystem.zip");
	printf("Download Succesfully.\n");
	const string name="Tobby System Main.exe";
	system(name.c_str()); 
	system("PAUSE");
	return 0;
}

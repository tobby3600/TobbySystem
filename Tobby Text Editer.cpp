#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h> //getch();
#include <string>
#include <cstring> //dev����ʱ����memset��Ҫ���ϸ�ͷ�ļ�.
using namespace std;
//int maxn = 20;
//int flag=0;//�����ĵ���־��0��δ���棬1�Ǳ���
int maxn;

class layout
{ //�нṹ��
public:
	int line = 1;
	string row = "";
};

layout lay;
string filename;
string s;

/*void openfile(){
    cout<<"�������ļ�:"<<endl;
    cin>>filename;
    ofstream outfile;
    outfile.open(filename.c_str(),ios::app);
}*/

void menu();
void mainkmp(string mains);

void statistics()
{
	cout << endl
			 << endl;
	cout << "�ļ�����" << filename << endl;
	for (int l = 0; l < lay.line; l++)
	{
		cout << "��" << l + 1 << "���ַ�����" << (int)lay.row[l] << endl;
	}
}

void display()
{ //��ʾ��ǰ�ĵ��ַ���Ϣ
	cout << "�ļ�����" << filename << endl;
	layout temp;
	int n = 0;
	int i = 0;
	while (s[i] != '\0')
	{
		if (n == maxn)
		{
			if (s[i] == '\n')
			{
				temp.line++;
				temp.row = temp.row + char(n);
				cout << s[i];
				n = 0;
			}
			else
			{
				temp.line++;
				temp.row = temp.row + char(n);
				cout << endl
						 << s[i];
				n = 1;
			}
		}
		else
		{
			if (s[i] == '\n')
			{
				temp.line++;
				temp.row = temp.row + char(n);
				cout << s[i];
				n = 0;
			}
			else
			{
				cout << s[i];
				n++;
			}
		}
		i++;
	}
	temp.row = temp.row + char(n);
	lay = temp;
}

void displayre(string temp)
{
	//cout << "������Ҫ�滻��ȥ�����ݣ��ԡ�esc��������" << endl;
	int n = 0;
	int i = 0;
	while (temp[i] != '\0')
	{
		if (n == maxn)
		{
			if (temp[i] == '\n')
			{
				cout << temp[i];
				n = 0;
			}
			else
			{
				cout << endl
						 << temp[i];
				n = 1;
			}
		}
		else
		{
			if (temp[i] == '\n')
			{
				cout << temp[i];
				n = 0;
			}
			else
			{
				cout << temp[i];
				n++;
			}
		}
		i++;
	}
}

int cal(int x, int y)
{
	int i = 0;
	for (int l = 0; l < x - 1; l++)
	{
		i = i + (int)lay.row[l];
	}
	i = i + y;
	for (int a = 0; a < i; a++)
	{
		if (s[a] == '\n')
			i++;
	}
	return i;
}

void create()
{
	string name;
	cout << "���봴���ļ�������" << endl;
	cin >> name;
	//ofstream outfile(name);
	ofstream outfile(name.c_str());
	if (outfile.is_open())
	{
		cout << "New file created!" << endl;
		filename = name;
	}
	cout << endl;
	outfile.close();
}

void read()
{
	cout << "������Ҫ������ļ���" << endl;
	string name;
	cin >> name;
	filename = name;
	//ifstream infile(name);
	ifstream infile(name.c_str());
	string reads;
	char c;
	if (!infile.is_open())
	{
		system("cls");
		cout << "��ȡ�ļ�ʧ��!��ʧ�ܻ��޴��ļ�" << endl;
	}
	else
	{
		while ((c = infile.get()) != EOF)
			reads = reads + c;
		s = reads;
		system("cls");
		cout << name << "��ȡ���" << endl;
		cout << endl;
		infile.close();
		cout << "�ļ����ݣ�" << endl;
		display();
	}
}

void write()
{
	if (filename[0])
	{
		//string name = filename;
		ofstream outfile(filename.c_str());
		if (outfile.is_open())
		{
			cout << s;
			outfile << s;
			cout << filename << "�ļ�д�����" << endl;
		}
		else if (!outfile.is_open())
		{
			cout << "���ļ�д��ʧ��!��ʧ�ܻ��޴��ļ�" << endl;
		}
		outfile.close();
		cout << endl;
	}
	else
	{
		cout << "����δ���κ�һ���ļ���" << endl;
	}
}

void read1()
{
	if (filename[0])
	{
		//if(flag==0){
		cout << "�����ļ�δ���棬�Ƿ񱣴沢�رգ�����ر�/������ر�/ȡ����Y/N/C��" << endl;
		char c;
		cin >> c;
		if (c == 'Y')
		{
			write(); //149
			read();
		}
		else if (c == 'N')
		{
			read(); //124
		}
		else if (c == 'C')
		{
			menu();
		}
		else
		{
			read1();
		}
		//}
	}
	else
	{
		read();
	}
}

void input()
{
	cout << "������Ҫд����ļ���" << endl;
	string name;
	cin >> name;
	filename = name;
	//flag=0;
	system("cls");
	//cout << "�ļ�����" << filename << endl;
	display(); //31
	char c = '0';
	int n = 0;
	if (lay.row.length() == 0)
		n = 0;
	else
		n = (int)lay.row[lay.row.length() - 1];
	while (1)
	{
		c = _getch();
		if (c != 27)
		{
			if (c != 13 && c != 8 && c != (-32))
			{
				if (n == maxn)
				{
					cout << endl
							 << c;
					n = 1;
				}
				else
				{
					cout << c;
					n++;
				}
				s = s + c;
			}
			else if (c == 13)
			{
				cout << endl;
				n = 0;
				s = s + "\n";
			}
			else if (c == 8)
			{
				s = s.substr(0, s.length() - 1);
				system("cls");
				display();
				n = (int)lay.row[lay.row.length() - 1];
			}
		}
		else
			break;
	}
	system("cls");
	display();
	cout << "�Ƿ񱣴�ղŵı༭?��/��(Y/N)" << endl;
	char ch;
	cin >> ch;
	if (ch == 'Y')
	{

		//flag=1;
		write();
	}
}

void insert()
{
	if (filename[0])
	{
		int x = 1, y = 1;
		int i = 0;
		cout << "������Ҫ�����λ�����꣺" << endl;
		cin >> x >> y;
		if (lay.line < x)
		{
			cout << "���ĵ�û����ô����" << endl;
		}
		else if ((int)lay.row[x - 1] < y)
		{
			cout << "����û�и�����" << endl;
		}
		else
		{
			char c;
			i = cal(x, y);
			system("cls");
			cout << "�ļ���" << filename << "���룺" << endl;
			display();
			while (1)
			{
				c = _getch();
				if (c != 27)
				{
					if (c != 13 && c != 8 && c != (-32))
					{
						s = s.substr(0, i) + c + s.substr(i, s.length() - 1);
						i++;
						system("cls");
						cout << "�ļ���" << filename << "���룺" << endl;
						display();
					}
					else if (c == 13)
					{
						s = s.substr(0, i) + '\n' + s.substr(i, s.length() - 1);
						i++;
						system("cls");
						cout << "�ļ���" << filename << "���룺" << endl;
						display();
					}
					else if (c == 8)
					{
						if (i >= 0)
						{
							s = s.substr(0, i - 1) + s.substr(i, s.length() - 1);
							i--;
							system("cls");
							cout << "�ļ���" << filename << "���룺" << endl;
							display();
						}
					}
				}
				else
					break;
			}
		}
	}
	else
	{
		cout << "����δ���κ�һ���ļ���Ҫ���ļ���?��/��(Y/N)" << endl;
		char ch;
		cin >> ch;
		if (ch == 'Y')
		{
			read1();
			insert();
		}
	}
}

void move()
{
	if (filename[0])
	{
		int x1, y1, x2, y2, x3, y3;
		int i1, i2, i3;
		i1 = i2 = i3 = 0;
		int a1, b1, c1, a2, b2, c2, a3, b3, c3;
		a1 = b1 = c1 = a2 = b2 = c2 = a3 = b3 = c3 = 0;
		cout << "�����뿪ʼ���꣺" << endl;
		do
		{
			if (a1 == 1)
				cout << "���ĵ�û����ô����" << endl;
			else if (b1 == 1)
				cout << "����û�и�����" << endl;
			cin >> x1 >> y1;
			a1 = b1 = c1 = 0;
			if (lay.line < x1)
				a1 = 1;
			else if ((int)lay.row[x1 - 1] < y1)
				b1 = 1;
			else
				i1 = cal(x1, y1);
		} while (a1 != 0 || b1 != 0 || c1 != 0);
		cout << "������������꣺" << endl;
		do
		{
			if (a2 == 1)
				cout << "���ĵ�û����ô����" << endl;
			else if (b2 == 1)
				cout << "����û�и�����" << endl;
			else if (c2 == 1)
				cout << "�����겻�ڿ�ʼ����֮��" << endl;
			cin >> x2 >> y2;
			a2 = b2 = c2 = 0;
			if (lay.line < x2)
				a2 = 1;
			else if ((int)lay.row[x2 - 1] < y2)
				b2 = 1;
			else
			{
				i2 = cal(x2, y2);
				if (i2 <= i1)
					c2 = 1;
			}
		} while (a2 != 0 || b2 != 0 || c2 != 0);
		cout << "������Ŀ�����꣺" << endl;
		do
		{
			if (a3 == 1)
				cout << "���ĵ�û����ô����" << endl;
			else if (b3 == 1)
				cout << "����û�и�����" << endl;
			else if (c3 == 1)
				cout << "�����겻Ӧ���ڿ�ʼ�ͽ�������֮��" << endl;
			cin >> x3 >> y3;
			a3 = b3 = c3 = 0;
			if (lay.line < x3)
				a3 = 1;
			else if ((int)lay.row[x3 - 1] < y3)
				b3 = 1;
			else
			{
				i3 = cal(x3, y3);
				if (i3 > i1 && i3 <= i2)
					c3 = 1;
			}
		} while (a3 != 0 || b3 != 0 || c3 != 0);
		string temp = s.substr(i1, i2 - i1);
		if (i3 < i1)
		{
			int cha = i2 - i1;
			i1 = i1 + cha;
			i2 = i2 + cha;
		}
		s = s.substr(0, i3) + temp + s.substr(i3, s.length() - 1);
		s = s.substr(0, i1) + s.substr(i2, s.length() - 1 + (i2 - i1));
		cout << "�ƶ����:" << endl;
		display();
	}
	else
	{
		cout << "����δ���κ�һ���ļ���Ҫ���ļ���?��/��(Y/N)" << endl;
		char ch;
		cin >> ch;
		if (ch == 'Y')
		{
			read1();
			move();
		}
	}
}

void replace()
{
	if (filename[0])
	{
		int x1, y1, x2, y2, i1, i2;
		i1 = i2 = 0;
		int a1, b1, c1, a2, b2, c2;
		a1 = b1 = c1 = a2 = b2 = c2 = 0;
		cout << "�����뿪ʼ���꣺" << endl;
		do
		{
			if (a1 == 1)
				cout << "���ĵ�û����ô����" << endl;
			else if (b1 == 1)
				cout << "����û�и�����" << endl;
			cin >> x1 >> y1;
			a1 = b1 = c1 = 0;
			if (lay.line < x1)
				a1 = 1;
			else if ((int)lay.row[x1 - 1] < y1)
				b1 = 1;
			else
				i1 = cal(x1, y1);
		} while (a1 != 0 || b1 != 0 || c1 != 0);
		cout << "������������꣺" << endl;
		do
		{
			if (a2 == 1)
				cout << "���ĵ�û����ô����" << endl;
			else if (b2 == 1)
				cout << "����û�и�����" << endl;
			else if (c2 == 1)
				cout << "�����겻�ڿ�ʼ����֮��" << endl;
			cin >> x2 >> y2;
			a2 = b2 = c2 = 0;
			if (lay.line < x2)
				a2 = 1;
			else if ((int)lay.row[x2 - 1] < y2)
				b2 = 1;
			else
			{
				i2 = cal(x2, y2);
				if (i2 <= i1)
					c2 = 1;
			}
		} while (a2 != 0 || b2 != 0 || c2 != 0);
		system("cls");
		cout << "������Ҫ�滻��ȥ�����ݣ��ԡ�esc��������" << endl;
		string temp;
		char c;
		while (1)
		{
			c = _getch();
			if (c != 27)
			{
				if (c != 13 && c != 8 && c != (-32))
				{
					temp = temp + c;
					system("cls");
					displayre(temp);
				}
				else if (c == 13)
				{
					temp = temp + "\n";
					system("cls");
					displayre(temp);
				}
				else if (c == 8)
				{
					temp = temp.substr(0, temp.length() - 1);
					system("cls");
					displayre(temp);
				}
			}
			else
				break;
		}
		s = s.substr(0, i1) + temp + s.substr(i2, s.length() - 1);
		system("cls");
		display();
	}
	else
	{
		cout << "����δ���κ�һ���ļ���Ҫ���ļ���?��/��(Y/N)" << endl;
		char ch;
		cin >> ch;
		if (ch == 'Y')
		{
			read1();
			replace();
		}
	}
}

void deletefile()
{
	if (filename[0])
	{
		cout << "��ȷ��Ҫɾ�����ĵ����������𣿸ò������޷���������1/0��" << endl;
		int i = 0;
		cin >> i;
		if (i == 1)
		{
			cout << "ɾ��������ʼִ��" << endl;
			string temp;
			s = temp;
			write();
		}
		else if (i == 0)
		{
			cout << "ɾ������ȡ��" << endl
					 << endl;
		}
	}
	else
	{
		cout << "����δ���κ�һ���ļ���" << endl;
	}
}

void option()
{
	cout << endl
			 << endl;
	cout << "1 �������ĵ���" << endl;								//create 110
	cout << "2 ���򿪲���ȡ�ĵ���" << endl;					//read1 168
	cout << "3 ����ʼ���룺" << endl;								//input 192  ĩβ׷��
	cout << "4 ��д���ĵ���" << endl;								//write 149  ����input��׷�ӵ�����
	cout << "5 ��ͳ����Ϣ��" << endl;								//statistics 23
	cout << "6 �����룺" << endl;										//insert 233
	cout << "7 ���ƶ���" << endl;										//move 288
	cout << "8 ���滻��" << endl;										//replace 349
	cout << "9 ��ɾ���ļ����������ݣ�" << endl;			//deletefile 415
	cout << "10�����ң�" << endl;										//mainkmp 586
	cout << "11���رձ༭�����Զ����棩��" << endl; //write 149
	cout << "��ʾ�������������Ӧ������" << endl;
	cout << endl;
}

void menu()
{
	int i;
	option();
	cin >> i;
	if (i == 1)
	{
		system("cls");
		create();
		menu();
	}
	else if (i == 2)
	{
		system("cls");
		read1();
		menu();
	}
	else if (i == 3)
	{
		system("cls");
		input();
		menu();
	}
	else if (i == 4)
	{
		system("cls");
		write();
		menu();
	}
	else if (i == 5)
	{
		system("cls");
		statistics();
		menu();
	}
	else if (i == 6)
	{
		system("cls");
		insert();
		menu();
	}
	else if (i == 7)
	{
		system("cls");
		move();
		menu();
	}
	else if (i == 8)
	{
		system("cls");
		replace();
		menu();
	}
	else if (i == 9)
	{
		system("cls");
		deletefile();
		menu();
	}
	else if (i == 10)
	{
		system("cls");
		mainkmp(s);
		menu();
	}
	else if (i == 11)
	{
		write();
		exit(0);
	}
	else
	{
		cout << "û��ָ����������������룺" << endl;
		menu();
	}
}

int main()
{
	printf("Tobby Text Editer V0.2 beta\n");
	cout << "�����ñ༭��ÿ������ַ�����" << endl;
	cin >> maxn;
	menu(); //452
	return 0;
}

const int kmpmaxn = 100;
int nxt[kmpmaxn];
string kmps, kmpp;
void print(int ans)
{
	cout << ans << endl;
}
void getNext(string p)
{
	// ��ʼ����
	int j = 0;
	int k = -1;
	nxt[0] = -1;
	// ������֪��ǰjλ�Ʋ��j+1λ
	while (j < p.size() - 1)
	{ //p[k]��ʾǰ׺��p[j]��ʾ��׺
		if (k == -1 || p[j] == p[k])
		{
			++j;
			++k;
			if (p[j] != p[k])
				nxt[j] = k; //�Ż�
			else
				nxt[j] = k;
		}
		else
			k = nxt[k];
	}
}
void kmp(int lens, int lenp)
{
	display();
	cout << endl
			 << endl;
	int num = 0;
	int i = 0, j = 0, ans = -1; //������ans==1,��ƥ��ʧ��
	while (i < lens)
	{
		if (j == -1 || kmps[i] == kmpp[j])
		{
			i++;
			j++;
		}
		else
			j = nxt[j];
		if (j == lenp)
		{
			ans = i - lenp; //�±��0��ʼ
			int l = 1, r = 0;
			num++;
			cout << "��" << num << "�γ��֣���";
			for (int c = 0; c < ans; c++)
			{
				if (r == maxn)
				{
					if (s[c] == '\n')
					{
						l++;
						r = 0;
					}
					else
					{
						l++;
						r = 1;
					}
				}
				else
				{
					if (s[c] == '\n')
					{
						l++;
						r = 0;
					}
					else
					{
						r++;
					}
				}
			}
			cout << l << "�У���" << r << "�С�" << endl;
		}
	}
	if (num == 0)
		cout << "���ĵ���û�ҵ�ָ���ֶ�" << endl;
}

void mainkmp(string mains)
{ //����
	if (filename[0])
	{
		system("cls");
		cout << "������Ҫ���ҵ��ֶΣ�" << kmpmaxn << "���ַ����ڣ���" << endl;
		kmps = mains;
		string temp;
		char c;
		while (1)
		{
			c = _getch();
			if (c != 27)
			{ //esc
				if (c != 13 && c != 8 && c != (-32))
				{ //enter BackSpace
					temp = temp + c;
					system("cls");	 //����
					displayre(temp); //69
				}
				else if (c == 13)
				{
					temp = temp + "\n";
					system("cls");
					displayre(temp);
				}
				else if (c == 8)
				{
					temp = temp.substr(0, temp.length() - 1);
					system("cls");
					displayre(temp);
				}
			}
			else
				break;
		}
		cout << endl;
		kmpp = temp;
		memset(nxt, -1, sizeof(nxt));

		getNext(kmpp);
		int lens = kmps.size();
		int lenp = kmpp.size();
		kmp(lens, lenp);
	}
	else
	{
		cout << "����δ���κ�һ���ļ���Ҫ���ļ���?��/��(Y/N)" << endl;
		char ch;
		cin >> ch;
		if (ch == 'Y')
		{
			read1();
			mainkmp(s);
		}
	}
}

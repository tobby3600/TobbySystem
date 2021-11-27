#include<bits/stdc++.h>
using namespace std;
int x,y;
char tmp,ch0;
string s;
stack <int> s1;
stack <char> s2;

int oprsort(char p) {
	if(p=='+'||p=='-')
		return 1;
	if(p=='*'||p=='/')
		return 2;
	if(p=='^')
		return 3;
	return 0;
}

void js() {
	int m,n;
	char z;
	n=s1.top();
	s1.pop();
	m=s1.top();
	s1.pop();
	z=s2.top();
	s2.pop();
	switch(z) {
		case '+':
			s1.push(m+n);
			break;
		case '-':
			s1.push(m-n);
			break;
		case '*':
			s1.push(m*n);
			break;
		case '/':
			s1.push(m/n);
			break;
		default:
			s1.push(pow(m,n));
	}
	return;
}

int main() {
	printf("Tobby Calcer Beta V0.1\n");
	puts("请输入表达式(支持+,-,*,/,^)"); 
	cin>>s;
	s='('+s+')';
	int i=0;
	tmp='(';
	do {
		if(tmp=='(') {
			s2.push('(');
		} else if(tmp==')') {
			while(s2.top()!='(')
				js();
			s2.pop();
		} else if(tmp>='0'&&tmp<='9'||tmp=='-'&&s[i-1]=='(')

		{
			if(tmp=='-')
				x=0,y=-1;
			else
				x=tmp-'0',y=1;
			ch0=s[++i];
			while(ch0>='0'&&ch0<='9')
				x=x*10+ch0-'0',ch0=s[++i];
			i--;
			x*=y;
			s1.push(x);
		} else {
			while(oprsort(tmp)<=oprsort(s2.top())) {
				js();
			}
			s2.push(tmp);
		}
	} while(tmp=s[++i]);
	printf("Result:%lld",(long long int)s1.top());
	return 0;
}

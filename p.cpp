#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
class set
{
	int i,j;
	char n[50],p1[80],p2[80];
	public:
	set(int l,int m);
	void s();
}a(1,1);
set::set(int l,int m)
{
	
	ifstream b;
	b.open("password.dat",ios::binary);
	b.read((char*)&a,sizeof(a));
	if(i==0||l==0)
	{
		cout<<"name your diary\n";
		cin.ignore();
		gets(n);
		i=1;
	}
	if(j==0||m==0)
	{
		cout<<"enter a new password\n";
		cin.ignore();
		gets(p1);
		j=1;
	}
	else if(j==1)
	{
		while(1)
		{
			cout<<"enter the password\n";
			cin.ignore();
			gets(p2);
			if(strcmp(p2,p1)==0)
			{
				cout<<"welcome\n";
				break;
			}
			else
			{
			 cout<<"password incorrect\n";
			}
		}
    }	
	b.close();
	ofstream c;
	c.open("password.dat",ios::binary|ios::beg);
	c.write((char*)&a,sizeof(a));
	c.close();
}
void set::s()
{
	int ch;
	cout<<"1.to change name\n2.to change password\n";
	cin>>ch;
	if(ch==1)
	set(0,1);
	else if(ch==2)
	set(1,0);
	
}
class diary
{
	int d,m,y;
	char par[200];
	public:
	void in();
	void out();
}b;
void diary::in()
{
 ofstream a;
 time_t t=time(0);
 a.open("diary.dat",ios::binary|ios::app);
 struct tm *now=localtime(&t);
 d=now->tm_mday;
 m=now->tm_mon+1;
 y=now->tm_year+1900;
 cout<<"enter what happened today\n";
 cout<<"date:"<<d<<"-"<<m<<"-"<<y<<endl;
 cin.ignore();
 gets(par);
 a.write((char*)&b,sizeof(b));
 a.close();	
}
void diary::out()
{
 int d1,m1,y1,k;
 ifstream a;
 a.open("diary.dat",ios::binary);
 cout<<"enter the date month and year of entry\n";
 cin>>d1>>m1>>y1;
 while(a.read((char*)&b,sizeof(b)))
 {
   if((d1==d)&&(m1==m)&&(y1==y))
   {
    puts(par);
    k=1;
   }
   if(k==0)
   cout<<"file not found\n";
 }
   a.close();
}
int main()
{
	int ch;
	do
	{
	cout<<"1.to make todays entry\n2.to display a particular day entry\n3.settings\n4.exit\n";
    cin>>ch;
    switch(ch)
    {
    	case 1:
    	b.in();
    	break;
    	case 2:
    	b.out();
    	break;
    	case 3:
    	a.s();
    	break;
    	case 4:
    	exit(0);
    	default:
    	cout<<"enter valid input\n";
	}
	}while(ch!=4);
}
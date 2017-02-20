using namespace std;
#include<iostream>
#include<iomanip>
#include<cstring>
#include<ctime>
#include<stdio.h>
#include<fstream>
class user
{
		public:
			char username[10];
			char password[16];
			char name[20];
			int date;
			int month;
			int year;
};
user ob1;
class Thirdlife
{
		public:
			char username[10];
			char password[16];
			int login();
			int signup();	
};
int homepage()
{
	int c;
	cout<<endl<<"1. Login"<<endl<<"2. Signup"<<endl<<"choice :";
	cin>>c;
	Thirdlife u;
	if(c==1)
	{
		u.login();
	}
	if(c==2)
	{
		u.signup();
	}
	return 0;
}
int Thirdlife :: login()
{
	Thirdlife ob;
	user ob2;
	cout<<setw(45)<<"Login"<<endl<<endl;
	cin.ignore();
	cout<<setw(35)<<"Username :";
	gets(ob.username);
	cout<<endl<<setw(35)<<"Password :";
	gets(ob.password);
	ifstream hp1;
	hp1.open(ob.username,ios :: out|ios :: binary);
	if(hp1==0)
	{
		cout<<"XX WRONG DATA ENTERED XX";
		homepage();
	}
	else
		{
			hp1.read((char*)&ob2,sizeof(ob2));
			if(strcmp(ob.password,ob2.password)!=0)
				{
					cout<<endl<<"XX WRONG DATA ENTERED XX";
					homepage();
				}
		}
	cin.ignore();
	return 0;
}
int Thirdlife :: signup()
{	
	char password[16];
	//*signup:
	cout<<setw(45)<<"Signup"<<endl<<endl;
	cin.ignore();
	cout<<setw(35)<<"Username :";
	gets(ob1.username);
	ofstream hp(ob1.username,ios::out|ios::binary);
	cout<<endl<<setw(35)<<"Password :";
	gets(ob1.password);
	cout<<endl<<setw(35)<<"re-enter your password :";
	gets(password);
	if(strcmp(ob1.password,password)!=0)
		{
			cout<<endl<<setw(35)<<"XX PASSWORD DIDN'T MATCHED XX";
			cout<<endl<<setw(35)<<"Re-enter all your informaton";
			cin.ignore();
			//*goto signup;	
		}
	date:
	cout<<setw(35)<<"date of birth(mm-dd-yyyy) :";
	scanf("%d-%d-%d",&ob1.date,&ob1.month,&ob1.year);
	cout<<endl;
	if(ob1.year>1900 && ob1.year<2017)
		{
			
			if(ob1.month>0 && ob1.month<=7)
				{
					if(ob1.month%2!=0)
						{
							if(ob1.date<0 && ob1.date>31)
								{	
									cout<<endl<<setw(35)<<"XX Wrong data entered XX";
									cout<<endl<<setw(35)<<"Re-enter your Date of Birth";
									cin.ignore();
									goto date;
								}
						}		
					else if(ob1.month%2==0)
				{
					if(ob1.date<0 && ob1.date>30)
						{	
							cout<<endl<<setw(35)<<"XX Wrong data entered XX";
							cout<<endl<<setw(35)<<"Re-enter your Date of Birth";
							cin.ignore();
							goto date;
						}
				}
					if(ob1.month==2)
						{
							if((ob1.year%4!=0) && (ob1.year%100==0) || (ob1.year%400!=0))
								{
									
									if(ob1.date<0 && ob1.date>29)
										{
											cout<<endl<<setw(35)<<"XX Wrong data entered XX";
											cout<<endl<<setw(35)<<"Re-enter your Date of Birth";
											cin.ignore();
											goto date;	
										}
								}
							else
								if(ob1.date<0 && ob1.date>28)
										{
											cout<<endl<<setw(35)<<"XX Wrong data entered XX";
											cout<<endl<<setw(35)<<"Re-enter your Date of Birth";
											cin.ignore();
											goto date;	
										}
							
						}
				}
			else if(ob1.month>7 && ob1.month<=12)
				{
					if(ob1.month%2!=0)
						{
							if(ob1.date<0 && ob1.date>30)
								{	
									cout<<endl<<setw(35)<<"XX Wrong data entered XX";
									cout<<endl<<setw(35)<<"Re-enter your Date of Birth";
									cin.ignore();
									goto date;
								}
						}
					else if(ob1.month%2==0)
						{
							if(ob1.date<0 && ob1.date>31)
								{	
									cout<<endl<<setw(35)<<"XX Wrong data entered XX";
									cout<<endl<<setw(35)<<"Re-enter your Date of Birth";
									cin.ignore();
									goto date;
								}
						}
				}
	}
	hp.write((char*)&ob1,sizeof(ob1));
	hp.close();
	cout<<endl<<"Welcome :)";
	cin.ignore();
	homepage();
	return 0;
}
int main()
{
	homepage();
	return 0;
}

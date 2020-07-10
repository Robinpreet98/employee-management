#include<conio.h>


#include<stdio.h>
#include<string.h>
int w,z,d,t;
void check(int e);
class trans
{
public:
int empid;
int srno;
float totalpay;
int month,year;
char tdate[50];
char ename[50];
public:
int accept()
{
 cout<<endl<<"Enter Month";
 cin>>month;
 cout<<endl<<"Enter Year";
 cin>>year;
 cout<<"Enter today date";
 gets(tdate);
 cout<<endl<<"Enter emp id";
 cin>>empid;
 fstream rd;
 rd.open("emp.txt",ios::in);
 rd.seekg(0,ios::end);
 int n=rd.tellg()/sizeof(obj);
 rd.seekg(0,ios::beg);
 for(int i=1;i<=n;i++)
 {
  rd.read((char *)&obj,sizeof(obj));
  if(obj.empid==empid)
  {
   strcpy(ename,obj.name);
   totalpay=obj.bsal+obj.hra+obj.perks;
   cout<<endl<<"Name :"<<ename;
   cout<<endl<<"Basic salary: "<<obj.bsal;
   cout<<endl<<"House rental allowance: "<<obj.hra;
   cout<<endl<<"Perks : "<<obj.perks;
   cout<<endl<<"Total : "<<totalpay;
   fstream rd1;
   rd1.open("pay.txt",ios::in);
   rd1.seekg(0,ios::end);
   int tn=rd1.tellg()/sizeof(tobj);
   srno=tn+1;
   cout<<endl<<"Sr No "<<srno;
   return 1;
   break;
  }
 }
 return 0;
}
void tdisplay()
{
 cout<<srno<<"\t"<<ename<<"\t"<<totalpay<<"\t"<<tdate<<endl;
}
};
trans tobj;
class emp
{
 public:
int empid;
float bsal,hra,perks;
char name[50],fname[50],doj[50];
public:
void accept()
{
 cout<<endl<<"enter employee ID ";
 cin>>empid;
 cout<<"enter name ";
 gets(name);
 cout<<"enter father name ";
 gets(fname);
 cout<<"enter basic salary ";
 cin>>bsal;
 cout<<"enter house rental allowance ";
 cin>>hra;
 cout<<"enter perks ";
 cin>>perks;
}
void display()
{
 cout<<endl<<"employee ID "<<empid;
 cout<<endl<<"employee name "<<name;
 cout<<endl<<"father name "<<fname;
 cout<<endl<<"basic salary "<<bsal;
 cout<<endl<<"house rental allowance "<<hra;
 cout<<endl<<"perks "<<perks;
 cout<<endl<<"**********************************************"<<endl;
}
};
emp obj;
void addemp()
{
 obj.accept();
 fstream wr;
 wr.open("emp.txt",ios::app);
 wr.write((char *)&obj,164);
 cout<<"object written successfully";
}
void viewemp()
{
fstream rd;
rd.open("emp.txt",ios::in);
rd.seekg(0,ios::end);
int n=rd.tellg();
int count=n/sizeof(obj);
rd.seekg(0,ios::beg);
for(int i=1;i<=count;i++)
{
rd.read((char*)&obj,164);
obj.display();
}
}
 void search()
 { int u,k=1;
  cout<<endl<<" enter 1 for search by empoyee ID"<<endl<<" enter 2 for search by employee name"<<endl;
  cin>>u;
  if(u==1)
  {
    fstream rd1;
    int e;
    cout<<" Enter The EMPLOYEE ID to be SEARCHED : ";
    cin>>e;
    rd1.open("emp.txt",ios::in);
    rd1.seekg(0,ios::end);
    int n=rd1.tellg();
    int count=n/sizeof(obj);
    rd1.seekg(0,ios::beg);
    for(int i=1;i<=count;i++)
     { rd1.read((char *)&obj,164);
       if(k==1)
	{ if(obj.empid==e)
	  {
	    obj.display();
	     k=0;
	  }
	}
      }
  }
  else if(u==2)
  {  fstream y;char x[50];
     cout<<endl<<"enter the employee name : ";
     gets(x);
     y.open("emp.txt",ios::in);
     y.seekg(0,ios::end);
     int n=y.tellg()/sizeof(obj);
     y.seekg(0,ios::beg);
     for(int i=1;i<=n;i++)
     { y.read((char *)&obj,sizeof(obj));
       if(stricmp(x,obj.name)==0)
       {  k=0;
	obj.display();
       }
     }
   }
   else {cout<<" wrong input "; }
  if(k==1){printf("employeeid not found");}
 }

void remrec()
 {
  fstream rd,wr;
  int e;
  int flag=0;
  cout<<" enter employee id to remove: ";
  cin>>e;
  d=e;
  check(d);
  if(z==1){
  rd.open("emp.txt",ios::in);
  wr.open("temp.txt",ios::out);
  rd.seekg(0,ios::end);
  int n=rd.tellg();
  int count=n/sizeof(obj);
  rd.seekg(0,ios::beg);
  for(int i=1;i<=count;i++)
  { rd.read((char *)&obj,164);
     if(obj.empid==e)
      { cout<<"  OBJECT REMOVED SUCCESSFULLY . ";
	flag=1;
      }
     else if(obj.empid!=e)
      {
       wr.write((char *)&obj,164);
      }
  }
   rd.close();
   wr.close();
   if(flag==1)
   {
     rd.open("temp.txt",ios::in);
     wr.open("emp.txt",ios::out);
     for(int j=1;j<=count-1;j++)
     {
     rd.read((char *)&obj,164);
     wr.write((char *)&obj,164);
     }}
   }
   else
   {printf("no such employee ID");
   }
 }
 void editrec()
 {
  fstream wr,rd;
  int e;
  int flag=0;
  cout<<" ENTER THE EMPLOYEE ID TO BE EDITED : ";
  cin>>e;
  t=e;
  check(t);
  if(z==1){
  rd.open("emp.txt",ios::in);
  wr.open("temp.txt",ios::out);
  rd.seekg(0,ios::end);
  int n=rd.tellg();
  int count=n/sizeof(obj);
  rd.seekg(0,ios::beg);
  for(int i=1;i<=count;i++)
  {rd.read((char  *)&obj,164);
   if(obj.empid==e)
   {obj.accept();
   flag=1;
   }
   wr.write((char *)&obj,sizeof(obj));
  }
   rd.close();
   wr.close();
   if(flag==1)
   {
     rd.open("temp.txt",ios::in);
     wr.open("emp.txt",ios::out);
      for(int j=1;j<=count;j++)
       {
	 rd.read((char *)&obj,sizeof(obj));
	 wr.write((char *)&obj,sizeof(obj));
       }  }
       printf("  SUCESSFULLY EDITED. ");
    }
    else{printf("   EMPLOYEE NOT FOUND . ");}
 }

void givepay()
{

 if(tobj.accept()==1)
 {
  fstream wr1;
  wr1.open("pay.txt",ios::app);
  wr1.write((char *)&tobj,sizeof(tobj));
  cout<<"Pay disbursed sucessfully";
 }
 else
 {
 cout<<"Invalid empid";
 }
}
void report1()
{
 int m,y;
 clrscr();
 cout<<endl<<"enter month";
 cin>>m;
 cout<<endl<<"enter year";
 cin>>y;
 fstream rd1;
 rd1.open("pay.txt",ios::in);
 rd1.seekg(0,ios::end);
 int n=rd1.tellg()/sizeof(tobj);
 rd1.seekg(0,ios::beg);
 for(int i=1;i<=n;i++)
 {
  rd1.read((char *)&tobj,sizeof(tobj));
  if(m==tobj.month && y==tobj.year)
  {
  tobj.tdisplay();
  }
 }
}
 void report2()
  { int empi,j;
    clrscr();
    cout<<endl<<" ENTER THE EMPLOYEE ID :   ";
    cin>>empi;
    fstream rr;
    rr.open("pay.txt",ios::in);
    rr.seekg(0,ios::end);
    int b=rr.tellg()/sizeof(tobj);
    rr.seekg(0,ios::beg);
    for(int i=1;i<=b;i++)
    { rr.read((char *)&tobj,sizeof(tobj));
      if(empi==tobj.empid)
      {tobj.tdisplay(); j=1;}
    }       if(j!=1){printf(" DATA NOT FOUND .");}
  }
void check(int e)
 {
  fstream rd;
  rd.open("emp.txt",ios::in);
  rd.seekg(0,ios::end);
  int n=rd.tellg();
  int count=n/164;
  rd.seekg(0,ios::beg);
  for(int i=1;i<=count;i++)
  {rd.read((char *)&obj,164);
     if(obj.empid==e)
     {
       z=1;

     }
  }

}
void main()
{
 int option;
 int flag=0;
 while(flag==0)
 {
 clrscr();
 cout<<"enter 1 add employee"<<endl;
 cout<<"enter 2 view employee"<<endl;
 cout<<"enter 3 to search"<<endl;
 cout<<"enter 4 to remove"<<endl;
 cout<<"enter 5 to edit"<<endl;
 cout<<"enter 6 to givepay"<<endl;
 cout<<"enter 7 to report"<<endl;
 cout<<"enter 8 to exit"<<endl;
 cout<<"*******************************"<<endl;
 cin>>option;
 switch(option)
 {
 case 1:
 {
  addemp();
  break;
 }
 case 2:
 {
  viewemp();
  break;
 }
 case 3:
 {
  search();
  break;
 }
 case 4:
 {
  remrec();
  break;
 }
 case 5:
 {
  editrec();
  break;
 }
  case 6:
 {
  givepay();
  break;
 }
  case 7:
 {
    { int v;
      cout<<endl<<"   1-view report month wise"<<endl<<"   2-view report employee wise";
      cin>>v;
      if(v==1){report1();}else if(v==2){report2();}
    break;}
 }
 case 8:
 {
 flag=1;
 break;
 }
 }
 getch();
}
}

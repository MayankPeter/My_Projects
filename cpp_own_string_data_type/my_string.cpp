#include<iostream>
#include<cstring>
using namespace std;

class my_string
{
char *ptr;

public:

/*------------------------- Default constructor ------------------------------------------*/


/*1*/my_string()
{
ptr = new char;
}

/*------------------------- parameterized constructor for my_string str = "vector"; ------------------------------------------*/


/*2*/my_string(const char *p)
{
ptr = new char[strlen(p)+1];
strcpy(ptr,p);
}

/*------------------------- copy constructor for a1(a2) ------------------------------------------*/


/*3*/my_string(const my_string &a)
{
ptr = new char[strlen(a.ptr)+1];
strcpy(ptr,a.ptr);
}
/*----------------------------------- Destructor ---------------------------------------------*/
~my_string()
{
delete []ptr;
}

/*------------------------- member = operator overload ------------------------------------------*/

/*4*/void operator =(const char *t)
{
this->ptr = new char[strlen(t)+1];
strcpy(ptr,t);
}

/*------------------------- member bool == operator overload ------------------------------------------*/

/*5*/bool operator ==(my_string &a)
{
if(strcmp(ptr,a.ptr)==0)
return 1;
else
return 0;
}

/*------------------------- member bool >= operator overload ------------------------------------------*/

/*6*/bool operator >=(my_string &a)
{
if(strcmp(ptr,a.ptr)>=0)
return 1;
else
return 0;
}

/*------------------------- member bool <= operator overload ------------------------------------------*/

/*7*/bool operator <=(my_string &a)
{
if(strcmp(ptr,a.ptr)<=0)
return 1;
else
return 0;
}

/*------------------------- member bool != operator overload -------------------------------------------*/

/*8*/bool operator !=(my_string &a)
{
if(strcmp(ptr,a.ptr)!=0)
return 1;
else
return 0;
}

/*------------------------- member bool > operator overload --------------------------------------------*/

/*9*/bool operator >(my_string &a)
{
if(strcmp(ptr,a.ptr)>0)
return 1;
else
return 0;
}

/*-------------------------- member bool < operator overload -------------------------------------------*/

/*10*/bool operator <(my_string &a)
{
if(strcmp(ptr,a.ptr)<0)
return 1;
else
return 0;
}


/*11*/friend ostream& operator <<(ostream& ,my_string &); 
/*12*/friend istream& operator >>(istream& ,my_string &); 
/*13*/friend int strlen(my_string &);
/*14*/friend int strcmp(my_string &,my_string &);
/*15*/friend istream& getline(istream &,my_string &);
/*16*/friend void strcpy(my_string&,my_string&);
};

/*---------------------------- friend cout overload ----------------------------------------------*/

ostream& operator <<(ostream& out,my_string &a) 
{
out << a.ptr;
return out;
}

/*-------------------------- friend cin overload -------------------------------------------------*/

istream& operator >>(istream& in,my_string &s) 
{

//cin.ignore();
fflush(stdin);
FILE *fp = fopen("my_stdin","w+");
char c;
int i=0,size=0;
while(c=getchar())
{
size++;
if(c== '\n'||c==' ')
break;
fputc(c,fp);
}
rewind(fp);
s.ptr = (char*)realloc(s.ptr,size);
while((c=fgetc(fp))!=EOF)
{
s.ptr[i++]=c;
}
s.ptr[i]='\0';
fclose(fp);


/*fflush(stdin);

char ch;
int i=0;
a.ptr  = new char;
while(1)
{
ch = getchar();
if(ch==' ' || ch=='\n')
break;
a.ptr[i++] = ch;
a.ptr = (char *)realloc(a.ptr,i+1);
}
a.ptr[i]='\0';
*/

return in;
}

/*-------------------------- friend strlen() overload -------------------------------------------*/

int strlen(my_string &a)
{
int i;
for(i=0;a.ptr[i];i++);
return i;
}

/*-------------------------- friend strcmp() overload ------------------------------------------*/

int strcmp(my_string &a, my_string &b)
{
int i;
for(i=0;a.ptr[i];i++)
{
if(a.ptr[i]!=b.ptr[i])
break;
}
if(a.ptr[i]==b.ptr[i])
return 0;
else if(a.ptr[i]>b.ptr[i])
return 1;
else 
return -1;
}

/*-------------------------- friend strcpy(s1,s2) ----------------------------------------------*/
void strcpy(my_string &a, my_string &b)
{
a.ptr = (char*)realloc(a.ptr,sizeof(b.ptr));
strcpy(a.ptr,b.ptr);
}


/*-------------------------- friend getline(cin,s) ---------------------------------------------*/
istream& getline(istream &in,my_string &s)
{
fflush(stdin);
FILE *fp = fopen("my_stdin","w+");
char c;
int i=0,size=0;
while((c=fgetc(stdin))!=-1)
{
size++;
if(c=='\n')
break;
fputc(c,fp);
}
rewind(fp);
s.ptr = (char*)realloc(s.ptr,size);
while((c=fgetc(fp))!=EOF)
{
s.ptr[i++]=c;
}

s.ptr[i]='\0';
fclose(fp);
return in;
}




int main()
{

bool ret;
/*----------------------------------------------------------------------------------------------*/
my_string str = "vector";

str = "vector";					//str.operator =(char *)
cout << "str = "<< str << endl;
						//operator <<(cout,str);
my_string s1("vector india");			//paramaterized constructor
cout << s1 << endl;

my_string s2(s1);
cout << s2 << endl;

my_string s3;
cout << "Input s3: " << endl;
cin >> s3;					//operator >>(cin,s3);
cout<<"s3 = " << s3 << endl;
/*-----------------------------------------------------------------------------------------------*/

cout << boolalpha;

ret = s1==s2;					//s1.operator ==(my_string &)
cout<< "s1==s2 = " << ret << endl;

ret = s1>=s2;					//s1.operator >=(my_string &)
cout<< "s1>=s2 = " << ret << endl;

ret = s1<=s2;					//s1.operator <=(my_string &)
cout<< "s1<=s2 = " << ret << endl;

ret = s1>s2;					//s1.operator >(my_string &)
cout<< "s1>s2 = " << ret << endl;

ret = s1<s2;					//s1.operator <(my_string &)
cout<< "s1<s2 = " << ret << endl;

ret = s1!=s2;					//s1.operator !=(my_string &)
cout<< "s1!=s2 = " << ret << endl;
/*-----------------------------------------------------------------------------------------------*/

cout << "string length is = "<< strlen(s3) << endl; //string length calculation

/*-----------------------------------------------------------------------------------------------*/

cout <<"strcmp = "<< strcmp(str,s3) << endl;			//string compare function

/*-----------------------------------------------------------------------------------------------*/
my_string s4;
getline(cin,s4);				//getline(cin,s) 
cout << "s4 = " << s4 << endl;
/*-----------------------------------------------------------------------------------------------*/

my_string s5("mayank"),s6;
strcpy(s6,s5);
cout<< "strcpy = " << s6 << endl; 
}

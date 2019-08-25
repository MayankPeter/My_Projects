#include<iostream>
#define Green "\033[32;45;1m"
#define Reset "\033[0m"
using namespace std;

template<class Type>
class stack
{
	Type a[5];
	int cur=-1;
	public:
	void push();
	void pop();
	void display();
	int mainmenu(stack<char>&, stack<float>&, stack<double>&);
	int submenu();
};

	template<class Type>
void stack<Type>::push()
{
	Type n;
	cout<< Green << "Enter the value to push : " << Reset;
	cin >> n;
	cur++;
	if(cur<5)
	{
		a[cur]=n;
	}
	else
	{
		cout << endl << "Stack Overflow !!" << endl;
		cur--;
	}
	cout << endl << "After push:" << endl;
	display();
	return;
}

	template<class Type>
void stack<Type>::pop()
{
	if(cur<0)
	{
		cout<<"Stack Underflow !!" << endl;
	}
	else
	{
		cur--;
	}
	cout << endl << "After pop:" << endl;

	display();
	return;
}

	template <class Type>
void stack<Type>::display()
{	
//	system("clear");
	for(int i=cur;i>=0;i--)
	{
	cout << "\t\t\t- - - - - - " << endl;
	cout << "\t\t\t|         |" << endl;
	if(i==cur)
	{
	cout << "\t\tTop --->";
	if(a[i]<10)
	{
	cout <<"|   " << a[i] << "     |"<< endl;
        }
	else
	{
	cout <<"|    " << a[i] << "   |"<< endl;
	}
	cout << "\t\t\t|         |" << endl;
	}
	else
	{
	if(a[i]<10)
	{
	cout <<"\t\t\t|  " << a[i] << "     |"<< endl;
	}
	else
	{
	cout <<"|    " << a[i] << "   |"<< endl;
	}
        cout << "\t\t\t|         |" << endl;
	}
	}
	if(cur!=-1)
	cout << "\t\t\t- - - - - - " << endl;
	else
	cout << "Stack is Empty" << endl;
	return;
}

int main()
{
	stack<int>obj0;
	stack<int>obj1;
	stack<char>obj2;
	stack<float>obj3;
	stack<double>obj4;

	obj1.mainmenu(obj2,obj3,obj4);

	return 0;
}

	template<class Type>
int stack<Type>::mainmenu(stack<char>&obj2, stack<float>&obj3, stack<double>&obj4)
{
	int choice1,count1=0;

L1:
	cout << "1) Int 2) Char 3) Float 4) Double 5) Exit" << endl;
	cin >> choice1;
	/*
	   if(choice1==5)
	   {
	   cout << "Thankyou, Please Visit Again!!" << endl;
	   return 0;
	   }
	 */
if(choice1>0 && choice1<6)
{
switch(choice1)
{
case 1:(*this).submenu();
	break;
case 2:obj2.submenu();
	break;
case 3:obj3.submenu();
	break;
case 4:obj4.submenu();
	break;
case 5: cout << "Thankyou, Please Visit Again!!" << endl;
	return 0;
}
goto L1;
}
else 
{
if(count1<2)
{
cout << "Invalid Choice.. Please Try Again!!" << endl;
if(count1==1)
cout << endl << "This is your last chance" << endl <<endl;
count1++;
goto L1;
}
else if(count1==2)
{
count1++;
}
else
{
return 0; 
}
}
return 0;
}

template<class Type>
int stack<Type>::submenu()
{
int choice2,count2=0;

L2:
cout << "1) Push  2) Pop  3) Display  4) Exit" << endl;
cin >> choice2;

if(choice2==4)
{
return 0;
}
else if(choice2>=1 && choice2<=3)
{
switch(choice2)
{
case 1:push();
	goto L2;
	break;
case 2:pop();
	goto L2;
	break;
case 3:display();
	goto L2;
	break;
}
}
else
{
if(count2<3)
{
if(count2==0 || count2==1)
{
cout << "Invalid Choice" << endl;
count2++;
}
else if(count2==2)
{
count2++;
cout << "Invalid choice.. This is your last chance" << endl;
}
else
{
cout << "Please Read Manual And Try Again" << endl;
return 0;
}
goto L2;
}
}
return 0;
}


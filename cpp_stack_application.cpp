#include<iostream>
#include<cstring>
#include<iomanip>

#define Reset "\033[0m"
#define Green_d "\u001b[32m"
#define Cyan_d "\u001b[36m"
#define Red_d "\u001b[31m"
#define Yellow_d "\u001b[33m"
#define Magenta_d "\u001b[35m"
#define Blue_d "\u001b[34m"

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
	cout<< Magenta_d << "Enter the value to push : " << Reset;
	cin >> n;
	cur++;
	if(cur<5)
	{
		a[cur]=n;
	}
	else
	{
		cout << endl << Red_d << "Stack Overflow !!" << Reset << endl;
		system("clear");
		cur--;
	}
	cout << endl << Green_d << "After push:" << Reset << endl;
	display();
	return;
}

	template<class Type>
void stack<Type>::pop()
{
	if(cur<0)
	{
		cout<< Red_d <<"Stack Underflow !!"<<Reset << endl;
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

	for(int i=cur;i>=0;i--)
	{
		cout << Cyan_d << "\t\t\t----------------" << Reset << endl;
		cout << "\t\t\t" << Cyan_d << "|              |" << Reset << endl;
		if(i==cur)
		{
			cout  << "\t\t" << Red_d << "Top --->" << Reset;
			cout <<Cyan_d <<"|    " <<Reset<< Yellow_d << std::setfill(' ') << std::setw(6) << a[i] << Reset << Cyan_d<<"    |"<<Reset<< endl;
			cout << Cyan_d <<"\t\t\t|              |" << Reset << endl;
		}
		else
		{
			cout << Cyan_d <<"\t\t\t|    "<< Reset << Yellow_d << std::setfill(' ') << std::setw(6) << a[i] << Reset << Cyan_d << "    |"<< Reset << endl;
			cout << Cyan_d <<"\t\t\t|              |" << Reset << endl;
		}
	}
	if(cur!=-1)
		cout << Cyan_d << "\t\t\t----------------" << Reset <<endl;
	else
		cout << endl << Blue_d << "Stack is Empty" << Reset << endl << endl;
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
	cout<< Blue_d << "1) Int 2) Char 3) Float 4) Double 5) Exit" << Reset << endl;
	cin >> choice1;
	
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
			case 5: cout << Green_d << "Thankyou, Please Visit Again!!" << Reset << endl;
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
	char ans;
	
	if(cur>-1)
	{
	cout << Red_d << "Warning: Previous values are present. Do you want to clear? Y/N" << Reset << endl;
	cin >> ans;
	}
	if(ans=='y' || ans=='Y')
	cur=-1;
	else if(ans=='N' || 'n'){}
	else
	cout << Red_d << "Invalid Choice Please try again" << Reset << endl;
L2: 
	cout << Blue_d << "1) Push  2) Pop  3) Display  4) Exit" << Reset << endl;
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
				cout << Red_d << "Invalid Choice" << Reset << endl;
				count2++;
			}
			else if(count2==2)
			{
				count2++;
				cout << Red_d << "Invalid choice.. This is your last chance" << Reset << endl;
			}
			else
			{
				cout <<  Red_d << "Please Read Manual And Try Again" << Reset << endl;
				return 0;
			}
			goto L2;
		}
	}
	return 0;
}

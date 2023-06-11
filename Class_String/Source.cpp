/*Develop a String class (For now only do the methods from the list), which will be used to work with strings.The class must contain :
  - default constructor to create a string of 80 characters;
  - constructor that allows you to create a string of arbitrary size;
  - a constructor that creates a stringand initializes it with the string received from the user.The class must contain methods for entering lines from the keyboardand displaying lines on the screen.
  - Copy constructor
  - int Length() method;
  - Char StartWith();
  - Char EndsWith();
  - Method bool equal(const char*);
  - char* GetStr();
  - void SetStr(const char* str);*/

#include<iostream>

using namespace std;

class String
{
public:
	String()
	{
		_size = 81;
		_str = new char[_size];
		if (_str == NULL)
		{
			cout << "Error\n";
			exit(-1);
		}
		_str[0]={'\0'};
	}
	String(int size)
	{
		_size = size;
		_str = new char[_size+1];
		if (_str == NULL)
		{
			cout << "Error\n";
			exit(-1);
		}
		_str[0] = { '\0' };
	}
	String(int size, const char str[])
	{
		_size = size;
		_str = new char[_size + 1];
		if (_str == NULL)
		{
			cout << "Error\n";
			exit(-1);
		}
		/*int i = -1;
		do
		{
			i++;
			_str[i] = str[i];
		} while (str[i]!='\0');*/
		for (int i = 0; i <= _size; i++)
		{
			if (str[i] == '\0')
			{
				_str[i] = str[i];
				break;
			}
			_str[i] = str[i];
		}
	}
	~String() { delete[]_str; }
	void setString() { gets_s(_str,_size); }
	void getString() { cout << _str; }
private:
	char *_str;
	int _size;
};

int main()
{
	
	String test;
	test.setString();
	test.getString();
	cout << endl;
	
	system("pause");
	return 0;
}
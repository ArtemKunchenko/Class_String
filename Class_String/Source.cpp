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
	String();//constructor default
	String(int size);//constructor with param
	String(const char str[]);//constructor with param
	String(const String& initial);//copy constructor
	~String(); //distructor
	void setString() { gets_s(_str, _size); }//setter
	void getString() { cout << _str; }//getter
	int Length();
	char StartWith();
	char EndsWith();
	bool Equal(const char* str);
	char* GetStr();
	void SetStr(const char* str);
private:
	char* _str;
	int _size;
};

int main()
{

	/*String test("Hallo");
	test.setString();
	test.getString();
	cout << endl<<test.Length() << endl;
	test.SetStr("");
	test.getString();
	cout << endl << test.Length() << endl;*/
	String test1;
	String test2(test1);
	system("pause");
	return 0;
}

String::String()
{
	_size = 81;
	_str = new char[_size];
	if (_str == NULL)
	{
		cout << "Error\n";
		exit(-1);
	}
	_str[0] = { '\0' };
	cout << "Construcror default\t" << this << endl;
}

String::String(int size)
{
	_size = size;
	_str = new char[_size + 1];
	if (_str == NULL)
	{
		cout << "Error\n";
		exit(-1);
	}
	_str[0] = { '\0' };
	cout << "Construcror with params\t" << this << endl;
}

String::String(const char str[])
{
	int size = 0;
	for (int i = 0; str[i] != '\0'; i++) size++;
	_size = size + 1;
	_str = new char[_size];
	if (_str == NULL)
	{
		cout << "Error\n";
		exit(-1);
	}
	
	for (int i = 0; i <= size; i++)
	{
		if (str[i] == '\0')
		{
			_str[i] = str[i];
			break;
		}
		_str[i] = str[i];
	}
	cout << "Construcror with params\t" << this << endl;
}

String::String(const String& initial)
{
	this->_size = initial._size;
	this->_str = new char[initial._size];
	if (_str == NULL)
	{
		cout << "Error\n";
		exit(-1);
	}
	for (int i = 0; i < _size; i++)
	{
		this->_str[i] = initial._str[i];
	}
	cout << "Copy constructor\t" << this << endl;
}

String::~String()
{
	delete[]_str; 
	cout << "Distructor\t" << this << endl;
}

int String::Length()
{
	int counter = 0;
	for (int i = 0; _str[i]!='\0'; i++) counter++;
	return counter;
}

char String::StartWith()
{
	return _str[0];
}

char String::EndsWith()
{
	char last_symbol = _str[0];
	for (int i = 0; _str[i] != '\0'; i++) last_symbol = _str[i];
	return last_symbol;
}

bool String::Equal(const char*str)
{
	int counter = 0;
	for (int i = 0; str[i] != '\0'; i++) counter++;
	if (Length() != counter) return false;
	else
	{
		for (int i = 0; _str[i]!='\0'; i++)
		{
			if (_str[i] != str[i])
			{
				return false;
				break;
			}
		}
		return true;
	}
}

char* String::GetStr()
{
	return _str;
}

void String::SetStr(const char* str)
{
	int size = 0;
	for (int i = 0; str[i] != '\0'; i++) size++;
	_size = size + 1;
	if (_str != nullptr) delete[]_str;
	_str = new char[_size];
	for (int i = 0; i <= size; i++)
	{
		if (str[i] == '\0')
		{
			_str[i] = str[i];
			break;
		}
		_str[i] = str[i];
	}
}



#include <iostream>
#include <stack>
#include <string>

using namespace std;

// checks whether or not two curly brackets are opening and closing
bool Brackets(char opening, char closing)
{
	if( opening == '{' && closing == '}' ) return true;
	return false;
}

// checks for when
bool BalancedBrackets(string b)
{
	stack<char> a;
	for(int i = 0; i < b.length(); i++)
	{
		if( b[i] == '{' )
			a.push(b[i]);
		else if (b[i] == '}')
		{
			if( a.empty() || !Brackets( a.top(), b[i] ) )
				return false;
			else
				a.pop();
		}
	}
	return a.empty();
}

int main()
{
	// tests BalancedBrackets function
	string c;
	cout << "Enter an expression: ";
	cin >> c;
	if(BalancedBrackets(c))
		cout << "Valid" << endl;
	else
		cout << "Invalid." << endl;
}

#include"Cats.h"
void initialize(queue<char>& p)
{
	string s;
	int i = 0, flag = 1;
	while (flag)
	{
		getline(cin, s);
		for (i = 0; i < s.size(); i++)
		{
			if (!(isdigit(s[i]) || s[i] == 'J' || s[i] == 'K' || s[i] == 'Q' || s[i] == 'A'))
			{
				cout << "Wrong£¡Please input again!" << endl;
				break;
			}
			if (i == s.size() - 1) flag = 0;
		}
	}
	for (i = 0; i < s.size(); i++)
	{
		p.push(s[i]);
	}
}

bool check(string s, char c)
{
	int i = 0;
	if (s == "")
		return false;
	while (i < s.size())
	{
		if (s[i] == c)
			return true;
		i++;
		if (i == s.size())
			return false;
	}
}

string showcards(queue<char> p)
{

	string s;
	while (!p.empty())
	{
		s += p.front();
		p.pop();
	}
	return s;
}

void playcards(string player, queue<char>& A, stack<char>& table)
{
	string s = "";
	char tempcard;
	stack<char> tempcards;
	cout << "The cards of player" << player << ":" << showcards(A) << endl;
	if (check(s, A.front()))
	{
		tempcard = A.front();
		A.pop();
		cout << "Player" << player << "put the card of:" << tempcard << endl;
		tempcards.push(tempcard);
		while (table.top() != tempcard)
		{
			tempcards.push(table.top());
			table.pop();
			s.pop_back();
		}
		tempcards.push(table.top());
		table.pop();
		s.pop_back();
		cout << "Player" << player << "takes";
		while (!tempcards.empty())
		{
			A.push(tempcards.top());
			cout << tempcards.top();
			tempcards.pop();
		}
		cout << endl;
	}
	else
	{
		cout << "Player" << player << "put the card of:" << A.front() << endl;
		s += A.front();
		table.push(A.front());
		A.pop();
	}
	cout << "The cards of" << player << ":" << showcards(A) << endl;
	cout << "The cards on the table now:" << s << endl;
	cout << endl;
}

void main_process(queue<char>& A, queue<char>& B, stack<char>& table)
{
	string s = "";
	char tempcard;
	stack<char> tempcards;
	cout << "*********************************************************************************************************" << endl;
	cout << "Action!" << endl;
	while (!(A.empty() || B.empty()))
	{
		playcards("A", A, table);
		playcards("B", B, table);
	}
	string winner;
	if (A.empty()) winner = "B";
	else if (B.empty()) winner = "A";
	cout << "The game ends£¡" << endl << winner << "Wins!" << endl;
}
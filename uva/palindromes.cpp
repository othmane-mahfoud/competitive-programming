#include<iostream>
#include<algorithm>
#include<map>
#include<string.h>
#include<string>

using namespace std;

int main (){
	freopen ("output.txt","w",stdout);
	map<char, char> map;
	map['A'] = 'A';
	map['B'] = ' ';
	map['C'] = ' ';
	map['D'] = ' ';
	map['E'] = '3';
	map['F'] = ' ';
	map['G'] = ' ';
	map['H'] = 'H';
	map['I'] = 'I';
	map['J'] = 'L';
	map['K'] = ' ';
	map['L'] = 'J';
	map['M'] = 'M';
	map['N'] = ' ';
	map['O'] = 'O';
	map['P'] = ' ';
	map['Q'] = ' ';
	map['R'] = ' ';
	map['S'] = '2';
	map['T'] = 'T';
	map['U'] = 'U';
	map['V'] = 'V';
	map['W'] = 'W';
	map['X'] = 'X';
	map['Y'] = 'Y';
	map['Z'] = '5';
	map['1'] = '1';
	map['2'] = 'S';
	map['3'] = 'E';
	map['4'] = ' ';
	map['5'] = 'Z';
	map['6'] = ' ';
	map['7'] = ' ';
	map['8'] = '8';
	map['9'] = ' ';
	string str;
	while(cin >> str){
		string str2 = str;
		reverse(str2.begin(), str2.end());
		if (str.compare(str2)==0)
		{
			str2 = "";
			for (int i = 0; i < str.length(); ++i)
			{
				if (map[str[i]]!=' ')
					str2 += map[str[i]];
				else
					str2 += str[i];
			}
			string str3 = str;
			reverse(str3.begin(), str3.end());
			if (str2.compare(str3)==0)
			{
				cout << str << " -- is a mirrored palindrome." << endl;
			}
			else{
				cout << str << " -- is a regular palindrome." << endl;
			}
		}
		else {
			str2 = "";
			for (int i = 0; i < str.length(); ++i)
			{
				if (map[str[i]]!=' ')
					str2 += map[str[i]];
				else
					str2 += str[i];
			}
			string str3 = str;
			reverse(str3.begin(), str3.end());
			if (str2.compare(str3)==0)
			{
				cout << str << " -- is a mirrored string." << endl;
			}
			else{
				cout << str << " -- is not a palindrome." << endl;
			}
		}
		cout << endl;
	}
	fclose(stdout);
	return 0;
}
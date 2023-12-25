#include <iostream>
#include <string>
using namespace std;

string lcs(const string& str1, const string& str2, int m, int n) 
{

	if (m == 0 || n == 0)
		return "";
	
	if (str1[m - 1] == str2[n - 1])
		return lcs(str1, str2, m - 1, n - 1) + str1[m - 1];
	else
	{	
		string s1= lcs(str1, str2, m, n - 1);
		string s2 = lcs(str1, str2, m - 1, n);
		return (s1.length() > s2.length()) ? s1 : s2;
	}
}

int main()
{
	int n;
	cout << "how many sequences you want to enter? : ";
	cin >> n;
	cin.ignore();
	string* s = new string[n];
	for (int i = 0; i < n; i++)
	{
		cout << "enter sequence " << i + 1 << " : ";
		getline(cin,s[i]);
	}
	if (n > 1)
	{
		string ans = lcs(s[0], s[1],s[0].length(),s[1].length());
		for (int i = 2; i < n; i++)
			ans = lcs(ans, s[i], ans.length(), s[i].length());
		cout << "longest common subsequence is : " << ans;
		return 0;
	}
	else if (n == 1)
		cout << s[0];
	return 0;
}
#include <iostream>
#include <string>
using namespace std;

string lcs(const string& str1, const string& str2) 
{
    int length1 = str1.length();
    int length2 = str2.length();
    int** dp = new int* [length1 + 1];
    for (int i = 0; i < length1 + 1; i++)
        dp[i] = new int[length2 + 1]{ 0 };

    
    for (int i = 1; i <= length1; i++) 
    {
        for (int j = 1; j <= length2; j++) 
        {
            if (str1[i - 1] == str2[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else 
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    
    int i = length1;
    int j = length2;
    string result;

    while (i > 0 && j > 0) 
    {
        if (str1[i - 1] == str2[j - 1])
        {
            result = str1[i - 1] + result;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else 
            j--;
    }

    for (int i = 0; i < length1 + 1; i++)
        delete[] dp[i];
    delete[] dp;
    dp = nullptr;

    return result;
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
		getline(cin, s[i]);
	}
	if (n > 1)
	{
		string ans = lcs(s[0], s[1]);
		for (int i = 2; i < n; i++)
			ans = lcs(ans, s[i]);
		cout << "longest common subsequence is : " << ans;
		return 0;
	}
	else if (n == 1)
		cout << s[0];
	return 0;
}
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

bool areMultiples(int* denominations, int size)
{
	for (int i = 0; i < size-1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (denominations[i] % denominations[j] != 0)
				return false;
		}
	}
	return true;
}

int coinChangeGreedy(int* denominations, int size, int total)
{
	int noOfCoins = 0;
	for (int i = 0; i < size && total > 0; i++)
	{
		noOfCoins = noOfCoins + total / denominations[i];
		total = total % denominations[i];
	}
	if (total > 0)
		return -1;
	else
		return noOfCoins;
}

int coinChangeDP(int* denominations,int size, int total)
{
	
	int* dp = new int[total + 1];
	for (int i = 0; i <= total; i++)
		dp[i] = INT_MAX;

	dp[0] = 0;

	
	for (int i = 1; i <= total; i++) 
	{
		for (int j = 0; j < size; j++)
		{
			if (i >= denominations[j] && dp[i - denominations[j]] != INT_MAX)
				dp[i] = min(dp[i], dp[i - denominations[j]] + 1);		
		}
	}
	
	return (dp[total] == INT_MAX) ? -1 : dp[total];
}

int main()
{
	int n;
	string s;
	ifstream file;
	file.open("denominations.txt");
	file >> n;
	int* denominations = new int[n];
	for (int i = 0; i < n; i++)
	{
		file >> s;
		file >> denominations[i];
	}
	
	cout << "denominations are : " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << denominations[i];
		cout << ' ' << s << '\b';
		cout << " \n";
	}
	int total;
	cout << "enter total money : ";
	cin >> total;

	int noOfCoins;
	if (areMultiples(denominations, n))
		noOfCoins = coinChangeGreedy(denominations, n, total);
	else
		noOfCoins = coinChangeDP(denominations, n, total);

	if (noOfCoins == -1)
		cout << "solution not possible";
	else
		cout << "minimum number of coins required for change : " << noOfCoins;

	return 0;
}
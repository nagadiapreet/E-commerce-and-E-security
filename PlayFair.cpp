#include<bits/stdc++.h>
using namespace std;

char GenerateKey(string Key, char ans[5][5])
{
	bool isPresent[26] = {false};
	int N = Key.length();
	string new_key = "";

	//Removing Duplicates
	for(int n=0;n<N;n++)
	{
		if(!isPresent[Key[n]-'a'])
		{
			new_key += Key[n];
			isPresent[Key[n]-'a'] = true;
		}
	}

	Key = "";
	N = new_key.length();

	//original key without duplicates
	for(int n=0;n<N;n++)
	{
		int row = n/5;
		int col = n%5;
		ans[row][col] = new_key[n];
	}

	//appending remaining letters
	for(int n=0;n<26;n++)
	{
		if(!isPresent[n] && (char)('a'+n)!='j')
		{
			int row = N/5;
			int col = N%5;
			ans[row][col] = (char)('a'+n);
			N++;
		}
	}

	char filler;
	for(int n=0;n<26;n++)
	{
		if(!isPresent[n])
			return (char)('a'+n);
	}
}

int findRow(char key[5][5], char X)
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(key[i][j]==X)
				return i;
		}
	}
}

int findCol(char key[5][5], char X)
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(key[i][j]==X)
				return j;
		}
	}
}

string Encrypt(string data, char key[5][5], char filler)
{
	int N = data.length();
	string new_data = "";
	string ans = "";

	new_data += data[0];
	for(int n=1;n<N;n++)
	{
		if(new_data[new_data.length()-1]==data[n])
		{
			new_data += filler;
			n--;
		}
		else
			new_data += data[n];
	}

	N = new_data.length();
	if(N%2==1)
	{
		new_data += filler;
		N++;
	}

	for(int n=0;n<N;n+=2)
	{
		int r1 = findRow(key, new_data[n]);
		int c1 = findCol(key, new_data[n]);
		int r2 = findRow(key, new_data[n+1]);
		int c2 = findCol(key, new_data[n+1]);

		if(r1==r2)
		{
			ans += key[r1][(c1+1)%5];
			ans += key[r2][(c2+1)%5];
		}
		else if(c1==c2)
		{
			ans += key[(r1+1)%5][c1];
			ans += key[(r2+1)%5][c2];
		}
		else
		{
			ans += key[r1][c2];
			ans += key[r2][c1];
		}
	}

	return ans;
}

int main()
{
	cout<<"********** PlayFair Cipher ***********"<<endl;
	cout<<"Enter Plain Text(No spaces/only small alphabets): ";
	string plainText;
	cin>>plainText;

	cout<<"Enter Key(No spaces/only small alphabets): ";
	string tempKey;
	cin>>tempKey;

	char Key[5][5];
	char filler = GenerateKey(tempKey, Key);
	cout<<"Generated Key: "<<endl;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
			cout<<Key[i][j]<<" ";
		cout<<endl;
	}

	string cipherText = Encrypt(plainText, Key, filler);
	cout<<"CipherText = "<<cipherText<<endl;

	return 0; 
}

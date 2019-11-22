#include<bits/stdc++.h>
using namespace std;

string GenerateKey(string Key)
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
		Key += new_key[n];

	//appending remaining letters
	for(int n=0;n<26;n++)
	{
		if(!isPresent[n])
			Key += (char)('a'+n);
	}

	return Key;
}

string Encrypt(string data, string key)
{
	int N = data.length();
	string ans = "";

	for(int n=0;n<N;n++)
		ans += key[data[n]-'a'];

	return ans;
}

string Decrypt(string data, string key)
{
	int N = data.length();
	string ans = "";

	for(int n=0;n<N;n++)
	{
		int index;
		for(index=0;index<26;index++)
		{
			if(key[index]==data[n])
				break;
		}
		ans += (char)(index + 'a');
	}
	return ans;
}

int main()
{
	cout<<"********** MonoAlphabetic ***********"<<endl;
	cout<<"Enter Plain Text(No spaces/only small alphabets): ";
	string plainText;
	cin>>plainText;

	cout<<"Enter Key(No spaces/only small alphabets): ";
	string Key;
	cin>>Key;

	Key = GenerateKey(Key);
	cout<<"Generated Key: "<<Key<<endl;

	string cipherText = Encrypt(plainText, Key);
	cout<<"CipherText = "<<cipherText<<endl;

	cout<<"PlainText = "<<Decrypt(cipherText, Key)<<endl;

	return 0; 
}

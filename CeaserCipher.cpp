#include<bits/stdc++.h>
using namespace std;

string Encrypt(string data, int key)
{
	int N = data.length();
	string ans = "";

	for(int n=0;n<N;n++)
	{
		char temp = (char)('a' + (data[n] - 'a' + key)%26);
		ans += temp;
	}
	return ans;
}

string Decrypt(string data, int key)
{
	int N = data.length();
	string ans = "";

	for(int n=0;n<N;n++)
	{
		char temp = (char)('a' + (data[n] -'a' - key + 26)%26);
		ans += temp;
	}
	return ans;
}

int main()
{
	cout<<"********** Ceaser Cipher ***********"<<endl;
	cout<<"Enter Plain Text(No spaces/only small alphabets): ";
	string plainText;
	cin>>plainText;

	cout<<"Enter Key: ";
	int Key;
	cin>>Key;

	string cipherText = Encrypt(plainText, Key);
	cout<<"CipherText = "<<cipherText<<endl;

	cout<<"PlainText = "<<Decrypt(cipherText, Key)<<endl;

	return 0; 
}

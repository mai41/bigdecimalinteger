#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class BigDecimalInt
{
private:
	int carry = 0;
	bool check = false;
	//vector <int> num;
	string s1;
	string dec = "";
	char temp;
	string temp_2 = "1";
	int n;
public:
	BigDecimalInt(string decStr); // Initialize from string
	BigDecimalInt(int decInt); // Initialize from integer
	friend void equalsize(string, BigDecimalInt);
	friend bool checkbigger(string, BigDecimalInt);
	BigDecimalInt operator+ (BigDecimalInt anotherDec);
	BigDecimalInt operator- (BigDecimalInt anotherDec);
	friend ostream& operator<< (ostream & out, BigDecimalInt b1);
	void plusminusplus(BigDecimalInt anotherDec);
	void plusminusminus(BigDecimalInt anotherDec);
	virtual ~BigDecimalInt();

};



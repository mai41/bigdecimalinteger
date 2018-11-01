#include "BigDecimalInt.h"


BigDecimalInt::BigDecimalInt(string decStr)
{
	s1 = decStr;
	if (s1[0] == '-')
	{
		s1.erase(0, 1);
		check = true;
	}

}
BigDecimalInt::BigDecimalInt(int decInt)
{

}
void BigDecimalInt::plusminusplus(BigDecimalInt anotherDec) {
	for (int i = s1.length() - 1; i >= 0; i--)
	{
		if (anotherDec.s1[i] > s1[i] - carry)
		{
			n = (s1[i] - '0' - carry) + 10 - (anotherDec.s1[i] - '0');
			carry = 1;
		}
		else
		{

			n = (s1[i] - '0' - carry) - (anotherDec.s1[i] - '0');
		}
		temp = n + '0';
		dec = temp + dec;
	}//dec = '-' + dec;
}
void BigDecimalInt::plusminusminus(BigDecimalInt anotherDec) {
	for (int i = s1.length() - 1; i >= 0; i--)
	{
		if (i != 0) {

			if (anotherDec.s1[i] > s1[i] - carry)
			{
				n = (anotherDec.s1[i] - '0' - carry) + 10 - (s1[i] - '0');
				carry = 1;
			}
			else
			{

				n = (anotherDec.s1[i] - '0' - carry) - (s1[i] - '0');
			}
			temp = n + '0';
			dec = temp + dec;
		}
		else
		{
			n = (anotherDec.s1[i] - '0' - carry) - (s1[i] - '0');
		}


	}
	//dec = '-' + dec;
}
void equalsize(string s1, BigDecimalInt b2)
{
	if (s1.length() > b2.s1.length())
	{
		for (int i = 0; i <= (s1.length() - b2.s1.length()); i++)
		{
			b2.s1 = '0' + b2.s1;

		}
	}
	else if (s1.length() < b2.s1.length())
	{
		for (int i = 0; i <= (b2.s1.length() - s1.length()); i++)
		{
			s1 = '0' + s1;
		}

	}
}
bool checkbigger(string s1, BigDecimalInt b1)
{
	for (int i = 0; i < s1.length(); i++)
	{
		if (b1.s1[i] == s1[i])
			continue;
		else if (s1[i] > b1.s1[i])
			return true;
		else
			return false;
	}
	return true;
}
ostream& operator<< (ostream & out, BigDecimalInt b1)
{
	for (int j = 0;j < b1.s1.length(); j++)
	{
		out << b1.s1[j] << " ";
	}
	return out;

}
BigDecimalInt BigDecimalInt:: operator+ (BigDecimalInt anotherDec)
{
	equalsize(s1, anotherDec);
	if (!check && !anotherDec.check)
	{
		for (int k = anotherDec.s1.length() - 1; k >= 0; k--)
		{
			if ((anotherDec.s1[k] - '0' + s1[k] - '0' + carry) >= 10)
			{
				n = anotherDec.s1[k] - '0' + s1[k] - '0' + carry - 10;
				carry = 1;
			}
			else
			{
				n = anotherDec.s1[k] - '0' + s1[k] - '0' + carry;
				carry = 0;
			}
			temp = n + '0';
			dec = temp + dec;
		}
		return BigDecimalInt(dec);
	}
	else if (!anotherDec.check && check)
	{
		cout << "**********";

		cout << "fffff:";
		for (int i = s1.length() - 1; i >= 0; i--)
		{
			if (anotherDec.s1[i] < s1[i] - carry)
			{
				n = (anotherDec.s1[i] - '0') + 10 - (s1[i] - '0' - carry);
				carry = 1;
			}
			else
			{

				n = (anotherDec.s1[i] - '0') - (s1[i] - '0' - carry);
			}
			temp = n + '0';
			dec = temp + dec;
		}
		return BigDecimalInt(dec);

	}
	else if (anotherDec.check && !check) {
		if (checkbigger(s1, anotherDec) == true)
		{
			/*for (int i = s1.length() - 1; i >= 0; i--)
			{
				if (anotherDec.s1[i] > s1[i] - carry)
				{
					n = (s1[i] - '0' - carry)+ 10 -(anotherDec.s1[i] - '0') ;
					carry = 1;
				}
				else
				{

					n = (s1[i] - '0' - carry)-(anotherDec.s1[i] - '0');
				}
				temp = n + '0';
				dec = temp + dec;
			}//dec = '-' + dec;*/
			plusminusplus(anotherDec);
		}
		else {
			//	plusminusminus(anotherDec);
				//dec = '-' + dec;
		}
		return BigDecimalInt('-' + dec);
	}
	else if (anotherDec.check && check)
	{
		for (int k = anotherDec.s1.length() - 1; k >= 0; k--)
		{
			if ((anotherDec.s1[k] - '0' + s1[k] - '0' + carry) >= 10)
			{
				n = anotherDec.s1[k] - '0' + s1[k] - '0' + carry - 10;
				carry = 1;
			}
			else
			{
				n = anotherDec.s1[k] - '0' + s1[k] - '0' + carry;
				carry = 0;
			}
			temp = n + '0';
			dec = temp + dec;
		}dec = '-' + dec;
		return BigDecimalInt('-' + dec);
	}
}
BigDecimalInt BigDecimalInt :: operator- (BigDecimalInt anotherDec)
{
	dec = "";
	carry = 0;
	equalsize(s1, anotherDec);
	if (!anotherDec.check && !check)
	{
		for (int i = s1.length() - 1; i >= 0; i--)
		{
			if (anotherDec.s1[i] < s1[i] - carry)
			{
				n = (anotherDec.s1[i] - '0') + 10 - (s1[i] - '0' - carry);
				carry = 1;
			}
			else
			{

				n = (anotherDec.s1[i] - '0') - (s1[i] - '0' - carry);
			}
			temp = n + '0';
			dec = temp + dec;
		}
		return BigDecimalInt(dec);
	}
	else if (anotherDec.check && !check)
	{


		for (int k = anotherDec.s1.length() - 1; k >= 0; k--)
		{
			if ((anotherDec.s1[k] - '0' + s1[k] - '0' + carry) >= 10)
			{
				n = anotherDec.s1[k] - '0'
					+ s1[k] - '0' + carry - 10;
				carry = 1;
			}
			else
			{
				n = anotherDec.s1[k] - '0' + s1[k] - '0' + carry;
				carry = 0;
			}
			temp = n + '0';
			dec = temp + dec;
		}
		//dec = '-' + dec;
		return BigDecimalInt('-' + dec);
	}
	else if (!anotherDec.check && check)
	{
		for (int k = anotherDec.s1.length() - 1; k >= 0; k--)
		{
			if ((anotherDec.s1[k] - '0' + s1[k] - '0' + carry) >= 10)
			{
				n = anotherDec.s1[k] - '0' + s1[k] - '0' + carry - 10;
				carry = 1;
			}
			else
			{
				n = anotherDec.s1[k] - '0' + s1[k] - '0' + carry;
				carry = 0;
			}
			temp = n + '0';
			dec = temp + dec;
		}
		return BigDecimalInt(dec);
	}
	else if (anotherDec.check && check)
	{

		for (int i = s1.length() - 1; i >= 0; i--)
		{
			if (anotherDec.s1[i] > s1[i] - carry)
			{
				n = (s1[i] - '0' - carry) + 10 - (anotherDec.s1[i] - '0');
				carry = 1;
			}
			else
			{

				n = (s1[i] - '0' - carry) - (anotherDec.s1[i] - '0');
			}
			temp = n + '0';
			dec = temp + dec;
		}
		dec = '-' + dec;

		return BigDecimalInt('-' + dec);
	}
}
BigDecimalInt::~BigDecimalInt()
{
}


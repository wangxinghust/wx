#include <string>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		string s;
		int thousands = num / 1000;
		num -= thousands * 1000;
		for (int i = 0; i < thousands; ++i) {
			s += 'M';
		}
		int hundreds = num / 100;
		num -= hundreds * 100;
		switch (hundreds) {
		case 1:s += 'C'; break;
		case 2:s += "CC"; break;
		case 3:s += "CCC"; break;
		case 4:s += "CD"; break;
		case 5:s += "D"; break;
		case 6:s += "DC"; break;
		case 7:s += "DCC"; break;
		case 8:s += "DCCC"; break;
		case 9:s += "CM"; break;
		}
		int tens = num / 10;
		num -= tens * 10;
		switch (tens) {
		case 1:s += 'X'; break;
		case 2:s += "XX"; break;
		case 3:s += "XXX"; break;
		case 4:s += "XL"; break;
		case 5:s += "L"; break;
		case 6:s += "LX"; break;
		case 7:s += "LXX"; break;
		case 8:s += "LXXX"; break;
		case 9:s += "XC"; break;
		}
		switch (num) {
		case 1:s += 'I'; break;
		case 2:s += "II"; break;
		case 3:s += "III"; break;
		case 4:s += "IV"; break;
		case 5:s += "V"; break;
		case 6:s += "VI"; break;
		case 7:s += "VII"; break;
		case 8:s += "VIII"; break;
		case 9:s += "IX"; break;
		}
		return s;
	}

	const int ints[13] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
	const string roman[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	string intToRoman2(int num) {
		string s;
		while (num > 0) {
			for (int i = 0; i < 13; ++i) {
				if (num / ints[i] > 0) {
					s += (roman[i]);
					num -= ints[i];
					break;
				}
			}
		}
		return s;
	}

	string intToRoman3(int num) {
		//'I' = 1, 'X' = 10, 'C' = 100, 'M' = 1000, 'V' = 5, 'L' = 50, 'D' = 500;
		// Subtractive Notation
		// Number	 4	 9	 40     90      400     900
		// Notation	 IV	 IX	 XL	XC	CD      CM
		string res = "";
		while (num >= 1000) {
			num -= 1000;
			res.push_back('M');
		}
		if (num >= 900) {
			num -= 900;
			res.append("CM");
		}
		if (num >= 500) {
			num -= 500;
			res.push_back('D');
		}
		if (num >= 400) {
			num -= 400;
			res.append("CD");
		}
		while (num >= 100) {
			num -= 100;
			res.push_back('C');
		}
		if (num >= 90) {
			num -= 90;
			res.append("XC");
		}
		if (num >= 50) {
			num -= 50;
			res.push_back('L');
		}
		if (num >= 40) {
			num -= 40;
			res.append("XL");
		}
		while (num >= 10) {
			num -= 10;
			res.push_back('X');
		}
		if (num >= 9) {
			num -= 9;
			res.append("IX");
		}
		if (num >= 5) {
			num -= 5;
			res.push_back('V');
		}
		if (num >= 4) {
			num -= 4;
			res.append("IV");
		}
		while (num > 0) {
			num -= 1;
			res.push_back('I');
		}
		return res;
	}
};

//int main(int argc, char* argv[]) {
//	Solution a;
//	string s = a.intToRoman2(800);
//	return 0;
//}
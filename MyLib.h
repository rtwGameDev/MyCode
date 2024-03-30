#pragma once
#include <iostream>
#include <string>
using namespace std;

// Noi day chua cac ham doc lap voi cac thu vien

string Number_to_String(int number) {
	if (number == 0) return "0";
	string result = "";
	int n;
	while (number != 0) {
		n = number % 10;
		result = ((char)(n + 48)) + result;
		number = (number - n) / 10;
	}
	return result;
}
int String_to_Number(string str) {
	int result = 0; int index = 1;
	for (int i = (int)str.length() - 1; i >= 0; --i) {
		if (str[i] < '0' || str[i] > '9') {
			return -1;
		}
		result += ((int)str[i] - 48) * index;
		index = index * 10;
	}
	return result;
}
string FormatPassWord(string password) {
	string result = "";
	return "";
}
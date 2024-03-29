#pragma once
#ifndef MyLib_H
#define MyLib_H
#include <iostream>
#include <string>
#include <math.h>
#include "DSCB.h"
using namespace std;
	// convert number to string
	string Number_to_String(int number) {
		if (number == 0) return "0";
		string result = "";
		int n;
		while (number != 0) {
			n = number % 10;
			result = ((char) (n + 48)) + result;
			number = (number - n) / 10;
		}
		return result;
	}
	// convert string to number
	int String_to_Number(string str) {
		int result = 0; int index = 1;
		for (int i = (int) str.length() - 1; i >= 0; --i) {
			if (str[i] < '0' || str[i] > '9') {
				return -1;
			}
			result += ((int) str[i] - 48) * index;
			index = index * 10;
		}
		return result;
	}
	
	// Ma dong
	string HANDLE_LineCode(int iDong, int numberOfCharDONG) {
		string line_code = Number_to_String(iDong);
		for (int i = 1; i <= numberOfCharDONG - line_code.length(); ++i) {
			line_code = "0" + line_code;
		}
		return line_code;
	}

	// ma day
	void HANDLE_RangeCode(int soDay, int soDong, TICKET* LIST_TICKET) {
		int index = 1;
		int count = 1;
		int numberOfCharDAY = 0;
		float round = log((float)soDay) / log(26.0);
		float floor = (int)(log((float)soDay) / log(26.0));
		if (round - floor == 0) numberOfCharDAY = floor;
		else numberOfCharDAY = floor + 1;
		if (numberOfCharDAY == 0) numberOfCharDAY = 1;
		int numberOfCharDONG = (int) Number_to_String(soDong).length();

		// sinh cau hinh dau + cau hinh cuoi
		string start = "", end = "";
		for (int i = 1; i <= numberOfCharDAY; ++i) {
			start = "A" + start;
			end = "Z" + end;
		}
		string running = start;
		while (count <= soDay) {
			for (int i = 1; i <= soDong; ++i) {
				string codeTicket = "";
				codeTicket = running + HANDLE_LineCode(i, numberOfCharDONG);
				LIST_TICKET[index++].TICKET_CODE = codeTicket;
			}
			if (running == end) break;
			// chay xong vong for, ta da co dc day ma ve o day thu count = 1
			// count++ => tang len chuyen den day ve tiep theo
			// tang running them 1
			count++;
			// j la chi so nam cuoi config AAA
			int j = numberOfCharDAY - 1;
			bool ctn = true;
			while (ctn) { // ctn -> continue
				if (j < 0) ctn = false;
				else {
					if (running[j] < 'Z') {
						running[j] = (char)((int)running[j] + 1);
						ctn = false;
					}
					else {
						for (int k = j; k <= numberOfCharDAY - 1; ++k) {
							running[k] = 'A';
						}
						j--;
					}
				}
			}
			// ket thuc vong while => ta co dc cau hinh tiep theo va chac chan se ko bi day
		}
	}
	// Sinh so ve tu so dong va so day
	void GTicketNumber(int soDay, int soDong,TICKET* LIST_TICKET) {
		// so luong phan tu cua LIST_TICKET = soDay * soDong + 1
		HANDLE_RangeCode(soDay, soDong, LIST_TICKET);
	}
#endif
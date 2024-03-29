#pragma once
#ifndef TIMEFORMAT_H
#define TIMEFORMAT_H
#include <string>
#include <ctime>
#include <math.h>
#include "MyLib.h"
	const int MONTH[13] = { 0,31,28,31,30,31, 30, 31,31,30,31,30,31 };
	struct DATE_TIME {
		string day;
		string month;
		string year;
		string hour;
		string minute;
		DATE_TIME() {}
		DATE_TIME(string day, string month, string year, string hour, string minute) {
			this->day = day;
			this->month = month;
			this->year = year;
			this->hour = hour;
			this->minute = minute;
		}
		~DATE_TIME() {}
	};

	// chuyen doi thoi gian ve chuoi de hien thi
	// Tai sao thoi gian lai su dung string => khi convert qua cac chuan dinh dang thoi gian, vi du nhu 01/01/2023 thi dang int se ko lam dc (1/1/...)

	string getStringDATE_TIME(DATE_TIME date_time) {
		string time_to_string = "";
		time_to_string = time_to_string + date_time.day + "/"
			+ date_time.month + "/"
			+ date_time.year + " "
			+ date_time.hour + ":"
			+ date_time.minute;
		return time_to_string;
	}

	// Dinh dang lai thoi gian => "--/--/---- --:--"
	void Format(DATE_TIME& date_time) {
		if ((date_time.day).length() == 1) {
			date_time.day = "0" + date_time.day;
		}
		if ((date_time.month).length() == 1) {
			date_time.month = "0" + date_time.month;
		}
		if ((date_time.hour).length() == 1) {
			date_time.hour = "0" + date_time.hour;
		}
		if ((date_time.minute).length() == 1) {
			date_time.minute = "0" + date_time.minute;
		}
	}
	// Lay thoi gian hien tai
	DATE_TIME getCurrentTime() {
		// struct tm chua cac dinh dang thoi gian
		tm currentTime;

		// time_t tra lai thoi gian tihnh bang giay ke tu Epoch (01/01/1970)
		time_t now = time(0);

		// chuyen doi tu s sang doi tuong currentTime;
		localtime_s(&currentTime, &now);

		DATE_TIME date_time;
		date_time.day = Number_to_String(currentTime.tm_mday);
		date_time.month = Number_to_String(currentTime.tm_mon + 1);
		date_time.year = Number_to_String(currentTime.tm_year + 1900);
		date_time.hour = Number_to_String(currentTime.tm_hour);
		date_time.minute = Number_to_String(currentTime.tm_min);

		Format(date_time);

		return date_time;
	}
	// Ktra nam nhuan
	bool isLeapYear(int year) {
		if (year % 400 == 0)
			return true;
		if (year % 100 != 0 && year % 4 == 0)
			return true;
		return false;
	}

	// Chia tach kiem tra NGAY THANG NAM va GIO PHUT ra rieng voi vi NGAY THANG NAM TRONG 1 THANG BAT KI CO THE KHAC NHAU
	// 
	// Ktra xem 1 dinh dang DATE_TIME co dung theo lich hay ko
	bool checkDATE(DATE_TIME date_time) {
		int day = String_to_Number(date_time.day);
		int month = String_to_Number(date_time.month);

		int year = String_to_Number(date_time.year);

		if (year < 0) return false;

		switch (month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		{
			if (day <= 31 || day > 0) { return true; }
			else { return false; }
		}
		case 2:
		{
			if (isLeapYear(year) == true && day <= 29 && day >= 1) { return true; }
			else {
				if (isLeapYear(year) == false && day <= 28 && day >= 1) { return true; }
				else { return false; }
			}
		}
		case 4: case 6: case 9: case 11:
		{
			if (day <= 30 && day >= 1) { return true; }
			else { return false; }
		}
		default:
		{
			return false;
		}
		}
	}

	// Kiem tra tung thanh phan cua thoi gian
	bool checkTime_Hour(DATE_TIME date_time) {
		int hour = String_to_Number(date_time.hour);
		if (hour <= 23 && hour >= 0) return true;
		return false;
	}
	bool checkTime_minute(DATE_TIME date_time) {
		int minute = String_to_Number(date_time.minute);
		if (minute <= 59 && minute >= 0) return true;
		return false;
	}
	// Ktra GIO PHUT
	bool checkTIME(DATE_TIME date_time) {
		if (checkTime_Hour(date_time) && checkTime_minute(date_time)) return true;
		return false;
	}

	// Tinh so ngay ke tu 0/0/0
	int calDate_To_day(DATE_TIME date_time) {
		if (checkDATE(date_time) == true && checkTIME(date_time) == true) {
			Format(date_time);
			int year = String_to_Number(date_time.year);
			int month = String_to_Number(date_time.month);
			int day = String_to_Number(date_time.day);

			int DayOfYear = (year - 1) * 355 + (year - 1) / 4;
			int DayofMonth = 0;
			for (int i = 1; i <= month - 1; ++i) {
				DayofMonth += MONTH[i];
			}
			if (isLeapYear(year) == true && month > 2) {
				DayofMonth++;
			}
			return DayofMonth + DayOfYear + day - 1;
		}
		return -1;
	}
	// Tinh so phut giua 2 thoi diem
	long long calSpaceTime(DATE_TIME before, DATE_TIME after) {
		if (checkDATE(before) == true &&
			checkDATE(after) == true &&
			checkTIME(before) == true &&
			checkTIME(after) == true) 
		{
			Format(before);
			Format(after);
			long long hour = String_to_Number(before.hour);
			long long minute = String_to_Number(before.minute);

			long long minuteBefore = calDate_To_day(before) * 24 * 60 + hour * 60 + minute;

			hour = String_to_Number(after.hour);
			minute = String_to_Number(after.minute);

			long long minuteAfter = calDate_To_day(after) * 24 * 60 + hour * 60 + minute;

			return minuteAfter - minuteBefore;
		}
		return -1;
	}

	// Kitra thoi gian nhap vao va hien tai cach nhau bao nhiu phut
	long long checkTimeBefore(DATE_TIME date_time) {
		Format(date_time);
		DATE_TIME now = getCurrentTime();
		return calSpaceTime(date_time, now);
	}

	// Xac dinh xem thoi diem la o tuong lai hay qua khu
	// true => o tuong lai
	// false => o qua khu
	bool Past_future(DATE_TIME date_time) {
		Format(date_time);
		if (checkDATE(date_time) == false && checkTIME(date_time) == false) return false;
		// tgian da dung dinh dang
		DATE_TIME now = getCurrentTime();
		int hour_now =   String_to_Number(now.hour);
		int minute_now =   String_to_Number(now.minute);
		int day_now =   String_to_Number(now.day);
		int month_now =   String_to_Number(now.month);
		int year_now =   String_to_Number(now.year);
		
		int hour_dt =   String_to_Number(date_time.hour);
		int minute_dt =   String_to_Number(date_time.minute);
		int day_dt =   String_to_Number(date_time.day);
		int month_dt =   String_to_Number(date_time.month);
		int year_dt =   String_to_Number(date_time.year);

		if (year_dt > year_now) return true;
		else if (year_dt < year_now) return false;
		else {
			if (month_dt > month_now) return true;
			else if (month_dt < month_now) return false;
			else {
				if (day_dt > day_now) return true;
				else if (day_dt < day_now) return false;
				else {
					if (hour_dt > hour_now) return true;
					else if (hour_dt < hour_now) return false;
					else {
						if (minute_dt > minute_now) return true;
						else return false;
					}
				}
			}
		}
	}
	bool inThreeHours(DATE_TIME before, DATE_TIME after) {
		long long spaceTime = calSpaceTime(before, after);
		if (spaceTime <= 180) return true;
		return false;
	}
	bool inThirtyMinute(DATE_TIME before, DATE_TIME after) {
		long long spaceTime = calSpaceTime(before, after);
		if (spaceTime <= 30) return true;
		return false;
	}

#endif
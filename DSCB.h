#pragma once
#include <string>
#include "TimeFormat.h"
using namespace std;
enum TRANGTHAI {HUYCHUYEN, CONVE, HETVE, HOANTHANH};

// ve tren 1 chuyen bay
struct ticket {
	int SCMND{};
	string TICKET_CODE{};
	ticket() {}
	ticket(int SCMND, string TICKET_CODE) {
		this->SCMND = SCMND;
		this->TICKET_CODE = TICKET_CODE;
	}
};

// Thong tin 1 chuyen bay
struct Flight {
	string FilghtCode{}; // ma chuyen bay -- key
	dateTime giokhoihanh; // Ngay gio khoi hanh --------------------------------- BUG
	string Destination{}; // dai diem den
	TRANGTHAI flightStatus;
	string SoHieuMB;
	ticket* DS_VE = nullptr;
};

// moi nodeCB la 1 chuyen bay
struct NodeCB {
	// flight - chuyen bay
	Flight flight;
	NodeCB* next;
};


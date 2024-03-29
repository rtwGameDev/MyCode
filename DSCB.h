#pragma once
#ifndef DSCB_H
#define DSCB_H
#include <string>
#include "TimeFormat.h"
using namespace std;
	enum STATE {HUYCHUYEN, CONVE, HETVE, HOANTHANH};

	// ve tren 1 chuyen bay
	struct TICKET {
		int SCMND{};
		string TICKET_CODE{};
		TICKET() {}
		TICKET(int SCMND, string TICKET_CODE) {
			this->SCMND = SCMND;
			this->TICKET_CODE = TICKET_CODE;
		}
	};

	// Thong tin 1 chuyen bay
	struct Flight {
		string FilghtCode{}; // ma chuyen bay -- key
		// DATE_TIME TG_KhoiHanh; // Ngay gio khoi hanh --------------------------------- BUG
		string Destination{}; // dai diem den
		STATE flightStatus;
		string SoHieuMB;
		TICKET* DS_VE = nullptr;
	};

	// moi nodeCB la 1 chuyen bay
	struct NodeCB {
		// flight - chuyen bay
		Flight flight;
		NodeCB* next;
	};

#endif
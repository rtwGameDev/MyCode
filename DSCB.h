#pragma once
#include <string>
#include "TimeFormat.h"
using namespace std;

// cac trang thai cua chuyen bay
enum TRANGTHAI {HUYCHUYEN, CONVE, HETVE, HOANTHANH};

// Luu thong tin cua 1 ve
struct ticket {
	int SCMND{};
	string TICKET_CODE{};
	ticket() {}
	ticket(int SCMND, string TICKET_CODE) {
		this->SCMND = SCMND;
		this->TICKET_CODE = TICKET_CODE;
	}
};

// Tao mang danh sach ve
// --------------------------------------------------------------------------------------------------------------------------------------------------------------
string handleLineCode(int iDong, int numberOfCharDONG) {
	string line_code = Number_to_String(iDong);
	for (int i = 1; i <= numberOfCharDONG - line_code.length(); ++i) {
		line_code = "0" + line_code;
	}
	return line_code;
}

void handleRangeCode(int soDay, int soDong, ticket* listTicket) {
	int index = 1;
	int count = 1;
	int numberOfCharDAY = 0;
	float round = log((float)soDay) / log(26.0);
	float floor = (int)(log((float)soDay) / log(26.0));
	if (round - floor == 0) numberOfCharDAY = floor;
	else numberOfCharDAY = floor + 1;
	if (numberOfCharDAY == 0) numberOfCharDAY = 1;
	int numberOfCharDONG = (int)Number_to_String(soDong).length();

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
			codeTicket = running + handleLineCode(i, numberOfCharDONG);
			listTicket[index++].TICKET_CODE = codeTicket;
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

void GTicketNumber(int soDay, int soDong, ticket* listTicket) {
	// so luong phan tu cua LIST_TICKET = soDay * soDong + 1
	handleRangeCode(soDay, soDong, listTicket);
}
// --------------------------------------------------------------------------------------------------------------------------------------------------------------


// Thong tin cua 1 chuyen bay
struct Flight {
	string FlightCode{};
	dateTime Departure;
	string Destination{}; 
	TRANGTHAI flightStatus{};
	string SoHieuMB{};
	ticket* DS_VE = nullptr;
	Flight() {}
	Flight(string FlightCode, dateTime Departure, string Destination, TRANGTHAI status, string SoHieuMB) {
		this->FlightCode = FlightCode;
		this->Departure = Departure;
		this->Destination = Destination;
		this->flightStatus = status;
		this->SoHieuMB = SoHieuMB;
	}
	~Flight(){}
};
void KhoiTao_DSV(int soDay, int soDong, ticket* &DS_VE) {
	int soCho = soDay * soDong;
	DS_VE = new ticket[soCho + 1];
	GTicketNumber(soDay, soDong, DS_VE);
	return;
}
// moi nodeCB la 1 chuyen bay
struct NodeCB {
	// flight - chuyen bay
	Flight flight;
	NodeCB* next = nullptr;
	NodeCB() {}
	NodeCB(Flight flight) {
		this->flight = flight;
	}
	~NodeCB() {}
};

class DSCB {
private:
	NodeCB* head = nullptr;
	int n = 0; // n la so luong phan tu
	void insertAfter(NodeCB* pointer, Flight flight) {
		if (pointer == nullptr) return;
		NodeCB* newElement = new NodeCB(flight);
		newElement->next = pointer->next;
		pointer->next = newElement;
		return;
	}
	void insertHere(NodeCB* pointer, Flight flight) {
		if (pointer == nullptr) return;
		insertAfter(pointer, flight);
		// swap
		Flight temp = pointer->flight;
		pointer->flight = (pointer->next)->flight;
		(pointer->next)->flight = temp;
	}
public:
	bool isEmpty() {
		if (head == nullptr) return true;
		return false;
	}
	void insertElement(string FlightCode, dateTime Departure, string Destination, TRANGTHAI status, string SoHieuMB) {
		n++;
		Flight flight(FlightCode, Departure, Destination, status, SoHieuMB);
		NodeCB* newElement = new NodeCB(flight);
		// ta da cxo 1 node moi

		// insert theo thu tu theo ma chuyen bay
		NodeCB* temp = head;
		if (temp == nullptr) head = newElement;
		else {
			// chac chan phan tu dau ko bang nullptr
			while ((temp->flight).FlightCode < FlightCode) {
				if (temp->next == nullptr) {
					// xay ra khi phan tu cuoi cung nho hon phan tu can insert vao
					// TH them vao cuoi danh sach chuyen bay
					temp->next = newElement;
					return;
				}
				temp = temp->next;
			}
			// luc nay, dia chi temp dang luu 1 chuyen bay co MCB vua lon hon phtu can insert
			insertHere(temp, flight);
		}
	}
	// => true neu xoa thanh cong, false neu ko co phan tu nao bi xoa
	bool deleteElement(string FlightCode) {
		if (head == nullptr) return false;
		NodeCB* pointerBefore = nullptr;
		NodeCB* pointerAfter = head;

		// xu ly truong hop phan tu can xoa nam ngay dau, head phai thay doi
		if ((pointerAfter->flight).FlightCode == FlightCode) {
			head = head->next;
			delete pointerAfter;
			n--;
			return true;
		}
		NodeCB* temp = nullptr;
		// phan tu can xoa ko nam o dau
		pointerBefore = head;
		pointerAfter = head->next;
		while ( ((pointerAfter)->flight).FlightCode != FlightCode) {
			pointerAfter = pointerAfter->next;
			pointerBefore = pointerBefore->next;
			if (pointerAfter == nullptr) return false;
		}
		// chay ra toi day, chac chan ton tai phan tu can xoa
		// pointerAfter != nullptr, va pointerAfter chinh la phan tu can xoa
		temp = pointerAfter;
		pointerBefore->next = pointerAfter->next;
		delete temp;
		n--;
		return true;
	}
	NodeCB* search(string FlightCode) {
		NodeCB* temp = head;
		while (temp != nullptr) {
			if ((temp->flight).FlightCode == FlightCode) return temp;
			temp = temp->next;
		}
		return nullptr;
	}
	void show() {
		NodeCB* temp = head;
		while (temp != nullptr) {
			cout << (temp->flight).FlightCode << endl;
			temp = temp->next;
		}
	}
	int getNumberElement() {
		return n;
	}
};

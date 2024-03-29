#pragma once
#ifndef DSMB_H
#define DSMB_H
#include <iostream>
#include <string>
using namespace std;
	struct NodeMB {
		string SoHieuMB;
		string LoaiMB;
		int soDay;
		int soDong;
		void prInfo() {
			cout << SoHieuMB << " - " << LoaiMB << endl;
		}
		NodeMB();
		NodeMB(string SoHieuMB, string LoaiMB, int soDay, int soDong) {
			this->SoHieuMB = SoHieuMB;
			this->LoaiMB = LoaiMB;
			this->soDay = soDay;
			this->soDong = soDong;
		}
		~NodeMB() {}
	};
	class DSMB {
	private:
		// Mang con tro
		NodeMB* arr[300];
		int index = -1;
	public:
		bool isEmpty() {
			if (index == -1) return true;
			return false;
		}
		int exist(string SoHieuMB) {
			if (index != -1) {
				for (int i = 0; i <= index; ++i) {
					if (arr[i]->SoHieuMB == SoHieuMB) return i;
				}
			}
			return -1;
		}
		bool search(string SoHieuMB) {
			if (exist(SoHieuMB) != -1) return true;
			return false;
		}
		int SoLuongMB() {
			return index + 1;
		}
		void show() {
			for (int i = 0; i <= index; ++i) {
				arr[i]->prInfo();
			}
		}
		void insertElement(string SoHieuMB, string LoaiMB, int soDay, int soDong) {
			if (index < 299) {
				NodeMB* newElement = new NodeMB(SoHieuMB, LoaiMB, soDay, soDong);
				arr[++index] = newElement;
			}
			else {
				// Xu ly loi Tran o nho
				cout << "Day danh sach" << endl;
				//
			}
		}
		void deleteElement(string SoHieuMB) {
			int chiso = exist(SoHieuMB);
			if (chiso != -1) {
				delete arr[chiso];
				for (int i = chiso; i <= index - 1; ++i) {
					arr[i] = arr[i + 1];
				}
				--index;
			}
		}
	};

#endif
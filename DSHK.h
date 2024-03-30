#pragma once
#include <iostream>
#include <string>
using namespace std;
enum Phai { Nam = 1, Nu = 2 };

// chua thong tin hanh khach
struct HanhKhach {
	int SCMND{};
	string Ho{};
	string Ten{};
	Phai phai{};
	HanhKhach() {}
	HanhKhach(int SCMND, string Ho, string Ten, Phai phai) {
		this->SCMND = SCMND;
		this->Ho = Ho;
		this->Ten = Ten;
		this->phai = phai;
	}
	void prInfo() {
		cout << SCMND << " --- " << Ho << " " << Ten << " --- " << ((phai == Nam) ? "Nam" : "Nu") << endl;
	}
	~HanhKhach() {}
};
	
// 1 node cua cay AVL lua tru thong tin hanh khach
struct NodeHK {
	HanhKhach info;
	NodeHK* nodeLeft, * nodeRight;
	int height = 1;
	NodeHK() {
		nodeLeft = nullptr;
		nodeRight = nullptr;
	}
	NodeHK(HanhKhach info) {
		this->info = info;
		nodeLeft = nullptr;
		nodeRight = nullptr;
	}
	~NodeHK() {}
};

// lop DSHK
class DSHK {
private:
	NodeHK* root = nullptr;
	int number_of_HK = 0;
	// Tra lai chieu cao cua 1 node
	int max(int a, int b) {
		return a > b ? a : b;
	}
	int height_h(NodeHK* head) {
		if (head != nullptr) return head->height;
		else return 0;
	}
	// Tra lai chi so can bang
	int get_balance(NodeHK* head) {
		return height_h(head->nodeLeft) - height_h(head->nodeRight);
	}
	// xoay 
	NodeHK* rotateLeft(NodeHK* x) {
		NodeHK* y = x->nodeRight;
		NodeHK* T = y->nodeLeft;
		x->nodeRight = T;
		y->nodeLeft = x;
		x->height = 1 + max(height_h(x->nodeLeft), height_h(x->nodeRight));
		y->height = 1 + max(height_h(y->nodeLeft), height_h(y->nodeRight));
		return y;
	}
	NodeHK* rotateRight(NodeHK* x) {
		NodeHK* y = x->nodeLeft;
		NodeHK* T = y->nodeRight;
		x->nodeLeft = T;
		y->nodeRight = x;
		x->height = 1 + max(height_h(x->nodeLeft), height_h(x->nodeRight));
		y->height = 1 + max(height_h(y->nodeLeft), height_h(y->nodeRight));
		return y;
	}
	// Them 1 node moi vao cay
	NodeHK* insertElement(HanhKhach newInfo, NodeHK* head) {
		if (head == nullptr) {
			number_of_HK++;
			return new NodeHK(newInfo);
		}
		if (newInfo.SCMND > head->info.SCMND) head->nodeRight = insertElement(newInfo, head->nodeRight);
		else if (newInfo.SCMND < head->info.SCMND) head->nodeLeft = insertElement(newInfo, head->nodeLeft);
		else return head;
		head->height = 1 + max(height_h(head->nodeLeft), height_h(head->nodeRight));
		int balance = get_balance(head);

		if (balance < -1 && newInfo.SCMND > head->nodeRight->info.SCMND) {
			return rotateLeft(head);
		}
		if (balance > 1 && newInfo.SCMND < head->nodeLeft->info.SCMND) {
			return rotateRight(head);
		}
		if (balance < -1 && newInfo.SCMND < head->nodeRight->info.SCMND) {
			head->nodeRight = rotateRight(head->nodeRight);
			return rotateLeft(head);
		}
		if (balance > 1 && newInfo.SCMND > head->nodeLeft->info.SCMND) {
			head->nodeLeft = rotateLeft(head->nodeLeft);
			return rotateRight(head);
		}
		return head;
	}
	// Cac chuc nang xoa 1 node dua vao khoa chinh
	NodeHK* maxNode(NodeHK* head) {
		NodeHK* temp = head;
		while (temp->nodeRight != nullptr)
			temp = temp->nodeRight;
		return temp;
	}
	NodeHK* deleteElement(int SCMND, NodeHK* head) {
		if (head == nullptr) return nullptr;
		if (head->info.SCMND < SCMND)
			head->nodeRight = deleteElement(SCMND, head->nodeRight);
		else if (head->info.SCMND > SCMND)
			head->nodeLeft = deleteElement(SCMND, head->nodeLeft);
		else {
			if ((head->nodeLeft == nullptr) || (head->nodeRight == nullptr)) {
				NodeHK* temp = head->nodeLeft ? head->nodeLeft : head->nodeRight;
				if (temp == nullptr) {
					temp = head;
					head = nullptr;
				}
				else {
					*head = *temp;
				}
				delete temp;
			}
			else {
				NodeHK* maxLeftElement = maxNode(head->nodeLeft);
				head->info = maxLeftElement->info;
				head->nodeLeft = deleteElement(head->info.SCMND, head->nodeLeft);
			}
		}
		if (head == nullptr)
			return head;
		head->height = 1 + max(height_h(head->nodeLeft), height_h(head->nodeRight));
		int balance = get_balance(head);
		// balance > 1 tuc la cay dang lech trai, balance < -1 cay dang lech phai
		if (balance > 1 && get_balance(head->nodeLeft) >= 0)
			return rotateRight(head);
		if (balance < -1 && get_balance(head->nodeRight) <= 0)
			return rotateLeft(head);
		if (balance > 1 && get_balance(head->nodeLeft) < 0) {
			head->nodeLeft = rotateLeft(head->nodeLeft);
			return rotateRight(head);
		}
		if (balance < -1 && get_balance(head->nodeRight) > 0) {
			head->nodeRight = rotateRight(head->nodeRight);
			return rotateLeft(head);
		}
		return head;
	}
	void search(int SCMND, NodeHK* head, NodeHK*& temp) {
		if (head == nullptr) return;
		if (head->info.SCMND == SCMND) temp = head;
		if (head->info.SCMND < SCMND) search(SCMND, head->nodeRight, temp);
		else search(SCMND, head->nodeLeft, temp);
	}

	void show(NodeHK* root) {
		if (root != nullptr) {
			root->info.prInfo();
			show(root->nodeLeft);
			show(root->nodeRight);
		}
	}
public:
	bool isEmpty() {
		if (root == nullptr) return true;
		return false;
	}
	HanhKhach getInfo(int SCMND, string Ho, string Ten, Phai phai) {
		HanhKhach newHK(SCMND, Ho, Ten, phai);
		return newHK;
	}
	void insertNode(HanhKhach newElement) {
		root = insertElement(newElement, root);
	}
	void deleteNode(int SCMND) {
		if (search(SCMND)) {
			number_of_HK--;
			root = deleteElement(SCMND, root);
		}
	}
	void show() {
		show(root);
	}
	bool search(int SCMND) {
		NodeHK* temp = nullptr;
		search(SCMND, root, temp);
		if (temp == nullptr) return false;
		return true;
	}
	int getNumberAOfHK() {
		return number_of_HK;
	}
};

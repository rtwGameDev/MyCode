#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>
using namespace std;

class Student {
private:
    string stu_name;
    string stu_id;
    double *list_of_masks;
    unsigned num_of_masks;
public:
    Student() {
        num_of_masks = 0;
    }
    Student(string stu_name, string stu_id, double *list_of_masks, unsigned num_of_masks) {
        this->list_of_masks = list_of_masks;
        this->num_of_masks = num_of_masks;
        this->stu_id = stu_id;
        this->stu_name = stu_name;
    }
    ~Student() {}
    void add_masks(double mask) {
        double *newListMasks = new double[num_of_masks + 1];
        if (num_of_masks > 0) {
            for (int i = 0; i <= num_of_masks - 1; ++i) {
                newListMasks[i] = list_of_masks[i];
            }
        }
        newListMasks[num_of_masks] = mask;
        num_of_masks++;
        list_of_masks = newListMasks;
    }
    double compare(Student s) {
        double rs = 0;
        if (num_of_masks > 0) {
            for (int i = 0; i <= num_of_masks - 1; ++i) {
                rs += list_of_masks[i];
            }
            rs = rs / ((double) num_of_masks);
        }
        return rs;
    }
    double dtb() {
        double rs = 0;
        if (num_of_masks > 0) {
            for (int i = 0; i <= num_of_masks - 1; ++i) {
                rs += list_of_masks[i];
            }
            rs = rs / ((double) num_of_masks);
        }
        return rs;
    }
    void pr() {
        cout << stu_name << " " << stu_id << " " << fixed << setprecision(2) << dtb() << endl;
    }
    string mssv() {
        return stu_id;
    }
};

class D22Class {
private:
    Student *list_of_students;
    unsigned num_of_students;
public:
    D22Class() {
        num_of_students = 0;
    }
    ~D22Class() {}
    void add_student(Student student) {
        Student *newList = new Student[num_of_students + 1];
        if (num_of_students > 0) {
            for (int i = 0; i <= num_of_students - 1; ++i) {
                newList[i] = list_of_students[i];
            }
        }
        newList[num_of_students] = student;
        num_of_students++;
        list_of_students = newList;
    }

    void themsv(string name, string id, double *list, unsigned n) {
        Student newStudent(name, id, list, n);
        add_student(newStudent);
    }

    void printf_D22() {
        if (num_of_students <= 0) {
            cout << "Danh sach trong" << endl;
        }
        else {
            cout << endl << "Danh sach lop" << endl;
            for (int i = 0; i <= num_of_students - 1; ++i) {
                list_of_students[i].pr();
            }
        }
    }
    void sort_() {
        if (num_of_students >= 2) {
            for (int i = 0; i <= num_of_students - 2; ++i) {
                for (int j = i + 1; j <= num_of_students - 1; ++j) {
                    double a = list_of_students[i].dtb();
                    double b = list_of_students[j].dtb();
                    if (a < b) swap(list_of_students[i], list_of_students[j]);
                }
            }
        }
    }
    void nhap_diem(string mssv, double mask) {
        if (num_of_students <= 0) {
            cout << "Chua co sinh vien nao" << endl;
            return;
        }
        else {
            for (int i = 0; i <= num_of_students - 1; ++i) {
                if (list_of_students[i].mssv() == mssv) {
                    list_of_students[i].add_masks(mask);
                    return;
                }
            }
            cout << "Khong tin thay sinh vien nao co mssv " << mssv << endl;
            return;
        }
    }
    Student get_best_student() {
        sort_();
        return list_of_students[0];
    }
};

void choose() {
    cout << "Danh sach cac su lua chon" << endl;
    cout << "1. Them sinh vien" << endl;
    cout << "2. Xem danh sach" << endl;
    cout << "3. Nhap diem cho sinh vien" << endl;
    cout << "4. Sap xep sinh vien" << endl;
    cout << "5. Hoc sinh gioi nhat" << endl;
    cout << "0. Thoat chuong trinh" << endl;
    cout << "Nhap su lua chon: ";
}
int main() {
    D22Class app;
    while (true) {
        int n;
        cout << endl;
        choose();
        cin >> n;
        cout << endl;
        if (n == 1) {
            string name, id;
            unsigned num;
            cout << "Nhap ten sinh vien: ";
            cin.ignore();
            getline(cin, name);
            cout << "Nhap mssv: ";
            cin >> id;
            cout << "Nhap so luong diem: ";
            cin >> num;
            double *listMasks = new double[num];
            cout << "Nhap lan luot cac diem: ";
            for (int i = 0; i <= num - 1; ++i) {
                cin >> listMasks[i];
            }
            app.themsv(name, id, listMasks, num);
        }
        if (n == 2) {
            app.printf_D22();
        }
        if (n == 3) {
            string mssv;
            double mask;
            cout << "Nhap mssv: ";
            cin >> mssv;
            cout << "Nhap diem: ";
            cin >> mask;
            app.nhap_diem(mssv, mask);
        }
        if (n == 4) {
            app.sort_();
        }
        if (n == 5) {
            Student bestStudent = app.get_best_student();
            cout << endl << "Sinh vien gioi nhat" << endl;
            bestStudent.pr();
        }
        if (n == 0) {
            cout << "Thanks";
            return 0;
        }
        cout << endl;
    }
    return 0;
}
#pragma once
#include <iostream>
#include "DSMB.h" // Danh sach may bay
#include "DSHK.h" // Danh sach Hanh Khach
#include "MyLib.h" // Chua 1 so ham doc lap
#include "DSCB.h" // Danh sach chuyen bay
#include "TimeFormat.h" // Cac dinh dang thoi gian
using namespace std;
int main()
{
    {
        //dsMayBay myapp;
        //myapp.insertElement("1", "empty", 0, 0);
        //myapp.insertElement("2", "empty", 0, 0);
        //myapp.insertElement("3", "empty", 0, 0);
        //myapp.insertElement("4", "empty", 0, 0);
        //myapp.insertElement("5", "empty", 0, 0);
        //myapp.insertElement("6", "empty", 0, 0);
        //myapp.insertElement("7", "empty", 0, 0);
        //myapp.insertElement("8", "empty", 0, 0);
        //myapp.insertElement("9", "empty", 0, 0);
        //myapp.show();
        //cout << endl << "NUM: " << myapp.SoLuongMB() << endl;
        //cout << myapp.exist("116");
        //cout << endl;
        //myapp.deleteElement("7");
        //myapp.show();
        //cout << endl << "NUM: " << myapp.SoLuongMB();
    }
    {
        //DSHK app;
        //app.insertNode(app.getInfo(1, "empty", "K",  Nam));
        //app.insertNode(app.getInfo(2, "empty", "K",  Nam));
        //app.insertNode(app.getInfo(3, "empty", "K",  Nam));
        //app.insertNode(app.getInfo(4, "empty", "K",  Nam));
        //app.insertNode(app.getInfo(5, "empty", "K",  Nam));
        //app.insertNode(app.getInfo(6, "empty", "K",  Nam));
        //app.insertNode(app.getInfo(7, "empty", "K",  Nam));
        //app.insertNode(app.getInfo(8, "empty", "K",  Nam));
        //app.insertNode(app.getInfo(9, "empty", "K",  Nam));
        //app.insertNode(app.getInfo(10, "empty", "K",  Nam));
        //app.show();
        //cout << endl << "NUM: " << app.getNumberAOfHK() << endl << "--------" << endl;
        //app.deleteNode(4);
        //app.show();
        //cout
        //<< endl << "NUM: " << app.getNumberAOfHK() << endl;
    }
    {
        //dateTime time("1", "1", "2004", "9", "7");
        //Format(time);
        //cout << getStringDATE_TIME(time);
    }
    {
        //dateTime before("27", "3", "2024", "15", "30");
        //Format(before);
        //dateTime after = getCurrentTime();
        //cout << getStringDATE_TIME(before) << " " << getStringDATE_TIME(after) << endl;
        //cout << calSpaceTime(before, after);
    }
    {
        //cout << endl;
        //int index = 1;
        //int soDay = 25;
        //int soDong = 10;
        //int soCho = soDay * soDong;
        //ticket* listTicket = new ticket[soCho + 1];
        //GTicketNumber(soDay, soDong, listTicket);
        //for (int i = 1; i <= soDay; ++i) {
        //    for (int j = 1; j <= soDong; ++j) {
        //        cout << listTicket[index++].TICKET_CODE << " ";
        //    }
        //    cout << endl;
        //}
    }
    {
        DSCB app;
        dateTime now = getCurrentTime();
        app.insertElement("3", now, "LONDON", CONVE, "AH370");
        app.insertElement("2", now, "LONDON", CONVE, "AH370");
        app.insertElement("1", now, "LONDON", CONVE, "AH370");
        app.insertElement("4", now, "LONDON", CONVE, "AH370");
        app.insertElement("7", now, "LONDON", CONVE, "AH370");
        app.insertElement("5", now, "LONDON", CONVE, "AH370");
        app.insertElement("6", now, "LONDON", CONVE, "AH370");
        app.insertElement("10", now, "LONDON", CONVE, "AH370");
        app.insertElement("9", now, "LONDON", CONVE, "AH370");
        app.insertElement("8", now, "LONDON", CONVE, "AH370");
        app.deleteElement("4");
        app.show();
         
        Flight Datve = app.search("9")->flight;
        string MMB = Datve.SoHieuMB;
        // lay ra so hieu may bay, truy cap so day, so dong cua may bay
        int soDay = 27;
        int soDong = 10;
        
        int index = 1;
        KhoiTao_DSV(soDay, soDong, Datve.DS_VE);
        for (int i = 1; i <= soDay; ++i) {
            for (int j = 1; j <= soDong; ++j) {
                cout << Datve.DS_VE[index++].TICKET_CODE << " ";
            }
            cout << endl;
        }
        cout << app.getNumberElement();
    }
    return 0;
}

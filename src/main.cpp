#include "UserInterface.h"
#include "HanhKhach.h"
#include <iostream>
using namespace std;
int main() {
    auto ui = app::create();
    ui->run();
    return 0;
}
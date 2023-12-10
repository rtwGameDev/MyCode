// #include <iostream>
// #include <string>
// #include <stack>
// using namespace std;
// int split(string arr[], string str) {
//     int index = 0, id = 0;
//     while (index < str.length()) {
//         string temp = "";
//         while (str[index] != ' ') {
//             temp = temp + str[index];
//             index++;
//             if (index >= str.length()) break;
//         }
//         arr[id] = temp;
//         temp = "";
//         index++;
//         id++;
//     }
//     return --id;
// }
// int main() {
//     string str = "66 22 / 33 + 77 44 - *";
//     string arr[100];
//     stack <int> manhduy;
//     int len = split(arr, str);
//     for (int i = 0; i <= len; ++i) {
//         if (arr[i] == "+" or arr[i] == "-" or arr[i] == "*" or arr[i] == "/") {
//             int x, y, temp;
//             string o = arr[i];
//             x =  manhduy.top();
//             manhduy.pop();
//             y = manhduy.top();
//             manhduy.pop();
//             if (arr[i] == "+") temp = x + y;
//             if (arr[i] == "-") temp = y - x;
//             if (arr[i] == "/") temp = y / x;
//             if (arr[i] == "*") temp = x * y;
//             manhduy.push(temp);
//         }
//         else {
//             manhduy.push(stoi(arr[i]));
//         }
//     }    
//     cout << manhduy.top();
//     return 0;
// }
#include <iostream>
#include <string>
#include <stack>
#include <iomanip>
using namespace std;

void trim(string &str) {
    while (str[0] == ' ') {
        str.erase(0, 1);
    }
    while (str[str.length() - 1] == ' ') {
        str.erase(str.length() - 1, 1);
    }
}
void space(string &str) {
    for (int i = 0; i <= str.length() - 1; ++i) {
        if (str[i] == ' ' and str[i + 1] == ' ') {
            str.erase(i, 1);
            --i;
        }
    }
}
int split(string arr[], string str) {
    int index = 0, id = 0;
    while (index < str.length()) {
        string temp = "";
        while (str[index] != ' ') {
            temp = temp + str[index];
            index++;
            if (index >= str.length()) break;
        }
        arr[id] = temp;
        temp = "";
        index++;
        id++;
    }
    return --id;
}
int ut(string str) {
    if (str == ")" or str == "(") return 0;
    if (str == "+" or str == "-") return 1;
    if (str == "*" or str == "/") return 2;
    else return 10;
}
int main() {
    string result = "";
    string str = "(2 * 33 + 66 *                        55)";
    string arr[1000]; 
    stack <string> mang;
    for (int i = 0; i <= str.length() - 1; ++i) {
        if (str[i] == '(' or str[i] == ')') {
            str.insert(i + 1, " ");
            str.insert(i, " ");
            i++;
        }
    }
    trim(str);
    space(str);
    int n = split(arr, str); 

    
    for (int i = 0; i <= n; ++i) {
        cout << "@" << arr[i] ;
    }
    // ------------------------------------------------------------------------------
    cout << endl;

    for (int i = 0; i <= n; ++i) {
        int douutien = ut(arr[i]);
        // Neu la so thi in luon
        if (douutien == 10) {
            result = result + arr[i];
        }

        // co the la toan tu hoac dau ngoac
        else {

            // Dau ngoac mo => push luon
            if (arr[i] == "(") {
                mang.push(arr[i]);
            }
            else if (arr[i] == ")") {
                while (mang.top() != "(") {
                    result = result + mang.top();
                    mang.pop();
                }
                mang.pop();
            } 
            
            else 
            {
                // con lai cac toan tu
                // arr[i] luc nay la 1 toan tu
                if (mang.size() == 0) mang.push(arr[i]);
                else {
                    int topDt = ut(mang.top());
                    if (douutien > topDt) mang.push(arr[i]);
                    else if (douutien < topDt) {
                        result = result + mang.top();
                        mang.pop();
                        mang.push(arr[i]);
                    }
                }
                
            }
        }
    }

    // ------------------------------------------------
    if (mang.size() != 0) {
        result = result + mang.top();
    } 
    cout << result;
    return 0;
}
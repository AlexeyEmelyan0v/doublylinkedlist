#include <iostream>
#include "dllist.h"
using namespace std;
int main() {
    int cmnd=0,value;
    dllist<int> a;
    cout << "Input 999 if you want to end\n";
    cout << "Input 1 if you want check emptiness of list\n";
    cout << "Input 2 and value if you want to insert to the beginning of the list\n";
    cout << "Input 3 and value if you want to insert to the end of the linked list\n";
    cout << "Input 4 and value if you want to insert before the cursor\n";
    cout << "Input 5 if you want to remove an element from the beginning\n";
    cout << "Input 6 if you want to remove an element from the end\n";
    cout << "Input 7 if you want to remove cursor element\n";
    cout << "Input 8 if you want to move cursor forward\n";
    cout << "Input 9 if you want to move cursor back\n";
    cout << "Input 10 if you want to know value of the cursor element\n";
    while(cmnd!=999){
        cin>>cmnd;
        if (cmnd == 1) {
            if (a.empty()) {
                cout << "List is empty\n";
            }else{
                cout<< "List isn't empty\n";
            }
        }
        if(cmnd == 2) {
            cin>>value;
            a.begpush(value);
        }
        if(cmnd == 3) {
            cin>>value;
            a.endpush(value);
        }
        if(cmnd == 4) {
            cin>>value;
            try {
                a.curpush(value);
            }
            catch(const char* msg){
                cerr<<msg<<endl;
            }
        }
        if(cmnd == 5){
            try {
                a.begdel();
            }
            catch(const char* msg){
                cerr<<msg<<endl;
            }
        }
        if(cmnd == 6){
            try {
                a.enddel();
            }
            catch(const char* msg){
                cerr<<msg<<endl;
            }
        }
        if(cmnd == 7){
            try {
                a.curdel();
            }
            catch(const char* msg){
                cerr<<msg<<endl;
            }
        }
        if(cmnd == 8){
            try {
                a.curforward();
            }
            catch(const char* msg){
                cerr<<msg<<endl;
            }
        }
        if(cmnd == 9){
            try {
                a.curback();
            }
            catch(const char* msg){
                cerr<<msg<<endl;
            }
        }
        if(cmnd == 10){
            try {
                cout<<*a.cur<<endl;
            }
            catch(const char* msg){
                cerr<<msg<<endl;
            }
        }
        cout<<a<<endl;
    }
    return 0;
}

#include <iostream>
#include "dllist.h"
#define int long long
using namespace std;
dllist<int> a;
int score=0;
void row(){
    node<int>* wh;
    bool change = 1;
    while (change) {
        wh = a.head;
        change = 0;
        while (wh != nullptr && wh != a.tail) {
            if (wh != a.head) {
                if (wh->data == wh->next->data && wh->data == wh->prev->data) {
                    node<int>* oldcur=a.cur;
                    a.cur=wh->prev;
                    int x=a.cur->data;
                    while(a.cur!=nullptr && a.cur->data==x){
                        if(oldcur==a.cur){
                            oldcur=oldcur->next;
                        }
                        if(wh==a.cur){
                            wh=wh->next;
                        }
                        score++;
                        a.curdel();
                    }
                    change = 1;
                    if(oldcur!=nullptr) {
                        a.cur = oldcur;
                    }else{
                        a.cur=a.tail;
                    }
                    break;
                }
            }
            wh = wh->next;
        }
    }
}

void coutcursor(){
    node<int>* wh;
    wh = a.head;
    while (wh != a.cur) {
        cout << "  ";
        wh = wh->next;
    }
    cout << "^" << endl;
}

void pushcolor(int color,int pos){
    if (a.head == nullptr) {
        a.begpush(color);
    } else {
        if (pos == 0) {
            a.curpush(color);
        } else if (pos > 5 || pos < -5) {
            cout << "wrong position" << endl;
        } else if (pos > 0 && pos <= 5) {
            int cnt = 0;
            node<int> *oldcur = a.cur;
            for (int i = 0; i < pos; i++) {
                try {
                    a.curforward();
                    cnt++;
                }
                catch (const char *msg) {
                    cerr << msg << endl;
                    break;
                }
            }
            if (a.cur == a.tail && cnt != abs(pos)) {
                a.endpush(color);
            } else {
                a.curpush(color);
            }
            a.cur = oldcur;
        } else {
            int cnt = 0;
            node<int> *oldcur = a.cur;
            for (int i = 0; i < -pos; i++) {
                try {
                    a.curback();
                    cnt++;
                }
                catch (const char *msg) {
                    cerr << msg << endl;
                    break;
                }
            }
            a.curpush(color);
            a.cur = oldcur;
        }
    }
}

int stupidbot(int color){
    node<int>* l=a.cur;
    node<int>* r=a.cur;
    node<int>* wh;
    int lpos=0;
    for(int i=0;i<5;i++){
        if(l!=nullptr && l!=a.head){
            lpos--;
            l=l->prev;
        }
    }
    for(int i=0;i<5;i++){
        if(r!=nullptr && r!=a.tail){
            r=r->next;
        }
    }
    int pos=lpos;
    for(wh=l;wh!=r;wh=wh->next){
        if(wh->data==color && wh->next->data==color){
            return pos;
        }
        pos++;
    }
    pos=lpos;
    for(wh=l;wh!=nullptr && wh!=r->next;wh=wh->next){
        if(wh->data==color){
            return pos;
        }
        pos++;
    }

    return 0;
}

signed main() {
    int n, cmnd, pos, color;
    cin >> n;
    for (int i = 0; i < n; i++) {
        a.endpush(rand() % 3 + 1);
    }
    cout << a << endl;
    node<int> *wh = a.head;
    while (wh != a.cur) {
        cout << "  ";
        wh = wh->next;
    }
    row();
    cout << "^" << endl;
    cout << "Input 1 if you want to play\n";
    cout << "Input 2 if you want to watch\n";
    cout << "Input 999 if you want to end\n";
    cin >> cmnd;
    if (cmnd == 1) {
        while (cmnd != 999 && pos!=999) {
            color = rand() % 3 + 1;
            cout << "Color: " << color << endl;
            cout << "Input position where you want to insert:";
            cin >> pos;
            pushcolor(color,pos);
            row();
            cout << a << endl;
            coutcursor();
            cout<<"Your score: "<<score<<endl;
        }
    } else {
        int cnt = 1;
        while(true){
            color=rand()%3+1;
            int pos=stupidbot(color);
            pushcolor(color,pos);
            row();
            if(cnt==1000000){
                cnt=0;
                cout<<"Balls left: "<<a.size()<<endl;
                cout<<"Score: "<<score<<endl;
            }
            cnt++;
        }
    }
    return 0;
}

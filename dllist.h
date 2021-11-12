#ifndef DOUBLYLINKEDLIST_DLLIST_H
#define DOUBLYLINKEDLIST_DLLIST_H
#include <iostream>
#include <cassert>
using namespace std;

template<typename T>
class node {
public:
    node<T> *next;
    node<T> *prev;
    T data;
    node(T value) {
        next=nullptr;
        prev=nullptr;
        data=value;
    }
    template<typename Type>
    friend ostream &operator<<(ostream &, const node<Type> &);
};

template<typename T>
ostream& operator<<(ostream& out, const node<T>& a) {
    out << a.data;
    return out;
}

template<typename T>
class dllist {
public:
    node<T> *head;
    node<T> *tail;
    node<T> *cur;

    dllist() {
        head = nullptr;
        tail = nullptr;
        cur = nullptr;
    }

    bool empty() {
        if (head == nullptr) {
            return true;
        }
        return false;
    };

    int size() {
        int cnt=1;
        if(empty()){
            return 0;
        }
        node<T>* wh=head;
        while(wh!=tail){
            cnt++;
            wh=wh->next;
        }
        return cnt;
    }

    void begpush(T v) {
        node<T> *ndp = new node(v);
        if (empty()) {
            head = ndp;
            tail = ndp;
            cur = ndp;
        } else {
            head->prev = ndp;
            ndp->next = head;
            head = ndp;
        }
    }

    void endpush(T v) {
        node<T> *ndp = new node(v);
        if (empty()) {
            head = ndp;
            tail = ndp;
            cur = ndp;
        } else {
            tail->next = ndp;
            ndp->prev = tail;
            tail = ndp;
        }
    }

    void curpush(T v) {
        if (cur == nullptr) {
            throw "cursor == nullptr";
        } else if (cur == head) {
            begpush(v);
        } else {
            node<T> *ndp = new node(v);
            node<T> *prep = cur->prev;
            prep->next = ndp;
            ndp->prev = prep;
            cur->prev = ndp;
            ndp->next = cur;
        }
    }

    void curforward() {
        if (cur == nullptr) {
            throw "cursor == nullptr";
        } else if (cur != tail) {
            cur = cur->next;
        }
    }

    void curback() {
        if (cur == nullptr) {
            throw "cursor == nullptr";
        } else if (cur != head) {
            cur = cur->prev;
        }
    }

    void begdel() {
        if (empty()) {
            throw "list is empty";
        } else {
            if (head == tail) {
                node<T> *temp = head;
                head = nullptr;
                tail = nullptr;
                cur = nullptr;
                delete temp;
            } else {
                if (cur == head) {
                    cur = head->next;
                }
                node<T> *temp = head;
                head->next->prev = head->prev;
                head = head->next;
                delete temp;
            }
        }
    }

    void enddel() {
        if (empty()) {
            throw "list is empty";
        } else {
            if (head == tail) {
                node<T> *temp = tail;
                head = nullptr;
                tail = nullptr;
                cur = nullptr;
                delete temp;
            } else {
                if (cur == tail) {
                    cur = cur->prev;
                }
                node<T> *temp = tail;
                tail->prev->next = tail->next;
                tail = tail->prev;
                delete temp;
            }
        }
    };

    void curdel() {
        if (empty()) {
            throw "list is empty";
        } else if (cur == head) {
            begdel();
        } else if (cur == tail) {
            enddel();
        } else {
            node<T> *temp = cur;
            cur->next->prev = cur->prev;
            cur->prev->next = cur->next;
            cur = temp->next;
            delete temp;
        }
    }

    template<typename Type>
    friend ostream &operator<<(ostream &, const dllist<Type> &);
};

template<typename T>
ostream& operator<<(ostream& out, const dllist<T>& a) {
    node<T> *wh = a.head;
    while (wh != nullptr) {
        out << *wh << " ";
        wh = wh->next;
    }
    return out;
}

#endif //DOUBLYLINKEDLIST_DLLIST_H

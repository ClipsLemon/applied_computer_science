#include <iostream>
#include <cstdio>

using namespace std;

class mString {
    private: char *st;
    public:

    mString(){
        st = NULL;
    }

    void test(){
        st = new char(10);
        char c = 'a';
        for (int i = 0; i < 10; i++){
            st[i] = c++;
        }
        st[9] = '\0';
        cout << st;
    }

    ~mString(){
        if(st) {delete st;}
    }
    friend std::ostream& operator<< (std::ostream &out,  const mString &s);
    friend std::istream& operator>> (std::istream &in, mString &s);
    int length();
    void operator= (const mString &s);
    void operator= (const char* s1);
    //void operator+ (const mString &s);
    mString operator+ (const char* s) const;
    mString operator+ (const mString &s) const;
    friend mString operator+ (const char* s1, const mString &s);
    friend bool operator==  (const mString &s1, const mString &s2);
    friend bool operator> (const mString &s1, const mString &s2);
    friend bool operator>= (const mString &s1, const mString &s2);
    friend bool operator< (const mString &s1, const mString &s2);
    friend bool operator<= (const mString &s1, const mString &s2);
    mString substr(int start, int count);
    int find(const mString &s);
    int find(const char* s1);
};
//сделать replace(s1, s2) сам объект не меняется и replace(s1, s2, k) + перегрузки с массивами символов вместо объектов строк

int mString::find(const mString &s) {
    int i = 0, k = 0, k1 = 0, k2 = 0;
    while(s.st[k1++]);
    k1--;
    while(st[k2++]);
    k2--;
    if (k1 > k2) return -1;
    for(i = 0, k += k1; i + k1 <= k2; i++){
        mString sub = substr(i, k1);
        if (s == substr(i, k1)) {
            return i;
        }
    }
    return -1;
}

int mString::find(const char* s1) {
    int i = 0, k = 0, k1 = 0, k2 = 0;
    mString s2 = s1;
    while(s1[k1++]);
    k1--;
    while(st[k2++]);
    k2--;
    if (k1 > k2) return -1;
    for(i = 0, k += k1; i + k1 <= k2; i++){
        mString sub = substr(i, k1);
        if (s2 == substr(i, k1)) {
            return i;
        }
    }
    return -1;
}

mString mString::substr(int start, int count) {
    mString res;
    int i, k = start;
    res.st = new char[count + 1];
    for (i = 0; i < count; i++, k++) {
        res.st[i] = st[k];
    }
    res.st[count] = '\0';
    return res;
}

bool operator< (const mString &s1, const mString &s2) {
    bool res = !(s1 > s2) && !(s1 == s2);
    return res;
}

bool operator<= (const mString &s1, const mString &s2) {
    bool res = (s1 < s2) || (s1 == s2);
    return res;
}

void mString::operator= (const char* s1) {
    if (st) delete st;
    int i, k = 0;
    while (s1[k++]);
    st = new char[k];
    for (i = 0; i < k;i++) st[i] = s1[i];
    st[i] = '\0';
}

mString operator+ (const char* s1, const mString &s) {
    mString res;
    int i, k = 0, k1 = 0, k2 = 0;
    while(s.st[k1++]);
    k1--;
    while (s1[k2++]);
    k2--;
    res.st = new char[k1 + k2 + 1];
    for (i = 0; i < k2; i++) res.st[k++] = s1[i];
    for (i = 0; i < k1; i++) res.st[k++] = s.st[i];
    res.st[k] = '\0';
    return res;

} 

bool operator>= (const mString &s1, const mString &s2) {
    bool pr = (s1 > s2) || (s1 == s2);
    return pr;
    }


bool operator> (const mString &s1, const mString &s2) {
    int i, k = 0, k1 = 0, k2 = 0;
    while(s1.st[k1++]);
    k1--;
    while (s2.st[k2++]);
    k2--;
    int l = k1;
    if (k2 < l) l = k2;
    for (i = 0; i <= l; i++) {
        if (s1.st[i] > s2.st[i]) return 1;
        if (s1.st[i] < s2.st[i]) return 0;
    }
    return 0;
}

bool operator== (const mString &s1, const mString &s2) {
    int i, k = 0, k1 = 0, k2 = 0;
    while(s1.st[k1++]);
    k1--;
    while (s2.st[k2++]);
    k2--;
    if (k1 != k2) return 0;
    for (i = 0; i < k1; i++) if (s1.st[i] != s2.st[i]) return 0;
    return 1;
}

mString mString::operator+ (const mString &s) const{
    mString res;
    int i, k = 0, k1 = 0, k2 = 0;
    while(st[k1++]);
    k1--;
    while (s.st[k2++]);
    k2--;
    res.st = new char[k1 + k2 + 1];
    for (i = 0; i < k1; i++) res.st[k++] = st[i];
    for (i = 0; i < k2; i++) res.st[k++] = s.st[i];
    res.st[k] = '\0';
    return res;
}

mString mString::operator+ (const char * s1) const {
    mString res;
    int i, k = 0, k1 = 0, k2 = 0;
    while (st[k1++]);
    k1--;
    while (s1[k2++]);
    k2--;
    res.st = new char[k1 + k2 +1];
    for (i = 0; i <k1; i++) res.st[k++] = st[i];
    for (i = 0; i < k2; i++) res.st[k++] = s1[i];
    res.st[k] = '\0';
    return res;
    
}

std::ostream& operator<< (std::ostream &out,  const mString &s){
    out << s.st;
    return out;
}
 std::istream& operator>> (std::istream &in, mString &s){
    char buff[10000], t;
    int i, k = 0;
    t = in.get();
    while ((int)(t) != 10)
    {
        buff[k++] = t;
        t = in.get();
    }
    if (s.st) delete s.st;
    s.st = new char[k + 1];
    for (i = 0; i < k; i++) s.st[i]= buff[i];
    s.st[i]='\0';
    return in; 
 }

 int mString::length(){
    if (!st) return 0;
    int k = 0;
    while(st[k++]);
    return --k;
 }

 void mString::operator= (const mString &s){
    if (st) delete st;
    int i, k = 0;
    while (s.st[k++]);
    st = new char[k];
    for (i = 0; i < k;i++) st[i] = s.st[i];
    st[i] = '\0';
 }

int main(){
    //cout
    mString s, p, p1, p3, p2;
    bool p4, p5, p6;
    s.test();
    cout << endl;
    //cout << endl << s << endl;
    //cin >>s;
    //cout << s;
    //cout << s.length()<< endl;
    //p = s;
    p1 = "abcdefg";
    p2 = "efg";
    //cout << p << endl;
    //p = p + s;
    //p1 = p;
    //p3 = p1;
    //p4 = (p3 == p1);
    //cout << p << endl;
    int pfin = p1.find("bcd");
    //cout << p1.find("abc")<< endl;
    //cout << p4 << endl << p5 << endl;
    return 0;
}
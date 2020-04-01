#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;


class Ascii
{
public:
    int cod;
    int v[100];
private:
    int n = 0;
public:
    friend ostream& operator << (ostream& out, const Ascii& c) {
        out << char(c.cod) << " ";
        return out;
    }
    friend istream& operator >> (istream& in, Ascii& c) {
        in >> c.cod;
        return in;
    }
    bool operator < (const Ascii& val) const {
        return cod < val.cod;
    }
    void sortare() {
        int aux;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                if (v[i] < v[j]) {
                    aux = v[i];
                    v[i] = v[j];
                    v[j] = aux;
                }
            }
    }
    int valn() {
        return n;
    }
    void atrbn(int atr) {
        n = atr;
    }
    void cinandcout() {
        Ascii c1;
        ifstream f("in.txt");
        ofstream g1("out1.txt");
        while (f >> *this) {
            g1 << *this;
            this -> v[n++] = this -> cod;
        }
    }
    void Sorted() {
        n--;
        ofstream g2("out2.txt");
        while (n >= 0) {
            g2 << char(v[n]) << " ";
            n--;
        }
    }
};

int main()
{
    Ascii c1;
    c1.cinandcout();
    c1.sortare();
    c1.Sorted();
    return 0;
}
#include <iostream>
#include "polynomial.h"
using namespace std;

void stopien(double *wspolczynnik1) {
    int st1;
    for(int i = 0; i < 100; i++) {
        if(wspolczynnik1[99-i] != 0) {
            st1 = 99-i;
            cout << "Stopien tego wielomianu to: " << st1 << '\n';
            break;
        }
    }
}

void dodawanie(double *wspolczynnik1, double *wspolczynnik2, int st1, int st2) {
    int x = max(st1, st2);
    double suma_w[100]{0};
    for(int i = 0; i <= x; i++) {
        suma_w[x-i] = wspolczynnik1[x-i] + wspolczynnik2[x-i];
    }

    cout << "Suma tych wielomianow to: ";

    wyswietl_wielomian(suma_w, x);
    cout << '\n';
}

void odejmowanie(double *wspolczynnik1, double *wspolczynnik2, int st1, int st2) {
    int x = max(st1, st2);
    double odejmij_w[100]{0};
    int max_x = 0;
    for(int i = 0; i <= x; i++) {
        odejmij_w[x-i] = wspolczynnik1[x-i] - wspolczynnik2[x-i];
        if (odejmij_w[x-i] != 0 && max_x == 0)
            max_x = x-i;
    }
    x = max_x;
    cout << "Roznica tych wielomianow to: ";

    wyswietl_wielomian(odejmij_w, x);
    cout << '\n';

}

void wyswietl_wielomian(double *wspolczynnik, int st)
{
    for(int j = 0; j <= st; j++) {
        if(st-j == 0) {
            if(wspolczynnik[st-j] == 0) {
                continue;
            }
            else if(wspolczynnik[st-j] > 0 && st != 0) {
                cout << "+" << wspolczynnik[st-j];
            }
            else {
                cout << wspolczynnik[st-j];
            }
        }
        else {
            if (wspolczynnik[st-j] == 1 && j > 0) {
                cout << "+x";
            }
            else if (wspolczynnik[st-j] == 1 && j == 0) {
                cout << "x";
            }
            else if (wspolczynnik[st-j] == -1) {
                cout << "-x";
            }
            else if (wspolczynnik[st-j] == 0) {
                continue;
            }
            else if(j > 0 && wspolczynnik[st-j] > 0) {
                cout << "+" << wspolczynnik[st-j] << "x";
            }
            else {
                cout << wspolczynnik[st-j] << "x";
            }
            if(st-j == 1) 
            cout << "";
            else
            cout << "^" << st-j;
        }
    }
}

void mnozenie(double *wspolczynnik1, double *wspolczynnik2, int st1, int st2) {

    int stn = st1 + st2;
    double mnoz[200]{0};
    double stop[200]{0};

    for(int i = 0; i <= st1; i++) {
        for(int j = 0; j <= st2; j++) {
            mnoz[stn-i-j] += wspolczynnik1[st1-i] * wspolczynnik2[st2-j]; 
        }
    }

    cout << "Iloczyn tych wielomianow to: ";

    wyswietl_wielomian(mnoz, stn);
    cout << '\n';
}
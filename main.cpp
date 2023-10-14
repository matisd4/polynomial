#include <iostream>
#include "polynomial.h"
using namespace std;

int main() {

    int n, st1, st2;
    double a;
    double wspolczynnik1[100]{0};
    double wspolczynnik2[100]{0};
    for(int j = 0; j < 2; j++) {
        cout << "Jaki ma byc stopien wielomianu " << j+1 << "?" << '\n';
        cin >> n;
        cout << "Podaj odpowiednie wspolczynniki wielomianu " << j+1 << " od najwiekszego stopnia" << '\n';
        for(int i = 0; i <= n; i++) {
            cin >> a;
            if(j == 0){
                st1 = n;
                wspolczynnik1[st1-i] = a;
            }
            else {
                st2 = n;
                wspolczynnik2[st2-i] = a;
            } 
        }
    }

    stopien(wspolczynnik1);
    stopien(wspolczynnik2);

    dodawanie(wspolczynnik1, wspolczynnik2, st1, st2);
    odejmowanie(wspolczynnik1, wspolczynnik2, st1, st2);
    mnozenie(wspolczynnik1, wspolczynnik2, st1, st2);
}
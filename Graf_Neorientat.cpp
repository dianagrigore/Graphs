//
// Created by Diana Grigore on 14-Apr-20.
//

#include "Graf_Neorientat.h"
#include <istream>
#include <ostream>
#include <iostream>
#include "Lista.h"

Graf_Neorientat :: Graf_Neorientat(int nr, Lista lista) : Graf{nr}, L{lista} {
}


std ::istream& operator >>(std :: istream& in, Graf_Neorientat &src){

    in >> src.nr_noduri;
    in >> src.L;
    return in;
}

std :: ostream& operator <<(std :: ostream& out, Graf_Neorientat const &src){
    out << src.nr_noduri <<'\n';
    out << src.L <<'\n';
    return out;
}

void swap(Graf_Neorientat &first, Graf_Neorientat &second){
    using std :: swap;
    swap(first.L, second.L);
}

Graf_Neorientat :: Graf_Neorientat(const Graf_Neorientat& src) : Graf{src}, L{src.L} {
}

Graf_Neorientat &Graf_Neorientat ::operator=(Graf_Neorientat src){
    if (this != &src) {
        nr_noduri = src.nr_noduri;
        swap(src, *this);
    }
    return *this;
}

void Graf_Neorientat :: f(int ns){    //Metoda care returneaza vectorul de tati

    int tata[100];
    int poz = ns-1;
    for (int i = 0; i < 100; i++)
        tata[i] = 0;
    tata[ns] = -1;
    int dimensiune_lista = L.getdimensiune();
    Vector* listele = L.getvector();
    while (poz < dimensiune_lista) {
        int dimensiune_locala = listele[poz].getdimensiune();
        int* elemente = listele[poz].getelemente();
        for (int i = 0; i < dimensiune_locala; i++)
            if(tata[elemente[i]] == 0)
                tata[elemente[i]] = poz+1;
        poz++;
    }

    for (int i = 1; i <= dimensiune_lista; i++)
        if (tata[i] == -1)
            std :: cout << "Elementul " << i << " este radacina.\n";
        else
            std :: cout << "Tatal elementului " << i << " este " << tata[i] << '\n';
}




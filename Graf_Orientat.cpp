//
// Created by Diana Grigore on 14-Apr-20.
//

#include "Graf_Orientat.h"
#include "invalid_input_exception.h"
#include <iostream>

Graf_Orientat :: Graf_Orientat( int nr, MatriceAdiacenta matrice) :  Graf{nr}, A{matrice}{
}

void Graf_Orientat :: citeste(std::istream &in) {
    in >> nr_noduri;
    in >> A;
    if (this -> isgraf() == 0)
        throw invalid_input_exception("Matrice invalida");
}

std :: ostream& operator <<(std :: ostream& out, Graf_Orientat const &src){
    out << src.nr_noduri <<'\n';
    out << src.A <<'\n';
    return out;
}

void swap(Graf_Orientat &first, Graf_Orientat &second){
    using std :: swap;
    swap(first.nr_noduri, second.nr_noduri);
    swap(first.A, second.A);
}

Graf_Orientat :: Graf_Orientat(const Graf_Orientat& src) : Graf{src}, A{src.A} {
}

Graf_Orientat &Graf_Orientat ::operator=(Graf_Orientat src){
    if (this != &src) {
        swap(src, *this);
    }
    return *this;
}

int exista_nod_nevizitat(const int v[], int n){
    for (int i = 0; i < n; i++)
        if (v[i] != 1)
            return i;
    return -1;
}

void Graf_Orientat :: afisare_rezultat(int nod_start){
    int m = A.getrows();
    int *vizitat = A.parcurgere_latime(nod_start);
    if (exista_nod_nevizitat(vizitat, m)!= -1)
        std :: cout << "Graful nu este conex\n";
    else
        std :: cout << "Graful este conex\n";
    delete [] vizitat;
}

int Graf_Orientat :: isgraf(){
    int m = A.getcolumns();
    int n = A.getrows();
    return m == n;
}

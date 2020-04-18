//
// Created by Diana Grigore on 14-Apr-20.
//

#include "Graf_Orientat.h"
#include <iostream>

Graf_Orientat :: Graf_Orientat( int nr, MatriceAdiacenta matrice) :  Graf{nr}, A{matrice}{

}


std ::istream& operator >>(std :: istream& in, Graf_Orientat &src){
    in >> src.nr_noduri;
    in >> src.A;
    return in;
}

std :: ostream& operator <<(std :: ostream& out, Graf_Orientat const &src){
    out << src.nr_noduri <<'\n';
    out << src.A <<'\n';
    return out;
}

void swap(Graf_Orientat &first, Graf_Orientat &second){
    using std :: swap;
    swap(first.A, second.A);
}

Graf_Orientat :: Graf_Orientat(const Graf_Orientat& src) : Graf{src}, A{src.A} {
}

Graf_Orientat &Graf_Orientat ::operator=(Graf_Orientat src){
    if (this != &src) {
        nr_noduri = src.nr_noduri;
        swap(src, *this);
    }
    return *this;
}

int exista_nod_nevizitat(int v[], int n){
    for (int i = 0; i < n; i++)
        if (v[i] == 0)
            return i;
    return -1;
}

void parcurgere_latime(int** a, int n, int ns, int* viz)
{
    viz[ns] = 1;
    int p = 1;
    int u = 1;
    int c[100];
    c[u] = ns;
    while (p <= u) {
        for(int i = 0; i < n; i++)
            if(a[c[p]][i] == 1 && viz[i] == 0)
            {
                u++;
                c[u] = i;
                viz[i] = 1;
            }
        p++;
    }
}

void Graf_Orientat :: f(int ns){
    int vizitat[100];
    for (int i = 0; i <= 100; i++)
        vizitat[i] = 0;
    int m = A.getrows();
    int n = A.getcolumns();
    int **matrice = A.getmatrix();
    parcurgere_latime(matrice, n, ns, vizitat);
    if (exista_nod_nevizitat(vizitat, m))
        std :: cout << "Graful nu este conex\n";
    else
        std :: cout << "Graful este conex\n";

}

int Graf_Orientat :: isgraf(){
    int m = A.getcolumns();
    int n = A.getrows();
    if (m != n)
        return 0;
    return 1;
}

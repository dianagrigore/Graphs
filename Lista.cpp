//
// Created by Diana Grigore on 07-Apr-20.
//

#include "Lista.h"
#include "Vector.h"
Lista :: Lista(int dimensiune) : dimensiune{dimensiune}{
    lista = new Vector [dimensiune];
}

std :: istream& operator >>(std :: istream& in, Lista &lis){
    delete []lis.lista;
    in >> lis.dimensiune;
    lis.lista = new Vector[lis.dimensiune];
    for (int i = 0; i < lis.dimensiune; i++)
        in >> lis.lista[i];
    return in;
}

std :: ostream& operator <<(std :: ostream& out, const Lista& lis){
    for (int i = 0; i < lis.dimensiune; i++)
        out << lis.lista[i] << '\n';
    return out;
}

Lista :: ~Lista(){
    dimensiune = 0;
    delete [] lista;
}

void swap(Lista &first, Lista &second){
    using std :: swap;
    swap(first.dimensiune, second.dimensiune);
    swap(first.lista, second.lista);
}

Lista :: Lista(const Lista& lis){
    dimensiune = lis.dimensiune;
    lista = new Vector [dimensiune];
    for (int i = 0; i < dimensiune; i++)
        lista[i] = lis.lista[i];
}

Lista &Lista :: operator =(Lista src){
    if (this != &src)
        swap(*this, src);
    return *this;
}

int Lista :: getdimensiune() const {
    return dimensiune;
}

Vector& Lista :: operator [] (int index){
    return lista[index];
}
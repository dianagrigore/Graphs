//
// Created by Diana Grigore on 07-Apr-20.
//

#ifndef TEMA2_LISTA_H
#define TEMA2_LISTA_H
#include "Vector.h"

class Lista {
private:
    Vector *l;
    int dimensiune;
public:
    explicit Lista(int dimensiune=1);

    ~Lista();

    friend std::ostream& operator <<(std::ostream &out, const Lista &lis);

    friend std::istream& operator >>(std::istream &in, Lista &lis);

    friend void swap(Lista &first, Lista &second);

    Lista(const Lista& lis);

    Lista& operator =(Lista src);

    int getdimensiune() const;

    Vector* getvector() const;
};


#endif //TEMA2_LISTA_H

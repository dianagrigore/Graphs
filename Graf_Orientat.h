//
// Created by Diana Grigore on 14-Apr-20.
//

#ifndef TEMA2_GRAF_ORIENTAT_H
#define TEMA2_GRAF_ORIENTAT_H
#include "MatriceAdiacenta.h"
#include "Graf.h"

class Graf_Orientat : public Graf {
    MatriceAdiacenta A;
public:
    explicit Graf_Orientat(int nr=1, MatriceAdiacenta matrice = MatriceAdiacenta() );

    ~Graf_Orientat() override = default;

    friend std::ostream& operator <<(std::ostream &out, const Graf_Orientat &src);

    friend std::istream& operator >>(std::istream &in, Graf_Orientat &src);

    friend void swap(Graf_Orientat &first, Graf_Orientat &second);

    Graf_Orientat(const Graf_Orientat& src);

    Graf_Orientat& operator =(Graf_Orientat src);

    void f(int ns) override ;

    int isgraf();
};


#endif //TEMA2_GRAF_ORIENTAT_H

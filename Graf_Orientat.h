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
    explicit Graf_Orientat(int nr = 1, MatriceAdiacenta matrice = MatriceAdiacenta());

    ~Graf_Orientat() override = default;

    friend std::ostream& operator <<(std::ostream &out, const Graf_Orientat &src);

    virtual void citeste(std :: istream &in) override;

    friend void swap(Graf_Orientat &first, Graf_Orientat &second);

    Graf_Orientat(const Graf_Orientat& src);

    Graf_Orientat& operator =(Graf_Orientat src);

    void afisare_rezultat(int nod_start) override;

    int isgraf();
};


#endif //TEMA2_GRAF_ORIENTAT_H

//
// Created by Diana Grigore on 14-Apr-20.
//

#ifndef TEMA2_GRAF_NEORIENTAT_H
#define TEMA2_GRAF_NEORIENTAT_H
#include "Graf.h"
#include "Lista.h"

class Graf_Neorientat : public Graf{
protected:
    Lista L;
public:
    explicit Graf_Neorientat(int nr=1, Lista lista = Lista());

    ~Graf_Neorientat() override = default;

    friend std::ostream& operator <<(std::ostream &out, const Graf_Neorientat &src);

    friend std::istream& operator >>(std::istream &in, Graf_Neorientat &src);

    friend void swap(Graf_Neorientat &first, Graf_Neorientat &second);

    Graf_Neorientat(const Graf_Neorientat& src);

    Graf_Neorientat& operator =(Graf_Neorientat src);

    void f(int ns) override;
};


#endif //TEMA2_GRAF_NEORIENTAT_H

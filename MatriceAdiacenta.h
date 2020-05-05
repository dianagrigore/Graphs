//
// Created by Diana Grigore on 05-Apr-20.
//

#ifndef TEMA2_MATRICEADIACENTA_H
#define TEMA2_MATRICEADIACENTA_H
#include<istream>
#include<ostream>

class MatriceAdiacenta {
private:
    int **matrice;
    int m, n;

public:
    explicit MatriceAdiacenta(int m=1, int n=1, int val=0);

    ~MatriceAdiacenta();

    friend std::ostream& operator <<(std::ostream &out, const MatriceAdiacenta &matrix);

    friend std::istream& operator >>(std::istream &in, MatriceAdiacenta &matrix);

    friend void swap(MatriceAdiacenta &first, MatriceAdiacenta &second);

    MatriceAdiacenta(const MatriceAdiacenta& matrix);

    MatriceAdiacenta& operator =(MatriceAdiacenta matrix);

    int* parcurgere_latime(int ns);

    int getrows() const;

    int getcolumns() const;

};


#endif //TEMA2_MATRICEADIACENTA_H


#ifndef MatAijH
#define MatAijH
#include <complex>
#include <iostream>
#include <map>
#include <vector>

#include "ij.h"
#include "mat.h"
using namespace std;

template <class T>
class MatAij : protected mat {
   protected:
    map<ij, T> coef;

   public:
    MatAij(int = 1, int = 1);
    virtual ~MatAij();
    MatAij(const MatAij &other);

    MatAij &operator=(const MatAij &other);
    //double& operator()(int i, int j);
    T operator[](ij);
    MatAij operator+(MatAij &other);
    void insert(int, int, T);
    friend std::ostream &operator<<(std::ostream &, MatAij &);
    MatAij transpose();
    friend vector<T> operator-(vector<T>, vector<T>);
    friend vector<T> operator+(vector<T>, vector<T>);
    friend vector<T> operator*(T,vector<T>);
    
    vector<T> matVect(vector<T>);
    T dotsesq(vector<T>, vector<T>); 
    vector<T> solve(vector<T>, vector<T>);
};

#endif /* MatAijH */

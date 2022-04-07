
#include "mataij.h"

#include <cassert>
#include <iostream>

#include "mat.h"

using namespace std;

template <class T>
MatAij<T>::MatAij(int row, int column) : mat(row, column) {}

template <class T>
MatAij<T>::~MatAij() {}

template <class T>
MatAij<T>::MatAij(const MatAij& other) : mat(other) {
    this->coef = other.coef;
}

template <class T>
MatAij<T>& MatAij<T>::operator=(const MatAij& other) {
    this->mat::operator=(other);
    this->coef = other.coef;
    return (*this);
}

template <class T>
T MatAij<T>::operator[](ij I) {
    typename map<ij, T>::iterator it;
    it = this->coef.find(I);
    if (it != this->coef.end()) return it->second;
#pragma GCC diagnostic ignored "-Wuninitialized"
    T zero;
    return zero;
    // return (*this);
}

template <class T>
void MatAij<T>::insert(int i, int j, T a) {
    this->coef[ij(i, j)] = a;
}

template <class T>
ostream& operator<<(ostream& sortie, MatAij<T>& A) {
    typename map<ij, T>::iterator it;
    ij I;
    for (it = A.coef.begin(); it != A.coef.end(); it++) {
        I = it->first;
        sortie << "(" << I << "=" << it->second << endl;
    }
    return sortie;
}

template <class T>
MatAij<T> MatAij<T>::transpose() {
    MatAij R(this->row, this->column);
    ij I;
    typename map<ij, T>::iterator it;

    for (it = this->coef.begin(); it != this->coef.end(); it++) {
        I = it->first;
        R.coef[I.swap()] = it->second;
    }

    return R;
}

template <class T>
MatAij<T> MatAij<T>::operator+(MatAij& other) {
    MatAij<T> R(this->row, this->column);
    ij I;
    T somme;
    assert(this->column == other.column);
    assert(this->row == other.row);

    typename map<ij, T>::iterator itThis;
    typename map<ij, T>::iterator itOther;
    T zeros;
    itThis = this->coef.begin();
    itOther = other.coef.begin();

    while (itThis != this->coef.end() && itOther != other.coef.end()) {
        if (itThis->first == itOther->first)  // surchage de ==
        {
            somme = itThis->second + itOther->second;
            if (somme != zeros) {
                I = itThis->first;
                R.coef[I] = somme;
            }
            itThis++;
            itOther++;
        } else if (itThis->first < itOther->first) {
            I = itThis->first;
            R.coef[I] = itThis->second;
            itThis++;
        } else {
            I = itOther->first;
            R.coef[I] = itOther->second;
            itOther++;
        }
    }
    if (itOther != other.coef.end()) {
        while (itOther != other.coef.end()) {
            R.coef[itOther->first] = itOther->second;
            itOther++;
        }
    }
    if (itThis != this->coef.end()) {
        while (itThis != other.coef.end()) {
            R.coef[itThis->first] = itThis->second;
            itThis++;
        }
    }
    return R;
}

template <class T>
vector<T> MatAij<T>::matVect(vector<T> x) {
    T zero;
    typename map<ij, T>::iterator it;
    vector<T> y(x.size(), zero);
    for (it = this->coef.begin(); it != this->coef.end(); it++) {
        // yi = S(aij, xi)
        y[it->first.geti()] = y[it->first.geti()] + it->second * x[it->first.getj()];
    }
    return y;
}

template <class T>
vector<T> operator+(vector<T> x, vector<T> y) {
    vector<T> z(x);

    for (int i = 0; i < x.size(); i++) {
        z[i] = z[i] + y[i];
    }
    return z;
}
template <class T>
vector<T> operator-(vector<T> x, vector<T> y) {
    vector<T> z(x);

    for (int i = 0; i < x.size(); i++) {
        z[i] = z[i] - y[i];
    }
    return z;
}

template <class T>
vector<T> operator*(T scal, vector<T> x) {
    vector<T> z(x);

    for (int i = 0; i < x.size(); i++) {
        z[i] = z[i] * scal;
    }
    return z;
}

template <class T>
vector<T> MatAij<T>::solve(vector<T> b, vector<T> x) {
    int iter, maxIt = 300;
    T zero, alpha, beta;
    double testr, epsilon = 1e-9;
    vector<vector<T>> d(maxIt, vector<T>(this->row, zero));
    vector<vector<T>> Ad(maxIt, vector<T>(this->row, zero));

    // vector<vector<T>> r(this->row, zero);
    // vector<vector<T>> z(this->row, zero);

    vector<T> r(this->row, zero);
    vector<T> z(this->row, zero);
    vector<T> AdAd(maxIt, zero);

    z = this->matVect(x);
    r = b - z;
    d[0] = r;
    Ad[0] = this->matVect(d[0]);
    testr = (T)dotsesq(r, r);  // à créer
    iter = 0;
    AdAd[iter] = (T)dotsesq(Ad[iter], Ad[iter]);

    while ((testr > epsilon) && (iter < maxIt)) {
        alpha = (1 / AdAd[iter]) * dotsesq(r, Ad[iter]);
        x = x + alpha * d[iter];
        r = r - alpha * Ad[iter];

        d[iter + 1] = r;
        z = this->matVect(r);
        Ad[iter + 1] = z;

        for (int i = 0; i < iter + 1; i++) {
            beta = -dotsesq(Ad[iter + 1], (1 / AdAd[i]) * Ad[i]);
            d[iter + 1] = d[iter + 1] + beta * d[i];
            Ad[iter + 1] = Ad[iter + 1] + beta * Ad[i];
        }

        iter++;
        AdAd[iter] = real(dotsesq(Ad[iter], Ad[iter]));
    }
    std::cout<<x[0]<<"   "<<x[1]<<"   "<<x[2]<<"   "<<endl;
    return x;
}

template <class T>
T MatAij<T>::dotsesq(vector<T> x, vector<T> y) {
    T res;
    for (int i = 0; i < x.size(); i++) {
        res = res + x[i] * y[i];
    }

    return res;
}

// vector<double> operator+(vector<double> x, vector<double> y) {
//     vector<double> z(x);

//     for (int i = 0; i < x.size(); i++) {
//         z[i] = z[i] + y[i];
//     }
//     return z;
// }
// vector<double> operator-(vector<double> x, vector<double> y) {
//     vector<double> z(x);

//     for (int i = 0; i < x.size(); i++) {
//         z[i] = z[i] - y[i];
//     }
//     return z;
// }

// vector<complex<double>> operator+(vector<complex<double>> x,
//                                   vector<complex<double>> y) {
//     vector<complex<double>> z(x);

//     for (int i = 0; i < x.size(); i++) {
//         z[i] = z[i] + y[i];
//     }
//     return z;
// }
// vector<complex<double>> operator-(vector<complex<double>> x,
//                                   vector<complex<double>> y) {
//     vector<complex<double>> z(x);

//     for (int i = 0; i < x.size(); i++) {
//         z[i] = z[i] - y[i];
//     }
//     return z;
// }

template class MatAij<double>;
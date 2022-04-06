#ifndef MAT_H_
#define MAT_H_
#include <cassert>
#include <iostream>

class mat {
   protected:
    int row;
    int column;
    static int cpt;

   public:
    int getRow();
	int getColumn();
	mat(int = 1, int = 1);
    virtual ~mat();
    mat(const mat &other);

    mat &operator=(const mat &other);
    mat transpose();
};

#endif /* MAT_H_ */

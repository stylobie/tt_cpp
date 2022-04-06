#include "mat.h"

int mat::cpt = 0;

mat::mat(int row, int column) {
    // TODO Auto-generated constructor stub
    assert(row > 0);
    this->row = row;
    assert(column > 0);
    this->column = column;
    cpt++;
    std::cout << "constructor mat" << this->cpt << "\t" << row << "\t"
              << column << std::endl;
}

mat::~mat() {
    cpt--;
    std::cout << "destructor mat" << this->row << "," << this->column << "\t"
              << this->cpt << std::endl;
}

mat::mat(const mat &other) {
    // TODO Auto-generated constructor stub
    this->row = other.row;
    this->column = other.column;
    cpt++;
    std::cout << "copy constructor mat" << this->cpt << "\t" << row << "\t"
              << column << std::endl;
}

mat &mat::operator=(const mat &other) {
    // TODO Auto-generated method stub
    this->row = other.row;
    this->column = other.column;
    std::cout << "operator = mat  " << this->row << "," << this->column << "\t"
              << this->cpt << std::endl;
    return (*this);
}

mat mat::transpose() {
    mat r(this->column, this->row);
    return r;
}

int mat::getRow() { return this->row; }

int mat::getColumn() { return this->column; }
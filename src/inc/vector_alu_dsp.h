#ifndef VECCALC_H
#define VECCALC_H

#include <vector>

class VectorALU {
    public:
        VectorALU(const int *n, const int *p, const int nLen, const int pLen);
        ~VectorALU() = default;

        void sum(int *res, const int resLen);
        void multiply(int *res, const int resLen);

    private:
        std::vector<int> n_;
        std::vector<int> p_;
};

#endif
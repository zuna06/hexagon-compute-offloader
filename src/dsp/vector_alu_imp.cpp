#include <vector>
#include <iostream>

#include "vector_alu_dsp.h"
#include "vector_alu.h"
#include "AEEStdErr.h"

#include <cassert>

#define TSIZECHK(x, y, z) ((x) != (y) || (x) != (z) || (y) != (z))

// ouuu shiii

AEEResult vector_alu_open(const char *uri, remote_handle64* handle) {
    void* hptr = nullptr;
    hptr = static_cast<void*>(new unsigned char{});
    *handle = (remote_handle64)hptr;
    assert(*handle);
    return 0;
}

AEEResult vector_alu_close(remote_handle64 handle) {
    if (handle) delete (unsigned char*)(handle);
    return 0;
}

AEEResult vector_alu_sum(remote_handle64 h, const int *n, int nLen, const int *p, int pLen, int *res, int resLen) {
    // figure out size stuff later this is just for testing ^_^
    if ((TSIZECHK(nLen, pLen, resLen))) {
        // error or sum
        return 1;
    }

    VectorALU vALU(n, p, nLen, pLen);
    vALU.sum(res, resLen);

    return 0;
}

AEEResult vector_alu_multiply(remote_handle64 h, const int *n, int nLen, const int *p, int pLen, int *res, int resLen) {
    if ((TSIZECHK(nLen, pLen, resLen))) {
        // error or sum
        return 1;
    }

    VectorALU vALU(n, p, nLen, pLen);
    vALU.multiply(res, resLen);

    return 0;
}

VectorALU::VectorALU(const int *n, const int *p, const int nLen, const int pLen) {
    n_.assign(n, n + nLen);
    p_.assign(p, p + pLen);
}

void VectorALU::sum(int *res, const int resLen) {
    for (size_t i = 0; i < resLen; i++) {
        res[i] = p_[i] + n_[i];
    }
}

void VectorALU::multiply(int* res, const int resLen) {
    for (size_t i = 0; i < resLen; i++) {
            res[i] = p_[i] * n_[i];
    }
}

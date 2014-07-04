#ifndef __SYMALG__
#define __SYMALG__

#include <iostream>
#include <stdexcept>

class SymAlg{
    protected:
        bool keyset;

    public:
        virtual ~SymAlg();
        virtual std::string encrypt(const std::string & DATA) = 0;
        virtual std::string decrypt(const std::string & DATA) = 0;
        virtual unsigned int blocksize() = 0;
};
#endif

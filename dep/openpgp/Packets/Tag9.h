// Symmetrically Encrypted Data Packet
#ifndef __TAG9__
#define __TAG9__

#include "packet.h"

class Tag9 : public Packet{
    private:
        std::string encrypted_data;

    public:
        Tag9();
        Tag9(std::string & data);
        void read(std::string & data);
        std::string show();
        std::string raw();

        Tag9 * clone();

        std::string get_encrypted_data();

        void set_encrypted_data(const std::string & e);
};
#endif

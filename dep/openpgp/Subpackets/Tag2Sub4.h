// Exportable Certification
#ifndef __TAG2SUB4__
#define __TAG2SUB4__

#include "subpacket.h"

class Tag2Sub4 : public Subpacket{
    private:
        bool exportable;

    public:
        Tag2Sub4();
        Tag2Sub4(std::string & data);
        void read(std::string & data);
        std::string show();
        std::string raw();

        bool get_exportable();

        void set_exportable(const bool e);

        Tag2Sub4 * clone();
};
#endif

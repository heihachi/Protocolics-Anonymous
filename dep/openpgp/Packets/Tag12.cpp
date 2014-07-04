#include "Tag12.h"
Tag12::Tag12(){
    tag = 12;
}

Tag12::Tag12(std::string & data){
    tag = 12;
    read(data);
}

void Tag12::read(std::string & data){
    size = data.size();
    trust = data;
}

std::string Tag12::show(){
    std::stringstream out;
    out << "    Data (" << trust.size() << " octets): " << trust << "\n";
    return out.str();
}

std::string Tag12::raw(){
    return trust;
}

std::string Tag12::get_trust(){
    return trust;
}

void Tag12::set_trust(const std::string & t){
    trust = t;
    size = raw().size();
}

Tag12 * Tag12::clone(){
    return new Tag12(*this);
}

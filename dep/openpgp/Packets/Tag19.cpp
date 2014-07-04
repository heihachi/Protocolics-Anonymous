#include "Tag19.h"
Tag19::Tag19(){
    tag = 19;
    size = 20;
}

Tag19::Tag19(std::string & data){
    tag = 19;
    size = 20;
    read(data);
}

void Tag19::read(std::string & data){
    size = data.size();
    hash = data;
}

std::string Tag19::show(){
    std::stringstream out;
    out << "    SHA - 1 Hash of previous packet: " << hash << "\n";
    return out.str();
}

std::string Tag19::raw(){
    return hash;
}

std::string Tag19::get_hash(){
    return hash;
}

void Tag19::set_hash(const std::string & h){
    hash = h;
    size = raw().size();
}

Tag19 * Tag19::clone(){
    return new Tag19(*this);
}

#include "Tag2Sub11.h"
Tag2Sub11::Tag2Sub11(){
    type = 11;
}

Tag2Sub11::Tag2Sub11(std::string & data){
    type = 11;
    read(data);
}

void Tag2Sub11::read(std::string & data){
    psa = data;
    size = data.size();
}

std::string Tag2Sub11::show(){
    std::stringstream out;
    for(unsigned int x = 0; x < psa.size(); x++){
        out << "            sym alg - " << Symmetric_Algorithms.at(psa[x]) << " (sym " << (unsigned int) psa[x] << ")\n";
    }
    return out.str();
}

std::string Tag2Sub11::raw(){
    return psa;
}

std::string Tag2Sub11::get_psa(){
    return psa;
}

void Tag2Sub11::set_psa(const std::string & s){
    psa = s;
}

Tag2Sub11 * Tag2Sub11::clone(){
    return new Tag2Sub11(*this);
}

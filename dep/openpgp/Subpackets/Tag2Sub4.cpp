#include "Tag2Sub4.h"
Tag2Sub4::Tag2Sub4(){
    type = 4;
    size = 1;
}

Tag2Sub4::Tag2Sub4(std::string & data){
    type = 4;
    size = 1;
    read(data);
}

void Tag2Sub4::read(std::string & data){
    exportable = data[0];
}

std::string Tag2Sub4::show(){
    return std::string("            Exportable: ") + (exportable?"True":"False") + "\n";
}

std::string Tag2Sub4::raw(){
    return (exportable?"\x01":zero);
}

bool Tag2Sub4::get_exportable(){
    return exportable;
}

void Tag2Sub4::set_exportable(const bool e){
    exportable = e;
}

Tag2Sub4 * Tag2Sub4::clone(){
    return new Tag2Sub4(*this);
}

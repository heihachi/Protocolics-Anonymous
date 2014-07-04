#include "Tag13.h"
Tag13::Tag13(){
    tag = 13;
}

Tag13::Tag13(std::string & data){
    tag = 13;
    read(data);
}

void Tag13::read(std::string & data){
    size = data.size();
    if (!data.size()){
        // no data
        name = "";
        comment = "";
        email = "";
    }

    // find chars '(', ')', '<', '>'
    int c_s = -1, c_t = -1, e_s = -1, e_t = -1;
    for(unsigned int x = 0; x < data.size(); x++){
        if (data[x] == '('){
            c_s = x;
        }
        if (data[x] == ')'){
            c_t = x;
        }
        if (data[x] == '<'){
            e_s = x;
        }
        if (data[x] == '>'){
            e_t = x;
        }
    }

    if (c_s > 0){                                                   // if comment are not first
        name = data.substr(0, c_s - 1);
    }
    if ((c_s == -1) && (e_s > 0)){                                  // if no comment and email is not first
        name = data.substr(0, e_s - 1);
    }
    if (c_s != -1){                                                 // if there are comment
        if (!c_s){                                                  // if comment are first
            name = "";
        }
        comment = data.substr(c_s + 1, c_t - c_s - 1);
    }
    if (e_s != -1){                                                 // if there is an email
        if (!e_s){                                                  // if the email is the first thing
            name = "";
            comment = "";
        }
        email = data.substr(e_s + 1, e_t - e_s - 1);
    }
}

std::string Tag13::show(){
    std::stringstream out;
    out << "    User ID: " << name;
    if (comment != ""){
        out << " (" << comment << ")";
    }
    if (email != ""){
        out << " <" << email << ">";
    }
    out << "\n";
    return out.str();
}

std::string Tag13::raw(){
    std::string out = "";
    if (name != ""){
        out += name + "";
    }
    if (comment != ""){
        out += " (" + comment + ")";
    }
    if (email != ""){
        out += " <" + email + ">";
    }
    return out;
}

std::string Tag13::get_name(){
    return name;
}

std::string Tag13::get_comment(){
    return comment;
}

std::string Tag13::get_email(){
    return email;
}

void Tag13::set_name(const std::string & n){
    name = n;
    size = raw().size();
}

void Tag13::set_comment(const std::string & c){
    comment = c;
    size = raw().size();
}

void Tag13::set_email(const std::string & e){
    email = e;
    size = raw().size();
}

Tag13 * Tag13::clone(){
    return new Tag13(*this);
}

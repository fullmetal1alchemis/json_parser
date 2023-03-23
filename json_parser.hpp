#ifndef MY_JSON_PARSER_HPP
#define MY_JSON_PARSER_HPP

#include <cassert>
#include <memory>

#include "json_type.hpp"

#define CMP(ptr, arr, index) ((*(ptr)) == (arr)[(index)])
#define CMP_EXTEND2(ptr, arr, index) CMP(ptr, arr, index+1)&&CMP(ptr, arr, index)
#define CMP_EXTEND3(ptr, arr, index) CMP_EXTEND2(ptr, arr, index+1)&&CMP(ptr, arr, index)
#define CMP_EXTEND4(ptr, arr, index) CMP_EXTEND3(ptr, arr, index+1)&&CMP(ptr, arr, index)


namespace my_json_parser{

class my_json_parser{
    private:

    std::shared_ptr<zh_value> root;

    STATE my_parse_object(zh_value &val, my_json_context &jc);
    STATE my_parse_number(zh_value &val, my_json_context &jc);
    STATE my_parse_float(zh_value &val, my_json_context &jc);
    STATE my_parse_integer(zh_value &val, my_json_context &jc);
    STATE my_parse_array(zh_value &val, my_json_context &jc);
    STATE my_parse_constant(zh_value &val, my_json_context &jc);
    STATE my_parse_string(zh_value &val, my_json_context &jc);
    STATE my_parse_ws(my_json_context &jc); 
    
    public:
        my_json_parser(){

        }

};

class my_json_generator{
    private:

    public:
        my_json_generator(){

    }

    
};

auto my_json_parser::my_parse_object(zh_value &val, my_json_context &jc)->STATE{
    EXPECT(jc.json, '{');

    if( my_parse_ws(jc) != STATE::_success )
        return STATE::_early_end;

    STATE _state = my_parse_string(val, jc);
    if( _state != STATE::_success ){
        return _state;
    }

    if( my_parse_ws(jc) != STATE::_success )
        return STATE::_early_end;  

    
}


auto my_json_parser::my_parse_string(zh_value &val, my_json_context &jc)->STATE{
    
    EXPECT(jc.json, '"');

    String s;
    
    while(jc.json){
        switch(*(jc.json)){
            case '\\':
                
                char c = *(jc.json);
         
                if(c == '\\'){
                    s += '\\';
                } else if (c == '/'){
                    s += '/';
                } else if (c == 'b') {
                    s += '\b';
                } else if (c == 'f') {
                    s += '\f';
                } else if (c == 'n') {
                    s += '\n';
                } else if (c == 'r') {
                    s += '\r';
                } else if (c == 't') {
                    s += '\t';
                } else if (c == 'u') {

                } else {
                    goto early_end;
                }

                jc.json++;
                break;
            case '"':
                val.insert_string(s);
                jc.json++;
                return STATE::_success;
 
            default:
                s += *(jc.json++);
                
        }
    }


    early_end:
        return STATE::_early_end;
}

auto my_json_parser::my_parse_ws(my_json_context &jc)->STATE{
    constexpr char whitespace[4] = {'\t', ' ', '\r', '\n'};
    while( jc.json && CMP_EXTEND4(jc.json, whitespace, 0) ){
        jc.json++;
    }
    if(!(jc.json))
        return STATE::_early_end;
    return STATE::_success;
}









} // namespace end;

#endif
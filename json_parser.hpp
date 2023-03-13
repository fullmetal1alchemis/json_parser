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

    my_parse_ws(jc);
    if(jc.end)
        return STATE::_parse_object_err;
    EXPECT(jc.json, '"');
    STATE _state = my_parse_string(val, jc);
    if( _state != STATE::_success ){
        return _state;
    }

    my_parse_ws()
}

auto my_json_parser::my_parse_string(zh_value &val, my_json_context &jc)->STATE{
    
    EXPECT(jc.json, '"');
}

auto my_json_parser::my_parse_ws(my_json_context &jc)->STATE{
    constexpr char whitespace[4] = {'\t', ' ', '\r', '\n'};
    while( jc.json && (jc.json, whitespace, 0) ){
        jc.json++;
    }
    if(!(jc.json))
        jc.end == true;
    return STATE::_success;
}









} // namespace end;

#endif
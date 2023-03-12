#ifndef MY_JSON_PARSER_HPP
#define MY_JSON_PARSER_HPP

#include <cassert>
#include <memory>

#include "json_type.hpp"

namespace my_json_parser{

class my_json_parser{
    private:

    std::shared_ptr<zh_value> root;

    State my_parse_object(zh_value &val, my_json_context &jc);
    State my_parse_ws(zh_value &val, my_json_context &jc);
    State my_parse_number(zh_value &val, my_json_context &jc);
    State my_parse_float(zh_value &val, my_json_context &jc);
    State my_parse_integer(zh_value &val, my_json_context &jc);
    State my_parse_array(zh_value &val, my_json_context &jc);
    State my_parse_constant(zh_value &val, my_json_context &jc);


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

auto my_json_parse::my_parse_object(zh_value &val, my_json_context &my_json_context)->State{

}

#define CMPWS(ptr, arr, index) ((*(ptr)) == (arr)[(index)])
auto my_json_parser::my_parse_ws(zh_value &val, my_json_context &jc)->State{
    constexpr char whitespace[4] = {'\t', ' ', '\r', '\n'};
    while( *(jc.json) == whitespace[0])
}









} // namespace end;

#endif
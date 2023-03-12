/*
    Object -> {}
    class Object{}
    
*/
#ifndef MY_JSON_TYPE_HPP
#define MY_JSON_TYPE_HPP

#include <variant>
#include <string>
#include <vector>
#include <map>

namespace my_json_parser{

enum class ObjectType{
    _object,
    _array,
    _float,
    _interger,
    _string,
    _true,
    _false,
    _null,
};


class zh_value{
    using String = std::string;
    using Object = std::map<String, zh_value>;
    using Float = double;
    using Integer = int;
    using Array = std::vector<zh_value>;
    using Number = std::variant<Float, Integer>;
    using Value = std::variant<String, Object, Number, Array>;

    private:
        ObjectType t;
        Value t;
        
    public:
        zh_value(){

        }
};

}

#endif
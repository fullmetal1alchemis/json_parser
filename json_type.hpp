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
#include <any>
#include <cassert>

#define EXPECT(ptr, y) \
do { \
    assert(*(ptr) == (y)); \
    (ptr)++; \
} while(0)

#define ASSERT_HAS_TYPE(_type) assert(std::holds_alternative<(_type)> (obj_val.get_value()))
namespace my_json_parser{

class zh_value;

using String = std::string;
using Object = std::map<String, zh_value>;
using Float = double;
using Integer = int;
using Array = std::vector<zh_value>;
using Value = std::variant<String, Object, Number, Array, Float, Integer>;

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

enum class STATE{
    _success,
    _parse_object_err,
    _early_end,
};

typedef struct my_json_context{
    const char* json;
    bool end;
}my_json_context;

class zh_value{
    


    private:
        ObjectType _type;
        Value _t;
        
    public:

        zh_value(){

        }

        zh_value(ObjectType type, Value t){
            _type = type;
            _t = t;
        }

        void set_value(ObjectType type, Value t){
            _t = t;
            _type = type;
        }

        auto insert_string(const String &s)->void{
            ASSERT_HAS_TYPE(Object);

            auto _map = std::get<Object>(_t);
            if(_map.empty()){
                _map.insert( Object::value_type(s, {}) );
            } else {
                String first;
                for(const auto &[k,v]:_map){
                    first = k;
                }

                _map.clear();
                _map.insert( Object::value_type(first, s));
            }
        }

};

}

#endif
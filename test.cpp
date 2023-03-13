#include <iostream>
#include <variant>
#include <string>
#include <utility>
#include <map>
#include <vector>
#include <cassert>

using namespace std;

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

class zh_value;
using String = std::string;
using Object = std::map<String, zh_value>;
using Float = double;
using Integer = int;
using Array = std::vector<zh_value>;
using Value = std::variant<String, Object, Array, Float, Integer>;

class zh_value{


    private:
        ObjectType _type;
        Value _t;
        
    public:

        zh_value(){
            _type = ObjectType::_null;
            _t = 1;
        }

        zh_value(ObjectType type, const Value &t){
            _type = type;
            _t = t;
        }

        void set_value(ObjectType type, const Value &t){
            _t = t;
            _type = type;
        }

        auto get_value()->Value{
            return _t;
        }

        auto set_object(const String &s, const zh_value &v)->void{
            assert(std::holds_alternative<Object>(_t));

            std::get<Object>(_t).insert( Object::value_type (s, v) );
        }

        
};

int main(){
    String s = "\n\r\b\f\t";
    cout << s;
}

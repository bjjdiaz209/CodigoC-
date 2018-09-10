#include <iostream>

using namespace std;

class Object
{
public:
    virtual bool equals(const Object&) const = 0;
};

//ABC:   Abstract Base Class
class IComparable: public virtual Object
{
public:
    virtual ~IComparable()
    {}
    virtual int compareTo(const Object& src) const = 0;
};

class Integer: public virtual Object, public virtual IComparable
{
    int n;
public:
    Integer(int n)
    :n{n}
    {}

    bool equals(const Object& src) const override
    {
        //static_cast hace el casteo sin miedo
        //dynamic_cast hace el casteo verificando que el objeto se del mismo tipo
        auto& s = dynamic_cast<const Integer&>(src);
        return n == s.n;
    }

    int compareTo(const Object& src) const override
    {
        auto& s = dynamic_cast<const Integer&>(src);
        return n - s.n;
    }
};

int main(int argc, char const *argv[])
{
    IComparable* s = new Integer(2);
    Object* p = new Integer(4);

    cout << s->equals(*p) <<endl;
    cout << s->compareTo(*p) << endl;

    return 0;
}

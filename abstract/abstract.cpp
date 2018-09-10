#include <string>
#include <iostream>

using namespace std;

class Employee
{
    string name;
    string role;
public:
    Employee(const string& name, const string& role)
    :name{name}, role{role}
    {}

    const string& get_name() const
    {
        return name;    //funciona
    }

    const string& get_role() const
    {
        return role;    //funciona
    }

    //VIRTUAL PURE METHOD, los metodo virtuales tienen una carga extra
    virtual void show_job() const= 0;//metodo abstracto

    virtual ~Employee(){}
    //no hay destructores virtaules puros
    //virtual ~Employee(){} = 0;
};

class Jamitor : public Employee
{

public:
    Jamitor(const string& n)
    :Employee{n, "Jamitor"}
    {}//no llamar a metodos virtuales desde el contructor

    void show_job() const override
    {
        cout<<"limpiar"<<endl;
    }
//  ~Jamitor();	
};

class Boss : public Employee
{
public:
    Boss(const string& n)
    :Employee{n, "Boss"}
    {}

    void show_job() const override
    {
        cout<<"zzzzzz"<<endl;
    }
//  ~Boss();

};

void print(const Employee& e)
{
    cout<<e.get_name()<<endl;
    cout<<e.get_role()<<endl;
    e.show_job();
}

int main(int argc, char const *argv[])
{
    Boss s{"Juan Perez"};
    s.show_job();

    Jamitor e{"name"};
    print(e);
    print(s);

    return 0;
}
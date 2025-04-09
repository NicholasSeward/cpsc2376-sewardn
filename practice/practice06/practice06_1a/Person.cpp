#include "Person.h"


Person::Person(std::string name, int age, std::string email) : 
    age{age}, 
    name { name }, 
    email{email}
{}


int Person::getAge() const
{
    return age;
}


void Person::setAge(int age)
{
    this->age = age;
}

std::string Person::getName() const
{
    return name;
}
std::string Person::getEmail() const
{
    return email;
}

Person operator+(Person p1,  Person p2)
{
    return Person(p1.getName() + p2.getName(), p1.getAge() + p2.getAge());
}
std::ostream& operator<<(std::ostream& out, Person p)
{
    out << "Person(name:" << p.getName() << ", age:" << p.getAge() << ", email:" << p.getEmail() << ")";
    return out;
}
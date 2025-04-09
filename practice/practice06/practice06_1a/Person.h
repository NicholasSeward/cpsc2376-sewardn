#pragma once
#include <iostream>
#include <string>
class Person
{
private:
    int age;
    std::string name;
    std::string email;

public:
    Person(std::string name, int age=-1, std::string email="");
    int getAge() const;
    std::string getName() const;
    std::string getEmail() const;
    void setAge(int age);
    friend Person operator+(const Person& p1, const Person& p2);
    friend std::ostream& operator<<(std::ostream& out, const Person& p2);

};

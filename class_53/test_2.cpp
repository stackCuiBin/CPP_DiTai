/*************************************************************************
 ******* File Name: test_2.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Thu 04 Jul 2019 10:35:24 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class People
{
	string m_name;
	int m_age;
public:
	People(string name, int age)
	{
		m_name = name;
		m_age = age;
	}

	void print()
	{
		cout << "Name = " << m_name << ", "
			<< "Age = " << m_age << endl;
	}
};

class Teacher : public People
{
public:
	Teacher(string name, int age) : People(name, age)
	{}
};

class Student : public People
{
public:
	Student(string name, int age) : People(name, age)
	{}
};

class Doctor : public Teacher, public Student
{
public:
	Doctor(string name, int age) : Teacher(name + "1", age + 1), Student(name + "2", age + 2)
	{}
};

int main(int argc, const char* argv[])
{
	Doctor d("Cui", 30);

	/* d 继承过来两个print() 函数 */
	// d.print();	// error: request for member ‘print’ is ambiguous

	d.Teacher::print();
	d.Student::print();

    return 0;
}

/*
 * result:
 * Name = Cui1, Age = 31
 * Name = Cui2, Age = 32
 */

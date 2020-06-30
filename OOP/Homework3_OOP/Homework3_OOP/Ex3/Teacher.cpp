#include "Teacher.h"

Teacher::Teacher()
{
	this->name = "";
	this->degree = "";
}
Teacher::Teacher(string name, string degree)
{
	this->name = name;
	this->degree = degree;
}
Teacher::Teacher(const Teacher& teacher)
{
	this->name = teacher.name;
	this->degree = teacher.degree;
	this->courses = teacher.courses;
}

Teacher& Teacher::operator=(const Teacher& teacher)
{
	if (this!=&teacher)
	{
		this->name = teacher.name;
		this->degree = teacher.degree;
		this->courses = teacher.courses;
	}

	return *this;
}

void Teacher::setName(string name)
{
	this->name = name;
}
string Teacher::getName() const
{
	return this->name;
}

void Teacher::setDegree(string degree)
{
	this->degree = degree;
}
string Teacher::getDegree() const
{
	return this->degree;
}

void Teacher::addCourse(const Course& course)
{
	this->courses.push_back(course);
}
vector<Course>& Teacher::getCourses()
{
	return this->courses;
}
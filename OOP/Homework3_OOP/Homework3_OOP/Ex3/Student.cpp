#include "Student.h"

Student::Student()
{
	this->name = "";
	this->identityNumber = 0;
}
Student::Student(string name, int identityNumber)
{
	this->name = name;
	this->identityNumber = identityNumber;
}
Student::Student(const Student& student)
{
	this->name = student.name;
	this->identityNumber = student.identityNumber;
	this->grades = student.grades;
	this->courses = student.courses;
}

Student& Student::operator= (const Student& student)
{
	if (this!=&student)
	{
		this->name = student.name;
		this->identityNumber = student.identityNumber;
		this->grades = student.grades;
		this->courses = student.courses;
	}

	return *this;
}

void Student::setName(string name)
{
	this->name = name;
}

string Student::getName() const
{
	return this->name;
}

void Student::setIdentityNumber(int identityNumber)
{
	this->identityNumber = identityNumber;
}
int Student::getIdentityNumber() const
{
	return this->identityNumber;
}

void Student::addCourse(const Course& course)
{
	this->courses.push_back(course);
}
vector<Course>& Student::getCourses()
{
	return this->courses;
}

void Student::addGrade(int grade)
{
	this->grades.push_back(grade);
}
vector<int>& Student::getGrades()
{
	return this->grades;
}
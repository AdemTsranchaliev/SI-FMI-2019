#include "Course.h"


Course::Course()
{
	this->name = "";
	this->type = "";
	this->code = 0;
	Teacher teacher;
	this->teacher = teacher;

}
Course::Course(string name, string type, int code, Teacher teacher)
{
	this->name = name;
	this->type = type;
	this->code = code;;
	this->teacher = teacher;
}
Course::Course(const Course& course)
{
	this->name = course.name;
	this->type = course.type;
	this->code = course.code;;
	this->teacher = course.teacher;
	this->students = course.students;
}

Course& Course::operator=(const Course& course)
{
	if (this!=&course)
	{
		this->name = course.name;
		this->type = course.type;
		this->code = course.code;;
		this->teacher = course.teacher;
		this->students = course.students;
	}

	return *this;
}

void Course::setName(string name)
{
	this->name = name;
}
string Course::getName() const
{
	return this->name;
}

void Course::setType(string type)
{
	this->type = type;
}
string Course::getType() const
{
	return this->type;
}

void Course::setCode(int code)
{
	this->code = code;
}
int Course::getCode() const
{
	return this->code;
}

void Course::setTeacher(Teacher& teacher)
{
	this->teacher = teacher;
}
Teacher& Course::getTeacher()
{
	return this->teacher;
}

void Course::addStudent(const Student& student)
{
	this->students.push_back(student);
}
vector<Student>& Course::getStudents()
{
	return this->students;
}
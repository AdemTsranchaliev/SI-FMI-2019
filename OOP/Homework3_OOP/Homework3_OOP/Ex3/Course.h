#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Student.h"
#include "Teacher.h"

using namespace std;

class Course
{
private:
	string name;
	string type;
	int code;
	Teacher teacher;
	vector<Student> students;
public:
	Course();
	Course(string name,string type,int code,Teacher teacher);
	Course(const Course& course);

	void setName(string name);
	string getName() const;

	void setType(string type);
	string getType() const;

	void setCode(int code);
	int getCode() const;

	void setTeacher(Teacher& teacher);
	Teacher& getTeacher();

	void setStudent(string name);
	vector<Student>& getStudent();
};


#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Course.h"

class Teacher
{
private:
	string name;
	string degree;
	vector<Course> courses;
public:

	Teacher();
	Teacher(string name,string degree);
	Teacher(const Teacher& teacher);

	Teacher& operator=(const Teacher& teacher);

	void setName(string name);
	string getName() const;

	void setDegree(string degree);
	string getDegree() const;

	void addCourse(const Course& course);
	vector<Course>& getCourses();
};


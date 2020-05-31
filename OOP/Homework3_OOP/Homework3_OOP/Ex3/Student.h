#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Course.h"
using namespace std;
class Student
{
private:
	string name;
	int identityNumber;
	vector<Course> courses;
	vector<int> grades;
public:
	Student();
	Student(string name,int identityNumber);

	void setName(string name);
	string getName() const;

	void setIdentityNumber(int identityNumber);
	int getIdentityNumber() const;

	void addCourse(const Course& course);
	vector<Course>& getCourses();

	void addGrade(int course);
	vector<int>& getGrade();

};


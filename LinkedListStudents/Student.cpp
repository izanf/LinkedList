#include <string>;

using namespace std;

class Student {
private:
	string name;
	double reg;
	int age;
	float firstGrade;
	float secondGrade;
	float finalGrade;
	bool status;
	Student* next;

public:
	Student(string name, int age, double reg)
	{
		this->name = name;
		this->age = age;
		this->reg = reg;
		this->firstGrade = 0;
		this->secondGrade = 0;
		this->finalGrade = 0;
		this->status = false;
		this->next = NULL;
	};

	string getName() {
		return name;
	}

	double getReg() {
		return reg;
	}

	Student* getNext()
	{
		return next;
	}

	void setNext(Student* n)
	{
		next = n;
	}

	void setGrades(float fGrade, float sGrade) {
		firstGrade = fGrade;
		secondGrade = sGrade;

		finalGrade = (fGrade * 0.4) + (sGrade * 0.6);
	}

	float getFinalGrade()
	{
		return finalGrade;
	}
};

#include "Student.cpp";
#include <iostream>;

using namespace std;

class Students {
	double defaultReg = 1;
private:
	Student* start;
	Student* end;

public:
	Students()
	{
		start = NULL;
		end = NULL;
	}

	Students(Student student) {
		start = new Student(student);
		end = start;
	}

	virtual ~Students() {
		delete start;
	}

	void showAllStudents() {
		cout << "Imprimindo todos os alunos..." << endl;
		Student* s = start;

		if (empty()) {
			cout << "A lista não possui alunos." << endl;
		}
		else {
			for (int i = 0; s; i++) {
				cout << i << " - " << s->getName() << s->getReg() << endl;
				s = s->getNext();
			}
		}
	}

	void insertEnd(string name, int age) {
		Student* newStudent = new Student(name, age, defaultReg);

		if (empty())
		{
			start = newStudent;
			end = newStudent;
		}
		else {
			end->setNext(newStudent);
			end = newStudent;
		}
		
		defaultReg++;
	}

	bool empty() {
		return (start == NULL);
	}

	int size() {
		if (empty())
			return 0;
		Student* s = start;
		int sz = 0;
		do
		{
			s = s->getNext();
			sz++;
		} while (s);
	}

	bool exists(double reg) {
		Student* s = start;

		while (s)
		{
			if (s->getReg() == reg)
				return true;
			s = s->getNext();
		}

		return false;
	}

	void remove(double reg)
	{
		if (!empty())
		{
			Student* before = NULL;
			Student* s = start;

			if (start->getReg() == reg) {
				start = s->getNext();
				free(s);
			}
			else {
				while (s)
				{
					if (s->getReg() == reg) {
						before->setNext(s->getNext());
						free(s);
						break;
					}
					before = s;
					s = s->getNext();

					if (s == NULL) {
						cout << "Não foi encontrado nenhum aluno." << endl;
					}
				}
			}
		}
		else {
			cout << "A lista ainda esta vazia." << endl;
		}
	}
};

#include "Student.cpp";
#include <iostream>;

using namespace std;

class Students {
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
			for (int i = 1; s; i++) {
				cout << i << " - " << s->getName() << " (" << s->getReg() << ")" << endl;
				s = s->getNext();
			}
		}
	}

	void insertEnd(string name, int age, double reg) {
		Student* newStudent = new Student(name, age, reg);

		if (empty())
		{
			start = newStudent;
			end = newStudent;
		}
		else {
			end->setNext(newStudent);
			end = newStudent;
		}
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
						cout << s->getName() << " foi removido." << endl;
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

	void search(double reg) {
		Student* s = start;
		Student* foundStudent = NULL;
		char opt = NULL;

		while (s)
		{
			if (s->getReg() == reg) {
				foundStudent = s;
				break;
			}
			s = s->getNext();
		}

		if (foundStudent) {
			cout << "Aluno encontrado!" << endl << foundStudent->getReg() << " - " << foundStudent->getName() << endl;

			while (opt != 'S' && opt != 'N') {
				cout << "Alterar nota do aluno? 'S' - Sim / 'N' - Não: "; cin >> opt;

				if (opt == 'S') {
					handleGrades(foundStudent);
				}
				else if (opt != 'S' && opt != 'N')
					cout << "Opção inválida! Insira uma opção válida." << endl;
			}
		}
		else {
			cout << "Aluno não encontrado." << endl;
		}
	}

	void handleGrades(Student* student) {
		float firstGrade;
		float secondGrade;

		cout << "Insira a nota 1: "; cin >> firstGrade;
		cout << "Insira a nota 2: "; cin >> secondGrade;

		student->setGrades(firstGrade, secondGrade);
	}

	void calcFinalGrade() {
		Student* s = start;
		float average = 0;

		while (s)
		{
			average += s->getFinalGrade();
			s = s->getNext();
		}

		cout << "A média da turma é: " << average / size() << endl;
	}
};

#include <iostream>;
#include <typeinfo>;
#include "Students.cpp";

using namespace std;

int main()
{
    string name;
    int age;
    double reg;
    int option = NULL;
    Students list;
    char exit = NULL;

    while (option > 0 || option < 6) {
        system("cls");
        cout << "0 - Sair." << endl;
        cout << "1 - Criar lista." << endl;
        cout << "2 - Inserir novo aluno." << endl;
        cout << "3 - Remover aluno." << endl;
        cout << "6 - Listas todos os alunos." << endl;
        cout << "Selecione uma das opcoes acima: ";
        cin >> option;

        switch (option) {
            case 0:
                cout << "O programa foi encerrado." << endl;
                break;

            case 2:
                cout << "Qual o nome do aluno? "; cin >> name;
                cout << "E a idade? "; cin >> age;
                list.insertEnd(name, age);
                break;

            case 3:
                cout << "Por favor, informe a matricula do aluno: "; cin >> reg;
                list.remove(reg);
                break;

            case 6:
                list.showAllStudents();
                break;

            default:
                cout << "Insira uma opção válida!" << endl;
                break;
        }

        while (exit != 'S' && exit != 'N') {
            cout << "Deseja continuar? S - Continuar ou N - Encerrar: "; cin >> exit;
            if (exit == 'S')
                continue;
            else if (exit == 'N')
                return 0;
            else {
                exit = NULL;
            }
        }
        exit = NULL;
    }

    return 0;
}

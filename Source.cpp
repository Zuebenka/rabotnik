#include <iostream>
#include <fstream>

using namespace std;

struct Employee {
    string lastName;
    int experience;
    float hourlyRate;
    int workedHours;

    void input() {
        setlocale(LC_ALL, "ru");
        cout << "Введите фамилию: ";
        cin >> lastName;
        cout << "Стаж в годах: ";
        cin >> experience;
        cout << "Зп за час: ";
        cin >> hourlyRate;
        cout << "Кол-во проработанных часов: ";
        cin >> workedHours;
    }

    float calculateSalary() {
        float salary = workedHours * hourlyRate;
        if (experience >= 1 && experience < 3) {
            salary *= 1.05;
        }
        else if (experience >= 3 && experience < 5) {
            salary *= 1.08;
        }
        else if (experience >= 5) {
            salary *= 1.15;
        }
        return salary;
    }

    float calculateBonus() {
        if (experience >= 5) {
            return calculateSalary() * 0.2;
        }
        else {
            return 0;
        }
    }

    void display() {
        cout << "Last name: " << lastName << endl;
        cout << "Experience: " << experience << " years" << endl;
        cout << "Hourly rate: " << hourlyRate << endl;
        cout << "Worked hours: " << workedHours << endl;
        cout << "Salary: " << calculateSalary() << endl;
        cout << "Bonus: " << calculateBonus() << endl;
    }

    void saveToFile() {
        ofstream outFile;
        outFile.open("employee.txt");
        outFile << "Last name: " << lastName << endl;
        outFile << "Experience: " << experience << " years" << endl;
        outFile << "Hourly rate: " << hourlyRate << endl;
        outFile << "Worked hours: " << workedHours << endl;
        outFile << "Salary: " << calculateSalary() << endl;
        outFile << "Bonus: " << calculateBonus() << endl;
        outFile.close();
    }
};

int main() {
    Employee emp;
    emp.input();
    emp.display();
    emp.saveToFile();
    return 0;
}

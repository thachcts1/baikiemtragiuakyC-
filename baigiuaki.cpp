#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee {
private:
    int id;
    string name;
    float salary;

public:
    Employee() {
        id = 0;
        name = "";
        salary = 0;
    }

    Employee(int id, string name, float salary) {
        this->id = id;
        this->name = name;
        this->salary = salary;
    }

    void input() {
        cin.ignore();
        cout << "Nhap ten nhan vien: ";
        getline(cin, name);

        cout << "Nhap luong: ";
        cin >> salary;
    }

    void printInfo() {
        cout << "ID: " << id << " - Ten: " << name << " - Luong: " << salary << endl;
    }

    int getId() {
        return id;
    }

    void setSalary(float salary) {
        this->salary = salary;
    }
};


class EmployeeManager {
private:
    vector<Employee> list;
    int nextId;

public:
    EmployeeManager() {
        nextId = 3001;
    }

    void addEmployee() {
        cout << "\n--- THEM NHAN VIEN ---\n";

        Employee e(nextId, "", 0);
        e.input();

        list.push_back(e);
        cout << "=> Them thanh cong! Ma nhan vien: " << nextId << endl;

        nextId++;
    }

    void showAll() {
        cout << "\n--- DANH SACH NHAN VIEN ---\n";

        if (list.empty()) {
            cout << "Danh sach rong!\n";
            return;
        }

        for (auto &e : list)
            e.printInfo();
    }

    void updateSalaryById() {
        cout << "\n--- CAP NHAT LUONG ---\n";
        int id;
        cout << "Nhap ID nhan vien: ";
        cin >> id;

        for (auto &e : list) {
            if (e.getId() == id) {
                float newSalary;
                cout << "Nhap luong moi: ";
                cin >> newSalary;
                e.setSalary(newSalary);
                cout << "=> Cap nhat thanh cong!\n";
                return;
            }
        }
        cout << "=> Khong tim thay nhan vien!\n";
    }

    void deleteById() {
        cout << "\n--- XOA NHAN VIEN ---\n";
        int id;
        cout << "Nhap ID nhan vien: ";
        cin >> id;

        for (int i = 0; i < list.size(); i++) {
            if (list[i].getId() == id) {
                list.erase(list.begin() + i);
                cout << "=> Xoa thanh cong!\n";
                return;
            }

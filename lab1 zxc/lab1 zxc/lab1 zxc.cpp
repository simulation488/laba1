#include <iostream>
#include <stdexcept>
#include <string>

class ZHES {
private:
    std::string _district;
    int _zhesNumber;
    int _residents;
    double _monthlyPayment;
    int _paidResidents;

public:
    // Конструктор
    ZHES(const std::string& district, int zhesNumber, int residents, double monthlyPayment)
        : _district(district), _zhesNumber(zhesNumber), _residents(residents), _monthlyPayment(monthlyPayment), _paidResidents(0) {}

    // Методы доступа и модификации для district
    std::string getDistrict() const {
        return _district;
    }

    void setDistrict(const std::string& value) {
        if (!value.empty()) {
            _district = value;
        }
        else {
            throw std::invalid_argument("Район не может быть пустым.");
        }
    }

    // Методы доступа и модификации для zhesNumber
    int getZHESNumber() const {
        return _zhesNumber;
    }

    void setZHESNumber(int value) {
        _zhesNumber = value;
    }

    // Методы доступа и модификации для residents
    int getResidents() const {
        return _residents;
    }

    void setResidents(int value) {
        if (value > 0) {
            _residents = value;
        }
        else {
            throw std::invalid_argument("Число жильцов должно быть положительным числом.");
        }
    }

    // Методы доступа и модификации для monthlyPayment
    double getMonthlyPayment() const {
        return _monthlyPayment;
    }

    void setMonthlyPayment(double value) {
        if (value > 0) {
            _monthlyPayment = value;
        }
        else {
            throw std::invalid_argument("Месячная оплата должна быть положительным числом.");
        }
    }

    // Методы доступа и модификации для paidResidents
    int getPaidResidents() const {
        return _paidResidents;
    }

    void setPaidResidents(int value) {
        if (value >= 0 && value <= _residents) {
            _paidResidents = value;
        }
        else {
            throw std::invalid_argument("Число оплативших жильцов должно быть в диапазоне от 0 до общего числа жильцов.");
        }
    }

    // Метод для расчета общей задолженности жильцов
    double calculateDebt() const {
        return _monthlyPayment * (_residents - _paidResidents);
    }
};

int main() {
    // Пример использования
    std::setlocale(LC_ALL, "Russian");
    ZHES zhes("Центральный", 1, 500, 1500);
    zhes.setPaidResidents(200);

    std::cout << "Район: " << zhes.getDistrict() << std::endl;
    std::cout << "Номер ЖЭС: " << zhes.getZHESNumber() << std::endl;
    std::cout << "Число жильцов: " << zhes.getResidents() << std::endl;
    std::cout << "Месячная оплата: " << zhes.getMonthlyPayment() << " рублей" << std::endl;
    std::cout << "Число оплативших жильцов: " << zhes.getPaidResidents() << std::endl;
    std::cout << "Общая задолженность жильцов: " << zhes.calculateDebt() << " рублей" << std::endl;

    ZHES zhes1 ("Центральный 2", 2, 600, 1600);
    zhes.setPaidResidents(200);

    std::cout << "Район: " << zhes1.getDistrict() << std::endl;
    std::cout << "Номер ЖЭС: " << zhes1.getZHESNumber() << std::endl;
    std::cout << "Число жильцов: " << zhes1.getResidents() << std::endl;
    std::cout << "Месячная оплата: " << zhes1.getMonthlyPayment() << " рублей" << std::endl;
    std::cout << "Число оплативших жильцов: " << zhes1.getPaidResidents() << std::endl;
    std::cout << "Общая задолженность жильцов: " << zhes1.calculateDebt() << " рублей" << std::endl;

    return 0;
}
// MyProject.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include < stdio.h >
#include < string.h >
using namespace std;


/// <summary>
/// Создание нового автомобиля
/// </summary>
/// <param name="brand">марка автомобиля</param>
/// <param name="model">модель автомобиля</param>
/// <param name="year">год выпуска</param>
/// <param name="licensePlate">номер знака</param>
void createCar(struct Car* car);
/// <summary>
/// вывод информации об автомобиле
/// </summary>
/// <param name="brand">марка автомобиля</param>
/// <param name="model">модель автомобиля</param>
/// <param name="year">год выпуска</param>
/// <param name="licensePlate">номер знака</param>
void displayCar(struct Car* car);
/// <summary>
/// создание нового заказа на обслуживание
/// </summary>
/// <param name="car">информация об автомобиле</param>
/// <param name="dateTime">дата и время заказа</param>
/// <param name="description">описание работ</param>
void createOrder(struct Car* car, struct ServiceOrder* order);
/// <summary>
/// вывод информации о заказе на экран
/// </summary>
/// <param name="car">информация об автомобиле</param>
/// <param name="dateTime">дата и время заказа</param>
/// <param name="description">описание работ</param>

void displayOrder(struct Car* car, struct ServiceOrder* order);
/*
void addOrder();//добавление нового заказа в файл
void displayAllOrders();//вывод всех заказов из файла
void findOrderByCarNumber();//поиск заказа по номеру автомобиля
void deleteOrder();//удаление заказа из файла
*/
struct Car {
    string brand;
    string model;
    int year;
    string licensePlate;
};

struct ServiceOrder {
    Car car;
    string dateTime;
    string description;
};

int main()
{
    setlocale(0, "");

    int chapter;
    int choice;
    struct Car car = {};
    struct ServiceOrder order = {};
    struct Car car [100];
    struct ServiceOrder order [100];

    

    cout << "Добрый день!\n";
    cout << "Вас приветствует База данных СТО!\n\n";
    cout << "Выберите, пожалуйста нужный Вам раздел:\n 1 - Автомобили \n 2 - Заказы на обслуживание \n 3 - База данных\n";
    cin >> chapter;
    
    if (chapter == 1) {
        cout << "\nВыберите, пожалуйста нужный Вам пункт меню:\n";
        cout << "1 - Создание автомобиля\n 2 - Вывод информации об автомобиле\n";
        cin >> choice;
        if (choice == 1) { createCar(&car); }
        if (choice == 2) { displayCar(&car); }
    }
    if (chapter == 2) {
        cout << "\nВыберите, пожалуйста нужный Вам пункт меню:\n";
        cout << "1 - Создание заказа\n 2 - Вывод информации о заказе\n";
        cin >> choice;
        if (choice == 1) { createOrder(&car, &order); }
        if (choice == 2) { displayOrder(&car, &order); }
    }
    /*
    if (chapter == 3) {
        cout << "\nВыберите, пожалуйста нужный Вам пункт меню:\n";
        cout << "1 - Добавить заказ в файл\n 2 - Вывод всех заказов из файла\n 3 - Поиск заказа по номеру автомобиля\n 4 - Удаление заказа из файла\n";
        cin >> choice;
        if (choice == 1) { addOrder(); }
        if (choice == 2) { displayAllOrders(); }
        if (choice == 3) { findOrderByCarNumber(); }
        if (choice == 4) { deleteOrder(); }
    }
    
    */
}


void createCar(struct Car* car) {
   
    cout << "Марка автомобиля?\n";
    cin >> (*car).brand;
    cout << "Модель автомобиля?\n";
    cin >> (*car).model;
    cout << "Год выпуска автомобиля?\n";
    cin >> (*car).year;
    cout << "Номерной знак автомобиля?\n";
    cin >> (*car).licensePlate;
    cout << "Вы добавляете автомобиль:\n";
    cout << "Марка: " << (*car).brand << "\n\n";
    cout << "Модель: " << (*car).model << "\n\n";
    cout << "Год выпуска: " << (*car).year << "\n\n";
    cout << "Номерной знак: " << (*car).licensePlate << "\n\n";
}

void displayCar(struct Car* car) {
    
    cout << "Вы добавили автомобиль:\n";
    cout << "Марка: " << (*car).brand << "\n\n";
    cout << "Модель: " << (*car).model << "\n\n";
    cout << "Год выпуска: " << (*car).year << "\n\n";
    cout << "Номерной знак: " << (*car).licensePlate << "\n\n";
}

void createOrder(struct Car* car, struct ServiceOrder* order) {
    
    cout << "Введите дату и время\n";
    cin >> (*order).dateTime;
    cout << "Введите описание работ\n";
    cin >> (*order).description;
    cout << "Вы добавляете заказ:\n";
    cout << "Марка: " << (*car).brand << "\n\n";
    cout << "Модель: " << (*car).model << "\n\n";
    cout << "Год выпуска: " << (*car).year << "\n\n";
    cout << "Номерной знак: " << (*car).licensePlate << "\n\n";
    cout << "Дата и время\n";
    cin >> (*order).dateTime;
    cout << "Описание работ\n";
    cin >> (*order).description;
}

void displayOrder(struct Car* car, struct ServiceOrder* order) {
    
    cout << "Вы добавили заказ:\n";
    cout << "Марка: " << (*car).brand << "\n\n";
    cout << "Модель: " << (*car).model << "\n\n";
    cout << "Год выпуска: " << (*car).year << "\n\n";
    cout << "Номерной знак: " << (*car).licensePlate << "\n\n";
    cout << "Дата и время\n";
    cin >> (*order).dateTime;
    cout << "Описание работ\n";
    cin >> (*order).description;
}
/*
void addOrder() {

}
void displayAllOrders() {

}
void findOrderByCarNumber() {

}
void deleteOrder() {

}

*/
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

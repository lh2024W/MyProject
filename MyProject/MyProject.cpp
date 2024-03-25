// project.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdlib.h>
using namespace std;
/// <summary>
/// Создание нового автомобиля
/// </summary>
/// <param name="brand">марка автомобиля</param>
/// <param name="model">модель автомобиля</param>
/// <param name="year">год выпуска</param>
/// <param name="licensePlate">номер знака</param>
void createCar(struct Car* cars, int n);
/// <summary>
/// вывод информации об автомобиле
/// </summary>
/// <param name="brand">марка автомобиля</param>
/// <param name="model">модель автомобиля</param>
/// <param name="year">год выпуска</param>
/// <param name="licensePlate">номер знака</param>
void displayCar(struct Car* cars, int n);
/// <summary>
/// создание нового заказа на обслуживание
/// </summary>
/// <param name="car">информация об автомобиле</param>
/// <param name="dateTime">дата и время заказа</param>
/// <param name="description">описание работ</param>
void createOrder(struct Car* cars, struct ServiceOrder* orders, int n, int m);
/// <summary>
/// вывод информации о заказе на экран
/// </summary>
/// <param name="car">информация об автомобиле</param>
/// <param name="dateTime">дата и время заказа</param>
/// <param name="description">описание работ</param>
void displayOrder(struct Car* cars, struct ServiceOrder* orders, int n, int m);
/// <summary>
/// выбор меню в разделе машины
/// </summary>
/// <param name="cars">массив Cars</param>
/// <param name="n">количество элементов массива Cars</param>
void choiceMenuCars(struct Car* cars, int n);
/// <summary>
/// выбор меню в разделе заказы
/// </summary>
/// <param name="cars">массив Cars</param>
/// <param name="orders">массив Orders</param>
/// <param name="n">количество элементов массива Cars</param>
/// <param name="m">количество элементов массива Orders</param>
void choiceMenuOrders(struct Car* cars, struct ServiceOrder* orders, int n, int m);
/// <summary>
/// поиск по номеру авто в массиве Cars
/// </summary>
/// <param name="cars">массив Cars</param>
/// <param name="n">количество элементов массива Cars</param>
void findAutoInCars(struct Car* cars, int n);

/*
void addOrder();//добавление нового заказа в файл
void displayAllOrders();//вывод всех заказов из файла
void findOrderByCarNumber();//поиск заказа по номеру автомобиля
void deleteOrder();//удаление заказа из файла
*/


struct Car {
    char brand[20];
    char model[20];
    char year[10];
    char licensePlate[20];
};

struct ServiceOrder {
    Car car;
    char dateTime[20];
    char description[100];
};

int main()

{
    setlocale(0, "");

    int chapter;
    int choice;
    struct Car car = {};
    struct ServiceOrder order = {};
    struct Car cars[100];
    struct ServiceOrder orders[100];

    do
    {
        cout << "Добрый день!\n";
        cout << "Вас приветствует База данных СТО!\n\n";
        cout << "Выберите, пожалуйста нужный Вам раздел:\n 1 - Автомобили \n 2 - Заказы на обслуживание \n 3 - База данных\n 0 - Выход\n\n";
        cin >> chapter;

        if (chapter == 1) {
            do
            {
                cout << "\nВыберите, пожалуйста, нужный Вам пункт меню:\n";
                cout << "1 - Создание автомобиля\n 2 - Вывод информации об автомобиле\n 0 - Выход\n\n";
                cin >> choice;
                if (choice == 1) {
                    createCar(cars, 100);
                }
                if (choice == 2) {
                    displayCar(cars, 100);
                }
            } while (choice == 0);
        }


        if (chapter == 2) {
            do
            {
                cout << "\nВыберите, пожалуйста нужный Вам пункт меню:\n";
                cout << "1 - Создание заказа\n 2 - Вывод информации о заказе\n 0 - Выход\n\n";
                cin >> choice;
                if (choice == 1) { createOrder(cars, orders, 100, 100); }
                if (choice == 2) { displayOrder(cars, orders, 100, 100); }
            } while (choice == 0);

            if (chapter == 3) {
                do
                {
                    cout << "\nВыберите, пожалуйста нужный Вам пункт меню:\n";
                    cout << "1 - Добавить заказ в файл\n 2 - Вывод всех заказов из файла\n 3 - Поиск заказа по номеру автомобиля\n\n";
                    cout << "4 - Удаление заказа из файла\n 0 - Выход\n\n";
                    cin >> choice;
                    if (choice == 1) { cout << "Добавить заказ в файл\n"; }
                    if (choice == 2) { cout << "Вывод всех заказов из файла\n"; }
                    if (choice == 3) { cout << "Поиск заказа по номеру автомобиля\n"; }
                    if (choice == 4) { cout << "Удаление заказа из файла\n"; }
                } while (choice == 0);


            }
        }
    } while (chapter == 0);
}

void choiceMenuCars(struct Car* cars, int n) {
    int choice;
    cout << "Выберите действие\n";
    cout << "1 - Посмотреть информацию о добавленном автомобиле.\n";
    cout << "2 - Добавить еще автомобиль.\n";
    cout << "0 - Выход.\n\n";
    cin >> choice;
    if (choice == 1) { displayCar(cars, 100); }
    if (choice == 2) { createCar(cars, 100); }
    if (choice == 0) { exit; }
}

void choiceMenuOrders(struct Car* cars, struct ServiceOrder* orders, int n, int m) {
    int choice;
    cout << "Выберите действие\n";
    cout << "1 - Посмотреть информацию о добавленном заказе.\n";
    cout << "2 - Добавить еще заказ.\n";
    cout << "0 - Выход.\n\n";
    cin >> choice;
    if (choice == 1) { displayOrder(cars, orders, 100, 100); }
    if (choice == 2) { createOrder(cars, orders, 100, 100); }
    if (choice == 0) { exit; }
}


void createCar(struct Car* cars, int n) {
    int count = 0;
    cout << "Марка автомобиля?\n";
    gets_s(cars[count].brand);
    cout << "Модель автомобиля?\n";
    gets_s(cars[count].model);
    cout << "Год выпуска автомобиля?\n";
    gets_s(cars[count].year);
    cout << "Номерной знак автомобиля?\n";
    gets_s(cars[count++].licensePlate);
    choiceMenuCars(cars, 100);
}

void displayCar(struct Car* cars, int n) {
    int count = 0;
    int index = 0;
    for (index = 0; index < count; index++)
        cout << "Вы добавили автомобиль:\n";
    cout << "Марка: " << cars[index].brand << "\n\n";
    cout << "Модель: " << cars[index].model << "\n\n";
    cout << "Год выпуска: " << cars[index].year << "\n\n";
    cout << "Номерной знак: " << cars[index].licensePlate << "\n\n";
    choiceMenuCars(cars, 100);
}

void createOrder(struct Car* cars, struct ServiceOrder* orders, int n, int m) {
    int count = 0;
    cout << "Введите номер автомобиля.\n";
    cout << "Поиск автомобиля.\n";
    findAutoInCars(cars, 100);
    cout << "Введите дату и время приема заказа.\n";
    gets_s(orders[count].dateTime);
    cout << "Введите описание работ\n";
    gets_s(orders[count].description);
    choiceMenuOrders(cars, orders, 100, 100);
}

void displayOrder(struct Car* cars, struct ServiceOrder* orders, int n, int m) {
    int count = 0;
    int index = 0;
    cout << "Вы добавили заказ:\n";
    //cout << "Автомобиль: " << cars.car << "\n\n"; как показать найденый автомобиль???
    for (index = 0; index < count; index++)
        cout << "Дата и время: " << orders[index].dateTime << "\n\n";
    cout << "Описание работ: " << orders[index].description << "\n\n";
    choiceMenuOrders(cars, orders, 100, 100);
}

void findAutoInCars(struct Car* cars, int n) {
    char number[10];
    cout << "Введите номер авто.";
    cin >> number;
    for (int i = 0; i < n; i++) {
        if (number == cars[i].licensePlate)
            cout << cars[i].brand, cars[i].model, cars[i].year, cars[i].licensePlate;
        else
            cout << "Авто с таким номером не найдено. Попробуйте еще раз ввести номер авто.";
    }
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

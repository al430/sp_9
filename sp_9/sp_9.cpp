// sp_9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

double param;

void operation1(double* data, int size) {
    for (int i = 0; i < size; ++i) {
        data[i] += param;
        if (data[i] > 255) data[i] = 255;
    }
}

void operation2(double* data, int size) {
    for (int i = 0; i < size; ++i) {
        data[i] -= param;
        if (data[i] < 0) data[i] = 0;
    }
}

void operation3(double* data, int size) {
    for (int i = 0; i < size; ++i) {
        data[i] = 255 - data[i];
    }
}

void operation4(double* data, int size) {
    for (int i = 0; i < size; ++i) {
        if (data[i] < param) data[i] = 0;
        else data[i] = 255;
    }
}

void (*processors[])(double*, int) = {
    operation1,
    operation2,
    operation3,
    operation4
};

void applyProcessing(double* data, int size, void(*processor)(double*, int)) {
    if (processor != nullptr) {
        processor(data, size);
    }
}

int main() {
    setlocale(LC_ALL, "Rus");

    double data[100];
    double original[100];
    int size = 0;
    int choice = 0;
    srand(time(0));

    while (true) {
        cout << "1. Ввод\n2. Вывод\n3. Выбрать и выполнить обработку\n4. Восстановить исходные данные\n5. Выход\n";
        cin >> choice;

        if (choice == 1) {
            cout << "Размер: ";
            cin >> size;
            size = abs(size) % 100;
            for (int i = 0; i < size; ++i) {
                data[i] = rand()%255;
                original[i] = data[i];
            }
        }
        else if (choice == 2) {
            if (size == 0) {
                cout << "Нет данных\n";
                continue;
            }
            for (int i = 0; i < size; ++i) {
                cout << data[i] << " ";
            }
            cout << "\n";
        }
        else if (choice == 3) {
            if (size == 0) {
                cout << "Нет данных\n";
                continue;
            }

            cout << "До: ";
            for (int i = 0; i < size; ++i) {
                cout << data[i] << " ";
            }
            cout << "\n";

            cout << "1. Увеличить\n2. Уменьшить\n3. Инверсия\n4. Порог\n";
            int op = 0;
            cin >> op;

            if (op >= 1 && op <= 4) {
                if (op == 1 || op == 2 || op == 4) {
                    cout << "Параметр: ";
                    cin >> param;
                }

                void (*currentProcessor)(double*, int) = nullptr;
                currentProcessor = processors[op - 1];

                applyProcessing(data, size, currentProcessor);
            }
            else {
                cout << "Ошибка\n";
            }

            cout << "После: ";
            for (int i = 0; i < size; ++i) {
                cout << data[i] << " ";
            }
            cout << "\n";
        }
        else if (choice == 4) {
            if (size == 0) {
                cout << "Нет данных\n";
                continue;
            }
            for (int i = 0; i < size; ++i) {
                data[i] = original[i];
            }
            cout << "ОК\n";
        }
        else if (choice == 5) {
            break;
        }
        else {
            cout << "Ошибка\n";
        }
    }

    return 0;
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

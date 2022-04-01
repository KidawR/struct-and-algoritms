#include <iostream>
#include <chrono>
#include <string>

using namespace std;

int* SortMas(int* arr, int size) // функция ввода массива
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // меняем элементы местами
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}
//    // Вывод отсортированного массива на экран
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << " ";
//    }
//
//}

void timeLS(int* arr, int size, int value) {
    auto begin = std::chrono::high_resolution_clock::now();

    int i;
    int count = 0;
    for (i = 0 ; i < size ; i++ ){
        if (arr[i] == value){
            count++;
        }
    }
    auto end = chrono::high_resolution_clock::now();
    cout << chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
         << "*10^(-9)c=Поиск(" << i << "," << count << ")\t\t\t";
}

void timeLSB(int *arr, int size, int value) {
    auto begin = std::chrono::high_resolution_clock::now();
    int i;
    //Поиск с барьером
    if (size != 0) {
        int last = arr[size - 1]; //Сохраним прежний элемент массива
        arr[size - 1] = value; //Гарантируем, что value есть в массиве
        //Есть гарантия того, что элемент есть в массиве, значит индекс можно не проверять

        for (i = 0; arr[i] != value; ++i) { //Одно условие в цикле
        }
        arr[size - 1] = last; //Восстанавливаем последний элемент
        if (i != (size - 1) || value == last) { //Не уткнулись в барьер или последний элемент был искомым
            i = i;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    cout << chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
         << "*10^(-9)c = Поиск с барьером(" << i  <<  ")\t\t\t";
}

void timeBS(int *arr, int size, int value) {
    auto begin = std::chrono::high_resolution_clock::now();
    int i = 0;
    //<Бинарный поиск>
    bool found = false;
    int high = size - 1, low = 0;
    int middle = (high + low) / 2;
    while ( !found && high >= low ){
        i++;
        if (value == arr[middle])
            found = true;
        else if (value < arr[middle])
            high = middle - 1;
        else
            low = middle + 1;
        middle = (high + low) / 2;
    }

    auto end = chrono::high_resolution_clock::now();
    cout << chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
         << "*10^(-9)c = Бинарный поиск(" << i  <<  ")\t\t\t";
}

int* Random(int n, int percentSortedArray){
    int temp;

    int sizePercentArray = (percentSortedArray*n)/100;
    int* mas = new int[n];
    for (int i = 0; i < n; i++) {
        mas[i] = (rand() % 100) - 1;
    }
    if(percentSortedArray > 0) {
        for(int i = 0; i < sizePercentArray - 1; i++) {
            for(int j = 0;j < sizePercentArray - i - 1; j++){
                if(mas[j]>mas[j+1]){
                    temp = mas[j];
                    mas[j] = mas[j+1];
                    mas[j+1] = temp;
                }
            }
        }
    }
    return mas;
} // рандомный вывод функции

int* hands(int n, int percentSortedArray)
{
    int temp;
    int sizePercentArray = (percentSortedArray*n)/100;
    int* mas = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "mas[" << i + 1 << "]=";
        cin >> mas[i];
        cout << endl;

    }
    if(percentSortedArray > 0) {
        for(int i = 0; i < sizePercentArray - 1; i++) {
            for(int j = 0;j < sizePercentArray - i - 1; j++){
                if(mas[j]>mas[j+1]){
                    temp = mas[j];
                    mas[j] = mas[j+1];
                    mas[j+1] = temp;
                }
            }
        }
    }
    return mas;
} // ввод массива с рук

int* (*masflex[2])(int n, int percentSortedArray ) = { Random, hands };

bool Start( ){
    setlocale(LC_ALL, "Rus");
    int n = 0, k, numPut;
    int percentSortedArray, flac, value;
    bool flag = false;
    while (flag == false) {
        cout << "Выберите метод ввода массива 1- рандомно 2- руками\n";
        cout << "Вы вводите -";
        cin >> numPut;
        cout << endl;
        if (numPut < 1 || numPut > 2) {
            cout << "Вы ввели неверное значение\n";
        }else if(numPut == 2) {
            flag = true;
            cout << "Введите размер массива";
            cin >> n;
            cout << "\nВведите чесло которое ищете";
            cin >> value;
            cout << endl;
            cout << "Отсортированая часть: введите число от 0 до 100 %\n";
            cout << "Вы вводите:";
            cin >> percentSortedArray;

            int* mas = masflex[numPut - 1](n, percentSortedArray);
            cout << "Неотсортированный массив { ";
            SortMas(mas, n);
            cout << "}\n";

            cout << "Время затраченое на сортировку:\n";
            cout << "---------------------------------------------------------------------------------------------------------------------\n";
            timeLS(mas, n , value);
            cout<<"\n";
            timeLSB(mas, n, value);
            cout<<"\n";
            timeBS(mas, n, value);
            cout<<"\n";
            cout << "----------------------------------------------------------------------------------------------------------------------\n\n";
            if (n <= 100) {
                cout << "Отсортированный массив{ ";
                SortMas(mas, n);
                cout << "}\n";
            }
        }else if(numPut == 1){
            cout << "\nВведите число:";
            cin >> value;
            flag = true;
            n = 100;

            if(flac == 1) cout << "Прямая сортировка\n";

            for (int i = 0; i <= 4; i++) {
                cout << n << " элементов\n";
                cout << "\n\t\t";
                int *mas = masflex[numPut - 1](n, percentSortedArray);
                timeLS(mas, n, value);
                cout << "\n\t\t";
                timeLSB(mas, n, value);
                cout << "\n\t\t";
                int* arr= SortMas(mas, n);
                timeBS(arr, n, value);
                cout << "\n\t\t";
                timeLS(arr, n, value);
                cout << "\n\t\t";
                cout << "\n\n";
                if (i == 0) n = 500;
                if (i == 1) n = 2 * n;
                if (i == 2) n = 3 * n;
                if (i == 3) n = 10000;
            }
        }
    }
    cout << "чтобы завершить работу программы нажмите 0\n";
    cin >> k;
    cout << endl;
    if (k == 0) {
        cout << "Вы завершили работу программы";
        return true;
    } else Start();
} // основная функция с выводом всего

int main(){
    Start();
}
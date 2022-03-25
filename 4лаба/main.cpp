#include <iostream>
#include <chrono>
#include <string>
#include "QIM.h"
using namespace std;

void PrintMas(int* mas, int n) // функция ввода массива
{
    for (int i = 0; i < n; i++)
        cout << mas[i] << " ";
}

int* timeQS(int *mas, int n) {
    auto begin = std::chrono::high_resolution_clock::now();
    int *masQS = quicksort(mas, 0, n - 1); //Быстроя сортировка
    auto end = chrono::high_resolution_clock::now();
    cout << chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
    << "*10^(-9) c = Быстрая сортировка\t\t\t";
}
int* timeIS(int* mas,int n) {
    auto begin = std::chrono::high_resolution_clock::now();
    int *masIS = InsertSort(mas, n); //Сортировка вставками
    auto end = std::chrono::high_resolution_clock::now();
    cout << chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
    << "*10^(-9)c = Сортировка вставками\t\t\t";
}
int* timeMS(int* mas, int n) {
    auto begin = std::chrono::high_resolution_clock::now();
    MergeSort(mas, 0, n - 1); //Сортировка слиянием
    auto end = chrono::high_resolution_clock::now();
    cout << chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
    << "*10^(-9)c = Сортировка слиянием \t\t\t";
}
int* timeBS(int* mas, int n) {
    auto begin = std::chrono::high_resolution_clock::now();
    int *masBS = BoubleSort(mas, n); //Сортировка пузыриком
    auto end = chrono::high_resolution_clock::now();
    cout << chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
    << "*10^(-9)c = Сортировка пузыриком\t\t\t";
}

int* Random(int n, int percentSortedArray, int flac){
    int temp;

    int sizePercentArray = (percentSortedArray*n)/100;
    int* mas = new int[n];
    for (int i = 0; i < n; i++) {
        mas[i] = (rand() % 2001) - 10;
    }
    if(percentSortedArray > 0) {
        if(flac == 1) { //прямая сортировка
        for(int i = 0; i < sizePercentArray - 1; i++) {
            for(int j = 0;j < sizePercentArray - i - 1; j++){
                if(mas[j]>mas[j+1]){
                    temp = mas[j];
                    mas[j] = mas[j+1];
                    mas[j+1] = temp;
                }
            }
        }
        }else{ //обратная сортировка
            for(int i = 0; i < sizePercentArray - 1; i++){
                for(int j = 0;j < sizePercentArray - i - 1; j++){
                    if(mas[j]<mas[j+1]){
                        temp = mas[j];
                        mas[j] = mas[j+1];
                        mas[j+1] = temp;

                    }
                }
            }
        }
    }
    return mas;
} // рандомный вывод функции

int* hands(int n, int percentSortedArray, int flac)
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
        if(flac == 1) {
            cout << "Прямо\n";
            for(int i = 0; i < sizePercentArray - 1; i++) {
                for(int j = 0;j < sizePercentArray - i - 1; j++){
                    if(mas[j]>mas[j+1]){
                        temp = mas[j];
                        mas[j] = mas[j+1];
                        mas[j+1] = temp;
                    }
                }
            }
        }else{
            cout << "обратная\n";
            for(int i = 0; i < sizePercentArray - 1; i++){
                for(int j = 0;j < sizePercentArray - i - 1; j++){
                    if(mas[j]<mas[j+1]){
                        temp = mas[j];
                        mas[j] = mas[j+1];
                        mas[j+1] = temp;

                    }
                }
            }
        }
    }
    return mas;
} // ввод массива с рук

int* (*masflex[2])(int n, int percentSortedArray, int flac ) = { Random, hands };

bool Start( ){
    setlocale(LC_ALL, "Rus");
    int n = 0, k, numPut;
    int percentSortedArray, flac;
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
            cout << endl;
            cout << "Отсортированая часть: введите число от 0 до 100 %\n";
            cout << "Вы вводите:";
            cin >> percentSortedArray;
            cout << "Чтобы отсортированой частью заполнить: прямо-1, обратно-0\n Вы вводите:";
            cin >> flac;

            int* mas = masflex[numPut - 1](n, percentSortedArray, flac);
            cout << "Неотсортированный массив { ";
            PrintMas(mas, n);
            cout << "}\n";

            cout << "Время затраченое на сортировку:\n";
            cout << "---------------------------------------------------------------------------------------------------------------------\n";
            timeQS(mas, n);
            cout<<"\n";
            timeIS(mas, n);
            cout<<"\n";
            timeMS(mas, n);
            cout<<"\n";
            timeBS(mas, n);
            cout<<"\n";
            cout << "----------------------------------------------------------------------------------------------------------------------\n\n";
            if (n <= 100) {
                cout << "Отсортированный массив{ ";
                PrintMas(mas, n);
                cout << "}\n";
            }
        }else if(numPut == 1){
            flag = true;
            n = 20;
            for(flac = 1; flac <= 2; flac++) {

                if(flac == 1) cout << "Прямая сортировка\n";

                for (int i = 0; i < 6; i++) {
                    cout << n << " элементов\n";
                    cout << "\n\t\t";
                    for (percentSortedArray = 0; percentSortedArray <= 100; percentSortedArray += 25) {
                        cout << "%= " << percentSortedArray << "\t\t\t\t\t\t\t\t\t\t";
                    }
                    cout << "\n\t\t";
                    for (percentSortedArray = 0; percentSortedArray <= 100; percentSortedArray += 25) {
                        int *mas = masflex[numPut - 1](n, percentSortedArray, flac);
                        timeQS(mas, n);
                    }
                    cout << "\n\t\t";
                    for (percentSortedArray = 0; percentSortedArray <= 100; percentSortedArray += 25) {
                        int *mas = masflex[numPut - 1](n, percentSortedArray, flac);
                        timeIS(mas, n);
                    }
                    cout << "\n\t\t";
                    for (percentSortedArray = 0; percentSortedArray <= 100; percentSortedArray += 25) {
                        int *mas = masflex[numPut - 1](n, percentSortedArray, flac);
                        timeMS(mas, n);
                    }
                    cout << "\n\t\t";
                    for (percentSortedArray = 0; percentSortedArray <= 100; percentSortedArray += 25) {
                        int *mas = masflex[numPut - 1](n, percentSortedArray, flac);
                        timeBS(mas, n);
                    }
                    cout << "\n\n";
                    if (i == 0) n = 500;
                    if (i == 1) n = 2 * n;
                    if (i == 2) n = 3 * n;
                    if (i == 3) n = 5000;
                    if (i == 4) n = 2 * n;
                    if (i == 5) n = 20;
                }
                cout << "Обратная сортировка\n";
            }
        }
    }
    cout << "чтобы завершить работу программы нажмите 0\n";
    cin >> k;
    cout << endl;
    if (k == 0) {
        cout << "Вы завершили работу программы";
        return true;
    } else {
        Start();
    }
} // основная функция с выводом всего

int main(){
    Start();
}
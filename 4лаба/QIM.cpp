int* quicksort(int* masQS, int first, int last)
{
    int* mas = new int[last + 2];
    for (int i = 0; i < last + 1; i++) {
        mas[i] = masQS[i];
    }
    int mid, temp;
    int f = first, l = last;
    mid = mas[(f + l) / 2]; //вычисляем  средний элемент
    do
    {
        while (mas[f] < mid) f++; //сортировка правой части
        while (mas[l] > mid) l--; //сортировка левой части
        if (f <= l) //перестановка элементов
        {
            temp = mas[f];
            mas[f] = mas[l];
            mas[l] = temp;
            f++;
            l--;
        }
    }while (f < l);

    if (first < l) quicksort(mas, first, l);
    if (f < last);
    return mas;
}

int* InsertSort(int* masIS, int n) //сортировка вставками
{
    int* mas = new int[n];
    for (int i = 0; i < n; i++) {
        mas[i] = masIS[i];
    }
    int key = 0, temp = 0;
    for (int i = 0; i < n - 1; i++)
    {
        key = i + 1;
        temp = mas[key];
        for (int j = i + 1; j > 0; j--)
        {
            if (temp < mas[j - 1])
            {
                mas[j] = mas[j - 1];
                key = j - 1;
            }
        }
        mas[key] = temp;
    }
    return mas;
}

void Merge(int* masMS, int first, int last)
{
    int mid, start, final, j;
    int* mas = new int[last + 1];
    mid = (first + last) / 2; //вычисление среднего элемента
    start = first; //начало левой части
    final = mid + 1; //начало правой части
    j = first;
    for (j; j <= last; j++) //выпонить до начала до конца
        if ((start <= mid) && ((final > last) || (masMS[start] < masMS[final]))) {
            mas[j] = masMS[start];
            start++;
        }
        else {
            mas[j] = masMS[final];
            final++;
        }
    //возвращаем результат в список
    j = first;
    for (j; j <= last; j++)
        masMS[j] = mas[j];

}
void MergeSort(int* masMS, int first, int last)
{
    int mid;
    mid = (first + last) / 2;
    if (first < last)
    {

        MergeSort(masMS, first, mid); //сортировка левой части
        MergeSort(masMS, mid + 1, last); //сортировка правой части
        Merge(masMS, first, last); //слияние двух частей
    }
}

int* BoubleSort(int* masBS, int n){
    int* mas = new int[n];
    for (int i = 0; i < n; i++) {
        mas[i] = masBS[i];
    }
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0;j < n - i - 1; j++){
            if(mas[j]>mas[j+1]){
                int temp = mas[j];
                mas[j] = mas[j+1];
                mas[j+1] = temp;

            }
        }
    }
    return mas;
}
#include <iostream>
using namespace std;

template <typename T>
T maksimum(T arr[], int n)
{
    T max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

template <typename T>
T minimum(T arr[], int n)
{
    T min = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }

    return min;
}

template <typename T>
void sortuvaty(T arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T>
int dvijkovyi_poshuk(T arr[], int n, T znach)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == znach)
            return mid;

        if (arr[mid] < znach)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

template <typename T>
void zaminyty(T arr[], int n, T stare, T nove)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == stare)
            arr[i] = nove;
    }
}

template <typename T>
void vyvesty(T arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int main()
{
    int n;

    cout << "Vvedit kilkist elementiv: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Nekorektna kilkist!";
        return 0;
    }

    int arr[100];

    cout << "Vvedit elementy masyvu: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Maksymum: " << maksimum(arr, n) << endl;
    cout << "Minimum: " << minimum(arr, n) << endl;

    sortuvaty(arr, n);

    cout << "Vidsortovanyi masyv: ";
    vyvesty(arr, n);

    int znach;
    cout << "Vvedit element dlya dvijkovoho poshuku: ";
    cin >> znach;

    int index = dvijkovyi_poshuk(arr, n, znach);

    if (index != -1)
        cout << "Element znaideno na pozytsii: " << index << endl;
    else
        cout << "Element ne znaideno" << endl;

    int stare, nove;
    cout << "Yakyi element zaminyty: ";
    cin >> stare;

    cout << "Na yakе znachennia: ";
    cin >> nove;

    zaminyty(arr, n, stare, nove);

    cout << "Masyv pislia zaminy: ";
    vyvesty(arr, n);

    return 0;
}

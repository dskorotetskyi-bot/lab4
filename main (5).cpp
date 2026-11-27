
#include <iostream>
#include <cmath>
using namespace std;


// ---------- оголошення функцій ----------

// Proc43
// перевірка можливості утворення трикутника
bool IsTriangle(float a, float b, float c);
// виведення результату Proc43
void out_triangle(bool pb);
// задача Proc43 цілком
void task_proc43();

// Proc39
// введення K з перевіркою
bool in_K(int &pK);
// введення N з перевіркою
bool in_N(int &pN);
// перевірка існування N-ї цифри
bool DigitN(int K, int N);
// виведення результату Proc39
void out_digit(int pK, int pN, bool pb);
// задача Proc39 цілком
void task_proc39();

// Integer1
// введення відстані L
bool in_L(int &pL);
// знаходження кількості повних метрів
int meters(int pL);
// виведення результату Integer1
void out_meters(int pL, int pm);
// задача Integer1 цілком
void task_Int1();


// ---------- main ----------
int main()
{
    int choice;

    cout << "Меню:" << endl;
    cout << "1 - Proc43" << endl;
    cout << "2 - Proc39" << endl;
    cout << "3 - Integer1" << endl;
    cout << "Ваш вибір: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        task_proc43();
        break;
    case 2:
        task_proc39();
        break;
    case 3:
        task_Int1();
        break;
    default:
        cout << "Невірний пункт меню!" << endl;
    }

    return 0;
}


// ---------- визначення функцій ----------


// ===== Proc43 =====

bool IsTriangle(float a, float b, float c)
{
    if (a > 0 && b > 0 && c > 0 &&
        a + b > c && a + c > b && b + c > a)
        return true;
    else
        return false;
}

void out_triangle(bool pb)
{
    if (pb)
        cout << "True - трикутник можна утворити." << endl;
    else
        cout << "False - трикутник утворити не можна." << endl;
}

void task_proc43()
{
    float a, b, c;

    cout << "Proc43." << endl;

    for (int i = 1; i <= 3; i++)
    {
        cout << "Набір " << i << " (a b c): ";
        cin >> a >> b >> c;

        if (cin.fail())
        {
            cout << "Некоректні дані!" << endl;
            return;
        }

        out_triangle(IsTriangle(a, b, c));
    }
}


// ===== Proc39 =====

bool in_K(int &pK)
{
    cin >> pK;

    if (cin.fail())
        return true;

    if (pK <= 0 || pK >= 1000)
        return true;

    return false;
}

bool in_N(int &pN)
{
    cin >> pN;

    if (cin.fail())
        return true;

    if (pN <= 0 || pN > 4)
        return true;

    return false;
}

bool DigitN(int K, int N)
{
    if (N <= 0 || N > 4 || K <= 0 || K >= 1000)
        return false;

    int count = 0;

    while (K > 0)
    {
        count++;
        K = K / 10;
    }

    return count >= N;
}

void out_digit(int pK, int pN, bool pb)
{
    cout << "K = " << pK << ", N = " << pN << ": ";

    if (pb)
        cout << "True - цифра існує." << endl;
    else
        cout << "False - такої цифри немає." << endl;
}

void task_proc39()
{
    int k[5], n[5];

    cout << "Proc39." << endl;
    cout << "Введіть 5 цілих додатних чисел K (0 < K < 1000):" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "K" << i + 1 << " = ";

        if (in_K(k[i]))
        {
            cout << "Некоректне значення K!" << endl;
            return;
        }
    }

    cout << "Введіть 5 значень N (0 < N <= 4):" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "N" << i + 1 << " = ";

        if (in_N(n[i]))
        {
            cout << "Некоректне значення N!" << endl;
            return;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        out_digit(k[i], n[i], DigitN(k[i], n[i]));
    }
}


// ===== Integer1 =====

bool in_L(int &pL)
{
    cout << "Введіть відстань L у сантиметрах: ";
    cin >> pL;

    if (cin.fail())
        return true;

    if (pL < 0)
        return true;

    return false;
}

int meters(int pL)
{
    return pL / 100;
}

void out_meters(int pL, int pm)
{
    cout << "L = " << pL << " см." << endl;
    cout << "Кількість повних метрів = " << pm << endl;
}

void task_Int1()
{
    int L;

    cout << "Integer1." << endl;

    if (in_L(L))
        cout << "Некоректне значення L!" << endl;
    else
        out_meters(L, meters(L));
}


#include <iostream>
#include <stdlib.h>
#include <chrono>
using namespace std;

class Timer
{
    std::chrono::time_point<std::chrono::steady_clock> start, end;
public:
    Timer()
    {
        start = chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        end = chrono::high_resolution_clock::now();
        std::chrono::duration<float>duration = end - start;
        cout << " |||  Duration: " << duration.count();
    }
};
class Point
{
    int X, Y;
public:
    Point()
    {
        X = 1 + rand() % 100;
        Y = 1 + rand() % 100;
    }
    Point(int x, int y)
    {
        X = x;
        Y = y;
    }
    int GetX()
    {
        return X;
    }
    int GetY()
    {
        return Y;
    }
    bool operator == (Point& point2)
    {
        return (this->X == point2.X) && (this->Y == point2.Y);
    }
    bool operator > (Point& point2)
    {
        if (this->X > point2.X) return true;
        else
        {
            if (this->X == point2.X) return (this->Y > point2.Y);
            else return false;
        }
    }
    bool operator < (Point& point2)
    {
        if (this->X < point2.X) return true;
        else
        {
            if (this->X == point2.X) return (this->Y < point2.Y);
            else return false;
        }
    }
    friend ostream& operator<<(ostream& out, Point& t);
};
ostream& operator<<(ostream& out, Point& t)
{
    out << t.GetX() << "-" << t.GetY();
    return out;
}
template <typename T>
class Sort 
{
public:
    static void QuickSort(T* A[], int b, int e)
    {
        Timer time;
        InnerSort(A, b, e);
        cout << Sort<T>::CheckSort(A, e+1);
    }
    static void InnerSort(T* A[], int b, int e)
    {
        T x; int i, j, c = b, d = e;
        while (c < d) 
        {
            x = *A[(c + d) / 2]; i = c; j = d;
            while (i < j) 
            {
                while (*A[i] < x) i++;
                while (*A[j] > x) j--;
                if (i <= j)
                {
                    swap(A[i], A[j]); i++; j--;
                }
            }
            if (j - c < d - i)
            {
                if (c < j) InnerSort(A, c, j); c = i;
            }
            else { if (i < d) InnerSort(A, i, d); d = j; }
        }
    }
    static void ShellSort(T* A[], int n)
    {
        Timer time2;
        int i, j, h;
        for (h = 1; h <= n / 9; h = h * 3 + 1);
        while (h >= 1)
        {
            for (i = h; i < n; i++)
                for (j = i - h; j >= 0 && *A[j] > *A[j + h]; j -= h)
                    swap(A[j], A[j + h]);
            h = (h - 1) / 3;
        }
        cout << Sort<T>::CheckSort(A, n);
    }
    static bool CheckSort(T* A[], int n)
    {
        cout << "---Sorted? - ";
        for (int i = 0; i < n - 1; i++)
            if (*A[i] > *A[i + 1]) return false;
        return true;
    }
    static void Print(T* Mass[], int num)
    {
        for (int i = 0; i < num; i++) cout << *Mass[i] << " ";
        cout << endl;
    }
};
int main()
{ 
    //system("cls");
    srand(time(NULL));
    const int num = 1000000;
    Point* PointMass[num]; //Ï‡ÒÒË‚ ÛÍ‡Á‡ÚÂÎÂÈ Ì‡ num ‰ËÌ‡ÏË˜ÂÒÍËı Ó·˙ÂÍÚÓ‚ ÚËÔ‡ Point
    Point* CopyPointMass[num];
    int* CursorsMass[num];
    int DEcreaseIntMass[num];
    int INcreaseIntMass[num];
    int RandIntMass[num];
    /* Point Z; Point S;
    cout << "Z: " << Z << endl << "S: " << S << endl;

    Point F(10, 20); Point Q(10, 20);
    cout << "F: " << F << endl << "Q: " << Q << endl;

    bool result = Q == F; bool result2 = S == Z;
    cout << "\nQ = F: " << result << "\nS = Z: " << result2 << endl;

    result = Q > F; result2 = Z < S;
    cout << "\nQ > F: " << result << "\nZ < S: " << result2 << endl;
    */
    //////////////////Ã¿——»¬ POINT///////////////////////////////////
    for (int i = 0; i < num; i++)
    {
        PointMass[i] = new Point();
        CopyPointMass[i] = PointMass[i];
    }
    cout << "\n\n ///Start Point Mass///\n";
    cout << "\n\n ///Point Mass - Quick sort///\n";
    Sort<Point>::QuickSort(PointMass, 0, num-1);
    cout << "\n\n ///Point Mass - Shell sort///\n";
    Sort<Point>::ShellSort(CopyPointMass, num);

    //////////////////Ã¿——»¬ ”¡€¬¿Õ»ﬂ///////////////////////////////////
    for (int i = 0; i < num; i++)
    {
        DEcreaseIntMass[i] = num - i;
        CursorsMass[i] = &DEcreaseIntMass[i];
    }
    cout << "\n\n ///Start Decrease Mass///\n";
    cout << "\n\n ///Decrease Mass - Quick sort///\n";
    Sort<int>::QuickSort(CursorsMass, 0, num - 1);
    for (int i = 0; i < num; i++)CursorsMass[i] = &DEcreaseIntMass[i];
    cout << "\n\n ///Decrease Mass - Shell sort///\n";
    Sort<int>::ShellSort(CursorsMass, num);

    //////////////////Ã¿——»¬ ¬Œ«–¿—“¿Õ»ﬂ///////////////////////////////////
    for (int i = 0; i < num; i++)
    {
        INcreaseIntMass[i] = i;
        CursorsMass[i] = &INcreaseIntMass[i];
    }
    cout << "\n\n ///Start Increase Mass///\n";
    cout << "\n\n ///Increase Mass - Quick sort///\n";
    Sort<int>::QuickSort(CursorsMass, 0, num - 1);
    for (int i = 0; i < num; i++)CursorsMass[i] = &INcreaseIntMass[i];
    cout << "\n\n ///Increase Mass - Shell sort///\n";
    Sort<int>::ShellSort(CursorsMass, num);
  
    //////////////////Ã¿——»¬ —À”◊¿…Õ€’ ◊»—≈À///////////////////////////////////
    for (int i = 0; i < num; i++)
    {
        RandIntMass[i] = 1 + rand() % 100;
        CursorsMass[i] = &RandIntMass[i];
    }
    cout << "\n\n ///Start Random Mass///\n";
    cout << "\n\n ///Random Mass - Quick sort///\n";
    Sort<int>::QuickSort(CursorsMass, 0, num - 1);
    for (int i = 0; i < num; i++)CursorsMass[i] = &RandIntMass[i];
    cout << "\n\n ///Random Mass - Shell sort///\n";
    Sort<int>::ShellSort(CursorsMass, num);
}



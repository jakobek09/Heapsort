#include <iostream>

using namespace std;

void printTab(int tab[], int n)
{
    for (int j = 0; j < n; j++)
    {
        cout << tab[j] << " ";
    }
    cout << endl;
}

void heapify(int tab[], int n, int i)
{
    int largest = i;
    int right = 2 * i + 1;
    int left = 2 * i;

   

    if (left < n && tab[left] > tab[largest])
        largest = left;


    if (right < n && tab[right] > tab[largest])
        largest = right;


    if (largest != i) {

        swap(tab[i], tab[largest]);
        heapify(tab, n, largest);

    }

}



void build(int tab[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(tab, n, i);

    }
}

void heapSort(int tab[], int n)
{

    build(tab, n);

    for (int i = n - 1; i > 0; i--) {

        printTab(tab, i + 1);
        swap(tab[0], tab[i]);
        
        heapify(tab, i, 0);
        
    }
}



void read()
{
    int NoTests, size;
        cin >> NoTests;
        for (int i = 0; i < NoTests; i++)
        {
            cin >> size;
            int* tab = new int[size];
            for (int j = 0; j < size; j++)
            {
                cin >> tab[j];
            }
            heapSort(tab,size);
            printTab(tab, size);
            delete[] tab;
            cout << endl;
        }
    
}



int main()
{
    read();
    return 0;
}


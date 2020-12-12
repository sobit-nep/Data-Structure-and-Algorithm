#include <iostream>
using namespace std;
void insertion_sort(int arr[], int n)
{
    int i, j, key;

    for(i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while(arr[j] > key )
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}
int main()
{
    int arr_size;
    cout<<"\tInsertion Sort"<<endl;
    cout<<"\t\tenter the size of array: ";
    cin>>arr_size;

    int arr[arr_size];
    cout<<endl<<"\tenter the array elements:"<<endl;
    cout<<"\t";
    for(int i =0; i < arr_size; i++)
    {
        cin>>arr[i];
    }

    insertion_sort(arr, arr_size);

    cout<<endl<<"\tThe sorted array is:\n\t";
    for(int i = 0; i < arr_size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

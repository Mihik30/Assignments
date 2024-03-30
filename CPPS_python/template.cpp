//swap
#include <iostream>
using namespace std;
template<class T>
void swap(T i , T j)
{
    T temp = i;
    i=j;
    j=temp;
    
    cout<<i<<" "<<j<<endl;
}
int main()
{
    swap(10,20);
    swap(10.7,20.9);
    
    return 0;
}




//sort
#include <iostream>
#include <string>
using namespace std;
template<class T>
void print(T arr[] , int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        cout<<arr[i]<<endl;
    }
}
template<class T>
void sort(T arr[] , int n)
{
    T temp;
    for(int i = 0; i < n ; i++)
    {
        for(int j = i+1 ; j < n ; j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    print(arr,n);
}
int main()
{
    int arr[] = {5,6,4,3,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr, n);
    float arr1[] = {5.6,6.3,4.7,3.1,3.5,2.9};
    int n1 = sizeof(arr1)/sizeof(arr[0]);
    sort(arr1, n);
    // string arr2[] = {"c","a"};
    // int n2=2; //= sizeof(arr2)/sizeof(arr[0]);
    // sort(arr2 , n);
    
    return 0;
}



//linear search
#include <iostream>
using namespace std;
template<class T>
void sort(T arr[] , T n , T keyval)
{
    for(int i = 0 ; i < n ; i++)
    {
        if(arr[i]==keyval)
        {
            cout<<"value at position "<<i+1<<endl;
        }
    }
}
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10},keyval=2,n=10;
    sort(arr , n , keyval);
    
    float arr2[] = {1.95,2.38,3.69,4.86,5.14,6.22,7.76,8.890,9.5,16.8},keyval2=3.65,n2=10;
    sort(arr2 , n2 , keyval2);
    
    char arr1[] = {'j','t','q','i','o','p','e','x','k','c'},keyval1='x',n1=10;
    sort(arr1 , n1 , keyval1);
    return 0;
}


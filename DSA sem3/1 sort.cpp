#include<iostream> 
using namespace std; 
 
void Insertion_sort(int arr[],int n){ 
    int temp; 
    for(int i=0;i<n;i++){ 
        temp=arr[i]; 
        int j = i-1; 
        while(j>=0 && arr[j] > arr[i]){ 
            arr[j+1] = arr[j]; 
            j--; 
        } 
        arr[j+1] = temp; 
    } 
} 
void shell_sort(int arr[], int n) { 
    for (int gap = n / 2; gap > 0; gap /= 2) { 
        for (int j = gap; j < n; j++) { 
            int temp = arr[j]; 
            int i = j - gap; 
            while (i >= 0 && arr[i] > temp) { 
                arr[i + gap] = arr[i]; 
                i -= gap; 
            } 
            arr[i + gap] = temp; 
        } 
    } 
} 
 
int getMAX(int arr[],int n){ 
    int m = arr[0]; 
    for(int i=0;i<n;i++){ 
        if(arr[i]>m){ 
            m = arr[i]; 
        } 
    } 
    return m; 
} 
void counting_sort(int arr[],int n,int div){ 
    int output[n]; 
    int count[10]={0}; 
    for(int i=0;i<n;i++){ 
        count[(arr[i]/div)%10]++; 
    } 
    for(int i=1;i<10;i++){ 
        count[i] = count[i] + count[i-1]; 
    } 
    for(int i=n-1;i>=0;i--){ 
        output[count[(arr[i]/div)%10] - 1] = arr[i]; 
        count[(arr[i]/div)%10]--; 
    } 
    for (int i = 0; i < n; i++) { 
        arr[i] = output[i]; 
    } 
    
} 
void radix_sort(int arr[],int n){ 
    int m = getMAX(arr,n); 
    for(int div=1;m/div>0;div=div*10){ 
        counting_sort(arr,n,div); 
    } 
} 
 
int main() { 
    int n; 
    int div; 
    cout<<"Enter the number of elements: "; 
    cin>>n; 
    int arr[n]; 
    cout<<"Enter the number of elements: "; 
    for(int i=0;i<n;i++){ 
        cin>>arr[i]; 
    } 
    shell_sort(arr,n); 
    for(int i=0;i<n;i++){ 
        cout<<arr[i]; 
        cout<<endl; 
    } 
    Insertion_sort(arr,n); 
    for(int i=0;i<n;i++){ 
        cout<<arr[i]; 
        cout<<endl; 
    } 
    getMAX(arr,n); 
    counting_sort(arr,n,div); 
    radix_sort(arr,n); 
    for(int i=0;i<n;i++){ 
cout<<arr[i]; 
cout<<endl; 
} 
return 0; 
} 
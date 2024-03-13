#include <iostream>
using namespace std;
class matrix
{
    private:
        int m;
        int arr[100][100];
    public:
        void get_data()
        {
            cout<<"Enter dimension : ";
            cin>>m;
            cout<<"Enter matrix :";
            for(int i = 0 ; i < m ; i++)
            {
                for (int j = 0 ; j < m ; j++)
                {
                    cin>>arr[i][j];
                }
            }
            
        }
        void print_data()
        {
            for(int i = 0 ; i < m ; i++)
            {
                for (int j = 0 ; j < m ; j++)
                {
                    cout<<"\t"<<arr[i][j];
                }
                cout<<"\n";
            }
        }
        matrix operator+(matrix n2)
        {
            matrix p;
            p.m = m;
            for(int i = 0 ; i < m ; i++)
            {
                for (int j = 0 ; j < m ; j++)
                {
                    p.arr[i][j] = arr[i][j] + n2.arr[i][j];
                }
                cout<<"\n";
            }
            
            return (p);
        }
        matrix operator-(matrix n2)
        {
            matrix p;
            p.m = m;
            for(int i = 0 ; i < m ; i++)
            {
                for (int j = 0 ; j < m ; j++)
                {
                    p.arr[i][j] = arr[i][j] - n2.arr[i][j];
                }
                cout<<"\n";
            }
            
            return (p);
        }
        matrix operator*(matrix n2)
        {
            matrix p;
            p.m = m;
            for(int i = 0 ; i < m ; i++)
            {
                for (int j = 0 ; j < m ; j++)
                {
                    p.arr[i][j] = arr[i][j] * n2.arr[i][j];
                }
                cout<<"\n";
            }
            
            return (p);
        }
    
};



int main()
{
    int n;
    matrix n1,n2,n3;
    n1.get_data();
    n2.get_data();
    
    cout<<endl<<"1 to add"<<endl<<"2 to substract"<<endl<<"3 to multiply"<<endl<<"4 to display 1st matrix"<<endl<<"5 to display 2nd matrix"<<endl;
    cin>>n;
    
    switch(n)
    {
        case 1:
            n3 = n1+n2;
            n3.print_data();
            break;
        case 2:
            n3 = n1-n2;
            n3.print_data();
            break;
        case 3:
            n3 = n1*n2;
            n3.print_data();
            break;
        case 4:
            n1.print_data();
            break;
        case 5:
            n2.print_data();
        default:
            cout<<"Enter valid option";
    }
    
    return 0;
}

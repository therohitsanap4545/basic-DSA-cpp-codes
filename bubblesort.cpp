4#include<iostream>
using namespace std;

void bubble_sort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int main(){
    int n;
    int a[10];
    cout<<"enter the size of the array :";
    cin>>n;

    cout<<"enter"<<n<<"integers in any order :\n";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    bubble_sort(a,n);

    cout<<"sorted array :";
    for(int i = 0;i < n;i++)
    {
        cout<<a[i]<<" ";

    }
    cout<<endl;
    return 0;
}
/*PS C:\Users\ADMIN\OneDrive\Documents\cpp codes rohit> cd "c:\Users\ADMIN\OneDrive\Documents\cpp codes rohit\" ; if ($?) { g++ bubblesort.cpp -o bubblesort } ; if ($?) { .\bubblesort }
enter the size of the array :5
enter5integers in any order :
1 4 2 3 8
sorted array :1 2 3 4 8*/
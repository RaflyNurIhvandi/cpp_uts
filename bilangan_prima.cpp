#include <iostream>
using namespace std;
int main(){
    int angka_awal, angka_akhir;
    cout<<"** BILANGAN PRIMA **"<<endl;
    cout<<"Masukan angka awal : ";
    cin>>angka_awal;
    cout<<"Masukan angka terakhir : ";
    cin>>angka_akhir;
    cout<<"----------------------------"<<endl;
    for (int i = 2; i <= angka_akhir; i++){
        bool bilangan_prima = true;
        for (int j = 2; j <= i / 2; j++){
            if (i % j == 0){
                bilangan_prima = false;
                break;
            }
        }
        if (bilangan_prima && i >= angka_awal){
            cout<<i<<" ";
        }
    }
}
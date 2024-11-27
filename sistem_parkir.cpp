#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void kendaraan_masuk(vector<string>& data_kendaraan){
    string kode;
    cout<<endl<<"Masukan kode parkir kendaraan : ";
    cin>>kode;
    data_kendaraan.push_back(kode);
    cout<<"Kendaraan dengan kode "<<kode<<" berhasil masuk"<<endl;
    cout<<"---------------------"<<endl;
}

void kendaraan_keluar(vector<string>& data_kendaraan){
    string kode;
    cout<<endl<<"Masukan kode parkir kendaraaan : ";
    cin>>kode;

    auto cari_kode = find(data_kendaraan.begin(), data_kendaraan.end(), kode);

    if (cari_kode != data_kendaraan.end()){
        data_kendaraan.erase(cari_kode);
        cout<<"Kendaraan dengan kode "<<kode<<" berhasil keluar"<<endl;
    } else {
        cout<<"Kendaraan dengan kode "<<kode<<" tidak ditemukan"<<endl;
    }
    cout<<"---------------------"<<endl;
}

void tampil_data_kendaraan(vector<string>& data_kendaraan){
    if (data_kendaraan.empty()){
        cout<<endl<<"Data kendaraan yang parkir kosong."<<endl;
        cout<<"---------------------"<<endl;
        return;
    }
    cout<<endl<<"Data kendaraan yang sedang parkir :"<<endl;
    for (int i = 0; i < data_kendaraan.size(); i++){
        cout<<i+1<<". Kode : "<<data_kendaraan[i]<<endl;
    }
    cout<<"---------------------"<<endl;
}

int main(){
    cout<<"*** SISTEM PARKIR ***"<<endl<<endl;
    vector<string> data_kendaraan;
    int menu;
    bool program_berjalan = true;

    while (program_berjalan){
        cout<<"Menu :"<<endl;
        cout<<"1. Kendaraan masuk"<<endl;
        cout<<"2. Kendaraan keluar"<<endl;
        cout<<"3. Tampilkan data kendaraan"<<endl;
        cout<<"4. Keluar program"<<endl;
        cout<<endl<<"Silahkan pilih menu : ";
        cin>>menu;

        switch (menu){
        case 1:
            kendaraan_masuk(data_kendaraan);
            break;
        case 2:
            kendaraan_keluar(data_kendaraan);
            break;
        case 3:
            tampil_data_kendaraan(data_kendaraan);
            break;
        case 4:
            cout<<"Sistem dimatikan"<<endl;
            program_berjalan = false;
            break;
        default:
            cout<<"Pilihan tidak valid, pilih antara nomor 1 - 4 dengan mengetikan angka"<<endl;
            break;
        }
    }
    return 0;
}
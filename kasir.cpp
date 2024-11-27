#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

struct Barang{
    string kode_barang;
    string nama;
    int harga;
    int qty;
};

struct Voucer{
    string kode_voucer;
    int potongan_harga;
};


void lihat_data_barang(vector<Barang>& barang){
    cout<<endl<<"Data barang :"<<endl;
    for (int i = 0; i < barang.size(); i++){
        cout<<barang[i].kode_barang<<" | "<<barang[i].nama<<" -> Rp."<<barang[i].harga<<" -> "<<barang[i].qty<<" Pcs"<<endl;
    }   
}

void tambah_data_barang(vector<Barang>& barang){
    cout<<endl<<"TAMBAH DATA BARANG"<<endl;
    string kode_barang, nama;
    int harga, qty;
    cout<<"Masukan Kode Barang : ";
    cin>>kode_barang;
    cout<<"Masukan Nama Barang : ";
    cin>>nama;
    cout<<"Masukan Harga Barang : ";
    cin>>harga;
    cout<<"Masukan Jumlah Barang : ";
    cin>>qty;
    barang.push_back({kode_barang, nama, harga, qty});
    cout<<endl<<"Data barang berhasil dimasukan"<<endl;
    cout<<"----------------------"<<endl;
}

void hapus_data_barang(vector<Barang>& barang){
    string kode;
    cout<<endl<<"Masukan Kode Barang yang mau dihapus : ";
    cin>>kode;

    auto cari = find_if(barang.begin(), barang.end(), [&](Barang& b){return b.kode_barang == kode;});

    if (cari != barang.end()){
        barang.erase(cari);
        cout<<"Barang dengan kode "<<kode<<" berhasil dihapus."<<endl;
        cout<<"----------------------"<<endl;
    } else {
        cout<<"Barang dengan kode "<<kode<<" tidak ditemukan."<<endl;
        cout<<"----------------------"<<endl;
    }
}

void lihat_voucer(vector<Voucer>& voucer){
    cout<<endl<<"Voucer :"<<endl;
    for (int i = 0; i < voucer.size(); i++){
        cout<<voucer[i].kode_voucer<<" | Potongan -> "<<voucer[i].potongan_harga<<endl;
    }
    
}

struct CO{
    string kode_b;
    int jumlah;
    int total;
};

int hitungTotalHarga(vector<CO>& co) {
    return accumulate(co.begin(), co.end(), 0, [](int ttl, CO& c) {
        return ttl + c.total;
    });
}

void cek_out_barang(vector<Barang>& barang, vector<Voucer>& voucer){
    cout<<endl<<"---- CEK OUT ---"<<endl;
    vector<CO> co;
    string kode_v, metode_pembayaran;
    int uang_dibayarkan;
    bool runCekOut = true;

    while (runCekOut){
        string kode_b, konfirmasi;
        int jumlah;
        cout<<endl<<"Masukan Kode Barang : ";
        cin>>kode_b;
        cout<<"Masukan jumlah barang : ";
        cin>>jumlah;

        auto cari = find_if(barang.begin(), barang.end(), [&](Barang& b){return b.kode_barang == kode_b;});
        if (cari != barang.end()){
            for (int i = 0; i < barang.size(); i++){
                if (barang[i].kode_barang == kode_b){
                    co.push_back({kode_b, jumlah, (barang[i].harga * jumlah)});
                    cout<<barang[i].nama<<" | Rp."<<barang[i].harga<<" -> "<<jumlah<<"Pcs. Total : Rp."<<barang[i].harga * jumlah<<endl;
                }
            }
        } else {
            cout<<"Barang dengan kode "<<kode_b<<" tidak berada dalam daftar stok."<<endl;
        }
        
        cout<<endl<<"Apakah ingin menambahkan barang lagi [y/n] : ";
        cin>>konfirmasi;

        if (konfirmasi == "n"){
            runCekOut = false;
        }
    }
    cout<<"Masukan Kode Voucer jika ada : ";
    cin>>kode_v;
    cout<<"Masukan metode pembayaran : ";
    cin>>metode_pembayaran;

    int v_voucer;
    int total_belanja = hitungTotalHarga(co);
    auto cari_voucer = find_if(voucer.begin(), voucer.end(), [&](Voucer& v){return v.kode_voucer == kode_v;});
    if (cari_voucer != voucer.end()){
        v_voucer = cari_voucer->potongan_harga;
    } else {
        v_voucer = 0;
    };

    int total_belanja_akhir = total_belanja - v_voucer;
    cout<<"Anda mendapatkan potongan Rp."<<v_voucer<<endl;
    cout<<"Total uang yang harus dibayarkan : Rp."<<total_belanja_akhir<<endl;
    cout<<"Jumlah uang dibayarkan : ";
    cin>>uang_dibayarkan;

    int kembalian = uang_dibayarkan - total_belanja_akhir;

    cout<<endl<<"*********** STRUCK BELANJA ***********"<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"Nama Barang        Harga        Jumlah"<<endl;
    for (int i = 0; i < co.size(); i++){
        for (int j = 0; j < barang.size(); j++){
            if (co[i].kode_b == barang[j].kode_barang){
                cout<<barang[j].nama<<"      Rp."<<co[i].total<<"     "<<co[i].jumlah<<endl;
            }
        }
    }
    cout<<"--------------------------------------"<<endl;
    cout<<"Harga Jual                 : Rp."<<total_belanja<<endl;
    cout<<"Potongan Voucer            : Rp."<<v_voucer<<endl;
    cout<<"Total belanja              : Rp."<<total_belanja_akhir<<endl;
    cout<<"Tunai                      : Rp."<<uang_dibayarkan<<endl;
    cout<<"Kembali                    : Rp."<<kembalian<<endl;
    cout<<"Metode Pembayaran          : "<<metode_pembayaran<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"************ TERIMAKASIIH ************"<<endl;
}

int main(){
    vector<Barang> barang = {
        {"BRG1", "Sabun Rinsooo", 14000, 60},
        {"BRG2", "Sampo Sunslik", 12000, 30},
        {"BRG3", "Pepsoden Gigi", 16000, 10},
        {"BRG4", "Kaos Polossss", 50000, 45},
        {"BRG5", "Kopi Kenangan", 12000, 85},
        {"BRG6", "Kopi Goldaaaa", 10000, 12}
    };
    vector<Voucer> voucer = {
        {"V11", 1000},
        {"V12", 1500},
        {"V13", 2500},
    };
    int menu;
    bool isRunning = true;

    cout<<"*** APLIKASI KASIR ***"<<endl;
    while (isRunning){
        cout<<endl<<"Menu :"<<endl;
        cout<<"1. Cek out barang"<<endl;
        cout<<"2. Lihat daftar barang"<<endl;
        cout<<"3. Tambah data barang"<<endl;
        cout<<"4. Lihat Voucer yang berlaku"<<endl;
        cout<<"5. Hapus data barang"<<endl;
        cout<<"6. Keluar program"<<endl;
        cout<<endl<<"Pilih menu : ";
        cin>>menu;

        switch (menu){
        case 1:
            cek_out_barang(barang, voucer);
            break;
        case 2:
            lihat_data_barang(barang);
            break;
        case 3:
            tambah_data_barang(barang);
            break;
        case 4:
            lihat_voucer(voucer);
            break;
        case 5:
            hapus_data_barang(barang);
            break;
        case 6:
            cout<<"Sistem Dimatikan."<<endl;
            isRunning = false;
            break;
        default:
            cout<<"Pilihan tidak valid, pilih antara nomor 1 - 6 dengan mengetikan angka"<<endl;
            break;
        }
    }
}
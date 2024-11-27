#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <cmath>

using namespace std;

struct Kendaraan {
    string kode;
    time_t waktu_masuk;
};

void kendaraan_masuk(vector<Kendaraan>& data_kendaraan) {
    string kode;
    cout << endl << "Masukkan kode parkir kendaraan: ";
    cin >> kode;

    time_t waktu_sekarang = time(nullptr);
    data_kendaraan.push_back({kode, waktu_sekarang});

    cout << "Kendaraan dengan kode " << kode << " berhasil masuk pada "
         << put_time(localtime(&waktu_sekarang), "%H:%M:%S") << endl;
    cout << "---------------------" << endl;
}

void kendaraan_keluar(vector<Kendaraan>& data_kendaraan) {
    string kode;
    cout << endl << "Masukkan kode parkir kendaraan: ";
    cin >> kode;

    auto cari_kode = find_if(data_kendaraan.begin(), data_kendaraan.end(),
                             [&kode](const Kendaraan& k) { return k.kode == kode; });

    if (cari_kode != data_kendaraan.end()) {
        time_t waktu_keluar = time(nullptr);
        double durasi_jam = difftime(waktu_keluar, cari_kode->waktu_masuk) / 3600.0;
        int biaya = static_cast<int>(ceil(durasi_jam)) * 2000;

        cout << endl << "**************** STRUCK PARRKIR ****************" << endl;
        cout << "------------------------------------------------" << endl;
        cout << "Kendaraan dengan kode              : " << kode << endl << "Keluar pada                        : "
             << put_time(localtime(&waktu_keluar), "%H:%M:%S") << endl;
        cout << "Durasi parkir                      : " << fixed << setprecision(2) << durasi_jam << " jam" << endl;
        cout << "Biaya parkir                       : Rp " << biaya << endl;
        cout << "------------------------------------------------" << endl;
        cout << "***************** TERIMAKASIIH *****************" << endl << endl;

        data_kendaraan.erase(cari_kode);
        cout << "---------------------" << endl;
    } else {
        cout << "Kendaraan dengan kode " << kode << " tidak ditemukan." << endl;
        cout << "---------------------" << endl;
    }
}

void tampil_data_kendaraan(vector<Kendaraan>& data_kendaraan) {
    if (data_kendaraan.empty()) {
        cout << endl << "Data kendaraan yang parkir kosong." << endl;
        cout << "---------------------" << endl;
        return;
    }

    cout << endl << "Data kendaraan yang sedang parkir:" << endl;
    for (size_t i = 0; i < data_kendaraan.size(); ++i) {
        cout << i + 1 << ". Kode: " << data_kendaraan[i].kode
             << " | Waktu Masuk: " 
             << put_time(localtime(&data_kendaraan[i].waktu_masuk), "%H:%M:%S") << endl;
    }
    cout << "---------------------" << endl;
}

int main() {
    cout << "*** SISTEM PARKIR ***" << endl << endl;
    vector<Kendaraan> data_kendaraan;
    int menu;
    bool program_berjalan = true;

    while (program_berjalan) {
        cout << "Menu :" << endl;
        cout << "1. Kendaraan masuk" << endl;
        cout << "2. Kendaraan keluar" << endl;
        cout << "3. Tampilkan data kendaraan" << endl;
        cout << "4. Keluar program" << endl;
        cout << endl << "Silahkan pilih menu: ";
        cin >> menu;

        switch (menu) {
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
            cout << "Sistem dimatikan." << endl;
            program_berjalan = false;
            break;
        default:
            cout << "Pilihan tidak valid, pilih antara nomor 1 - 4 dengan mengetikkan angka." << endl;
            break;
        }
    }
    return 0;
}

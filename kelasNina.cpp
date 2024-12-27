#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
using namespace std;

struct Mahasiswa {
    string nim;
    string nama;
    string alamat;
    float ipk;
};

Mahasiswa sikc[30];
int pos = -1;

void updateData() {
    system("cls");
    if (pos == -1) {
        cout << "Tidak ada data untuk diupdate." << endl;
        cout << "\nTekan Enter untuk kembali ke menu...";
        cin.get();
        return;
    }

    string cariNIM;
    cout << "Masukkan NIM mahasiswa yang ingin diupdate: ";
    getline(cin, cariNIM);

    bool ditemukan = false;
    for (int i = 0; i <= pos; i++) {
        if (sikc[i].nim == cariNIM) {
            ditemukan = true;
            cout << "\nData ditemukan!" << endl;
            cout << "-----------------\n";
            cout << left
                 << setw(15) << "NIM"
                 << setw(20) << "Nama"
                 << setw(30) << "Alamat"
                 << setw(10) << "IPK" << endl;
            cout << string(75, '-') << endl;
            cout << left
                 << setw(15) << sikc[i].nim
                 << setw(20) << sikc[i].nama
                 << setw(30) << sikc[i].alamat
                 << setw(10) << sikc[i].ipk
                 << endl;

            cout << "\nMasukkan data baru:\n";
            cout << "Masukkan Nama: ";
            getline(cin, sikc[i].nama);
            cout << "Masukkan Alamat: ";
            getline(cin, sikc[i].alamat);
            cout << "Masukkan IPK: ";
            cin >> sikc[i].ipk;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "\nData berhasil diperbarui!" << endl;
            cout << "\nTekan Enter untuk kembali ke menu...";
            cin.get();
            break;
        }
    }

    if (!ditemukan) {
        cout << "\nData dengan NIM \"" << cariNIM << "\" tidak ditemukan." << endl;
        cout << "\nTekan Enter untuk kembali ke menu...";
        cin.get();
    }
}

void tampilkanSemuaData() {
    system("cls");
    if (pos == -1) {
        cout << "Tidak ada data untuk ditampilkan." << endl;
    } else {
        // Header tabel
        cout << left 
             << setw(5)  << "No" 
             << setw(15) << "NIM" 
             << setw(20) << "Nama" 
             << setw(30) << "Alamat" 
             << setw(10) << "IPK" << endl;
        cout << string(80, '-') << endl; // Garis pemisah

        // Isi tabel
        for (int i = 0; i <= pos; i++) {
            cout << left 
                 << setw(5)  << i + 1 
                 << setw(15) << sikc[i].nim 
                 << setw(20) << sikc[i].nama 
                 << setw(30) << sikc[i].alamat 
                 << setw(10) << fixed << setprecision(2) << sikc[i].ipk 
                 << endl;
        }
    }
    cout << "\nTekan Enter untuk kembali ";
    getch();
}

void masukkanData() {
    system("cls");
    if (pos >= 29) {
        cout << "\nData sudah penuh." << endl;
        cin.get(); // Menunggu enter ditekan agar kembali ke menu
        return;    
    }

    pos++;
    cout << "\nMasukkan Data Mahasiswa\n";
    cout << "-----------------\n";

    cout << "Masukkan NIM: ";
    getline(cin, sikc[pos].nim);
    cout << "Masukkan Nama: ";
    getline(cin, sikc[pos].nama);
    cout << "Masukkan Alamat: ";
    getline(cin, sikc[pos].alamat);
    cout << "Masukkan IPK: ";
    cin >> sikc[pos].ipk;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nData Berhasil Disimpan!\n";
    cout << "\nEnter Untuk Kembali ke Menu\n";
    cin.get();
}

void tampilkanMenu() {
    system("cls");
    cout << "Aplikasi Pencatatan Data Mahasiswa" << "\n";       
    cout << "1. Masukkan Data" << "\n";            
    cout << "2. Tampilkan Data" << "\n";            
    cout << "3. Update Data" << "\n";           
    cout << "4. Hapus Data" << "\n";            
    cout << "5. Keluar" << "\n";           
    cout << "Pilih menu: ";        
}

void hapusData() {
    system("cls");
    if (pos == -1) {
        cout << "Tidak ada data untuk dihapus." << endl;
        cout << "\nTekan Enter untuk kembali ke menu...";
        cin.get();
        return;
    }

    // Menampilkan semua data
    cout << "Data Mahasiswa Saat Ini:" << endl;
    cout << left
         << setw(5)  << "No" 
         << setw(15) << "NIM" 
         << setw(20) << "Nama" 
         << setw(30) << "Alamat" 
         << setw(10) << "IPK" << endl;
    cout << string(80, '-') << endl;

    for (int i = 0; i <= pos; i++) {
        cout << left
             << setw(5)  << i + 1
             << setw(15) << sikc[i].nim
             << setw(20) << sikc[i].nama
             << setw(30) << sikc[i].alamat
             << setw(10) << fixed << setprecision(2) << sikc[i].ipk
             << endl;
    }

    // Meminta NIM untuk data yang akan dihapus
    string cariNIM;
    cout << "\nMasukkan NIM mahasiswa yang ingin dihapus: ";
    getline(cin, cariNIM);

    bool ditemukan = false;
    for (int i = 0; i <= pos; i++) {
        if (sikc[i].nim == cariNIM) {
            ditemukan = true;

            // Konfirmasi penghapusan
            char konfirmasi;
            cout << "\nData ditemukan!" << endl;
            cout << "Apakah Anda yakin ingin menghapus data ini? (y/n): ";
            cin >> konfirmasi;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (konfirmasi == 'y' || konfirmasi == 'Y') {
                // Menghapus data dengan menggeser elemen-elemen di array
                for (int j = i; j < pos; j++) {
                    sikc[j] = sikc[j + 1];
                }
                pos--;

                cout << "\nData berhasil dihapus!" << endl;
            } else {
                cout << "\nPenghapusan dibatalkan." << endl;
            }

            cout << "\nTekan Enter untuk kembali ke menu...";
            cin.get();
            return;
        }
    }

    if (!ditemukan) {
        cout << "\nData dengan NIM \"" << cariNIM << "\" tidak ditemukan." << endl;
        cout << "\nTekan Enter untuk kembali ke menu...";
        cin.get();
    }
}

int main() {
    char pilihan;
    do {
        tampilkanMenu();
        pilihan = getch();

        switch (pilihan) {
        case '1':
            masukkanData();
            break;
        case '2':
            tampilkanSemuaData();
            break;
        case '3':
            updateData();
            break;
        case '4':
            hapusData();
            break;
        case '5':
            cout << "Terima kasih telah menggunakan aplikasi ini!" << endl;
            break;
        default:
            system("cls");
            cout << "Pilihan tidak tersedia. Coba lagi." << endl;
            getch();
            break;
        }
    } while (pilihan != '5');

    return 0;
}
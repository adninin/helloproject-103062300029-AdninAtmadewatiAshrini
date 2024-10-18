#ifndef BARANG_HPP
#define BARANG_HPP

#include <string>

using namespace std; 

class Barang {
private:
    string nama; // nama barang           
    int harga; // harga barang          
    int beratBarang; // berat barang      
    int stock; // jumlah stok barang

public:
    // const inisialisasi objek Barang
    Barang(string nama, int harga, int beratBarang, int stock) 
        : nama(nama), harga(harga), beratBarang(beratBarang), stock(stock) {}

    // untuk mendapatkan nama barang
    string getNama() const { return nama; }

    //untuk mendapatkan harga barang
    int getHarga() const { return harga; }

    // untuk mendapatkan berat barang
    int getBeratBarang() const { return beratBarang; }

    // untuk mendapatkan jumlah stok barang
    int getStock() const { return stock; }

    // untuk mengubah jumlah stok barang
    void setStock(int newStock) { stock = newStock; }

    // method mengecek apakah jumlah yang diminta tersedia dalam stok
    bool cekStock(int jumlah) {
        return stock >= jumlah; // mengembalikan true jika stok mencukupi
    }
};

#endif


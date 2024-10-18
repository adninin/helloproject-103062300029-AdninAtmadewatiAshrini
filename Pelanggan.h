#ifndef PELANGGAN_HPP
#define PELANGGAN_HPP

#include "Order.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std; 

class Pelanggan {
private:
    string nama; // nama pelanggan
    int uang; // jumlah uang yg dimiliki pelanggan
    vector<Order> keranjang; // keranjang berisi order barang
    int kapasitasKeranjang; // kapasitas maksimum keranjang dalam satuan berat
    int beratSaatIni; // berat barang yg saat ini ada di keranjang

public:
    // const inisialisasi objek Pelanggan
    Pelanggan(string nama, int uang) 
        : nama(nama), uang(uang), kapasitasKeranjang(5000), beratSaatIni(0) {}

    // untuk mendapatkan nama pelanggan
    string getNama() const { return nama; }

    // untuk mendapatkan jumlah uang pelanggan
    int getUang() const { return uang; }

    // method untuk menambahkan barang ke keranjang
    string addBarang(Barang& barang, int banyakBarang) {
    	
        // meemriksa apakah stock barang cukup
        if (!barang.cekStock(banyakBarang)) {
            return "Stock " + barang.getNama() + " kurang";
        }

        // memeriksa apakah barang sudah ada di keranjang
        for (auto& order : keranjang) {
            if (order.barang.getNama() == barang.getNama()) {
            	
                // jika sudah ada, tambahkan jumlahnya
                return addBarang(order.barang, order.banyakBarang + banyakBarang);
            }
        }

        // jika tidak ada di keranjang, lanjutkan dengan logika ini
        int totalBeratBaru = beratSaatIni + barang.getBeratBarang() * banyakBarang;
        
        // memeriksa apakah menambahkan barang melebihi kapasitas keranjang
        if (totalBeratBaru > kapasitasKeranjang) {
            int maxBarang = (kapasitasKeranjang - beratSaatIni) / barang.getBeratBarang();
            if (maxBarang > 0) {
            	
                // tambahkan barang maksimum yang dapat ditambahkan
                beratSaatIni += barang.getBeratBarang() * maxBarang;
                barang.setStock(barang.getStock() - maxBarang);
                keranjang.push_back(Order(barang, maxBarang));
                return "Maaf " + to_string(banyakBarang) + " " + barang.getNama() + " terlalu berat, tetapi " + to_string(maxBarang) + " " + barang.getNama() + " berhasil ditambahkan.";
            } else {
                return "Maaf, barang terlalu berat.";
            }
        } else {
            // jika tidak melebihi kapasitas, tambahkan barang ke keranjang
            beratSaatIni += barang.getBeratBarang() * banyakBarang;
            barang.setStock(barang.getStock() - banyakBarang);
            keranjang.push_back(Order(barang, banyakBarang));
            return nama + " berhasil menambahkan " + to_string(banyakBarang) + " " + barang.getNama();
        }
    }

    // method untuk menghitung total harga barang di keranjang
    int totalHargaBarang() {
        int totalHarga = 0;
        
        // menghitung total harga
        for (auto& order : keranjang) {
            totalHarga += order.banyakBarang * order.barang.getHarga();
        }
        return totalHarga; // mengembalikan total harga
    }

    // method untuk mengecek uang pelanggan
    string cekUang() {
        return "Uang " + nama + " sekarang " + to_string(uang); // mengembalikan informasi uang pelanggan
    }

    // method untuk reset keranjang
    void resetKeranjang() {
        keranjang.clear(); // menghapus semua order dari keranjang
        beratSaatIni = 0; // mengatur berat saat ini ke 0
    }

    // method untuk memproses pembelian di kasir
    string prosesPembelian() {
        if (keranjang.empty()) {
            return "Maaf tidak ada barang di keranjang " + nama; // mengembalikan pesan jika keranjang kosong
        }

		// menghitung total belanjaan
        int totalBelanjaan = totalHargaBarang(); 
        if (uang < totalBelanjaan) {
            return "Maaf " + nama + " tidak memiliki cukup uang"; // mengembalikan pesan jika uang tidak cukup
        }
        
		// menyimpan hasil pembelian
        string result = "Pembelian " + nama + " berhasil:\n"; 
        
        // menampilkan detail barang yang dibeli
        for (auto& order : keranjang) {
            int subTotal = order.banyakBarang * order.barang.getHarga();
            result += order.barang.getNama() + " " + to_string(order.banyakBarang) + " = " + to_string(subTotal) + "\n";
        }
        
        // menyertakan total belanjaan
        result += "Total Belanjaan = " + to_string(totalBelanjaan) + "\n"; 
        
        // mengurangi uang pelanggan
        uang -= totalBelanjaan; 
        
        // menyertakan sisa uang setelah pembelian
        result += "Sisa Uang = " + to_string(uang); 

		// mengosongkan keranjang setelah pembelian
        resetKeranjang(); 
        
        return result; // mengembalikan hasil pembelian
    }
};

#endif


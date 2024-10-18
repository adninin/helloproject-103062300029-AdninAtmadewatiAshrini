#ifndef KASIR_HPP
#define KASIR_HPP

#include "Pelanggan.h"
#include <iostream>

using namespace std; 

// struktur Kasir untuk menangani proses pembayaran pelanggan
struct Kasir {
    // fungsi untuk memproses pembelian pelanggan
    static void kasir(Pelanggan& pelanggan) {
        // memanggil metode prosesPembelian() dari objek pelanggan dan mencetak hasil
        cout << pelanggan.prosesPembelian() << endl;
    }
};

#endif


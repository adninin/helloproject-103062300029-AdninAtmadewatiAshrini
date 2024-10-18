#ifndef ORDER_HPP
#define ORDER_HPP

#include "Barang.h"

// struktur untuk merepresentasikan order
struct Order {
    Barang barang; // objek barang yang dipesan
    int banyakBarang; // jumlah barang yang dipesan

    // const inisialisasi objek Order
    Order(Barang barang, int banyakBarang) 
        : barang(barang), banyakBarang(banyakBarang) {}
};

#endif


#include "Kasir.h"
#include <iostream>
#include <vector>

using namespace std; 

int main() {
    int N;
    cin >> N; // membaca jumlah barang yang akan dimasukkan
    vector<Barang> daftarBarang; // vektor untuk menyimpan daftar barang

    // input barang
    for (int i = 0; i < N; i++) {
        string namaBarang;
        int harga, berat, stock;
        cin >> namaBarang >> harga >> berat >> stock; // membaca detail barang
        daftarBarang.push_back(Barang(namaBarang, harga, berat, stock)); // menambahkan barang ke daftar
    }

    int M;
    cin >> M; // membaca jumlah pelanggan yang akan dimasukkan
    vector<Pelanggan> daftarPelanggan; // vektor untuk menyimpan daftar pelanggan

    // input pelanggan
    for (int i = 0; i < M; i++) {
        string namaPelanggan;
        int uang;
        cin >> namaPelanggan >> uang; // membaca detail pelanggan
        daftarPelanggan.push_back(Pelanggan(namaPelanggan, uang)); // menambahkan pelanggan ke daftar
    }

    int P;
    cin >> P; // membaca jumlah perintah yang akan diproses

    // input kejadian
    for (int i = 0; i < P; i++) {
        string perintah;
        cin >> perintah; // membaca perintah yang akan diproses

        if (perintah == "ADD") { // jika perintahnya adalah ADD
            string namaPelanggan, namaBarang;
            int jumlahBarang;
            cin >> namaPelanggan >> namaBarang >> jumlahBarang; // membaca nama pelanggan, nama barang, dan jumlah barang

            // mencari pelanggan berdasarkan nama
            for (auto& pelanggan : daftarPelanggan) {
                if (pelanggan.getNama() == namaPelanggan) { // jika nama pelanggan ditemukan
                    // mencari barang berdasarkan nama
                    for (auto& barang : daftarBarang) {
                        if (barang.getNama() == namaBarang) { // jika nama barang ditemukan
                            cout << pelanggan.addBarang(barang, jumlahBarang) << endl; // Menambahkan barang ke keranjang dan mencetak hasil
                            break; // keluar dari loop barang
                        }
                    }
                    break; // keluar dari loop pelanggan
                }
            }
        } else if (perintah == "TOTAL_HARGA") { // jika perintahnya adalah TOTAL_HARGA
            string namaPelanggan;
            cin >> namaPelanggan; // membaca nama pelanggan

            // mencari pelanggan berdasarkan nama
            for (auto& pelanggan : daftarPelanggan) {
                if (pelanggan.getNama() == namaPelanggan) { // jika nama pelanggan ditemukan
                    // menghitung dan mencetak total harga belanjaan
                    cout << "Total harga belanjaan " << namaPelanggan << " adalah " << pelanggan.totalHargaBarang() << endl; 
                    break; // keluar dari loop pelanggan
                }
            }
        } else if (perintah == "KASIR") { // jika perintahnya adalah KASIR
            string namaPelanggan;
            cin >> namaPelanggan; // mmbaca nama pelanggan

            // mencari pelanggan berdasarkan nama
            for (auto& pelanggan : daftarPelanggan) {
                if (pelanggan.getNama() == namaPelanggan) { // jika nama pelanggan ditemukan
                    Kasir::kasir(pelanggan); // memproses pembelian menggunakan Kasir
                    break; // keluar dari loop pelanggan
                }
            }
        } else if (perintah == "CEK_UANG") { // jika perintahnya adalah CEK_UANG
            string namaPelanggan;
            cin >> namaPelanggan; // membaca nama pelanggan

            // mencari pelanggan berdasarkan nama
            for (auto& pelanggan : daftarPelanggan) {
                if (pelanggan.getNama() == namaPelanggan) { // jika nama pelanggan ditemukan
                    cout << pelanggan.cekUang() << endl; // menghitung dan mencetak sisa uang pelanggan
                    break; // keluar dari loop pelanggan
                }
            }
        }
    }

    return 0; // mengembalikan 0 menandakan program selesai
}


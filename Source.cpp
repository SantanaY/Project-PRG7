#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>


struct item_project
{
	char id[14] = {};
	char nama[32] = {};
	char sku[4] = {};
	int harga;
	int diskon_nominal;
	int diskon_persen;
	int stok;
};

struct pegawai_project
{
	char id[4] = {};
	char nama[32] = {};
	int harga_nondiskon = 0; // sebelum diskon
	int diskon_total = 0;
	int harga_diskon = 0; // setelah diskon
	int kuantitas_terjual = 0;
};

struct log_project
{
	char time[20] = {};
	char id_kasir[4] = {};
	char id_konsumen[4] = {};
	char id_item[14] = {};
	int harga;
	int diskon;
	int kuantiti;
};


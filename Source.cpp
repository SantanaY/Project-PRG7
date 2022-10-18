#include <iostream>
#include <fstream>
#include <string>
// #include <vector>
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

int main()
{

	int item_count = -1;
	int pegawai_count = -1;
	int log_count = -1;
	std::string top_line;
	std::string s_temp;

	// input file item.txt
	std::ifstream item_istream("./data/item.txt");

	while (std::getline(item_istream, top_line)) item_count++;
	item_project arr_item[item_count];

	item_istream.clear();
	item_istream.seekg(0);
	std::getline(item_istream, top_line);
	for (int i = 0; i < item_count; i++)
	{
		std::getline(item_istream, s_temp, '\t');
		strcpy(arr_item[i].id, s_temp.c_str());
		std::getline(item_istream, s_temp, '\t');
		strcpy(arr_item[i].nama, s_temp.c_str());
		std::getline(item_istream, s_temp, '\t');
		strcpy(arr_item[i].sku, s_temp.c_str());
		std::getline(item_istream, s_temp, '\t');
		arr_item[i].harga = stoi(s_temp);
		std::getline(item_istream, s_temp, '\t');
		arr_item[i].diskon_nominal = stoi(s_temp);
		std::getline(item_istream, s_temp, '\t');
		arr_item[i].diskon_persen = stoi(s_temp);
		std::getline(item_istream, s_temp);
		arr_item[i].stok = stoi(s_temp);
	}
	item_istream.close();

	// input file pegawai.txt
	std::ifstream pegawai_istream("./data/pegawai.txt");

	while (std::getline(pegawai_istream, top_line)) pegawai_count++;
	pegawai_project arr_pegawai[pegawai_count];

	pegawai_istream.clear();
	pegawai_istream.seekg(0);
	std::getline(pegawai_istream, top_line);
	for (int i = 0; i < pegawai_count; i++)
	{
		std::getline(pegawai_istream, s_temp, '\t');
		strcpy(arr_pegawai[i].id, s_temp.c_str());
		std::getline(pegawai_istream, s_temp);
		strcpy(arr_pegawai[i].nama, s_temp.c_str());
	}
	pegawai_istream.close();

	// input file log.txt
	std::ifstream log_istream("./data/log.txt");

	while (std::getline(log_istream, top_line)) log_count++;
	log_project arr_log[log_count];

	log_istream.clear();
	log_istream.seekg(0);
	std::getline(log_istream, top_line);
	for (int i = 0; i < log_count; i++)
	{
		std::getline(log_istream, s_temp, '\t');
		strcpy(arr_log[i].time, s_temp.c_str());
		std::getline(log_istream, s_temp, '\t');
		strcpy(arr_log[i].id_kasir, s_temp.c_str());
		std::getline(log_istream, s_temp, '\t');
		strcpy(arr_log[i].id_konsumen, s_temp.c_str());
		std::getline(log_istream, s_temp, '\t');
		strcpy(arr_log[i].id_item, s_temp.c_str());
		std::getline(log_istream, s_temp, '\t');
		arr_log[i].harga = stoi(s_temp);
		std::getline(log_istream, s_temp, '\t');
		arr_log[i].diskon = stoi(s_temp);
		std::getline(log_istream, s_temp);
		arr_log[i].kuantiti = stoi(s_temp);
	}
}

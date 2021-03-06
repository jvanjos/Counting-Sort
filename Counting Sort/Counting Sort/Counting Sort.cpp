// Counting Sort.cpp : define o ponto de entrada para o aplicativo do console.
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

std::ifstream arquivo;
std::vector<int> vetor;
std::vector<int> ordenado;

void countingSort() {
	int maior,i;
	maior = vetor[0];
	for (i = 0; i < vetor.size(); i++) {
		if (maior < vetor[i]) {
			maior = vetor[i];
		}
	}
	int *counting = new int[maior + 1];
	for (i = 0; i < maior + 1; i++) {
		counting[i] = 0;
	}
	for (i = 0; i < vetor.size(); i++) {
		counting[vetor[i]]++;
	}
	for (i = 1; i <= maior; i++) {
		counting[i] = counting[i] + counting[i - 1];
	}

	for (i = vetor.size() - 1 ; i >= 0; i--) {
		ordenado[counting[vetor[i]]-1] = vetor[i];
		counting[vetor[i]]--;
	}
}


int main() {
	std::string arquivoname;
	std::cout << "Quick Sort:" << std::endl << "Digite o nome do arquivo(ex. exemplo.txt): ";
	std::cin >> arquivoname;

	arquivo.open(arquivoname.data());
	if (!arquivo.is_open()) {
		system("pause");
		return -1;
	}
	int i;
	std::string stringer;
	while (!arquivo.eof()) {
		std::getline(arquivo, stringer);
		int num = std::stoi(stringer);
		vetor.push_back(num);
		ordenado.push_back(num);
	}
	countingSort();

	for (i = 0; i < ordenado.size(); i++) {
		std::cout << ordenado[i] << " " << std::endl;
	}
	system("pause");
	return 0;
}
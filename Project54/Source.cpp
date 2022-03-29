#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>

using namespace std;

void process(const char* fileName_1, const char* fileName_2);
void findANDreplace(char* str_l, char* resault_l, const char f, const char s);

int main() {
	setlocale(LC_ALL, "RUS");
	process("file.txt", "result.txt");
}

void process(const char* fileName_1, const char* fileName_2) {
	FILE* f = fopen(fileName_1, "rt");
	if (f == NULL)
	{
		cout << "Не удалось открыть файл " << fileName_1 << endl;
		return;
	}
	ofstream fo;
	fo.open(fileName_2);
	if (!fo.is_open())
	{
		cout << "Не удалось открыть файл " << fileName_2 << endl;
		fclose(f);
		return;
	}
	while (!feof(f))
	{
		char buff[250] = {};
		fgets(buff, 199, f);
		if (strlen(buff) > 0)
		{
			char buff2[250] = {};
			findANDreplace(buff, buff2, 'Я', 'я');
			cout << buff2;
			fo << buff2;
		}
	}
	fclose(f);
	fo.close();
}
void findANDreplace(char* str_l, char* resault_l, const char f, const char s) {
	char ss[] = { "Ты" };
	char ss2[] = { "ты" };
	int counter = 0;
	memset(resault_l, 0, sizeof(char) * 250);
	strcat(resault_l, str_l);
	for (int i = 0; i < strlen(resault_l); i++) {
		if (resault_l[i] == 'Я') {
			char s1[250] = {};
			char s2[250] = {};
			strncpy(s1, resault_l, i);
			strncpy(s2, i + 1 + resault_l, strlen(resault_l) - i);
			strcat(s1, ss);
			strcat(s1, s2);
			memset(resault_l, 0, sizeof(char) * 250);
			strcat(resault_l, s1);
			counter += 1;
			i = 0;
		}
		else if (resault_l[i] == 'я') {
			char s1[250] = {};
			char s2[250] = {};
			strncpy(s1, resault_l, i);
			strncpy(s2, i+1 + resault_l, strlen(resault_l) - i);
			strcat(s1, ss2);
			strcat(s1, s2);
			memset(resault_l, 0, sizeof(char) * 250);
			strcat(resault_l, s1);
			counter += 1;
			i = 0;
		}
	}
}
#include <iostream>
#include "data_converter.h"

int main()
{
	data_converter dates;

	dates.OpenFile("datas.txt");
	dates.convertData();
	dates.showDataInConsole();
	dates.saveDataToFile();

	getchar();
	return 0;

}
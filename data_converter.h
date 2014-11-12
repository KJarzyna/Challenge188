#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class data_converter
{
public:
	
	
	void OpenFile(string);
	void convertData();
	void showDataInConsole();
	void saveDataToFile();

private:

	fstream data_file;

	string filename;
	string singleline;
	string newline;
	string day,month,year;

	vector<string> data_new;

	unsigned int TypeOfDate;
	bool FileIsOpen;

	void GetSingleLine();
	void LookForSymbol();
	void Convert();
	void MonthToNumber();
	void CreateNewDate();
};
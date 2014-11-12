#include "data_converter.h"
#include <iostream>;

void data_converter::OpenFile(string file)
{
	filename = file;
	data_file.open(filename);

	if(data_file.good())
	{
		cout << "File opened successful!" << endl;
		FileIsOpen = true;
	}
	else
	{
		cout << "Error when opening file!" << endl;
		FileIsOpen = false;
	}
	
	//Open file and check if it's good
}

void data_converter::convertData()
{
	if(FileIsOpen)
	{
		while(!data_file.eof())
		{
		GetSingleLine();
		LookForSymbol();
		Convert();
		CreateNewDate();
		}

		data_file.close();

	}

	// Get old date from file and convert it to new date
	
}

void data_converter::GetSingleLine()
{
	getline(data_file, singleline);

	//Get single line from dates.txt
}

void data_converter::LookForSymbol()
{
	char symbols[5] = {'-', '*', '#', '/', ','};
	for(int n=0;n<5;n++)
	{
		if (singleline.find(symbols[n]) != string::npos)
		{
			TypeOfDate = n;
		}
		else
		{
			continue;
		}
	}

	//Each date have certain symbol. Search for each symbol and determine type of the date.
	/*
	Types:
	yyyy-mm-dd
	dd*mm*yyyy
	mm#yy#dd
	mm/dd/yy

	(month word) dd, yy
	(month word) dd, yyyy
	*/
}

void data_converter::Convert()
{
	switch (TypeOfDate)
		{
	case 0:
		{
			day = singleline.substr(8,2);
			month = singleline.substr(5,2);
			year = singleline.substr(0,4);
			break;
		}
	case 1:
		{
			day = singleline.substr(0,2);
			month = singleline.substr(3,2);
			year = singleline.substr(6,4);
			break;
		}
	case 2:
		{
			day = singleline.substr(6,2);
			month = singleline.substr(0,2);
			year = singleline.substr(3,2);

			if (atoi(year.c_str()) > 50) //Convert year from two digits to four digits (1950-2049)
			{
				year = "19" + year;
			}
			else
			{
				year = "20" + year;
			}
			break;
		}
	case 3:
		{
			day = singleline.substr(3,2);
			month = singleline.substr(0,2);
			year = singleline.substr(6,2);

			if (atoi(year.c_str()) > 50) //Convert year from two digits to four digits (1950-2049)
			{
				year = "19" + year;
			}
			else
			{
				year = "20" + year;
			}
			break;
		}
	case 4:
		{
			if(singleline.size()==10)
			{
				day = singleline.substr(4,2);
				month = singleline.substr(0,3);
				cout << month << endl;
				MonthToNumber();
				year = singleline.substr(8,2);

				if (atoi(year.c_str()) > 50) //Convert year from two digits to four digits (1950-2049)
				{
					year = "19" + year;
				}
				else
				{
					year = "20" + year;
				}

			}
			else
			{
				day = singleline.substr(4,2);
				month = singleline.substr(0,3);
				MonthToNumber();
				year = singleline.substr(8,4);

			}
			break;
		}
	default:
		{
			cout << "Niew³aœciwy format daty!" << endl;
			break;
		}

	}
	//Convert each type of date to day, month, year
}

void data_converter::MonthToNumber()
{

	if (month == "Jan") month = "01";
	else if (month == "Feb") month = "02";
	else if (month == "Mar") month = "03";
	else if (month == "Apr") month = "04";
	else if (month == "May") month = "05";
	else if (month == "Jun") month = "06";
	else if (month == "Jul") month = "07";
	else if (month == "Aug") month = "08";
	else if (month == "Sep") month = "09";
	else if (month == "Oct") month = "10";
	else if (month == "Nov") month = "11";
	else month = "12";

	//If month is not a number, convert it to number
	
}

void data_converter::CreateNewDate()
{
	newline = year + '-' + month + '-' + day;
	data_new.push_back(newline);

	//Create new date in ISO 8601 standard, year-month-day
}

void data_converter::showDataInConsole()
{
	for (int i=0; i<data_new.size(); i++)
	{
	cout << data_new[i] << endl;
	}

	//Show all converted dates in console
}

void data_converter::saveDataToFile()
{
	ofstream new_file("dates_converted.txt");
	for (int i=0; i<data_new.size(); i++)
	{
		new_file << data_new[i] << endl;
	}
	new_file.close();

	//Save all converted date to File 

}


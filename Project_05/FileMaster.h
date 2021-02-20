//definition for the class used for extracting information from the file
#pragma once
#ifndef FILEMASTER_H
#define FILEMASTER_H

class FileMaster
{
private:
	//private member variables
	std::fstream m_inFile;
	std::string m_filename;
	int m_numLines;		//represents the number of lines in the file

	//private member functions
	void openFile();
	void getLines();
	void closeFile();

public:
	FileMaster(const std::string filename);
	~FileMaster();
	void readFile(LinkedList &list);
	void writeFile(static LinkedList * list);
};

#endif // !FILEMASTER_H


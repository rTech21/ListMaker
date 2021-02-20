//implementation of the FileMaster class used for extracting information from the file

#include "stdafx.h"		//aditional headers included in the stdafx.h header
#include "ListNode.h"
#include "LinkedList.h"
#include "FileMaster.h"


//constructor for the FileMaster class, recives a string that represents the filename, and a bool representing if the file exists already
FileMaster::FileMaster(const std::string filename)
{
	m_filename = filename + ".txt";
	
	//open the file upon the object's creation
	openFile();
	//count the number of lines in the file
	getLines();
		
}

//destructor for the FileMaster class
FileMaster::~FileMaster()
{
	//close the file with the object's destruction
	closeFile();
}

//open the file and check for errors
void FileMaster::openFile()
{
	m_inFile.open(m_filename, std::ios::in | std::ios::out);
	//if the file doesn't exist create a new one
	if (!m_inFile)
	{
		m_inFile.open(m_filename, std::ios::out);
		m_inFile.close();
		m_inFile.open(m_filename, std::ios::in | std::ios::out);
	}
}

//function that returns the number of lines in the file
void FileMaster::getLines()
{
	//reset the file pointer back to begining of file
	m_inFile.clear();
	m_inFile.seekg(0, std::ios::beg);

	//variables
	std::string line;
	int numLines(0);	//counter for the number of lines in the file

	while (std::getline(m_inFile, line))
		++numLines;

	m_numLines = numLines;
}

//function to read the data from the file and store it in a linked list
void FileMaster::readFile(LinkedList &list)
{
	//reset the file pointer back to begining of file
	m_inFile.clear();
	m_inFile.seekg(0, std::ios::beg);

	std::string input;		//data read from file 

													//read the data from the file into strings
	for (int i(0); i < m_numLines; i++)
	{		
		std::getline(m_inFile, input);
		list.addBack(input);
	}

}

//close the file
void FileMaster::closeFile()
{
	m_inFile.close();
}

//prints a linked list to the currently open file
void FileMaster::writeFile(LinkedList * list)
{
	//reopen the file for writing
	std::ofstream(m_inFile);
	m_inFile.open(m_filename);

	//write the linked list to the file
	ListNode *p = list->getHead();

	while (p != NULL)
	{
		m_inFile << p->getItem() << std::endl;
		p = p->getNext();
	}

}
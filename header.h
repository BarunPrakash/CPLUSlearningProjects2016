/*
 * header.h
 *
 *  Created on: 21-Mar-2016
 *      Author: epl-lab
 */

#ifndef HEADER_H_
#define HEADER_H_

/**********************************************************/
#include<string>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdint.h>
#include<string.h>
using namespace std;

/************************************************************/

#define maxNumbOfSalsePerson  5
#define noOfQuater 4
#define offMode 0
#define onMode 1
#define arrayIndex 1
#define quarterFirst 3
#define quarterSecond 6
#define quarterThird  9
#define quarterFourth 12
#define numofFucCall 2
#define getInit 0
#define readFromFile 1
#define DEBUG





/*************************************************************/



typedef struct salesPersonRec
{
	string ID;
	double salseByquater[noOfQuater];
	double totalSales;
}salesPersonRec;

/*********************************************************************/
#if onMode
class empDataAnalysis
	{
		private:
		uint8_t index;
		uint8_t iQuarter;

		public:
		class salesPersonRec
		{
		    public:
			string ID;
			double salseByquater[noOfQuater];
			double totalSales;
		}salesPersonArr[maxNumbOfSalsePerson];
		public:
		void initialize(ifstream &);
		void getData(ifstream &);
		void salesByQuarter(double totalSalesByQuarter[]);
		void salesByYearlyForEachEmploye(void);
		void printEmployeReport(ofstream & outputData,double totalSalesByQuarter[]);
		void maxSalesByPerson(ofstream & );
		void maxSalesByQuarter(ofstream & outputFile ,double maxSalesByQt[]);
		void sumOfAllStack(void);

};
#endif

//memset(salesPersonRec,'\0',sizeof(salesPersonRec));
/*******************************************************************/
class empDataAnalysisB
	{


		public:
		class salesPersonRec
		{
		    public:
			string ID;
			double salseByquater[noOfQuater];
			double totalSales;
		}salesPersonArr[maxNumbOfSalsePerson];


};

class empDataAnalysisClass :public empDataAnalysisB
{
       private:
		uint8_t index;
		uint8_t iQuarter;


		public:
		void initialize(ifstream &);
		void getData(ifstream &);
		void salesByQuarter(double totalSalesByQuarter[]);
		void salesByYearlyForEachEmploye(void);
		void printEmployeReport(ofstream & outputData,double totalSalesByQuarter[]);
		void maxSalesByPerson(ofstream & );
		void maxSalesByQuarter(ofstream & outputFile ,double maxSalesByQt[]);
		void sumOfAllStack(void);



};

/**********************************************************************/

void initialize(ifstream & indata,salesPersonRec salesPersonList[]);
void getData(ifstream &indata,salesPersonRec salesPersonList[]);

/********************************************************************/

#if offMode
typedef   void (*funcForInit)(ifstream &,salesPersonRec *);
funcForInit readAndIntilize[numofFucCall]={initialize ,getData };
#endif

/******************************************************************/


extern void salesByQuarter(salesPersonRec list[],double totalSalesByQuarter[]);
extern void salesByYearlyForEachEmploye(salesPersonRec list[]);
extern void printEmployeReport(ofstream & outputData,salesPersonRec list[],double totalSalesByQuarter[]);
extern void maxSalesByPerson(ofstream & outputFile ,salesPersonRec list[]);
extern void maxSalesByQuarter(ofstream & outputFile ,double maxSalesByQt[]);
extern void sumOfAllStack(void);






/**********************************************************/





#endif /* HEADER_H_ */

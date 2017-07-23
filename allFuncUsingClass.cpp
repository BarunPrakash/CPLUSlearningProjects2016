
#include"header.h"
//extern  int x;
void static test(void){cout<<"I am in the file !!"<<'\n';}
//extern void imIntoHere(void)
void empDataAnalysis ::initialize(ifstream & indata)
{


	//uint8_t index=0;
	//uint8_t iQarter=0;
	//memset(salesPersonList,'\0',sizeof(salesPersonList));
	for(index=0;index< maxNumbOfSalsePerson;index++)
	{
		indata>>salesPersonArr[index].ID;
		for(;iQuarter<noOfQuater;iQuarter++)
		{
			salesPersonArr[index].salseByquater[iQuarter]=0.00;
		}
		salesPersonArr[index].totalSales=0.00;


	}
	return;



}
/***********************************************************************/
void empDataAnalysis::getData(ifstream &indata)
{

	//uint8_t indexMov=0,iQuarter=0;
	uint16_t month;
	double amount;
	string SID;
	indata>>SID;
	while(indata)
	{
		indata>>month>>amount;
		for(index=0;index<maxNumbOfSalsePerson;index++)
		{
			if(salesPersonArr[index].ID==SID)
			{
				break;
			}
		}
		if(1<=month&&month>=3)
		{
			iQuarter=1-arrayIndex;
		}
		else if(4<=month&&month<=6)
		{
			iQuarter=2-arrayIndex;
		}
		if(7<=month&&month<=9)
		{
			iQuarter=3-arrayIndex;
		}
		else
		{
			iQuarter=4-arrayIndex;
		}
		if(index<maxNumbOfSalsePerson)
		{
			salesPersonArr[index].salseByquater[iQuarter] +=amount;
		}
		else
		{
			cout<<"INvalid choice!!!"<<endl;
		}
		indata>>SID;

	}


return ;
}
/****************************************************************/
//This function finds the company’s total sales for each quarter
void empDataAnalysis::salesByQuarter(double totalSalesByQuarter[])
{
	//uint8_t indexMov=0,iQuarterMov;
	for(iQuarter=0;iQuarter<noOfQuater;iQuarter++)
	{
		for(index=0;index<maxNumbOfSalsePerson;index)
		{
			totalSalesByQuarter[iQuarter]+=salesPersonArr[index].salseByquater[iQuarter];
		}
	}



	return;


}
/************************************************************************/

//This function finds each salesperson’s yearly sales amount.
void empDataAnalysis::salesByYearlyForEachEmploye(void)
{

	//uint8_t indexMov=0,iQuarterMov;
		for(index=0;index<maxNumbOfSalsePerson;index++)
		{
			for(iQuarter=0;iQuarter<noOfQuater;iQuarter++)
			{
				salesPersonArr[index].totalSales+=salesPersonArr[index].salseByquater[iQuarter];
			}
		}

		return;

}
/******************************************************************************/
void empDataAnalysis::printEmployeReport(ofstream & outputData,double totalSalesByQuarter[])
{
	uint8_t indexMov=0,iQuarterMov=0;
	outputData<<"..................Anual Sales Report............................................."<<endl;
	outputData<<"ID             QT1            QT2               QT3             QT4         Total"<<endl;
	outputData<<"_________________________________________________________________________________"<<endl;
	for(indexMov=0;indexMov<maxNumbOfSalsePerson;indexMov++)
	{
		outputData<<salesPersonArr[indexMov].ID<<"        ";
		for(iQuarterMov=0;iQuarterMov<noOfQuater;iQuarterMov++)
		{

			outputData<<setw(10)<<salesPersonArr[indexMov].salseByquater[iQuarterMov];


		}
		outputData<<setw(10)<<salesPersonArr[indexMov].totalSales<<endl;
	}
	outputData<<"Total..";
	for(iQuarterMov=0;iQuarterMov<noOfQuater;iQuarterMov++)
	{
		outputData<<totalSalesByQuarter[iQuarterMov];
	}
	outputData<<endl<<endl;
	return;


}
/*********************************************************************/
void  empDataAnalysis:: maxSalesByPerson(ofstream & outputFile )
{
	uint8_t maxIndex=0;
	for(index=1;index<maxNumbOfSalsePerson;index++)
	{
		if(salesPersonArr[maxIndex].totalSales<salesPersonArr[index].totalSales)
		{
			maxIndex=index;

		}


	}
	outputFile<<"max sales is given by employe-ID"<<salesPersonArr[maxIndex].ID<<"Amoumt in $:-"<<salesPersonArr[maxIndex].totalSales<<endl;






}
/**********************************************************************/
//This function prints the quarter in which the maximum sales were made

void  empDataAnalysis:: maxSalesByQuarter(ofstream & outputFile ,double maxSalesByQt[])
{
	uint8_t indexMov=0,maxIndex=0;
	for(indexMov=1;indexMov<noOfQuater;indexMov++)
	{
		if(maxSalesByQt[maxIndex] <maxSalesByQt[indexMov])
		{
			maxIndex=indexMov;

		}


	}
	outputFile<<"max sales is given by employe:-"<<maxSalesByQt[maxIndex]<<'\n';

return;
}

/*************************************************************************/
void empDataAnalysis::sumOfAllStack(void)

{
	test();
	ofstream outputFile;
	ifstream inputFile;
	empDataAnalysis runFunc;
	double totalSalesByQuarter[noOfQuater];
	salesPersonRec salesPersonList[maxNumbOfSalsePerson];
	string input,output;
	cout<<"Enter the Employe ID File"<<endl;
	cin>>input;
	cout<<endl;
	inputFile.open(input.c_str());
	if(!inputFile)
	{
		cout<<"File has not been created for Emp id"<<'\n';
		return;
	}
	runFunc.initialize(inputFile);
	//readAndIntilize[getInit](inputFile,salesPersonList);
	inputFile.close();
	inputFile.clear();
	cout<<"Enter the Employe Data file"<<endl;
	cin>>input;
	cout<<endl;
	inputFile.open(input.c_str());
	if(!inputFile)
	{
		cout<<"File has not been created for data Analysis"<<'\n';
		return;
	}
	cout<<"Enter the outputfile:--"<<endl;
	cin>>output;
	cout<<endl;
	outputFile.open(output.c_str());

	if(!outputFile)
	{
		cout<<"File has not been created  for output"<<'\n';
		return;
	}
	runFunc.getData(inputFile);
	//readAndIntilize[readFromFile](inputFile,salesPersonList);
	runFunc.salesByQuarter(totalSalesByQuarter);
	runFunc.salesByYearlyForEachEmploye();
	runFunc.printEmployeReport( outputFile,totalSalesByQuarter);
	runFunc.maxSalesByPerson(outputFile );
	runFunc.maxSalesByQuarter(outputFile , totalSalesByQuarter);


	inputFile.close();
	inputFile.clear();
	outputFile.close();
	outputFile.clear();



return;
}



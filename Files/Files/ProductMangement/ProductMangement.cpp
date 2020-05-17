// ProductMangement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream >
#include "Product.h"
#include <string>
using namespace std;

//Notes
// file is viewed as a stream of uninitalized array of bytes from 0 to Len - 1  
//best link https://courses.cs.vt.edu/~cs2604/fall00/binio.html

//defines

//varibles
struct dfProduct dcProductList[MAX_PRODUCTS];// global list
string pcProductList[MAX_PRODUCTS];
fstream fsDataFile;
const char* strFilename = "DATA.DAT";
void init(void);
void fnNewProduct(struct dfProduct *);
void fnGetList(struct dfProduct*);


enum
{
	IDLE = 0,

	NEWPRODUCT,
	COPYPRODUCT,
	EDITPRODUT,
	LISTPRODUCTS,
	DELETEPRODUCT,
	EXIT,

	COUNT_OPTION
};

int fnSaveToFile(struct dfProduct* pdcProductList)
{
	fsDataFile.open(strFilename, ios::out | ios::binary);
	fsDataFile.write((char*)pdcProductList, sizeof(struct dfProduct) * MAX_PRODUCTS);
	fsDataFile.close();
	return 0;
}

int fndeleteProduct(int iIdDelete)
{
	if ( iIdDelete < MAX_PRODUCTS &&
		!dcProductList[iIdDelete].iProductID ==0 )
	{
		dcProductList[iIdDelete].fltWeight = 0;
		dcProductList[iIdDelete].iWidth = 0;
		dcProductList[iIdDelete].iProductID = 0;
		dcProductList[iIdDelete].iLength = 0;
		memset(dcProductList[iIdDelete].strProductName, 0, sizeof(dcProductList[iIdDelete].strProductName));
	}
	fnSaveToFile(dcProductList);
	return 0;
}

int fnCopyProduct(int iFromProduct,int iToProduct)
{
	if ( iFromProduct < MAX_PRODUCTS &&
		 iToProduct < MAX_PRODUCTS &&
		 !dcProductList[iFromProduct].iProductID == 0  )
	{
		dcProductList[iToProduct].fltWeight = dcProductList[iFromProduct].fltWeight;
		dcProductList[iToProduct].iWidth = dcProductList[iFromProduct].iWidth;
		dcProductList[iToProduct].iLength = dcProductList[iFromProduct].iLength;
		memcpy( dcProductList[iToProduct].strProductName, 
			    dcProductList[iFromProduct].strProductName,
				sizeof(dcProductList[iFromProduct].strProductName )   );
	}
	fnSaveToFile(dcProductList);
	return 0;
}


void fnProductDetails(int nEmptyLocation, struct dfProduct* pdcProductlist)
{
	pdcProductlist[nEmptyLocation].iProductID = nEmptyLocation;
	cout << "Enter Product name";
	cin >> pdcProductlist[nEmptyLocation].strProductName;
	cout << "Enter Length";
	cin >> pdcProductlist[nEmptyLocation].iLength;
	cout << "Enter iWidth";
	cin >> pdcProductlist[nEmptyLocation].iWidth;
	cout << "Enter Weight";
	cin >> pdcProductlist[nEmptyLocation].fltWeight;

}

void fnEditProduct(int nProductEdit)
{
	fnProductDetails(nProductEdit, dcProductList);
	fnSaveToFile(dcProductList);

}
void fnListProducts(struct dfProduct* pdcProductlist)
{
	for (int nIndex = 0; nIndex < MAX_PRODUCTS;nIndex++)
	{
		cout <<nIndex+1<<")"<<pdcProductlist[nIndex].strProductName << endl;
	}

}

int main()
{
	int iAppRunning = 0;
	int iCurrentState = 0;
	int iUserinput=0;
	init();


	while (!iAppRunning )
	{
		switch (iCurrentState)
		{
		case IDLE:
			cout << "*********Welcome to Product Mangement System*********"<<endl;
			cout << "*********MENU*********" << endl;
			cout << "Press 1 to Create a new Product" << endl;
			cout << "Press 2 to Copy Product" << endl;
			cout << "Press 3 to Edit a Product" << endl;
			cout << "Press 4 to List Products" << endl;
			cout << "Press 5 to Delete Product" << endl;
			cout << "Press 6 to Exit" << endl;
			cout << ">>";
			cin >> iUserinput;
			if (iUserinput < COUNT_OPTION &&
				iUserinput > 0)
			{
				iCurrentState = iUserinput;
			}
			else
			{
				iCurrentState = IDLE;
			}

			break;
		case NEWPRODUCT:
			fnNewProduct(dcProductList);
			iCurrentState = IDLE;
			break;
		case COPYPRODUCT:
			cout << endl << "\nEnter Product from:";
			int itoProduct;
			cin >> itoProduct;
			cout << endl<<"\nEnter Product copy to:";
			int iFromProduct;
			cin >> iFromProduct;
			fnCopyProduct(iFromProduct, itoProduct);
			iCurrentState = IDLE;
			break;
		case EDITPRODUT:
			cout << endl << "\nEnter Product to edit:";
			int Editproduct;
			cin >> Editproduct;
			fnEditProduct(Editproduct);
			iCurrentState = IDLE;
			break;
		case LISTPRODUCTS:
			fnListProducts(dcProductList);
			iCurrentState = IDLE;
			break;
		case DELETEPRODUCT:
			cout << endl << "\nEnter Product to Delete:";
			int Deleteproduct;
			cin >> Deleteproduct;
			fnEditProduct(Deleteproduct);
			iCurrentState = IDLE;
			break;
		case EXIT:
			cout << "Bye" << endl;
			iAppRunning = 1;
			break;
		default:
			iCurrentState = IDLE;
			break;
		}
	}
}
void init()
{
	memset(dcProductList, 0, sizeof(struct dfProduct) * MAX_PRODUCTS);
	fsDataFile.open(strFilename, ios::in | ios::binary);
	if (!fsDataFile.is_open())
	{
		//if the file doesnot esit// create the file and intialize to 0;
		fsDataFile.open(strFilename, ios::out | ios::binary);
		fsDataFile.write((char*)dcProductList, sizeof(struct dfProduct) * MAX_PRODUCTS);
		fsDataFile.close();
		//to file()
	}
	else
	{
		fsDataFile.read((char*)dcProductList, sizeof(struct dfProduct) * MAX_PRODUCTS);
		fsDataFile.close();
		//read and popluate the from the memory
	}
}

void fnGetList(struct dfProduct * pdcProductlist)
{
	for (int nIndex = 0; nIndex < MAX_PRODUCTS; nIndex++)
	{
		pcProductList[nIndex] = pdcProductlist[nIndex].strProductName;

	}
}
void fnNewProduct(struct dfProduct* pdcProductlist)
{
	int nEmptyLocation =0;

	for (int nIndex = 0; nIndex < MAX_PRODUCTS; nIndex++)
	{
		if ( pdcProductlist[nIndex].iProductID == 0)
		{	
			if (nIndex == 0)
			{
				nEmptyLocation = 1;
			}
			else
			{
				nEmptyLocation = nIndex;
			}
			break;
		}
	}
	fnProductDetails(nEmptyLocation, pdcProductlist);
    fnSaveToFile(pdcProductlist);
}
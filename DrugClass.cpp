#define _CRT_SECURE_NO_WARNINGS
#include "DrugClass.h"
#include <iostream>
#include <cstring>
using namespace std;


DrugClass::DrugClass(const char* DrugName, int Prise, bool Recipe, FormRelease Release, const char* Contry)
{
	SetAll(DrugName, Prise, Recipe, Release, Contry);
}

DrugClass::DrugClass(const DrugClass& Drug)
{
	SetAll(Drug.DrugName, Drug.DrugPrise, Drug.Recipe, Drug.Release, Drug.Country);
}

DrugClass::~DrugClass()
{
	//cout << "Called destructor" << endl;
	delete[] DrugName;
	delete[] Country;
}

void DrugClass::SetDrugName(const char* name)
{
	delete[] DrugName;
	DrugName = new char[strlen(name) + 1];
	strcpy(DrugName, name);
}

void DrugClass::SetDrugPrise(int DrugPrise)
{
	this->DrugPrise = DrugPrise;
}

void DrugClass::SetRecipe(bool Recipe)
{
	this->Recipe = Recipe;
}

void DrugClass::SetCountry(const char* Country)
{
	delete[] this->Country;
	this->Country = new char[strlen(Country) + 1];
	strcpy(this->Country, Country);
}

void DrugClass::SetRelease(FormRelease Release)
{
	this->Release = Release;
}

void DrugClass::GetRelease()
{
	switch (Release)
	{
	case FormRelease::Hard:
	{
		cout << "Hard" << endl;
		break;
	}

	case FormRelease::Soft:
	{
		cout << "Soft" << endl;
		break;
	}
	case FormRelease::Liqiud:
	{
		cout << "Liqiud" << endl;
		break;
	}
	case FormRelease::Gaseous:
	{
		cout << "Gaseous" << endl;
		break;
	}
	case FormRelease::None:
	{
		cout << "None" << endl;
		break;
	}
	default:
		break;
	}
}

void DrugClass::SetAll(const char* DrugName, int Prise, bool Recipe, FormRelease Release, const char* Contry)
{
	SetDrugName(DrugName);
	SetDrugPrise(Prise);
	SetRecipe(Recipe);
	SetRelease(Release);
	SetCountry(Contry);
}

void DrugClass::GetAll()
{
	GetDrugName();
	GetDrugPrise();
	GetRecipe();
	GetRelease();
	GetCountry();
	cout << endl;
}

void DrugClass::TheMostExpensiveDrug(DrugClass* drugs, int count, char* country)
{
	int m = 0;
	char* name = new char[64];
	for (int i = 0; i < count; i++)
	{
		if (strcmp(drugs[i].GetC(), country) == 0)
		{
			if (drugs[i].GetDrugP() > m)
			{
				name = drugs[i].GetDrugN();
				m = drugs[i].GetDrugP();
			}
		}
	}
	cout << "The most expensive drug is " << name << " which cost " << m << endl;
}

void DrugClass::RecipeAndNoRecipe(DrugClass* drugs, int count, char* country)
{
	int r = 0;
	int nr = 0;
	for (int i = 0; i < count; i++)
	{
		if (strcmp(drugs[i].GetC(), country) == 0)
		{
			if (drugs[i].GetR())
				r++;
			else
				nr++;
		}
	}
	cout << "Recipe drugs / no recipe drugs = " << r/nr << endl;
}

void DrugClass::DrugsWithEqualsRelease(DrugClass* drugs, int count, FormRelease Release)
{
	int c;
	cout << "Massiv of drugs: ";
	for (int i = 0; i < count; i++)
	{
		if (drugs[i].GetRel() == Release)
		{
			cout << drugs[i].GetDrugN() << ", ";
		}
	}
}

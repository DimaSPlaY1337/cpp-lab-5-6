#include <iostream>
#include "DrugClass.h"
#include <cstring>

using namespace std;

FormRelease LookRelease(char* crel, FormRelease frel)
{
    if (strcmp(crel, "hard") == 0)
        frel = FormRelease::Hard;
    else if (strcmp(crel, "soft") == 0)
        frel = FormRelease::Soft;
    else if (strcmp(crel, "liqiud") == 0)
        frel = FormRelease::Liqiud;
    else if (strcmp(crel, "gaseous") == 0)
        frel = FormRelease::Gaseous;

    return frel;
}

int main()
{
    //lab 5
    DrugClass drug;
    drug.SetDrugName("Cocaino");
    drug.SetDrugPrise(200);
    drug.SetRecipe(true);
    drug.SetRelease(FormRelease::Hard);
    drug.SetCountry("Russia");

    drug.GetDrugName();
    drug.GetDrugPrise();
    drug.GetRecipe();
    drug.GetRelease();
    drug.GetCountry();
    cout << endl;

    DrugClass second("Marivana", 1000, false, FormRelease::Soft, "Brazil");
    DrugClass third(second);
    third.GetAll();
    third.SetAll("Spirt", 300, false, FormRelease::Liqiud, "USA");
    third.GetAll();

    //lab 6
    int count;
    cout << "Add count of drugs:" << endl;
    cin >> count;
    DrugClass *drugs = new DrugClass[count];
    for (int i = 0; i < count; i++)
    {
        cout << "Add name of drug:" << endl;
        char* name = new char[64];
        cin >> name;
        drugs[i].SetDrugName(name);
        delete[] name;
        
        cout << "Add prise of drug:" << endl;
        int prise;
        cin >> prise;
        drugs[i].SetDrugPrise(prise);
        
        cout << "Do it have recipe?(yes or no):" << endl;
        bool recipe;
        char rec[64];
        cin >> rec;
        if (strcmp(rec, "yes") == 0)
            recipe = true;
        else
            recipe = false;
        drugs[i].SetRecipe(recipe);
        
        cout << "Add country of drug:" << endl;
        char* Country = new char[64];
        cin >> Country;
        drugs[i].SetCountry(Country);
        delete[] Country;
        
        cout << "Add release of drug(hard, soft, liqiud, gaseous):" << endl;
        FormRelease release = FormRelease::None;
        char rel[64];
        cin >> rel;
        drugs[i].SetRelease(LookRelease(rel, release));
    }

    //Самый дорогой препарат в стране X
    cout << "Add country for get the most expensive drug:" << endl;
    char* country = new char[64];
    cin >> country;
    DrugClass::TheMostExpensiveDrug(drugs, count, country);
    delete[] country;
    
    //Соотношение рецептурных и безрецептурных препаратов в стране X ?
    cout << "Add country for: Recipe drugs / no recipe drugs:" << endl;
    country = new char[64];
    cin >> country;
    DrugClass::RecipeAndNoRecipe(drugs, count, country);  
    delete[] country;
    
    //Список всех препаратов с формой выпуска N ? (N =1, 2, 3, 4)
    cout << "Add form release for get all massiv drugs:" << endl;
    char *release = new char[64];
    FormRelease rel = FormRelease::None;
    cin >> release;
    DrugClass::DrugsWithEqualsRelease(drugs, count, LookRelease(release, rel));
    delete[] release;
}

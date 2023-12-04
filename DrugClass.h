#include <iostream>
using namespace std;

enum class FormRelease : int
{
	Hard,
	Soft,
	Liqiud,
	Gaseous,
	None
};

class DrugClass
{

public:
	DrugClass() {};

	DrugClass(const char* DrugName, int Prise, bool Recipe, FormRelease Release, const char* Contry);

	DrugClass(const DrugClass& Drug);

	~DrugClass();

	void SetDrugName(const char* name);
	void GetDrugName() { cout << DrugName << endl; };
	char* GetDrugN() { return DrugName; }
	
	void SetDrugPrise(int DrugPrise);
	void GetDrugPrise() { cout << DrugPrise << endl; };
	int GetDrugP() { return DrugPrise; }
	
	void SetRecipe(bool Recipe);
	void GetRecipe() { cout << Recipe << endl; };
	bool GetR() { return Recipe;  };
	
	void SetCountry(const char* Country);
	void GetCountry() { cout << Country << endl; };
	char* GetC() { return Country;  }
	
	void SetRelease(FormRelease Release);
	void GetRelease();
	FormRelease GetRel() { return Release; };

	void SetAll(const char* DrugName, int Prise, bool Recipe, FormRelease Release, const char* Contry);
	void GetAll();

	static void TheMostExpensiveDrug(DrugClass *drugs, int count, char* country);
	static void RecipeAndNoRecipe(DrugClass *drugs, int count, char* country);
	static void DrugsWithEqualsRelease(DrugClass *drugs, int count, FormRelease Release);
private:
	char *DrugName = nullptr;
	char *Country = nullptr;
	int DrugPrise;
	bool Recipe = false;
	FormRelease Release = FormRelease::None;
};


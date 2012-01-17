#include "V2TechSchools.h"
#include "Log.h"



vector<techSchool> initTechSchools(Object* obj) {
	vector<techSchool> techSchools;

	vector<Object*> schoolObj = obj->getValue("schools");
	if (schoolObj.size() < 1)
	{
		log("Error: Could not load tech schools.\n");
		printf("Error: Could not load tech schools.\n");
	}
	
	vector<Object*> schoolsObj = schoolObj[0]->getLeaves();
	for (unsigned int i = 0; i < schoolsObj.size(); i++)
	{
		techSchool newSchool;
		newSchool.name						= schoolsObj[i]->getKey();
		newSchool.armyInvestment		= atof( schoolsObj[i]->getValue("army_tech_research_bonus")[0]->getLeaf().c_str() );
		newSchool.commerceInvestment	= atof( schoolsObj[i]->getValue("commerce_tech_research_bonus")[0]->getLeaf().c_str() );
		newSchool.cultureInvestment	= atof( schoolsObj[i]->getValue("culture_tech_research_bonus")[0]->getLeaf().c_str() );
		newSchool.industryInvestment	= atof( schoolsObj[i]->getValue("industry_tech_research_bonus")[0]->getLeaf().c_str() );
		newSchool.navyInvestment		= atof( schoolsObj[i]->getValue("navy_tech_research_bonus")[0]->getLeaf().c_str() );

		techSchools.push_back(newSchool);
	}

	return techSchools;
}
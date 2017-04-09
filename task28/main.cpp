#define CATCH_CONFIG_RUNNER 
#include "catch.hpp"
#include <iostream>
#include <sstream>
#include "Bacteria.h"
using namespace std;

TEST_CASE("checking bacterias names")
{
	ostringstream s1;
	Bacteria bacteria1{ "Marten", "Fourcade" };
	s1 << bacteria1 << endl;
	REQUIRE(s1.str() == "first name: 0 Marten last name: 1 Fourcade\n");

	ostringstream s2;
	Bacteria bacteria2{ "Simon", "Fourcade" };
	s2 << bacteria2 << endl;
	REQUIRE(s2.str() == "first name: 2 Simon last name: 1 Fourcade\n");

	ostringstream s3;
	Bacteria bacteria3{ "Simon", "Shemp" };
	s3 << bacteria3 << endl;
	REQUIRE(s3.str() == "first name: 2 Simon last name: 3 Shemp\n");

}

TEST_CASE("checking bacterias factory")
{
	BacteriaFactory factory;
	ostringstream s1;
	Bacteria bacteria1{ "Marten", "Fourcade" };
	Bacteria bacteria2 = factory.create_new(bacteria1);
	s1 << bacteria2 << endl;
	REQUIRE(s1.str() != "first name: 0 Marten last name: 1 Fourcade\n");
	REQUIRE(bacteria1.get_first_name() != bacteria2.get_first_name());
	REQUIRE(bacteria1.get_last_name() != bacteria2.get_last_name());
}

int main(int argc, char* argv[])
{
	srand(time(NULL));
	/*BacteriaFactory factory;
	Bacteria john_doe{ "John", "Doe" };

	cout << "John " << john_doe << endl;
	
	Bacteria bacteria = factory.create_new(john_doe);
	cout << bacteria << endl;*/

	int result = Catch::Session().run(argc, argv);
	getchar();
	return result;
}

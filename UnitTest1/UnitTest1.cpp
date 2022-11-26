#include "pch.h"
#include "CppUnitTest.h"
#include "W:\Университет\ИПЗ\laba3\laba3\laba3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1s)
	{
	public:
		// Check program number 1. The test will be successful if the interval is -10 to 10, n=4 and step 10 will be the expected values equal to y-values.
		TEST_METHOD(solvingEquationSystems_getMinus10and10and4and10returned)
		{
			double x1 = -10;
			double x2 = 10;
			double n = 4;
			double h = 10;

			double y;

			double expected[] = { 1, 5, 145 };

			for (int x = x1, i = 0; x <= x2; x += h, i++)
			{
				funcY(x, n, y);
				double actual = y;

				Assert::AreEqual(expected[i], actual);
			}
		}

	public:
		// Check program number 2. The test will be successful if the interval is 17 to 100, n=5 and step 15 will be the expected values equal to y-values.
		TEST_METHOD(solvingEquationSystems_get17and100and5and15returned)
		{
			double x1 = 17;
			double x2 = 100;
			double n = 5;
			double h = 15;

			double y;

			double expected[] = { 677, 2702, 6077, 10802, 16877, 24302 };

			for (int x = x1, i = 0; x <= x2; x += h, i++) {
				funcY(x, n, y);
				double actual = y;

				Assert::AreEqual(expected[i], actual);
			}
		}

	public:
		//The test will check the input values. The test is successful if all entered values pass the check.
		TEST_METHOD(сheckChecks_get120and1221and4and10_exceptionNotThrown)
		{
			double x1 = 120;
			double x2 = 1221;
			double n = 4;
			double h = 10;

			try
			{
				сheck(x1, x2, n, h);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}

	public:
		//Checks for error output and program ending when wrong values are entered. The test will succeed if the check fails. 
		TEST_METHOD(сheckChecks_get10and11and4an10_exceptionThrown)
		{
			double x1 = 10;
			double x2 = 11;
			double n = 4;
			double h = 10;

			try
			{
				сheck(x1, x2, n, h);
				Assert::Fail();
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}

	public:
		//Checks for error output and program ending when wrong values are entered. The test will succeed if the check fails. 
		TEST_METHOD(сheckChecks_get10and15and4an10_exceptionThrown)
		{
			double x1 = 10;
			double x2 = 15;
			double n = 4;
			double h = 10;

			try
			{
				сheck(x1, x2, n, h);
				Assert::Fail();
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
	public:
		//An example of failure to pass a test.
		TEST_METHOD(solvingEquationSystems2_get17and100and5and15returned)
		{
			double x1 = 17;
			double x2 = 100;
			double n = 5;
			double h = 15;

			double y;

			double expected[] = { 1000000, 1000000, 1000000, 1000000, 1000000, 1000000 }; //The values are too big and the same everywhere. This is impossible.

			for (int x = x1, i = 0; x <= x2; x += h, i++) {
				funcY(x, n, y);
				double actual = y;

				Assert::AreEqual(expected[i], actual);
			}
		}
	};
}
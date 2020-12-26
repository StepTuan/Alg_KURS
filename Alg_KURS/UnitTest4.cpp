#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include "../Alg_3_4/Header.h" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest4
{
	TEST_CLASS(UnitTest4)
	{
	public:

		TEST_METHOD(add_exp)
		{
			expres testExpression;
			string input, test;
			input.push_back('2');
			input.push_back(' ');
			input.push_back('+');
			input.push_back(' ');
			input.push_back('2');

			test.push_back('+');
			test.push_back(' ');
			test.push_back('2');
			test.push_back(' ');
			test.push_back('2');
			testExpression.set_Exp(input);

			testExpression.Get_prefix();

			Assert::AreEqual(test, testExpression.return_Exp());
		}

		TEST_METHOD(counting_test)
		{
			expres testExpression;
			string input, test;
			input.push_back('2');
			input.push_back(' ');
			input.push_back('+');
			input.push_back(' ');
			input.push_back('2');

			test.push_back('+');
			test.push_back(' ');
			test.push_back('2');
			test.push_back(' ');
			test.push_back('2');

			testExpression.set_Exp(input);
			testExpression.Get_prefix();
			double t = 4;

			Assert::AreEqual(t, testExpression.Calculate());
		}
	};
}

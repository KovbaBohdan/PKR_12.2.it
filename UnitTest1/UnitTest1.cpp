#include "pch.h"
#include "CppUnitTest.h"
#include "../PKR_lab_12.2.it/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* first = NULL, * last = NULL;
			for (int i = 1; i < 6; i++) {
				Input(first, last, i);
			}

			DeleteBefore(first, 3);

			Assert::AreEqual(3, first->info);
			Assert::AreEqual(4, first->link->info);
			Assert::AreEqual(5, last->info);
		}
	};
}

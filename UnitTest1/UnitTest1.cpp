#include "pch.h"
#include "CppUnitTest.h"
#include "../6.6/Array.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Array<int, 3, 5> unitTest;

			for (int i = 3; i < 5; i++)
				unitTest[i] = 0;

			Assert::AreEqual(2, (int)unitTest.size());
		}
	};
}

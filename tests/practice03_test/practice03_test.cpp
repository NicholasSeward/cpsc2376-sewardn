#include "pch.h"
#include "CppUnitTest.h"
#include "mathyStuff.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace practice03test
{
	TEST_CLASS(practice03test)
	{
	public:
		
		TEST_METHOD(TestAdd1)
		{
			Assert::AreEqual(5, add(2,3));
		}
		TEST_METHOD(TestAdd2)
		{
			Assert::AreEqual(-5, add(-2, -3));
		}
		TEST_METHOD(TestAdd3)
		{
			Assert::AreEqual(-2, add(-2,0));
		}
		TEST_METHOD(TestDouble1)
		{
			Assert::AreEqual(4, doubleValue(2));
		}
		TEST_METHOD(TestRect1)
		{
			Rectangle r{ 3,4 };
			Assert::AreEqual(12, r.area());
			r.width++;

			Assert::AreEqual(4, r.width);
			Assert::AreEqual(16, r.area());

		}
	};
}

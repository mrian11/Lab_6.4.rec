#include "pch.h"
#include "CppUnitTest.h"
#include"../lab_6.4.rec/LAB.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab64rec
{
	TEST_CLASS(UnitTestLab64rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double a[] = { 1.0, -2.0, 3.0, 4.0, -5.0, 6.0 };
			int n = 6;

			// Викликаємо функцію для знаходження максимального елемента
			double result = MaxRecursive(a, n, 0);

			// Перевіряємо, чи функція правильно знайшла максимальний елемент
			Assert::AreEqual(result, 6.0, 0.0001);
		}
			
		
	};
}

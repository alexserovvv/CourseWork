#include "pch.h"
#include "CppUnitTest.h"
#include "..\\CourseWork\pushRelabel.h"
#include "..\\CourseWork\Container.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{
	TEST_CLASS(Test)
	{
	public:

		TEST_METHOD(FileNotOpen)
		{
			Graph myGr;
			try
			{
				myGr.addVertex("test.txt");
			}
			catch (invalid_argument error)
			{
				Assert::AreEqual("Error - file not open", error.what());
			}

		}

		TEST_METHOD(CheckMaxFlow)
		{
			Graph myGr;
			try
			{
				myGr.getMaxFlow();
			}
			catch (out_of_range error)
			{
				Assert::AreEqual("Error - Vertex no create", error.what());
			}
		}

		TEST_METHOD(WorkTest)
		{
			Graph myGr;
			myGr.addVertex("D:\\АИСД\\CourseWork\\CourseWork\\testTrue.txt");
			myGr.addEdge("D:\\АИСД\\CourseWork\\CourseWork\\testTrue.txt");
			Assert::AreEqual(5, myGr.getMaxFlow());
		}

		TEST_METHOD(NoEdgeTest)
		{
			Graph myGr;
			myGr.addVertex("D:\\АИСД\\CourseWork\\CourseWork\\NoEdge.txt");
			myGr.addEdge("D:\\АИСД\\CourseWork\\CourseWork\\NoEdge.txt");
			Assert::AreEqual(0, myGr.getMaxFlow());
		}
		TEST_METHOD(NoflowTest)
		{
			Graph myGr;
			try
			{
				myGr.addVertex("D:\\АИСД\\CourseWork\\CourseWork\\noFlow.txt");
				myGr.addEdge("D:\\АИСД\\CourseWork\\CourseWork\\noFlow.txt");
			}
			catch (invalid_argument error)
			{
				Assert::AreEqual("Your file not correct - no Flow!", error.what());
			}
		}


	};
}
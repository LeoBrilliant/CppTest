/*
 * GTestTest.cpp
 *
 *  Created on: Oct 13, 2017
 *      Author: bliu
 */

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

int Factorial(int n)
{
	int result = 1;
	for(int i = 1; i <= n; ++i)
	{
		result *= i;
	}
	return result;
}

TEST(FactorialTest, Negetive)
{
	EXPECT_EQ(1, Factorial(-5));
	EXPECT_EQ(1, Factorial(-1));
	EXPECT_GT(Factorial(-10), 0);
}

TEST(FactorialTest, Zero)
{
	EXPECT_EQ(1, Factorial(0));
}

TEST(FactorialTest, Positive)
{
	EXPECT_EQ(1, Factorial(1));
	EXPECT_EQ(2, Factorial(2));
	EXPECT_EQ(6, Factorial(3));
	EXPECT_EQ(40320, Factorial(8));
}

//class FooTest;

class Foo
{
public:
	Foo() : m_i(0) {}
	int Bar(const string& input, const string& output)
	{
		cout << "input path is "  << input << endl;
		cout << "output path is " << output << endl;
		return 0;
	}

	void Xyz()
	{
		cout << "this is " << __func__ << endl;
	}

private:
	FRIEND_TEST(FooTest, ShowPrivate);
	int m_i;
};

class FooTest : public ::testing::Test
{
protected:
	FooTest() {}
	virtual ~FooTest() {}
	virtual void SetUp()
	{
		cout << __func__ << endl;
	}

	virtual void TearDown() {
		cout << __func__ << endl;
	}

	static void SetUpTestCase()
	{
		cout << __func__ << endl;
	}

	static void TearDownTestCase()
	{
		cout << __func__ << endl;
	}
};

class FooEnvironment : public ::testing::Environment
{
public:
	virtual ~FooEnvironment() {}
	virtual void SetUp()
	{
		cout << typeid(this).name() << __func__ << endl;
	}

	virtual void TearDown()
	{
		cout << typeid(this).name() << __func__ << endl;
	}
};

TEST_F(FooTest, MethodBarDoesAbc)
{
	const string input_filepath = "this/package/testdata/myinputfile.dat";
	const string output_filepath = "this/package/testdata/myoutputfile.dat";
	Foo f;
	EXPECT_EQ(0, f.Bar(input_filepath, output_filepath));
}

TEST_F(FooTest, DoesXyz)
{
	Foo f;
	f.Xyz();
	SUCCEED();
}

TEST_F(FooTest, ShowPrivate)
{
	Foo f;
	EXPECT_EQ(0, f.m_i);
	SCOPED_TRACE("A");
//	FAIL();
}

class MinimalistPrinter : public ::testing::EmptyTestEventListener
{
	virtual void OnTestStart(const ::testing::TestInfo& test_info)
	{
		printf("*** Test %s.%s starting.\n", test_info.test_case_name(), test_info.name());
	}

	// Called after a failed assertion or a SUCCEED() invocation.
	virtual void OnTestPartResult(const ::testing::TestPartResult& test_part_result)
	{
		printf("%s in %s:%d\n%s\n", test_part_result.failed() ? "*** Failure" : "Success",
				test_part_result.file_name(),
				test_part_result.line_number(),
				test_part_result.summary() );
	}

	virtual void OnTestEnd(const ::testing::TestInfo& test_info)
	{
		printf("*** Test %s.%s ending.\n", test_info.test_case_name(), test_info.name());
	}
};

void GTestTest()
{
	int argc = 1;
	string AppName("C++Test");
	char * argv[] = { (char *)AppName.data() };
	::testing::Environment * const foo_env = ::testing::AddGlobalTestEnvironment( new FooEnvironment() );
	::testing::InitGoogleTest(& argc, argv);

	::testing::TestEventListeners& listeners = ::testing::UnitTest::GetInstance()->listeners();
	delete listeners.Release(listeners.default_result_printer());
	listeners.Append( new MinimalistPrinter );
/*	int ret = RUN_ALL_TESTS();
	cout << foo_env << endl;
	cout << "test result: " << ret << endl;*/
}

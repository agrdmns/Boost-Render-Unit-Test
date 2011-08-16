// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// - boost unit test
// - 
// - sample_test.cpp
// -	A set of sample boost unit tests
// -
// - 2011-08-15  Put together by Sean Lynch using the tests from 
// -     https://github.com/jsankey/boost.test-examples
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE SampleTest
#include <boost/test/unit_test.hpp>
#include <exception>
#include <unistd.h>

int add(int i, int j)
{
    return i + j;
}

BOOST_AUTO_TEST_SUITE(VariantsSuite)

BOOST_AUTO_TEST_CASE(simplePass)
{
}

BOOST_AUTO_TEST_CASE(checkFailure)
{
    BOOST_CHECK(add(2, 2) == 5);
}

BOOST_AUTO_TEST_CASE(multipleCheckFailures)
{
    BOOST_CHECK(add(2, 2) == 3);
    BOOST_CHECK(add(2, 2) == 4);
    BOOST_CHECK(add(2, 2) == 5);
}

BOOST_AUTO_TEST_CASE(requireFailure)
{
    BOOST_REQUIRE(add(2, 2) == 5);
}

BOOST_AUTO_TEST_CASE(explicitError)
{
    BOOST_ERROR("Error message");
}

BOOST_AUTO_TEST_CASE(explicitFailure)
{
    BOOST_FAIL("Failure message");
}

BOOST_AUTO_TEST_CASE(errorThenFailure)
{
    BOOST_FAIL("Error message");
    BOOST_FAIL("Failure message");
}

BOOST_AUTO_TEST_CASE(uncaughtException)
{
    throw "Catch me if you can!";
}

BOOST_AUTO_TEST_CASE(stdException)
{
    throw new std::exception();
}

BOOST_AUTO_TEST_CASE(checkMessageFailure)
{
    BOOST_CHECK_MESSAGE(add(2, 2) == 5, "add(..) result: " << add(2, 2));
}

BOOST_AUTO_TEST_CASE(checkEqualFailure)
{
    BOOST_CHECK_EQUAL(add( 2,2 ), 5);
}

BOOST_AUTO_TEST_CASE(threeSeconds)
{
    sleep(3);
}

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE(PassingSuite)

BOOST_AUTO_TEST_CASE(pass1)
{
}

BOOST_AUTO_TEST_CASE(pass2)
{
}

BOOST_AUTO_TEST_CASE(pass3)
{
}

BOOST_AUTO_TEST_SUITE_END()

struct Massive
{
    int m;

    Massive() : m(2)
    {
        BOOST_TEST_MESSAGE("setup mass");
    }

    ~Massive()
    {
        BOOST_TEST_MESSAGE("teardown mass");
    }
};

BOOST_FIXTURE_TEST_SUITE(Physics, Massive)

BOOST_AUTO_TEST_CASE(specialTheory)
{
    int e = 32;
    int c = 4;

    BOOST_CHECK(e == m * c * c);
}

BOOST_AUTO_TEST_CASE(newton2)
{
    int f = 10;
    int a = 5;

    BOOST_CHECK(f == m * a);
}

BOOST_AUTO_TEST_SUITE_END()

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// - sample_test.cpp                                                          
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

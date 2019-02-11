#include <boost/test/unit_test.hpp>
#include <Address.h>

BOOST_AUTO_TEST_SUITE(AddressSuiteCorrect)


    BOOST_AUTO_TEST_CASE( AddressGetInfo ) {
        Address address;
        BOOST_REQUIRE_EQUAL(address.getStreet(), "ulica");
        BOOST_REQUIRE_EQUAL(address.getNumber(), "numer");
    }


    BOOST_AUTO_TEST_CASE( AddressSetInfo ) {

        Address address;
        address.setStreet("ulica test2");
        address.setNumber("37");
        BOOST_REQUIRE_EQUAL(address.getStreet(), "ulica test2");
        BOOST_REQUIRE_EQUAL(address.getNumber(), "37");
    }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(AddressSuiteFailure)

    BOOST_AUTO_TEST_CASE( AddressGetInfoCheck ) {
        Address address;
        BOOST_CHECK_EQUAL(address.getStreet(), "Blad"); //error - continue testing
        BOOST_CHECK_EQUAL(address.getStreet(), "ulica");
        BOOST_CHECK_EQUAL(address.getNumber(), "Blad"); //error - continue testing
        BOOST_CHECK_EQUAL(address.getNumber(), "numer");
    }

    BOOST_AUTO_TEST_CASE( AddressSetInfoCheck ) {
        Address address;
        address.setStreet("ulica test");
        address.setNumber("37");
        BOOST_CHECK_EQUAL(address.getStreet(), "Blad"); //error - continue testing
        BOOST_CHECK_EQUAL(address.getStreet(), "ulica test");
        BOOST_CHECK_EQUAL(address.getNumber(), "Blad"); //error - continue testing
        BOOST_CHECK_EQUAL(address.getNumber(), "37");
    }

BOOST_AUTO_TEST_SUITE_END()



#include <boost/test/unit_test.hpp>
#include "Vehicle.h"
#include "MotorVehicle.h"
#include "Bicycle.h"
#include "Car.h"
#include "Mope.h"

BOOST_AUTO_TEST_SUITE(VehicleSuiteCorrect)

    BOOST_AUTO_TEST_CASE( VehicleTest1 ) {
        Vehicle vehicle{"EBE46F9", "FORD", 1000};
        BOOST_REQUIRE_EQUAL(vehicle.getHire(), false);
        BOOST_REQUIRE_EQUAL(vehicle.getPrice(), 1000.0);
    }

    BOOST_AUTO_TEST_CASE( VehicleTest2 ) {
        Vehicle vehicle{"EBE46F9", "FORD", 1000};
        vehicle.setHire(true);
        BOOST_REQUIRE_EQUAL(vehicle.getHire(), true);
        BOOST_REQUIRE_EQUAL(vehicle.getPrice(), 1000.0);
    }

    BOOST_AUTO_TEST_CASE( CarTest1 ) {
        Car car{"EBE73BN", "MERCEDES", 1000, 1000, A};
        BOOST_REQUIRE_EQUAL(car.getPrice(), 1100.0);
        BOOST_REQUIRE_EQUAL(car.getMultipler(), 1.1);
        BOOST_REQUIRE_EQUAL(car.segmentMultipler(), 1.1); //error
    }

    BOOST_AUTO_TEST_CASE( CarTest2 ) {
        Car car{"EBE54TF","Samochod", 1000, 1001, B};
        BOOST_REQUIRE_EQUAL(car.getPrice(), 1100.5500000000002); //error
        BOOST_REQUIRE_EQUAL(car.getMultipler(), 1.0005);
        BOOST_REQUIRE_EQUAL(car.segmentMultipler(), 1.1);
    }

    BOOST_AUTO_TEST_CASE( CarTest3 ) {
        Car car{"EBE5GHT","Samochod", 1000, 2000, C};
        BOOST_REQUIRE_EQUAL(car.getPrice(), 1800.0);
        BOOST_REQUIRE_EQUAL(car.getMultipler(), 1.5);
        BOOST_REQUIRE_EQUAL(car.segmentMultipler(), 1.2);
    }

    BOOST_AUTO_TEST_CASE( CarTest4 ) {
        Car car{"EBEG65G","Samochod", 1000, 2001, D};
        BOOST_REQUIRE_EQUAL(car.getPrice(), 1950.0);
        BOOST_REQUIRE_EQUAL(car.getMultipler(), 1.5);
        BOOST_REQUIRE_EQUAL(car.segmentMultipler(), 1.3);
    }

    BOOST_AUTO_TEST_CASE( CarTest5 ) {
        Car car{"EL5283Y","Samochod", 1000, 1700, E};
        BOOST_REQUIRE_EQUAL(car.getPrice(), 1950.0);
        BOOST_REQUIRE_EQUAL(car.getMultipler(), 1.35);
        BOOST_REQUIRE_EQUAL(car.segmentMultipler(), 1.5);
    }

    BOOST_AUTO_TEST_CASE( BicycleTest ) {
        Bicycle bicycle{"gy65gg","Rower", 300};
        BOOST_REQUIRE_EQUAL(bicycle.getPrice(), 300.0);
    }

    BOOST_AUTO_TEST_CASE( MopeTest ) {
        Mope mope{"Z54RT","Skuter", 700, 50};
        BOOST_REQUIRE_EQUAL(mope.getPrice(), 700.0);
        BOOST_REQUIRE_EQUAL(mope.getMultipler(), 1.0);
    }



BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(VehicleSuiteFailure)

    BOOST_AUTO_TEST_CASE( VehicleTestInfoCheck ) {
        Vehicle vehicle{"1234567", "OPEL", 1000};
        BOOST_CHECK_EQUAL(vehicle.getHire(), true); // error
        BOOST_CHECK_EQUAL(vehicle.getHire(), false);
        BOOST_CHECK_EQUAL(vehicle.getPrice(), -9999); //error
        BOOST_CHECK_EQUAL(vehicle.getPrice(), 1000.0);
        BOOST_CHECK_EQUAL(vehicle.vehicleinfo(), "Blad"); //error
        BOOST_CHECK_EQUAL(vehicle.vehicleinfo(), "Numer rejestracyjny: 1234567\nMarka pojazdu: OPEL\nCena: 1000");
    }

    BOOST_AUTO_TEST_CASE( MopeTestInfoCheck ) {
        Mope mope{"TY5674","Skuter", 700, 50};
        BOOST_CHECK_EQUAL(mope.getPrice(), -9999.0); //error
        BOOST_CHECK_EQUAL(mope.getPrice(), 700.0);
        BOOST_CHECK_EQUAL(mope.getMultipler(), -9999.0); //error
        BOOST_CHECK_EQUAL(mope.getMultipler(), 1.0);
    }

BOOST_AUTO_TEST_SUITE_END()



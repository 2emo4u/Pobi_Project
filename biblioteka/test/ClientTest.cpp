#include <boost/test/unit_test.hpp>
#include "Client.h"

BOOST_AUTO_TEST_SUITE(ClientSuiteCorrect)

    BOOST_AUTO_TEST_CASE(ClientDataCase) {
        Client klient("Jan", "Kowalski", "1234567", "ulica", "1", Premium);
        BOOST_REQUIRE_EQUAL(klient.getFirstname(), "Jan");
        BOOST_REQUIRE_EQUAL(klient.getLastname(), "Kowalski");
        BOOST_REQUIRE_EQUAL(klient.getPersonalID(), "1234567");
        BOOST_REQUIRE_EQUAL(klient.getAmountVehicles(), 10.0);
        BOOST_REQUIRE_EQUAL(klient.getTurnover(), 0.0);
        BOOST_REQUIRE_EQUAL(klient.clientinfo(), "Jan Kowalski 1234567 ulica 1\nTyp klienta: Premium");
    }

    BOOST_AUTO_TEST_CASE(ClientBasicRabate) {
        Client klient("Jan", "Kowalski", "1234567", "ulica", "1", Basic);
        BOOST_REQUIRE_EQUAL(klient.getAmountVehicles(), 1.0);
        BOOST_REQUIRE_EQUAL(klient.getTurnover(), 0.0);
        klient.setTurnover(3500.5);
        BOOST_REQUIRE_EQUAL(klient.getTurnover(), 3500.50);
        BOOST_REQUIRE_EQUAL(klient.getRabate(), 1.0);
        BOOST_REQUIRE_EQUAL(klient.clientinfo(), "Jan Kowalski 1234567 ulica 1\nTyp klienta: Basic");
    }

    BOOST_AUTO_TEST_CASE(ClientStandardRabate) {
        Client klient("Jan", "Kowalski", "1234567", "ulica", "1", Standard);
        BOOST_REQUIRE_EQUAL(klient.getAmountVehicles(), 4.0);
        BOOST_REQUIRE_EQUAL(klient.getTurnover(), 0.0);
        klient.setTurnover(3000.0);
        BOOST_REQUIRE_EQUAL(klient.getTurnover(), 3000.0);
        BOOST_REQUIRE_EQUAL(klient.getRabate(), 0.95);
        BOOST_REQUIRE_EQUAL(klient.clientinfo(), "Jan Kowalski 1234567 ulica 1\nTyp klienta: Standard");
    }

    BOOST_AUTO_TEST_CASE(ClientPremiumRabate) {
        Client klient("Jan", "Kowalski", "1234567", "ulica", "1", Premium);
        BOOST_REQUIRE_EQUAL(klient.getAmountVehicles(), 10.0);
        BOOST_REQUIRE_EQUAL(klient.getTurnover(), 0.0);
        klient.setTurnover(4000.0);
        BOOST_REQUIRE_EQUAL(klient.getTurnover(), 4000.0);
        BOOST_REQUIRE_EQUAL(klient.getRabate(), 1.4000);
        BOOST_REQUIRE_EQUAL(klient.clientinfo(), "Jan Kowalski 1234567 ulica 1\nTyp klienta: Premium");
    }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(ClientFailure)

    BOOST_AUTO_TEST_CASE(ClientInfoCheck) {
        Client klient("Jan", "Kowalski", "1234567", "ulica", "1", Standard);
        BOOST_CHECK_EQUAL(klient.getFirstname(), "Blad"); //error - continue testing
        BOOST_CHECK_EQUAL(klient.getFirstname(), "Jan");
        BOOST_CHECK_EQUAL(klient.getLastname(), "Blad"); //error - continue testing
        BOOST_CHECK_EQUAL(klient.getLastname(), "Kowalski");
        BOOST_CHECK_EQUAL(klient.getPersonalID(), "Blad"); //error - continue testing
        BOOST_CHECK_EQUAL(klient.getPersonalID(), "1234567");
        BOOST_CHECK_EQUAL(klient.getAmountVehicles(), -9999); //error - continue testing
        BOOST_CHECK_EQUAL(klient.getAmountVehicles(), 4.0);
        BOOST_CHECK_EQUAL(klient.getTurnover(), -9999); //error - continue testing
        BOOST_CHECK_EQUAL(klient.getTurnover(), 0.0);
        BOOST_CHECK_EQUAL(klient.clientinfo(), "Blad"); //error - continue testing
        BOOST_CHECK_EQUAL(klient.clientinfo(), "Jan Kowalski 1234567 ulica 1\nTyp klienta: Standard");
    }   // oczekiwane 6 bledow

    BOOST_AUTO_TEST_CASE(SetClientInfoCheck) {
        Client klient;
        klient.setFirstname("Jan");
        BOOST_CHECK_EQUAL(klient.getFirstname(), "Blad"); //error - continue testing
        BOOST_CHECK_EQUAL(klient.getFirstname(), "Jan");
        klient.setLastname("Kowalski");
        BOOST_CHECK_EQUAL(klient.getLastname(), "Blad"); //error - continue testing
        BOOST_CHECK_EQUAL(klient.getLastname(), "Kowalski");
        BOOST_CHECK_EQUAL(klient.getPersonalID(), "Blad"); //error - continue testing
        BOOST_CHECK_EQUAL(klient.getPersonalID(), "PESEL");
        klient.setRegisteredAddress("ulica", "1");
        BOOST_CHECK_EQUAL(klient.getAmountVehicles(), -9999); //error - continue testing
        BOOST_CHECK_EQUAL(klient.getAmountVehicles(), 1.0);
        BOOST_CHECK_EQUAL(klient.clientinfo(), "Blad"); //error - continue testing
        BOOST_CHECK_EQUAL(klient.clientinfo(), "Jan Kowalski PESEL ulica 1\nTyp klienta: Basic");
        klient.changeClientType(Premium);
        BOOST_CHECK_EQUAL(klient.getAmountVehicles(), -9999); //error - continue testing
        BOOST_CHECK_EQUAL(klient.getAmountVehicles(), 10.0);
        klient.setTurnover(4000.5);
        BOOST_CHECK_EQUAL(klient.getTurnover(), -9999); //error - continue testing
        BOOST_CHECK_EQUAL(klient.getTurnover(), 4000.50);
        BOOST_CHECK_EQUAL(klient.clientinfo(), "Blad"); //error - continue testing
        BOOST_CHECK_EQUAL(klient.clientinfo(), "Jan Kowalski PESEL ulica 1\nTyp klienta: Premium");
    }   // oczekiwanych 8 bledow

BOOST_AUTO_TEST_SUITE_END()


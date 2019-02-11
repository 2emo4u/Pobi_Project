#include "Interface.h"
#include "Client.h"
#include "Car.h"
#include "Mope.h"
#include "Bicycle.h"
#include "RentsRepository.h"
#include "ClientRepository.h"
#include "VehicleRepository.h"
#include "RentsManager.h"
#include <iostream>

using namespace std;

typedef shared_ptr < Car > CarPtr;
typedef shared_ptr < Mope > MopePtr;
typedef shared_ptr < Bicycle > BicyclePtr;

Interface::Interface(RentsRepositoryPtr rentsRepository, ClientRepositoryPtr clientRepository,
                     VehicleRepositoryPtr vehicleRepository)
        :rentsRepository{rentsRepository}, clientRepository{clientRepository}, vehicleRepository{vehicleRepository} {
    RentsManager rentManager{rentsRepository, clientRepository, vehicleRepository};
    ClientPtr client1 = make_shared < Client > ();
    ClientPtr client2 = make_shared < Client > ("Artur", "Badura", "95081300243", "Polnocna", "11",
                                                Basic);
    ClientPtr client3 = make_shared < Client > ("Tomasz", "Gromadko", "73111300211", "Kopernika", "67",
                                                Premium);
    clientRepository->createClient(client1);
    clientRepository->createClient(client2);
    clientRepository->createClient(client3);

    CarPtr car1 = make_shared < Car > ("EBE56TY","Opel", 1000, 700, A);  //0
    CarPtr car2 = make_shared < Car > ("EBE56GY","BMW", 3000, 1000, B); //1
    CarPtr car3 = make_shared < Car > ("EPI56TY","Toyota", 9000, 1700, C); //2
    CarPtr car4 = make_shared < Car > ("EBEVF43","Zaz", 8000, 2700, E); //3

    MopePtr mope1 = make_shared < Mope > ("G67HT","Adamoto", 400, 170); //4
    MopePtr mope2 = make_shared < Mope > ("G62HT","Mondial", 700, 50); //5
    MopePtr mope3 = make_shared < Mope > ("V57HF","Derbi", 1200, 60); //6
    MopePtr mope4 = make_shared < Mope > ("BG56T","Cagiva", 1400, 40); //7

    BicyclePtr bicycle1 = make_shared < Bicycle > ("N77UJ","Mondraker", 100); //8
    BicyclePtr bicycle2 = make_shared < Bicycle > ("M4RC1","Dadelo", 300);
    BicyclePtr bicycle3 = make_shared < Bicycle > ("KW4R3","Kross", 220);

    vehicleRepository->addVehicle(car1);
    vehicleRepository->addVehicle(car2);
    vehicleRepository->addVehicle(car3);
    vehicleRepository->addVehicle(car4);

    vehicleRepository->addVehicle(mope1);
    vehicleRepository->addVehicle(mope2);
    vehicleRepository->addVehicle(mope3);
    vehicleRepository->addVehicle(mope4);

    vehicleRepository->addVehicle(bicycle1);
    vehicleRepository->addVehicle(bicycle2);

    rentManager.RentVehicle(0, 0);
    rentManager.RentVehicle(1, 2);
    rentManager.RentVehicle(2, 3);
    rentManager.RentVehicle(1, 5);
    rentManager.RentVehicle(2, 7);
 // rentManager.RentVehicle(1, 9);

    rentManager.returnVehicle(0);
    rentManager.returnVehicle(2);
    rentManager.returnVehicle(3);
 // rentManager.returnVehicle(5);
 // rentManager.returnVehicle(7);
 // rentManager.returnVehicle(9);


    cout << "--------------------------------------------" << endl;
    cout<<rentsRepository->rentArchiveReport()<<endl;
    cout<<rentsRepository->getAllClientRents(client1);


    cout << "\n------------------------------------------" << endl;
}

Interface::~Interface() {}




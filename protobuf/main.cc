#include <iostream>

#include "addressbook.pb.h"

int main() {
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    std::cout << "Hello World!" << std::endl;

    tutorial::Person* person = new tutorial::Person;
    person->set_name("rayed");
    std::cout << "[";
    person->SerializeToOstream(&std::cout);
    std::cout << "]" << std::endl;
    delete person;
    return 0;
}

#include <iostream>
#include <vector>

void vector_test()
{
    int i;
    std::vector<int> vec;

    // push 5 values into the vector
    for(i = 0; i < 5; i++){
       vec.push_back(i);
    }

    std::cout << "Looping using vector size " << vec.size() << std::endl;
    for(i = 0; i < vec.size(); i++){
       std::cout << "value of vec [" << i << "] = " << vec[i] << std::endl;
    }

    std::cout << "Looping using iterator" << std::endl;
    std::vector<int>::iterator v = vec.begin();
    while( v != vec.end()) {
       std::cout << "value of v = " << *v << std::endl;
       v++;
    }

    std::cout << "Loop using forech" << std::endl;
    for (auto &i: vec) {
        std::cout << "We have:" << i << std::endl;
    }
}

int main()
{
    std::cout << "==== Hello World! ====" << std::endl;
    vector_test();
    return 0;
}

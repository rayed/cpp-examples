#include <iostream>
#include <vector>
#include <boost/foreach.hpp>

using namespace std;

void vector_test()
{
    int i;
    vector<int> vec;

    // display the original size of vec
    cout << "vector size = " << vec.size() << endl;

    // push 5 values into the vector
    for(i = 0; i < 5; i++){
       vec.push_back(i);
    }

    // display extended size of vec
    cout << "extended vector size = " << vec.size() << endl;

    // access 5 values from the vector
    for(i = 0; i < 5; i++){
       cout << "value of vec [" << i << "] = " << vec[i] << endl;
    }

    // use iterator to access the values
    vector<int>::iterator v = vec.begin();
    while( v != vec.end()) {
       cout << "value of v = " << *v << endl;
       v++;
    }

    BOOST_FOREACH(int i, vec) {
        cout << "We have:" << i << endl;
    }
}

int main()
{
    std::cout << "==== Hello World! ====" << std::endl;
    vector_test();
    return 0;
}

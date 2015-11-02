#include "multiSetHelp.h"
#include <iostream>
using namespace std;

template <typename T>
multiSetHelp<T>::multiSetHelp(){
    key = "";
    num = 1;
}
template <typename T>
multiSetHelp<T>::multiSetHelp(T setKey){
    key = setKey;
    num = 1;
}

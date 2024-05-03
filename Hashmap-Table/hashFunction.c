#include <stdlib.h>
#include <string.h>

int hashFunction(int keyValue){
    return (keyValue % capacity);
}

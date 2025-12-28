#include <string>
using namespace std;
int hash(const string& key,int tableSize){
    int hashVal=0;
    for(char c : key){
        hashVal+=c;
    }
    return hashVal%tableSize;
}
int hash1(const string& key,int tableSize){
    int hashVal=key[0]+key[1]*27+key[2]*729;
    return hashVal%tableSize;
    
}
int hashGood(const string& key, int tableSize){
    int hashVal=0;
    for(char c: key){
        hashVal= hashVal*37+c;
    }
    return hashVal%tableSize;
}
int main(){
    return 0;
}
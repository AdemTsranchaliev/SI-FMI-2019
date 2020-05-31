
#include "FileSystem.h"
#include "Music.h"


using namespace std;


int main()
{
    FileSystem d;
    
    Music mus("Galin","Yavash",2014,Date("now"),123,".mp33");
    d.createNewFolder("Adem");
    d.addFileToFolder("Adem",&mus);
    return 0;
}
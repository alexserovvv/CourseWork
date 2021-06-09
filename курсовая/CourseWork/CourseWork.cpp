#include "pushRelabel.h"
using namespace std;

int main()
{
    Graph mg;
    string filename;
    bool ret = true;
    while (ret == true)
    {
        cout << "Enter the name of the text file - ";
        cin >> filename;
        try
        {
            mg.addVertex(filename);
            mg.addEdge(filename);
            ret = false;
        }
        catch (invalid_argument error)
        {
            cout << error.what() << endl;
        }
        cout << endl;
    }
    try
    {
        cout << "maximum flow is " << mg.getMaxFlow();
    }
    catch (out_of_range error)
    {
        cout << error.what() << endl;
    }

    return 0;

}
#include <iostream>
#include <fstream>
#include <vector>
#include "wumanber.h"

using namespace std;

int main(int argc, char* argv[])
{
    //step1: init patterns
    vector<string> patterns;
    ifstream pat("patterns");
    string s;
    while (pat>>s)
        patterns.push_back(s);

    //step2: init wumanber
    WuManber wu;
    wu.Init(patterns);

    //step3: find patterns using wumanber in paraell
    ifstream text("text");
    while (text>>s)
    {
        //interface1
        cout << s << " hit:" << wu.Search(s) << endl;
        //interface2
        set<string> res;
        wu.Search(s, res);
        for (set<string>::iterator it = res.begin(); it != res.end(); ++it)
        {
            cout << "\t" << *it << endl;
        }
    }    
    
    return 0;
}

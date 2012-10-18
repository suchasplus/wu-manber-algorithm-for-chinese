#include <iostream>
#include <fstream>
#include <vector>

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
        cout << s << " hit:" << wu.Search(s) << endl;
    
    return 0;
}

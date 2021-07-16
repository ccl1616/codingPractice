#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){

    //declaration container and iterator
    map<string, string> mapStudent;
    // map<string, string>::iterator iter;
    // map<string, string>::reverse_iterator iter_r;

    // //insert element
    mapStudent.insert(pair<string, string>("r000", "student_zero"));

    // mapStudent["r123"] = "student_first";
    // mapStudent["r456"] = "student_second";

    // //traversal
    // for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
    //             cout<<iter->first<<" "<<iter->second<<endl;
    // for(iter_r = mapStudent.rbegin(); iter_r != mapStudent.rend(); iter_r++)
    //             cout<<iter_r->first<<" "<<iter_r->second<<endl;

    // //find and erase the element
    // iter = mapStudent.find("r123");
    // if(iter != mapStudent.end())
    //    cout<<"Find, the value is "<<iter->second<<endl;
    // else
    //    cout<<"Do not Find"<<endl;

    // mapStudent.erase(iter);

    // iter = mapStudent.find("r123");

    // if(iter != mapStudent.end())
    //    cout<<"Find, the value is "<<iter->second<<endl;
    // else
    //    cout<<"Do not Find after erase"<<endl;

    map<int, int> num_map;
    // num_map.insert(pair<int, int>(5, 10));
    num_map.insert(make_pair(5,10));
    map<int, int>::iterator iter;
    iter = num_map.find(5);
    if(iter != num_map.end())
        cout<<"Find, the value is "<<iter->second<<endl;
    else 
        cout<<"Do not Find"<<endl;

    return 0;
}
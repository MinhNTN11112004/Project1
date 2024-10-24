/*Description
Given a family tree represented by child-parent (c,p) relations in which c is a child of p. Perform queries about the family tree:
descendants <name>: return number of descendants of the given <name>
generation <name>: return the number of generations of the descendants of the given <name>
Note that: the total number of people in the family is less than or equal to 10
4
Input
Contains two blocks. The first block contains information about child-parent, including lines (terminated by a line containing ***), 
each line contains: <child> <parent> where <child> is a string represented the name of the child and <parent> is a string represented the name of the parent. 
The second block contains lines (terminated by a line containing ***), each line contains two string <cmd> and <param> where 
<cmd> is the command (which can be descendants or generation) and <param> is the given name of the person participating in the  query.
Output
Each line is the result of a corresponding query.
Example
Input
Peter Newman
Michael Thomas
John David
Paul Mark
Stephan Mark
Pierre Thomas
Mark Newman
Bill David
David Newman
Thomas Mark
***
descendants Newman
descendants Mark
descendants David
generation Mark
***
Output
10
5
2
2*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;
unordered_map<string, vector<string>> familyTree;
void addRelation(const string& child, const string& parent) {
    familyTree[parent].push_back(child);
}
int countDescendants(const string& name) {
    if (familyTree.find(name) == familyTree.end()) return 0;
    int count = familyTree[name].size(); 
    for (const auto& child : familyTree[name]) {
        count += countDescendants(child); 
    }
    return count;
}
int countGenerations(const string& name) {
    if (familyTree.find(name) == familyTree.end()) return 0;
    int maxDepth = 0;
    for (const auto& child : familyTree[name]) {
        maxDepth = max(maxDepth, countGenerations(child));
    }
    return 1 + maxDepth; 
}
int main() {
    string line;
    while (getline(cin, line) && line != "***") {
        istringstream iss(line);
        string child, parent;
        iss >> child >> parent;
        addRelation(child, parent);
    }
    while (getline(cin, line) && line != "***") {
        istringstream iss(line);
        string command, name;
        iss >> command >> name;
        if (command == "descendants") {
            int numDescendants = countDescendants(name);
            cout << numDescendants << endl;
        } else if (command == "generation") {
            int numGenerations = countGenerations(name);
            cout << numGenerations << endl;
        }
    }
    return 0;
}

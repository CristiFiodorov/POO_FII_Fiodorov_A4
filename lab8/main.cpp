#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <queue>
#include <utility>

using namespace std;

class Compare {
public:
    bool operator() (pair<string, int> p1, pair<string, int> p2) {
        if (p1.second < p2.second)
            return true;
        if (p1.second > p2.second)
            return false;
        if (p1.first < p2.first)
            return false;
        return true;
    }
};

string* tokenize(string s)
{
    string* words = new string[100];
    string del[]{ " ", ",", "?", "!", ".", "\n" };
    int start = 0;
    int end = s.find(del[0]);
    for (int j{ 1 }; j < 6; ++j)
        if (end > s.find(del[j]))
            end = s.find(del[j]);

    int i = 0;
    while (end != -1) 
    {
        if (end - start > 0)
        {
            words[i] = s.substr(start, end - start);
            ++i;
        }
        s.replace(end, 1, "_");

        start = end + 1;

        end = s.find(del[0]);
        for (int j{ 0 }; j < 6; ++j)
            if (end > s.find(del[j]))
                end = s.find(del[j]);
    }

    words[i] = s.substr(start, end - start);

    return words;
}


int main()
{
    string str;

    fstream newfile;
    newfile.open("file.txt", ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()) 
    { 
        string tp;
        while (getline(newfile, tp))
        { //read data from file object and put it into string.
            str += tp;
        }
        newfile.close(); //close the file object.
    }

    string* words;

    words = tokenize(str);

    map<string, int> map1;

    for (int i{ 0 }; i < 100; ++i)
    {
        if (words[i] == "\0")
            break;
        if (!map1.count(words[i]))
            map1[words[i]] = 1;
        else
        {
            int count = map1[words[i]];
            map1[words[i]] = count + 1;
        }
    }


    priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> myQueue;
    for (auto mapIterator = map1.begin(); mapIterator != map1.end(); mapIterator++) {
        myQueue.push(pair<string, int>(mapIterator->first, mapIterator->second));
    }

    while (!myQueue.empty())
    {

        cout <<myQueue.top().first << ":" << myQueue.top().second << endl;
        myQueue.pop();
    }

    return 0;
}

#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>

struct Times
{
    int departure;
    int arrival;
};

class Comparator
{
public:
    bool operator() (const Times& t1, const Times& t2) const
    {
        if(t1.arrival == t2.arrival)
            return t1.departure < t2.departure;
        return t1.arrival > t2.arrival;
    }
};

std::map < std::string, int > cityToID;
std::vector < std::vector < std::vector < Times > > > G;

int cities = 0;
int connections;
int source;
int destination;

void readData()
{
    std::cout << "Podaj liczbe polaczen: ";
    std::cin >> connections;
    std::cout << "Podaj polaczenia:\n";
    for(int i = 0; i < connections; ++i)
    {
        std::string s, d;
        Times t;
        std::cin >> s >> d >> t.departure >> t.arrival;
        if(cityToID.find(s) == cityToID.end())
        {
            if(s.compare("Warszawa") == 0)
            {
                source = cities;
            }
            if(s.compare("Jelenia_Gora") == 0)
            {
                destination = cities;
            }
            cityToID[s] = cities++;
        }
        G[cityToID[s]][cityToID[d]].push_back(t);
    }
}

void Dijkstra()
{
    std::priority_queue<Times, std::vector<Times>, Comparator> Q;
    while(!Q.empty())
    {

    }
}

/*void testComparator()
{
    std::priority_queue<Times, std::vector<Times>, Comparator> Q;
    Times t;
    t.arrival = 11;
    t.departure = 10;
    Q.push(t);
    t.departure = 9;
    Q.push(t);
    t.arrival = 7;
    Q.push(t);
    t.arrival = 19;
    Q.push(t);
    t.departure = 20;
    Q.push(t);
    while(!Q.empty())
    {
        Times v = Q.top();
        Q.pop();
        std::cout << v.arrival << "-" << v.departure << std::endl;
    }   
}*/

int main()
{
    readData();
    return 0;
}
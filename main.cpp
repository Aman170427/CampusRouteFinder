#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

const int N = 9;

string locations[N] = {
    "Main Gate",
    "Library",
    "Block 1",
    "Block 2",
    "Cafeteria",
    "Auditorium",
    "Parking",
    "Lab",
    "Sports Ground"
};

vector<int> adj[N];

// Add connection between two locations
void addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Display all locations
void displayLocations()
{
    int i;

    cout << "\nCampus Locations:\n";

    for (i = 0; i < N; i++)
    {
        cout << i + 1 << ". " << locations[i] << endl;
    }
}

// Display adjacency list
void displayGraph()
{
    int i, j;

    cout << "\nGraph Representation (Adjacency List):\n";

    for (i = 0; i < N; i++)
    {
        cout << locations[i] << " -> ";

        for (j = 0; j < (int)adj[i].size(); j++)
        {
            cout << locations[adj[i][j]] << " -> ";
        }

        cout << "NULL" << endl;
    }
}

// BFS to find shortest route
void BFS(int source, int destination)
{
    vector<bool> visited(N, false);
    vector<int> parent(N, -1);
    queue<int> q;

    int current, i, next;

    visited[source] = true;
    q.push(source);

    while (!q.empty())
    {
        current = q.front();
        q.pop();

        if (current == destination)
        {
            break;
        }

        for (i = 0; i < (int)adj[current].size(); i++)
        {
            next = adj[current][i];

            if (!visited[next])
            {
                visited[next] = true;
                parent[next] = current;
                q.push(next);
            }
        }
    }

    if (!visited[destination])
    {
        cout << "\nNo route exists between "
             << locations[source] << " and "
             << locations[destination] << "." << endl;
        return;
    }

    vector<int> path;
    int v;

    for (v = destination; v != -1; v = parent[v])
    {
        path.push_back(v);
    }

    reverse(path.begin(), path.end());

    cout << "\nShortest Route:\n";

    for (i = 0; i < (int)path.size(); i++)
    {
        cout << locations[path[i]];

        if (i < (int)path.size() - 1)
        {
            cout << " -> ";
        }
    }

    cout << "\nMinimum number of edges: "
         << path.size() - 1 << endl;
}

// DFS traversal
void DFSUtil(int current, vector<bool> &visited)
{
    int i, next;

    visited[current] = true;

    cout << locations[current] << endl;

    for (i = 0; i < (int)adj[current].size(); i++)
    {
        next = adj[current][i];

        if (!visited[next])
        {
            DFSUtil(next, visited);
        }
    }
}

// Display reachable and disconnected locations
void performDFS(int source)
{
    vector<bool> visited(N, false);
    int i;

    cout << "\nLocations reachable from "
         << locations[source] << ":\n";

    DFSUtil(source, visited);

    cout << "\nDisconnected Locations:\n";

    bool found = false;

    for (i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            cout << locations[i] << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "No disconnected locations." << endl;
    }
}

int main()
{
    int choice;

    // Create campus connections
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(1, 4);
    addEdge(2, 3);
    addEdge(3, 4);
    addEdge(3, 5);
    addEdge(4, 5);
    addEdge(5, 6);

    do
    {
        cout << "\n===== CAMPUS ROUTE FINDER =====\n";
        cout << "1. Display Campus Locations\n";
        cout << "2. Display Graph\n";
        cout << "3. Find Shortest Route using BFS\n";
        cout << "4. Find Reachable Locations using DFS\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        if (choice == 1)
        {
            displayLocations();
        }
        else if (choice == 2)
        {
            displayGraph();
        }
        else if (choice == 3)
        {
            int source, destination;

            displayLocations();

            cout << "\nEnter source location number: ";
            cin >> source;

            cout << "Enter destination location number: ";
            cin >> destination;

            if (source < 1 || source > N ||
                destination < 1 || destination > N)
            {
                cout << "Invalid location number!" << endl;
            }
            else
            {
                BFS(source - 1, destination - 1);
            }
        }
        else if (choice == 4)
        {
            int source;

            displayLocations();

            cout << "\nEnter starting location number: ";
            cin >> source;

            if (source < 1 || source > N)
            {
                cout << "Invalid location number!" << endl;
            }
            else
            {
                performDFS(source - 1);
            }
        }
        else if (choice == 5)
        {
            cout << "Thank you for using Campus Route Finder!"
                 << endl;
        }
        else
        {
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 5);

    return 0;
}


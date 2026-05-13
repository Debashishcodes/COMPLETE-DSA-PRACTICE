#include <iostream>
#include <vector>
#include <queue>
using namespace std;
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        queue<int> q;

        for(int i = 0; i < n; i++){
            q.push(students[i]);
        }

        int i = 0; // index for sandwiches
        int count = 0;

        while(q.size() > 0 && count != q.size()){
            if(q.front() == sandwiches[i]){
                count = 0;
                q.pop();
                i++;
            }
            else{
                q.push(q.front());
                q.pop();
                count++;
            }
        }
        return q.size();
    }
int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<int> students(n);
    vector<int> sandwiches(n);

    cout << "Enter students preferences (0 or 1): ";
    for(int i = 0; i < n; i++){
        cin >> students[i];
    }

    cout << "Enter sandwiches stack (0 or 1): ";
    for(int i = 0; i < n; i++){
        cin >> sandwiches[i];
    }

    int result = countStudents(students, sandwiches);

    cout << "Number of students unable to eat: " << result << endl;

    return 0;
}
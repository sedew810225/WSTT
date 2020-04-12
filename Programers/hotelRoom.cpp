#include <string>
#include <vector>
using namespace std;

long long find(long long room, vector<long long>& selected) {
    if (room == selected[room]) return room;
    else {
        selected[room] = find(selected[room], selected);
        return selected[room];
    }
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    vector<long long> selected;

    long long targetRoom = 0;
    long long nextRoom = 0;
    long long i = 0;

    for (i = 0; i <= k; i++) selected.push_back(i);

    for (i = 0; i < room_number.size(); i++) {
        targetRoom = find(room_number[i], selected);
        answer.push_back(targetRoom);

        if (targetRoom + 1LL <= k) {
            nextRoom = find(targetRoom + 1, selected);
            selected[targetRoom] = nextRoom;
        }
        else {
            selected[targetRoom] = 0;
        }
    }
    return answer;
}

int main() {
    vector<long long> room_number = { 1,3,4,1,3,1,1 };
    vector<long long> result;

    result = solution(7, room_number);

    return 0;

}
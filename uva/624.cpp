#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_solution(vector<int> selected_tracks, int sum){
	vector<int>::iterator it;
	for (it = selected_tracks.begin(); it < selected_tracks.end(); it++){
		cout << *it << " ";
	}
	cout << "sum:" << sum << endl;
}

bool select_tracks_utility(vector<int> track_durations, vector<int> selected_tracks, int n, int sum){
	if (sum < n)
		return true;
	else{
		sum += track_durations[0];
		selected_tracks.push_back(track_durations[0]);
		int temp = track_durations[0];
		track_durations.erase(track_durations.begin());
		if (select_tracks_utility(track_durations, selected_tracks, n, sum))
			return true;
		sum -= temp;
		selected_tracks.erase(track_durations.end());
		track_durations.push_back(temp);
		return false;
	}
	return false;
}

void select_tracks(vector<int> track_durations, int n){
	int sum = 0;
	vector<int> selected_tracks;
	if (select_tracks_utility(track_durations, selected_tracks, n, sum))
		print_solution(selected_tracks, sum);
	else
		cout << "impossible" << endl;
}

int main(){
	while(true){
		int n;
		int num_of_tracks;
		int temp;
		cin >> n >> num_of_tracks;
		vector<int> track_durations(num_of_tracks);
		for (int i = 0; i < num_of_tracks; ++i){
			cin >> temp;
			track_durations.push_back(temp);
		}
		select_tracks(track_durations, n);
	}
	return 0;
}


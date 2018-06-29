#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


class Solution {
public:
  int carFleet(int target, vector<int>& position, vector<int>& speed) {

    // calculate final time
    vector<float> final_time(1e6, -1);
    for (size_t i=0; i < position.size(); ++i) {
      final_time[ position[i] ] = static_cast<float>((target - position[i])) / static_cast<float>(speed[i]);
    }

    // now traverse final time and count the fleets
    int fleets(0);
    float last_time(final_time.back());
    fleets = accumulate(final_time.rbegin(), final_time.rend(), 0, [&last_time] (int acum, float t) {
        if (t >= 0) {
          if (t > last_time) {
            last_time = t;
            return acum+1;
          }
        }
        return acum;
      });

    return fleets;
  }
};

int main()
{
  Solution sol;
  // int target=12;
  // vector<int> position{10, 8, 0, 5, 3};
  // vector<int> speed{2, 4, 1, 1, 3};

  //int target=10;
  // vector<int> position{6, 8};
  // vector<int> speed{3, 2};

  int target=10;
  vector<int> position{8, 3, 7, 4, 6, 5};
  vector<int> speed{4, 4, 4, 4, 4, 4};


  auto output = sol.carFleet(target, position, speed);

  cout << output << "\n";

}

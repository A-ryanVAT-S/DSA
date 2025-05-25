 #include <bits/stdc++.h>
using namespace std;

vector<int> arr = {1, 2, 3, 4, 5}; // Example vector
vector<pair<int, int>> arr2 = {{1, 2}, {3, 4}, {5, 6}}; // Example vector of pairs
int n = arr2.size(); // Size of the vector

 // Function to sort in descending order
 bool dec(int a, int b) { return a > b;}
 sort(arr.begin(),arr.end(),dec);

 //directly using STL
 sort(arr.begin(),arr.end(),grater<int>());

 //loop to print array elements and move to next line
 for(int i=0;i<n;i++){
    cout<<arr[i]<<'\n'[i==n-1];
 }
 
 //to take input from user
 for(auto &x : arr) {
    cin >> x;
 }

//sorting pair of vectors
sort(arr2.begin(), arr2.end()); // Sorts by first element (start), then second (end)
sort(arr2.begin(), arr2.end(), [](auto &a, auto &b){ return a.second < b.second; }); // Sorts by second element (end)


// taking input for pair of vectors
for(auto &p : arr2) {
    cin >> p.first >> p.second;
}

// Printing the vector of pairs
for(const auto &p : arr2) {
    cout << p.first << " " << p.second << '\n';
}
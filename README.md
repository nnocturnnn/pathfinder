# pathfinder

7
Home-BusStop,4
BusStop-Work,7
Home-Taxi,1
Metro-Home,6
Taxi-Work,10
Work-Gym,2
Metro-Work,8
Taxi-Gym,12
BusStop-Park,18
Park-Metro,16

========================================
Path: Home -> BusStop
Route: Home -> BusStop
Distance: 4
========================================
========================================
Path: Home -> Work
Route: Home -> BusStop -> Work
Distance: 4 + 7 = 11
========================================
========================================
Path: Home -> Work
Route: Home -> Taxi -> Work
Distance: 1 + 10 = 11
========================================
========================================
Path: Home -> Taxi
Route: Home -> Taxi
Distance: 1
========================================
========================================
Path: Home -> Metro
Route: Home -> Metro
Distance: 6
========================================
========================================
Path: Home -> Gym
Route: Home -> BusStop -> Work -> Gym
Distance: 4 + 7 + 2 = 13
========================================
========================================
Path: Home -> Gym
Route: Home -> Taxi -> Gym
Distance: 1 + 12 = 13
========================================
========================================
Path: Home -> Park
Route: Home -> BusStop -> Park
Distance: 4 + 18 = 22
========================================
========================================
Path: Home -> Park
Route: Home -> Metro -> Park
Distance: 6 + 16 = 22
========================================
========================================
Path: Home -> Park
Route: Home -> BusStop -> Park
Distance: 4 + 18 = 22
========================================
========================================
Path: BusStop -> Work
Route: BusStop -> Work
Distance: 7
========================================
========================================
Path: BusStop -> Taxi
Route: BusStop -> Home -> Taxi
Distance: 4 + 1 = 5
========================================
========================================
Path: BusStop -> Metro
Route: BusStop -> Home -> Metro
Distance: 4 + 6 = 10
========================================
========================================
Path: BusStop -> Gym
Route: BusStop -> Work -> Gym
Distance: 7 + 2 = 9
========================================
========================================
Path: BusStop -> Park
Route: BusStop -> Park
Distance: 18
========================================
========================================
Path: Work -> Taxi
Route: Work -> Taxi
Distance: 10
========================================
========================================
Path: Work -> Metro
Route: Work -> Metro
Distance: 8
========================================
========================================
Path: Work -> Gym
Route: Work -> Gym
Distance: 2
========================================
========================================
Path: Work -> Park
Route: Work -> Metro -> Park
Distance: 8 + 16 = 24
========================================
========================================
Path: Taxi -> Metro
Route: Taxi -> Home -> Metro
Distance: 1 + 6 = 7
========================================
========================================
Path: Taxi -> Gym
Route: Taxi -> Work -> Gym
Distance: 10 + 2 = 12
========================================
========================================
Path: Taxi -> Gym
Route: Taxi -> Gym
Distance: 12
========================================
========================================
Path: Taxi -> Park
Route: Taxi -> Home -> BusStop -> Park
Distance: 1 + 4 + 18 = 23
========================================
========================================
Path: Taxi -> Park
Route: Taxi -> Home -> Metro -> Park
Distance: 1 + 6 + 16 = 23
========================================
========================================
Path: Taxi -> Park
Route: Taxi -> Home -> BusStop -> Park
Distance: 1 + 4 + 18 = 23
========================================
========================================
Path: Metro -> Gym
Route: Metro -> Work -> Gym
Distance: 8 + 2 = 10
========================================
========================================
Path: Metro -> Park
Route: Metro -> Park
Distance: 16
========================================
========================================
Path: Gym -> Park
Route: Gym -> Work -> Metro -> Park
Distance: 2 + 8 + 16 = 26
========================================
e2r1p2% make
e2r1p2% ./pathfinder 1.txt
========================================
Path: Home -> BusStop
Route: Home -> BusStop
Distance: 4
========================================
========================================
Path: Home -> Work
Route: Home -> BusStop -> Work
Distance: 4 + 7 = 11
========================================
========================================
Path: Home -> Work
Route: Home -> Taxi -> Work
Distance: 1 + 10 = 11
========================================
========================================
Path: Home -> Taxi
Route: Home -> Taxi
Distance: 1
========================================
========================================
Path: Home -> Metro
Route: Home -> Metro
Distance: 6
========================================
========================================
Path: Home -> Gym
Route: Home -> BusStop -> Work -> Gym
Distance: 4 + 7 + 2 = 13
========================================
========================================
Path: Home -> Gym
Route: Home -> Taxi -> Gym
Distance: 1 + 12 = 13
========================================
========================================
Path: Home -> Park
Route: Home -> BusStop -> Park
Distance: 4 + 18 = 22
========================================
========================================
Path: Home -> Park
Route: Home -> Metro -> Park
Distance: 6 + 16 = 22
========================================
========================================
Path: Home -> Park
Route: Home -> BusStop -> Park
Distance: 4 + 18 = 22
========================================
========================================
Path: BusStop -> Work
Route: BusStop -> Work
Distance: 7
========================================
========================================
Path: BusStop -> Taxi
Route: BusStop -> Home -> Taxi
Distance: 4 + 1 = 5
========================================
========================================
Path: BusStop -> Metro
Route: BusStop -> Home -> Metro
Distance: 4 + 6 = 10
========================================
========================================
Path: BusStop -> Gym
Route: BusStop -> Work -> Gym
Distance: 7 + 2 = 9
========================================
========================================
Path: BusStop -> Park
Route: BusStop -> Park
Distance: 18
========================================
========================================
Path: Work -> Taxi
Route: Work -> Taxi
Distance: 10
========================================
========================================
Path: Work -> Metro
Route: Work -> Metro
Distance: 8
========================================
========================================
Path: Work -> Gym
Route: Work -> Gym
Distance: 2
========================================
========================================
Path: Work -> Park
Route: Work -> Metro -> Park
Distance: 8 + 16 = 24
========================================
========================================
Path: Taxi -> Metro
Route: Taxi -> Home -> Metro
Distance: 1 + 6 = 7
========================================
========================================
Path: Taxi -> Gym
Route: Taxi -> Work -> Gym
Distance: 10 + 2 = 12
========================================
========================================
Path: Taxi -> Gym
Route: Taxi -> Gym
Distance: 12
========================================
========================================
Path: Taxi -> Park
Route: Taxi -> Home -> BusStop -> Park
Distance: 1 + 4 + 18 = 23
========================================
========================================
Path: Taxi -> Park
Route: Taxi -> Home -> Metro -> Park
Distance: 1 + 6 + 16 = 23
========================================
========================================
Path: Taxi -> Park
Route: Taxi -> Home -> BusStop -> Park
Distance: 1 + 4 + 18 = 23
========================================
========================================
Path: Metro -> Gym
Route: Metro -> Work -> Gym
Distance: 8 + 2 = 10
========================================
========================================
Path: Metro -> Park
Route: Metro -> Park
Distance: 16
========================================
========================================
Path: Gym -> Park
Route: Gym -> Work -> Metro -> Park
Distance: 2 + 8 + 16 = 26
========================================
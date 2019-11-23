# pathfinder

## Pathfinder How to use:

make
./pathfinder [filename]
```
4
Greenland-Bananal,8 
Fraser-Greenland,10 
Bananal-Fraser,3 
Java-Fraser,5 
```
## output:
```
========================================
Path: Greenland -> Bananal
Route: Greenland -> Bananal
Distance: 8
========================================
========================================
Path: Greenland -> Fraser
Route: Greenland -> Fraser
Distance: 10
========================================
========================================
Path: Greenland -> Java
Route: Greenland -> Fraser -> Java
Distance: 10 + 5 = 15
========================================
========================================
Path: Bananal -> Fraser
Route: Bananal -> Fraser
Distance: 3
========================================
========================================
Path: Bananal -> Java
Route: Bananal -> Fraser -> Java
Distance: 3 + 5 = 8
========================================
========================================
Path: Fraser -> Java
Route: Fraser -> Java
Distance: 5
========================================
```

# Google Hashcode 2021

2021's hashcode was themed after Google maps and the problem was a traffic light schedulling problem which involed maximising the number of cars passed through the city traffic network. 

## Results 
Our team ranked 3rd in entire Australia and top 8% in the global rankings out of 9000+ participants, scoring 9 519 815 points. 

## Solution Discussion
To test the solution on your machine, compile the source code with the following:
```
g++ maps.cpp functions.cpp classes.cpp
```

The approach we took to solve the problem involves two steps:
1. Calculate the popularity of each street (measure of how often it is travelled on).
2. Map this popularity into different traffic light timings.

To calculate the popularity we simply counted how often a specified street appears on a car's path.
Once the popularities were calculated, they were converted into timings with the following:
```
timing = ceil(intersection_duration * street_pop / intersection_pop)
```
Other algorithms we're considered too; however, discarded due to the competition's time constraints.

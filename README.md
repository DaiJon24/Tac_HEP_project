# Tac_HEP_project

Project plan:
 Start with the clustering algo-
     In order to get local maxima we would first determine an average value of the array and then loop through to find the points that are 2 std deviations above the mean. Then we
     would loop through the remaining points to determine the absolute maximum( check i-1 and i+1 of a specific point to see if its a max then do the same for j-1 and j+1). Save i and j values.
     then in order to build the clusters we would sum all surrounding points( a(i,j+1) + a(i,j-1) + a(i+1,j) + a(i-1,j) + a(i+1,j+1)....)

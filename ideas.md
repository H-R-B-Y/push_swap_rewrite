Need to check the best LIS is actualy worth performing

this check needs to be:
distance from the top (min of the index and the (len - index -1))
plus the difference between the best LIS previous best


because we cannot pass metadata to the function we need to track the index and the LIS length at the same time.

otherwise we could harm the performance by doing excess rotations when it is not explicitly necessary.


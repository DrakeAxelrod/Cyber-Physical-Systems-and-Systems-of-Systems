import matplotlib.pyplot as plt
import numpy as np
actual_steering = list()
computed_steering = list()

# get the standard deviation of the steering angle
std_steering = np.std(computed_steering)
# check whether the computed steering angle is within the threshold +/- 0.05
# and calculate the number of correct predictions
correct_predictions = 0
for i in range(len(computed_steering)):
    if abs(computed_steering[i] - actual_steering[i]) < 0.05:
        correct_predictions += 1
# print the results
print('The standard deviation of the steering angle is: ' + str(std_steering))
print('The number of correct predictions is: ' + str(correct_predictions))
print('The percentage of correct predictions is: ' + str(correct_predictions / len(computed_steering)))
# print the total number of data points
print('The total number of data points is: ' + str(len(computed_steering)))

#!/usr/bin/env python3
import socket
import numpy as np

def display_stats(actual_steering: list, computed_steering: list):
    computed_num_max = 0
    computed_num_0 = 0
    actual_num_max = 0
    actual_num_0 = 0
    # get the standard deviation of the steering angle
    std_steering = np.std(actual_steering)
    # check whether the computed steering angle is within the threshold +/- 0.05
    # and calculate the number of correct predictions
    correct_predictions = 0
    for i in range(len(actual_steering)):
        if abs(actual_steering[i]) == 0:
            actual_num_0 += 1
        if abs(actual_steering[i]) == 0.290888:
            actual_num_max += 1
    for i in range(len(computed_steering)):
        if abs(computed_steering[i]) == 0:
            computed_num_0 += 1
        if abs(computed_steering[i]) == 0.290888:
            computed_num_max += 1
        if abs(computed_steering[i] - actual_steering[i]) <= 0.05:
            correct_predictions += 1
    perc = correct_predictions / len(computed_steering)
    # print the results
    print("============================== Results ==============================")
    print('the steering angle standard deviation: ' + str(std_steering))
    print("The number of actual 0s: " + str(actual_num_0))
    print("The number of computed 0s: " + str(computed_num_0))
    print("The number of actual maxs: " + str(actual_num_max))
    print('The number of computed maxs: ' + str(computed_num_max))
    print('the number correct predictions: ' + str(correct_predictions))
    print('The percentage of correct predictions is: ' + str(round(perc *100)) + '%')
    print('The total # of data points: ' + str(len(computed_steering)))
    print("=====================================================================")

# open a csv file called results.csv and reatd the actualSteering column into a list and the computedSteering column into a list
actual_steering = list()
computed_steering = list()
with open('/tmp/results.csv', 'r') as f:
    for line in f:
        line = line.split(';')
        if line[0] != None:
          actual_steering.append(float(line[0]))
        if line[1] != None:
          computed_steering.append(float(line[1]))
    f.close()

display_stats(actual_steering, computed_steering)

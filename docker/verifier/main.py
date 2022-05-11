#!/usr/bin/env python3
import socket
import os
import subprocess
import datetime
import numpy as np
import matplotlib.pyplot as plt
from multiprocessing import Pool

def display_stats(timestamps: list, computed_steering: list, actual_steering: list):
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
    # plot

def create_graph(timestamps: list, computed_steering: list, actual_steering: list, name: str):
  pngname = rec_file.replace("CID-140-recording-2020-03-18_", "").replace("-selection.rec", "")
  # convert the timestamps to seconds passed since entry 0
  timestamps = [
    str(x) + "0" if len(str(x)) == 15 else  str(x)
  for x in timestamps]
  # plot the steering angle
  # 0 margins
  plt.figure(figsize=(16,10))
  plt.plot(timestamps, actual_steering, 'r', label='actual steering')
  plt.plot(timestamps, computed_steering, 'b', label='computed steering')
  plt.legend()
  plt.title(f"{name}")
  # rotate all the x-axis labels by 90 degrees
  plt.xticks(rotation=90)
  # skip every other label
  plt.xticks(timestamps[::10])
  # change the font size of the x-axis labels to be half
  plt.xticks(fontsize=8)
  plt.xlabel("sampleTimeStamp (microseconds)")
  plt.ylabel("steeringAngles (radians)")
  # remove white space around the plot
  plt.tight_layout()
  plt.savefig(f"./graphs/{pngname}.png")
  plt.close()



def readCSV(filepath: str):
  # open a csv file called results.csv and reatd the actualSteering column into a list and the computedSteering column into a list
  timestamps = list()
  actual_steering = list()
  computed_steering = list()
  file, ext = os.path.splitext(filepath)
  filepath = f"./csvs/{file}.csv"
  with open(filepath, 'r') as f:
      for line in f:
          line = line.split(';')
          if line[1] != None:
            timestamps.append(int(line[1]))
          if line[2] != None:
            computed_steering.append(float(line[2]))
          if line[3] != None:
            actual_steering.append(float(line[3]))
      f.close()
  return timestamps, computed_steering, actual_steering


def run_rec_file(rec_file: str):
  filename = rec_file.replace("CID-140-recording-2020-03-18_", "").replace("-selection.rec", "")
  cmd = f"./runner.sh ./recordings/{rec_file} {rec_file}"
  p = subprocess.Popen(cmd, stdout=subprocess.PIPE, shell=True)
  (output, err) = p.communicate()
  #This makes the wait possible
  p_status = p.wait()
  (timestamps, computed_steering, actual_steering) = readCSV(rec_file)
  display_stats(timestamps, computed_steering, actual_steering)
  create_graph(timestamps, computed_steering, actual_steering, rec_file)

def run_all_rec_files():
  run_rec_file("CID-140-recording-2020-03-18_144821-selection.rec")
  run_rec_file("CID-140-recording-2020-03-18_145043-selection.rec")
  run_rec_file("CID-140-recording-2020-03-18_145233-selection.rec")
  run_rec_file("CID-140-recording-2020-03-18_145641-selection.rec")
  run_rec_file("CID-140-recording-2020-03-18_150001-selection.rec")

if __name__ == '__main__':
  run_all_rec_files()

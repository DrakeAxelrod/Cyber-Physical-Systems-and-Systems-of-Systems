#!/usr/bin/env python3
import socket
import os
import shutil
import subprocess
import threading
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd
from time import sleep

class DataSet():
  def __init__(self, rec_file: str, timestamps: list, actual_steering: list, computed_steering: list):
    self.rec_file = rec_file
    # timestamp list
    self.timestamps = timestamps
    # actual angle list
    self.actual_steering = actual_steering
    # computed angle list
    self.computed_steering = computed_steering
    self.previous_computed_steering = [0 for i in range(len(self.computed_steering))]

  # the __str__ method is used to print the object display the class attributes in a pretty way
  def __str__(self):
    return f"""
    File: {self.rec_file}
    TimeStamps: [ {self.timestamps[0]}, {self.timestamps[1]}, {self.timestamps[2]}, ... ]
    Actual Steering: [ {self.actual_steering[0]}, {self.actual_steering[1]}, {self.actual_steering[2]}, ... ]
    Computed Steering: [ {self.computed_steering[0]}, {self.computed_steering[1]}, {self.computed_steering[2]}, ... ]
    Previous Computed Steering: [ {self.previous_computed_steering[0]}, {self.previous_computed_steering[1]}, {self.previous_computed_steering[2]}, ... ]
    """

  def display_stats(self):
    computed_num_max = 0
    computed_num_0 = 0
    actual_num_max = 0
    actual_num_0 = 0
    # get the standard deviation of the steering angle
    std_steering = np.std(self.actual_steering)
    # check whether the computed steering angle is within the threshold +/- 0.05
    # and calculate the number of correct predictions
    correct_predictions = 0
    for i in range(len(self.actual_steering)):
      if abs(self.actual_steering[i]) == 0:
        actual_num_0 += 1
      if abs(self.actual_steering[i]) == 0.290888:
        actual_num_max += 1
    for i in range(len(self.computed_steering)):
      if abs(self.computed_steering[i]) == 0:
        computed_num_0 += 1
      if abs(self.computed_steering[i]) == 0.290888:
        computed_num_max += 1
      if abs(self.computed_steering[i] - self.actual_steering[i]) <= 0.05:
        correct_predictions += 1
    perc = correct_predictions / len(self.computed_steering)
    # print the results
    print("File: " + self.rec_file)
    print("============================== Results ==============================")
    print('the steering angle standard deviation: ' + str(std_steering))
    print("The number of actual 0s: " + str(actual_num_0))
    print("The number of computed 0s: " + str(computed_num_0))
    print("The number of actual maxs: " + str(actual_num_max))
    print('The number of computed maxs: ' + str(computed_num_max))
    print('the number correct predictions: ' + str(correct_predictions))
    print('The percentage of correct predictions is: ' + str(round(perc *100)) + '%')
    print('The total # of data points: ' + str(len(self.computed_steering)))
    print("=====================================================================")

  def create_graph(self):
    # make all lists normalized on the timestamp length
    self.actual_steering = self.actual_steering[:len(self.timestamps)]
    self.computed_steering = self.computed_steering[:len(self.timestamps)]
    self.previous_computed_steering = self.previous_computed_steering[:len(self.timestamps)]

    # create the graph
    pngname = self.rec_file.replace("./csvs/CID-140-recording-2020-03-18_", "").replace("-selection.csv", "")
    # convert the timestamps to seconds passed since entry 0
    self.timestamps = [str(x) for x in self.timestamps]
    # plot the steering angles
    plt.figure(figsize=(16,10))
    plt.plot(self.timestamps, self.actual_steering, 'r', label='actual steering')
    plt.plot(self.timestamps, self.computed_steering, 'b', label='computed steering')
    plt.plot(self.timestamps, self.previous_computed_steering, 'g', label='previous computed steering')
    plt.legend()
    plt.title(f"{self.rec_file}")
    # rotate all the x-axis labels by 90 degrees
    plt.xticks(rotation=90)
    # skip every other label
    plt.xticks(self.timestamps[::10])
    # change the font size of the x-axis labels to be half
    plt.xticks(fontsize=8)
    plt.xlabel("sampleTimeStamp (microseconds)")
    plt.ylabel("steeringAngles (radians)")
    # remove white space around the plot
    plt.tight_layout()
    # save the plot
    plt.savefig(f"./graphs/{pngname}.png")
    plt.close()

  def update(self, rec_file, timestamps, actual_steering, computed_steering):
    # update the previous computed steering angle
    self.previous_computed_steering = self.computed_steering
    # update the computed steering angle
    self.computed_steering = computed_steering
    # update the actual steering angle
    self.actual_steering = actual_steering
    # update the timestamps
    self.timestamps = timestamps
    # update the recording file
    self.rec_file = rec_file
    self.actual_steering = self.actual_steering[:len(self.timestamps)]
    self.computed_steering = self.computed_steering[:len(self.timestamps)]
    self.previous_computed_steering = self.previous_computed_steering[:len(self.timestamps)]

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

def readCSV(filepath: str):
  # open a csv file called results.csv and reatd the actualSteering column into a list and the computedSteering column into a list
  timestamps = list()
  actual_steering = list()
  computed_steering = list()
  file, ext = os.path.splitext(filepath)
  filepath = f"{file}.csv"
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
  # return a new instance of the DataSet class
  return (filepath, timestamps, computed_steering, actual_steering)

def run_all_rec_files():
  for file in os.listdir("./recordings"):
    if file.endswith(".rec"):
      cmd = f"./runner.sh ./recordings/{file} {file}"
      p = subprocess.Popen(cmd, stdout=subprocess.PIPE, shell=True)
      (output, err) = p.communicate()
      p_status = p.wait()

# run a single recording file
def run_rec_file(filepath: str, i):
  # pngname = filepath.replace("CID-140-recording-2020-03-18_", "").replace("-selection.rec", "")
  # get the id of the current thread
  cmd = f"./runner.sh ./recordings/{filepath} {filepath.replace('.rec', '')} {i+1}"
  p = subprocess.Popen(cmd, stdout=subprocess.PIPE, shell=True)
  (output, err) = p.communicate()
  p_status = p.wait()

# run all the records as threads and wait for them to finish before moving on
def run_all_rec_files_as_threads():
  threads = []
  for i, file in enumerate(os.listdir("./recordings")):
    if file.endswith(".rec"):
      t = threading.Thread(target=run_rec_file, args=(file,i,))
      threads.append(t)
      sleep(1)
      t.start()
  for t in threads:
    t.join()

def create_data_sets():
  datasets = list()
  for file in os.listdir("./csvs"):
    if file.endswith(".csv"):
      # the base name of the file
      name = os.path.basename(file)
      datasets.append(readCSV(name))
  return datasets

# move the csv files into a tmp folder
def move_csvs_to_tmp():
  # create a tmp folder if it doesn't exist
  if not os.path.exists("./tmp"):
    os.mkdir("./tmp")
  # move all the csv files into the tmp folder
  for file in os.listdir("./csvs"):
    if file.endswith(".csv"):
      shutil.move(f"./csvs/{file}", f"./tmp/{file}")

def move_csvs_back():
  # move all the csv files back into the csvs folder
  for file in os.listdir("./tmp"):
    if file.endswith(".csv"):
      shutil.move(f"./tmp/{file}", f"./csvs/{file}")


def clean_tmp():
  # if the tmp folder exists, delete it
  if os.path.exists("./tmp"):
    for file in os.listdir("./tmp"):
      if file.endswith(".csv"):
        os.remove(f"./tmp/{file}")
  # delete the tmp folder
    os.rmdir("./tmp")

# make a box plot of all of the actual steering angles vs the computed steering angles of all the data sets
def make_box_plot(datasets: list):
  # create a figure with a size of 16x10
  plt.figure(figsize=(16,10))
  # create a list of the actual steering angles
  actual_steering = list()
  # create a list of the computed steering angles
  computed_steering = list()
  # loop through all the data sets
  for k in datasets.keys():
    # add the actual steering angles to the list
    actual_steering.append(datasets[k].actual_steering)
    # add the computed steering angles to the list
    computed_steering.append(datasets[k].computed_steering)
  # create a box plot of the actual steering angles
  plt.boxplot(actual_steering)
  # create a box plot of the computed steering angles
  plt.boxplot(computed_steering)
  # set the title of the plot
  plt.title("Actual Steering Angles vs Computed Steering Angles")
  # set the x-axis label
  plt.xlabel("Data Set")
  # set the y-axis label
  plt.ylabel("Steering Angles (radians)")
  # save the plot
  plt.savefig("./graphs/boxplot_actual_vs_computed.png")
  # close the plot
  plt.close()
  # before and after slope chart
  # create a seaborn slope char of the previous and computed steering angles
  sns.set(style="whitegrid")
  # create a figure with a size of 16x10
  plt.figure(figsize=(16,10))
  # create a list of the actual steering angles
  previous_steering = list()
  # create a list of the computed steering angles
  current_steering = list()
  # loop through all the data sets
  for k in datasets.keys():
    # add the previous steering angles to the list
    previous_steering.append(datasets[k].previous_computed_steering)
    # add the current steering angles to the list
    current_steering.append(datasets[k].computed_steering)
  # crate a df from timestamps and previous steering angles
  df = pd.DataFrame({"timestamps": datasets[k].timestamps, "previous_steering": previous_steering})
  # create a df from timestamps and current steering angles
  df2 = pd.DataFrame({"timestamps": datasets[k].timestamps, "current_steering": current_steering})
  # create a slope chart of previous steering angles vs current steering angles
  sns.lineplot(x="timestamps", y="previous_steering", data=df)
  # create a slope chart of current steering angles vs current steering angles
  sns.lineplot(x="timestamps", y="current_steering", data=df2)
  # set the title of the plot
  plt.title("Previous Steering Angles vs Current Steering Angles")
  # set the x-axis label
  plt.xlabel("Data Set")
  # set the y-axis label
  plt.ylabel("Steering Angles (radians)")
  # save the plot
  plt.savefig("./graphs/slope_chart_previous_vs_current.png")
  # close the plot
  plt.close()

if __name__ == '__main__':
  # run_all_rec_files_as_threads()
  datasets = dict()
  for file in os.listdir("./csvs"):
    if file.endswith(".csv"):
      (filepath, timestamps, computed_steering, actual_steering) = readCSV("./csvs/" + file)
      datasets[file] = DataSet(file, timestamps, computed_steering, actual_steering)
  sleep(1)
  move_csvs_to_tmp()
  sleep(1)
  run_all_rec_files_as_threads()
  sleep(1)
  # block until all the threads are done
  while threading.active_count() > 1:
    pass
  sleep(1)
  # update the data sets with the new csv files
  for k in datasets.keys():
    (filepath, timestamps, computed_steering, actual_steering) = readCSV("./csvs/" + datasets[k].rec_file)
    datasets[k].update(filepath, timestamps, computed_steering, actual_steering)
  sleep(1)
  try:
    for k in datasets.keys():
      datasets[k].create_graph()
      print(datasets[k])
    make_box_plot(datasets)
  except Exception as e:
    print(e)
    move_csvs_back()
  sleep(1)
  clean_tmp()

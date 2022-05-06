import socket
import numpy as np

computed_steering = list()
actual_steering = list()


def flush_data():
    actual_steering.clear()
    computed_steering.clear()


def load_data(data: str):
    global computed_steering
    global actual_steering
    result = data.split("|")
    actual_steering.append(float(result[0]))
    computed_steering.append(float(result[1]))


def display_stats():
    global computed_steering
    global actual_steering
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
        if abs(computed_steering[i] - actual_steering[i]) < 0.05:
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
    flush_data()



serv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serv.bind(("127.0.0.1", 9900))
serv.listen(5)
while True:
    conn, addr = serv.accept()
    from_client = ""
    while True:
        data = conn.recv(4096)
        if not data:
            break
        from_client += str(data.decode())
        if from_client == "FINISHED":
            display_stats()
        else:
            load_data(from_client)

        # print(from_client)
    conn.close()

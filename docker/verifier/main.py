#!/usr/bin/env python2
# OpenDaVINCI - Portable middleware for distributed components.
# Copyright (C) 2017 Christian Berger, Julian Scholle
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

import cv2

import OD4Listener
import opendlv_standard_message_set_pb2

def onMessage(msg, timeStamps):
    print("sent: " + str(timeStamps[0]) + ", received: " + str(timeStamps[1]) + ", sample time point: "  + str(timeStamps[2]))
    print(msg)


def onImage(msg, image, timeStamps):
    print("sent: " + str(timeStamps[0]) + ", received: " + str(timeStamps[1]) + ", sample time point: "  + str(timeStamps[2]))
    print(msg)
    cv2.imshow('image', image)
    cv2.waitKey(1)

# "Main" part.
listener = OD4Listener.OD4Listener(cid=253, port=9900) # Connect to OpenDaVINCI CID session under CID 189.
#node.registerMessageCallback(28, onMessage, opendavinci_pb2.odcore_data_SharedPointCloud)

# // Message identifier: 1039.
# message opendlv_proxy_DistanceReading {
#     optional float distance = 1;
# }
listener.registerMessageCallback(1039, onMessage, opendlv_standard_message_set_pb2.opendlv_proxy_DistanceReading)
listener.connect()
listener.run()

#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Tue Oct 30 11:39:17 2020

@author: arun
"""

import requests, json, argparse, decimal, csv
from scipy.spatial import distance

import matplotlib.pyplot as plt
import numpy


headrs = {'Authorization':"user pass", 'Content-Type':"application/json"}

key_to_be_changed = ["coordX", "coordY", "coordZ"]

description_str = "Used to auto-update station coordinates. Usage example: python station_coordinates_updater.py --url=\"https://station-registry-api.com" --demo_mode=True --input_file=station_coordinates.csv"
hardcoded_url = "https://station-registry-api.com"
minimum_coordinates_precision = 3
old_vs_new_distance_threshold = 2.0
demo_mode = True


def parser_add_args(parser):
    """
    Add arguments to the parser
    :param arg_parser:
    :return:
    """
    parser.add_argument("--url", type=str, required=False,
                            help="Station Registry URL, Example: --url=\"https://station-registry-api.com")
    parser.add_argument("--demo_mode", type=str, required=True,
                            help="True, if you want to just test functionality but not change values, False, if you want to change values, Example: --demo_mode=True")
    parser.add_argument("--input_file", type=str, required=True,
                            help="csv file containing station names and coordinates, Example: --input_file=station_coordinates.csv")
    return parser

def get_number_of_digits_after_decimal(value):
    return -decimal.Decimal(str(value)).as_tuple().exponent

def parse_file_to_dict(filename):
    with open(filename, mode='r') as infile:
        reader = csv.reader(infile)
        #Skip header row
        next(reader)
        return {rows[0]:[float(rows[1]),float(rows[3]),float(rows[5])] for rows in reader}

def check_new_coordinates(old_key_value_array, new_key_value_array):
    precision_flag = True
    norm_flag = True
    norm = distance.euclidean(old_key_value_array, new_key_value_array)

    for i in range(len(new_key_value_array)):
        if get_number_of_digits_after_decimal(new_key_value_array[i]) < minimum_coordinates_precision:
            precision_flag = False
    if norm >= old_vs_new_distance_threshold:
        norm_flag = False

    return norm, precision_flag, norm_flag

def post_request(req_url, json_data):
    response = None
    try:
        response = requests.post(req_url, headers=headrs, data=json.dumps(json_data))
    except Exception as e:
        print("Exception occured: " + str(e))
    return response

def get_json_key_values(json_body, key_name_array):
    old_key_values_array = []
    for item in key_name_array:
        old_key_values_array.append(json_body[item])
    return old_key_values_array


def change_value(req_url, sp_id, key_name_array, key_value_array, logging = False):

    #Fetch station payload
    post_response = post_request(req_url + "getById", {"id":sp_id})
    payload_to_be_edited = json.loads(post_response.text)

    #Make copy of original value
    original_payload = payload_to_be_edited["station"].copy()

    #Check if values pass sanity checks
    old_key_values_array = get_json_key_values(original_payload, key_to_be_changed)
    norm, precision_flag, norm_flag = check_new_coordinates(old_key_values_array,key_value_array)

    if precision_flag and norm_flag and float(original_payload['estimatedAccuracy']) > 0.1:
        #Assign new value to payload key
        for i in range(len(key_name_array)):
            payload_to_be_edited["station"][key_name_array[i]] = round(key_value_array[i],4)
            print("* * * * * * * * * * * * * * * * * Changing " + key_name_array[i] + " of station " + str(original_payload["stationId"]) + " from " + str(old_key_values_array[i]) + " to " + str(key_value_array[i]) + "* * * * * * * * * * * * * * * * * ")
        post_response = post_request(req_url + "update", payload_to_be_edited)
        if logging == True:
            with open("old_station_coordinates.csv", mode='a') as oldfile:
                oldfile.write(str(original_payload["stationId"]) + "," + str(old_key_values_array[0]) + "," + str(old_key_values_array[1]) + "," + str(old_key_values_array[2]) + "\n")
            with open("new_station_coordinates.csv", mode='a') as newfile:
                newfile.write(str(original_payload["stationId"]) + "," + str(round(key_value_array[0],4)) + "," + str(round(key_value_array[1],4)) + "," + str(round(key_value_array[2],4)) + "\n")

    else:
        post_response = None
        if not precision_flag:
            print ("New coordinates failed checks for station: " + str(original_payload["stationId"]) + ", precision check: " + str(precision_flag))
        if not norm_flag:
            print ("New coordinates failed checks for station: " + str(original_payload["stationId"]) + ", old coordinates to new coordinates distance too high: " + str(norm))
        print("* * * * * * * * * * * * * * * * * Not changing coordinates of station " + str(original_payload["stationId"]) + "* * * * * * * * * * * * * * * * * ")
        if logging == True:
            with open("faulty_station_coordinates.csv", mode='a') as faultfile:
                faultfile.write(str(original_payload["stationId"]) + "," + str(old_key_values_array[0]) + "," + str(old_key_values_array[1]) + "," + str(old_key_values_array[2]) + "\n")

    return [original_payload, post_response]

#Must be removed
#def compute_plot_write_ppp_computations(json_body, ppp_file_data):
#Must be removed

def get_station_payload_id(station_coordinates_dict, url):
    #initialize dict of station payload id's used for update request
    station_payload_id_dict = dict.fromkeys(station_coordinates_dict.keys(),None)
    json_body = {}
    key_counter = 0
    last_scan_key_array = []
    last_scan_key = None
    all_prod_station_dict = {}
    while (key_counter < len(station_coordinates_dict) and last_scan_key not in last_scan_key_array):
        #Retrieve & store station_payload_ids for relevant stations in same order
        last_scan_key_array.append(last_scan_key)
        list_response = post_request(url + "list", json_body)
        station_list = json.loads(list_response.text)
        last_scan_key = station_list['lastScanKey']
        json_body = {'lastScanKey':last_scan_key}
        for item in station_list['stations']:
            if (item['stationId'] in station_coordinates_dict.keys()):
                station_payload_id_dict[item['stationId']] = item['id']
                key_counter += 1
                print("Station " + str(item['stationId']) + " found")
    return station_payload_id_dict, all_prod_station_dict

def main(url, demo_mode, station_coordinates_dict):

    full_url = url + "/stations/"
    station_payload_id_dict, all_prod_station_dict = get_station_payload_id(station_coordinates_dict, full_url)

    #Change all stations' data in a loop
    for station, payload_id in station_payload_id_dict.iteritems():
        if payload_id != None:
            #Edit Value
            [previous_payload, r] = change_value(full_url, payload_id, key_to_be_changed, station_coordinates_dict[station],not demo_mode)
            if r != None:
                print("Request Status Code: " + str(r.status_code) + ", Request Status Reason: " + str(r.reason))
                if demo_mode:
                    #Restore Value
                    print("Returning to previous values")
                    old_key_values_array = get_json_key_values(previous_payload, key_to_be_changed)
                    [_, r] = change_value(full_url, payload_id, key_to_be_changed, old_key_values_array,False)
                    if r != None:
                        print("Request Status Code: " + str(r.status_code) + ", Request Status Reason: " + str(r.reason))
        else:
            print("Station " + station + " not found")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=description_str)
    parser = parser_add_args(parser)
    args = parser.parse_args()
    if args.demo_mode == "False":
        demo_mode = False

    url = args.url
    if not args.url:
        url = hardcoded_url

    station_coordinates_dict = parse_file_to_dict(args.input_file)

    main(url, demo_mode, station_coordinates_dict)

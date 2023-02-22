# -*- coding: utf-8 -*-
"""
Created on Tue Feb 21 11:30:02 2023

@author: PGS2KOR
"""

import csv


def receive_bms_paramters(sender_input):
    charge_rate = []
    temperature = []
    BMS_Parameters = {}
    bms_parameters = csv.reader(sender_input.split('\n'), delimiter=',')
    bms_parameters = [value for value in bms_parameters][1:-1]
    
    for parameter_values in bms_parameters:
        charge_rate.append(float(parameter_values[0]))
        temperature.append(float(parameter_values[1]))
    BMS_Parameters = {'ChargeRate': charge_rate, 'Temperature': temperature}
    return BMS_Parameters

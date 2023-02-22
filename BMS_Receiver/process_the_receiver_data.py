# -*- coding: utf-8 -*-
"""
Created on Tue Feb 21 11:38:10 2023

@author: PGS2KOR
"""

def simple_moving_average(values):
    return sum(values) / len(values)


def find_simple_moving_average(bms_parameters):
    sma_for_charge_rate = simple_moving_average(bms_parameters['ChargeRate'][-5:])
    sma_for_temperature = simple_moving_average(bms_parameters['Temperature'][-5:])
    return (sma_for_charge_rate, sma_for_temperature)


def find_max_and_min_values_of_parameters(bms_parameters):
    max_min_values_of_parameters = {}
    max_min_values_of_parameters = {'ChargeRate': {'max': max(bms_parameters['ChargeRate']), 'min': min(bms_parameters['ChargeRate'])},\
                                    'Temperature': {'max': max(bms_parameters['Temperature']), 'min': min(bms_parameters['Temperature'])}}
    return max_min_values_of_parameters
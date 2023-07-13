#!/usr/bin/python3

"""
This module defines a function that returns the list of available attributes and methods of an object.
"""


def lookup(obj):
    """
    Returns a list object containing the available attributes and methods of the given object.
    """
    return dir(obj)

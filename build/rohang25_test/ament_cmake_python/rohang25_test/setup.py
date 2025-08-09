from setuptools import find_packages
from setuptools import setup

setup(
    name='rohang25_test',
    version='0.1.0',
    packages=find_packages(
        include=('rohang25_test', 'rohang25_test.*')),
)

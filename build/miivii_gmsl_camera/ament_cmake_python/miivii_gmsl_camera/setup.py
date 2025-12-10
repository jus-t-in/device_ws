from setuptools import find_packages
from setuptools import setup

setup(
    name='miivii_gmsl_camera',
    version='0.0.0',
    packages=find_packages(
        include=('miivii_gmsl_camera', 'miivii_gmsl_camera.*')),
)

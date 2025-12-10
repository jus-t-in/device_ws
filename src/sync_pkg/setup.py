from setuptools import setup
import os
from glob import glob

package_name = 'sync_pkg'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Your Name',
    maintainer_email='you@example.com',
    description='Synchronize lidar, cameras and radar',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'multi_sync_rename = sync_pkg.multi_sync_rename:main',
            'multi_sync_pub = sync_pkg.multi_sync_pub:main',
        ],
    },
)


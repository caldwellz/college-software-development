#Program: 2a.3
#Name: Josh Hetherton, Zach Caldwell
#Date: 1/17/2017
#Instructor: Jeff Light
#Description: Calculate Area and Volume

# This program will read in the radius and length of a cylinder and computes the area and volume

radius = float(input('Please enter the radius of the cylinder:'))
length = float(input('Please enter the length of the cylinder:'))

area = (radius ** 2) * 3.14159
volume = area * length

print('The area of the cylinder is:', area)
print('The volume of the cylinder is:', volume)

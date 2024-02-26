#mihik shah
#FY23B1D065
import numpy as np
import matplotlib.pyplot as plt
# creating the dataset
data = {'India':2, 'Aussie':6, 'New Zealand ':0,
'West Indies ':2}
courses = list(data.keys())
values = list(data.values())
fig = plt.figure(figsize = (10, 5))
# creating the bar plot

plt.bar(courses, values, color ='#87CEEB',
width = 0.4)
plt.xlabel("Team name ")
plt.ylabel("Wins ")
plt.title(" ODI World Cup")
plt.show()

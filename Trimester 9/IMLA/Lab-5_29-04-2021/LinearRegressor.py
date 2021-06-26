# -*- coding: utf-8 -*-
"""
Created on Thursday April 28 10:07:23 2021
@author: Prakash Waghmode
"""

"""
y = b0 + b1*x1
y: dependent variable
b0: constant
b1: coefficient
x1: independent variable
"""

import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# Importing the dataset

dataset = pd.read_csv('salary-data.csv')
X = dataset.iloc[:, :-1].values   #get a copy of dataset exclude last column
y = dataset.iloc[:, 1].values    #get array of dataset in column 1st

# Splitting the dataset into the Training set and Test set (30 observations- 20 will be used train, 10 will be used test)
from sklearn.model_selection import train_test_split 
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=1/3, random_state=0)

"""
# Scaling
from sklearn.preprocessing import StandardScaler
sc_X = StandardScaler()
X_train = sc_X.fit_transform(X_train)
X_test = sc_X.transform(X_test)
"""

# Fitting Simple Linear Regression to the Training set
from sklearn.linear_model import LinearRegression
regressor = LinearRegression()
regressor.fit(X_train, y_train)

# Predicting the Test set results
y_pred = regressor.predict(X_test)


# Visualizing the Training set results
viz_train = plt
viz_train.scatter(X_train, y_train, color='red')
viz_train.plot(X_train, regressor.predict(X_train), color='blue')
viz_train.title('Salary VS Experience (Training set)')
viz_train.xlabel('Year of Experience')
viz_train.ylabel('Salary')
viz_train.show()

# Visualizing the Test set results
viz_test = plt
viz_test.scatter(X_test, y_test, color='red')
viz_test.plot(X_train, regressor.predict(X_train), color='blue')
viz_test.title('Salary VS Experience (Test set)')
viz_test.xlabel('Year of Experience')
viz_test.ylabel('Salary')
viz_test.show()
y_pred = regressor.predict([[5]])   # passed exp=5 to predict salary 
print(y_pred)                      # or

y_pred = regressor.predict(X_test) # passed the whole x-test data column to predict salary for respective data point
print(y_pred)

#x_pred = regressor.predict([[73452]])
#print(x_pred)
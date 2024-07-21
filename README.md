# ECNG1009-Heart-Disease-Data-Mining-and-Analysis-Proj

## Background

According to the National Heart, Lung and Blood Institute (NHLBI), heart disease is a catch-all phrase for a variety of conditions that affect the heart’s structure and function. Furthermore, the World Health 
Organization (WHO) states that, cardiovascular diseases (CVDs) are the number one cause of death globally. The term “heart disease” is often used interchangeably with the term “cardiovascular disease” in 
discussing this topic. Persons suffering from heart diseases are at risk to acute events such as heart attacks and strokes, which are mainly caused by a blockage that prevents blood from flowing to the heart or 
brain. The most common reason for the blockage is a buildup of plaque, which is made up of fat and cholesterol, on the inner walls of the blood arteries that supply the brain or heart. Due to heart diseases 
being one of the biggest causes of mortality in the world, its prediction is regarded as one of the most important topics in the world. The WHO also states that “People with cardiovascular disease or who are at 
high cardiovascular risk (due to the presence of one or more risk factors such as hypertension, diabetes, hyperlipidaemia, or already established disease) need early detection.” Therefore, this project aimed to 
analyse the Heart Disease UCI Cleveland dataset to determine which attribute of patients, such as angina or diabetes, could be most suitable for determining whether or not a patient had a cardiovascular disease.

## Goals

### 1. Determine the Correlation Between Gender and Heart Disease
This function outputs to the console screen the total number of males and females, the number and percentage of persons with and without heart disease, and the quantity of males and females with and without 
disease.

### 2. Determine the Most Common Age Group and Average Age ff Heart Disease Patients
This function executes two sub-functions. One function shows the age information for all the patients, and the other shows the age data for only heart disease patients. The age information is classed by the 
lowest, highest, and overall average age, the average male and female age, as well as a histogram with 5 age group bins, starting from the lowest age. Each bin has a range of 10 years.

### 3. Determine the Relationship Between Exercised-Induced Angina and Heart Disease
This function displays the number of individuals who do and do not experience exercised-induced angina. In addition, the number of heart disease and non-heart disease patients who do and do not experience 
exercise-induced angina is also output.

### 4. Ascertain Which Chest Pain Types Are More Prevalent Among Heart Disease Patients
This function shows the number of heart disease and non-heart disease patients and the type of chest pain experienced.

### 5. Calculate the Probability That a Heart Disease Patient Has Either Diabetes, High Blood Pressure or Cholesterol
For this function, the user has to choose specifically which risk factor to display data for. For each factor, a probability tree displays the probability of an individual in this dataset having heart disease as 
well as the probability of the specific risk factor.

### 6. Determine The Correlation Between Narrowed Blood Vessels And Heart Disease
This function shows number of blood vessels highlighted by the fluoroscopy for all patients and heart disease patients. The percentage of heart patients is also output.

------

## Use

### 1
The application requires the UCI heart disease CSV input file. If the file is not found, an error is displayed on the console and the program quits.

### 2
If the file is found in the directory, The application prints a menu to the console prompting the user to make a choice which produces visualisations and text reports based on the selection.

### 3.
The application has built is error catching which prints error messages to the console if the any of the values in the csv do not match the required input


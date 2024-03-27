# Simulation of a Spatial SEIR Model
Simulations related to a Bachelor's Thesis at LMU Munich inspired by the outbreak of COVID19.

In this repo, you can find the simulations related to the spatial SEIR models.
Such models generalize classical SEIR ones that are only charactarized via differential equations, without considering any spatial relations.

I designed and implemented the model in C++ using stochastic modelling, you can see an example of a development of the epidemic below (green = susceptible, yellow = incubated, red = infected, blue = removed):

The case when the stochastic parameters suggest a controlled outbreak (what the government would prefer):
![image](https://github.com/vdrvar/seir-spatial-outbreak-simulation/assets/48907543/4977f319-5a7d-428f-b6dc-2f1b3f92fb1e)



The borderline case when the stochastic parameters suggest a risky spreading of the disease:
![image](https://github.com/vdrvar/seir-spatial-outbreak-simulation/assets/48907543/ee95a204-982a-4c5a-9605-ddacd5294188)



The case when the stochastic parameters suggest a total outbreak (what the government should avoid):
![image](https://github.com/vdrvar/seir-spatial-outbreak-simulation/assets/48907543/45d428ac-cac3-4b29-89b8-3f42cf56691d)


# Simulation of a Spatial SEIR Model
Simulations related to a Bachelor's Thesis at LMU Munich inspired by the outbreak of COVID19

In this repo, you can find the simulations related to the spatial SEIR models.
Such models generalize classical SEIR ones that are only charactarized via differential equations, without considering any spatial relations.

I designed and implemented the model in C++ using stochastic modelling, you can see an example of a development of the epidemic below (green = susceptible, yellow = incubated, red = infected, blue = removed):

The case when the stochastic parameters suggest a controlled outbreak (what the government would prefer):
![bacc_gif3](https://github.com/vdrvar/simulation_of_a_spatial_SEIR_model/assets/48907543/3c2d6c4f-d599-444f-8d99-8816c1666a90)


The borderline case when the stochastic parameters suggest a risky spreading of the disease:
![bacc_gif2](https://github.com/vdrvar/simulation_of_a_spatial_SEIR_model/assets/48907543/5bdbc20c-b880-4c37-97c6-64856235cc8e)


The case when the stochastic parameters suggest a total outbreak (what the government should avoid):
![bacc_gif](https://github.com/vdrvar/simulation_of_a_spatial_SEIR_model/assets/48907543/cde4c2aa-bc64-4a87-9a8c-7b07c6ee5083)

# Overview

An oceanographic (or waterways) data buoy containing a sensor to measure the water clarity (turbidity), correllate the turbidity with tide levels and then display the results on a mobile device.  The buoy will be deployed in the Encinal Basin. This correllation of tides and turbidity determines the optimal time for viewing bat rays in the Encinal Basin. 

## Background

The small building near Wind River building D (1321 Atlantic Ave, Alameda, California) provides an ideal area for Bat ray viewing under certain conditions. This is due to it's overhanging walkway combined with the shallow slope of the seabed in that area.The best viewing requires the following three conditions:
 

    The tide is within a certain range
    The building is not casting a shadow over the viewing area
    The water is fairly clear

 ##Goal

Build and deploy a buoy in Encinal basin behind building D. The buoy will contain a sensor to measure the clarity (turbidity) of the water and network the data to a host computer. Tidal and turbidity data will be compared with shadow information and presented to the user on a mobile device. I think this would entail Arduino(s) and Galileo hardware and Rocket.

This could provide an interesting service to Alameda and beyond, possibly garnering publicity for Wind River. Personally,  I have on several occasions brought my kids in the hopes of seeing bat rays, only to be thwarted by the conditions.

Expansion of the initial sensing could include things such as salinity, dissolved oxygen, electrical conductivity, temperature etc. Possibly becoming part of the Data Buoy Coop Panel community (part of the Joint Technical Commission for Oceanography and Marine Meteorology) in supplying beneficial scientific data.

###Condition #1 is readily obtainable from tide charts and empirical data. Tide chart data for a year in advance is available online (Alameda, CA  StationId: 9414750 here). Or, tides can be calculated on the Arduino.  My observations indicate tides of over +3.5 ft are good.

###Condition #2 is easily calculated (here). This is a nice to have feature, maybe not necessary.

###Condition #3 can be determined with a turbidity sensor. Commercial turbidmeters are very expensive. I've spent a lot of time resolving this and have determined that using a turbidity sensor from a common household dishwasher should suffice. We'll use the Amphenol TSD-10 or TSW-10,  $5! Characterizations of the sensor are below.




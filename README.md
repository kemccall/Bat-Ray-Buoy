# Overview

An oceanographic (or waterways) data buoy containing a sensor to measure the water clarity (turbidity), correllate the turbidity with tide levels and then display the results on a mobile device.  The buoy was to be be deployed in the Encinal Basin. This correllation of tides and turbidity determines the optimal time for viewing bat rays in the Encinal Basin. 

# Status
All hardware is operational (in a prototype state) and the software runs the turbidity sensor. The code here is in a state where the GSM comm works and the sensor code works, but gettiing both to work simultaneoulsy has not been accomplished. In all reality, if I were to switch to using the Particle platform this probably wouldn't be necessary. I think the Partricle board does everything including cellular communications very simply and cheaply.

## Hardware List

* Arduino 101 (if I did this again I'd used a [Particle.io devise] (https://www.particle.io/products/hardware/electron-cellular-2g-3g-lte), which can replace both the Arduino AND the GSM board cheaper and simpler! The only reason we used the Arduino 101 was because our marketing department wouldn't pay for a non Intel device. This ultimately led to so many complications that the project was never fully completed. 
* Arduino GSM shield (if you must)
* Battery w/solar charger would be nice.
* Amphenol TSW-10 (5 V) or TSD-10 (3 V) turbidity sensor. I think the 5 volt works better just due to allowing a wider range of variation. These are used in household washing machines and cost about $3 each. I spent a lot of time working with these and characterizing them under different conditions (3.3V supplies vs 5V, temperature extremes and such). Data sheets can be found here (https://www.mouser.com/ProductDetail/Amphenol-Advanced-Sensors/TSD-10?qs=cmBPKiaX3MylKvR%252bTrNAhw%3D%3D)
* Dallas DS18B20 1 wire digital thermometer.I beleive there was a special model that was a solid probe for external use, and not just a circuit as is shown in this data sheet. (https://datasheets.maximintegrated.com/en/ds/DS18B20.pdf)
* 3 inch outside diameter, schedule 40 PVC, or ABS sewer pipe (if I was to do it againm I'd use 4", or larger to be able to insert my hand all the way in  the tubing.)
* Qty 1, 3 inch ABS cleanout plug (http://www.osh.com/Osh-Categories/Plumbing/Rough-Plumbing/Pipes-%26-Fittings/Abs-Fittings/Canplas-Cleanout-Plug%2C-3-Inch%2C-ABS/p/1447374).
* Qty 1, # inch ABS counter sunk cleanout (http://www.osh.com/Osh-Categories/Plumbing/Rough-Plumbing/Pipes-%26-Fittings/Abs-Fittings/Canplas-Countersunk-Cleanout-Plug-With-O-Ring%2C-3-Inch%2C-ABS/p/1827690)
* Qty 2, 3 inch adapters (http://www.osh.com/Osh-Categories/Plumbing/Rough-Plumbing/Pipes-%26-Fittings/Abs-Fittings/Canplas-Adapter%2C-3-Inch%2C-ABS/p/1447077)
* Faom insulation paneling materia. This was used as the original stability ring because it was so easy to work with.  http://www.homedepot.com/p/Project-Panels-FOAMULAR-1-in-x-2-ft-x-2-ft-R-5-Insulation-Sheathing-PP1/203553730

### Enclosure
The enclosure is made of 3 inch ABS (or schedule 40 PVC) pipe and fittings with the exception of the stability ring. There's nothing particular about the ABS sewer pipe I used  other than it's inexpensive and readily available. You could use schedule 40 or 80 PVC, or different colored pipe. I would have liked clear PVC, but clear is considerably more expensive.

See the wiki for pictures.

I've attempted to make the simplest mechanical device, using readily avaiable materials from local (USA) hardware stores. Simplicity of construction with the least number of connections should provide confidence in water tightness. Here's an example of schedule 40 pipe http://www.pvcfittingsonline.com/pipe/schedule-40-pvc-pipe.html. Here in the states we can often find it in short lengths (12 to 18 inches) so you don't need to buy a long standard length. Additionally a variety of caps are used as well for the top and bottom ends. 
### Stablilty Ring
My prototype for the stability ring is made from Foamular(tm) rigid insulation, because it's very easy to work with and inexpensive. Eventually I'll 3D print the ring probably out of PLA. Here's the exact piece of insulation I used that allowed me to cut several rings. that I painted. http://www.homedepot.com/p/Project-Panels-FOAMULAR-1-in-x-2-ft-x-2-ft-R-5-Insulation-Sheathing-PP1/203553730.


## More Info
See the wiki pages https://github.com/kemccall/Bat-Ray-Buoy/wiki
